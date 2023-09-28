from fastapi import Depends, FastAPI, HTTPException, status
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from pydantic import BaseModel
from datetime import datetime, timedelta
from jose import JWTError, jwt
from passlib.context import CryptContext
from models.client import Client

SECRET_KEY = "f3423d619e4b9b58e521076ef18c7146d833b7c9fb6dcac03570e6716e3c814b"
ALGORITHM = "HS256"
ACCESS_TOKEN_MINUTES = 30

db = {
    "Vzgo": {
        "name": "Vzgo",
        "email": "vzgo@gmail.com",
        "hashed_password": "",
        "disabled": False 
    }
}

class Token(BaseModel):
    access_token: str
    token_type: str


class TokenData(BaseModel):
    name: str or None = None

class ClientInDB(Client):
    hashed_password: str

pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
oauth_2_scheme = OAuth2PasswordBearer(tokenUrl="token")


app = FastAPI()

def verify_password(plain_password, hashed_password):
    return pwd_context.verify(plain_password, hashed_password)


def get_password_hashe(password):
    return pwd_context.hash(password)

def get_client(db, name: str):
    if name in db:
        client_data = db[name]
        return ClientInDB(**client_data)
    

def authenticate_client(db, name: str, password: str):
    client = get_client(db, name)
    if not client:
        return False
    if not verify_password(password, client.hashed_password):
        return False

    return client


def create_access_token(data: dict, expires_data: timedelta or None = None):
    to_encode = data.copy()
    if expires_data:
        expire = datetime.utcnow() + expires_data
    else:
        expire = datetime.utcnow() + timedelta(minutes=15)
    
    to_encode.update({"exp": expire})
    encoded_jwt = jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)
    return encoded_jwt


async def get_current_client(token: str = Depends(oauth_2_scheme)):
    credential_exception = HTTPException(status_code=status.HTTP_401_UNAUTHORIZED,
                                         detail="Could not validate credentials", headers={"WWW-Authenticate" : "Bearer"})
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        nam: str = payload.get("sub")
        if nam is None:
            raise credential_exception
        
        token_data = TokenData(name=nam)

    except JWTError:
        raise credential_exception
    
    client = get_client(db, name=token_data.name)
    if client is None:
        raise credential_exception
    
    return client



async def get_current_active_client(current_client: ClientInDB = Depends(get_current_client)):
    if current_client.disabled:
        raise HTTPException(status_code=400, detail="Inactive clinet")
    
    return current_client



@app.post("/token", response_model=Token) 
async def login_for_access_token(form_data: OAuth2PasswordRequestForm = Depends()):
    client = authenticate_client(db, form_data.username, form_data.password)
    if not client:
        raise HTTPException(status_code=status.HTTP_401_UNAUTHORIZED,
                                         detail="INcorrect username or password", headers={"WWW-Authenticate" : "Bearer"})
    access_token_epires = timedelta(minutes=ACCESS_TOKEN_MINUTES)
    access_token = create_access_token(
        data={"sub": client.name}, expires_data=access_token_epires)
    return {"access_token": access_token, "token_type": "bearer"}
    

@app.get("/client/me/", response_model=Client)
async def read_client_me(current_client: Client = Depends(get_current_active_client)):
    return current_client


@app.get("/user/me/items")
async def read_own_items(current_client: Client = Depends(get_current_active_client)):
    return[{"item_id": 1, "owner": current_client}]
