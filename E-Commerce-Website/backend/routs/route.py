from fastapi import APIRouter, Form, HTTPException
from models.client import Client
from config.database import client_collection
from schema.schemas import list_serial
from bson import ObjectId
from typing import List
# from registration import authentication

router = APIRouter()

# GET

@router.get("/")
async def get_client():
    try:
        clients = list_serial(client_collection.find())
        return clients
    except Exception as e:
        return {"error": str(e)}
    

# POST

# @router.post("/") 
# async def post_client(client: Client):
#     client_collection.insert_one(dict(client))


# @router.post("/create-account")
# async def create_account(
#     name: str = Form(...),
#     email: str = Form(...),
#     password: str = Form(...),
# ):
#     try:
#         # Your endpoint logic here

#         cl = Client(name, email, password, "add", "num", ["coff"])
#         client_collection.insert_one(dict(cl))

#         # If everything is successful, you can return a success message or status code
#         return {"message": "Account created successfully"}

#     except Exception as e:
#         # Handle the exception and return an appropriate response
#         raise HTTPException(status_code=500, detail=str(e))



@router.post("/create-account")
async def create_account(
    name: str = Form(...),
    email: str = Form(...),
    password: str = Form(...),
    address: str = Form(...),
    phone_number: str = Form(...),
    orders: List[str] = Form(...),
):
    # Perform server-side validation here (e.g., check if email is unique, validate password strength, etc.)

    # Check if the email is already registered
    # if email in [client.email for client in db.values()]:
    #     raise HTTPException(
    #         status_code=status.HTTP_400_BAD_REQUEST,
    #         detail="Email is already registered"
    #     )
    try:
    # Create a Client instance using keyword arguments
        cl = Client(
            name=name,
            email=email,
            password=password,
            address=address,
            phone_number=phone_number,
            orders=orders,
        )
        client_collection.insert_one(dict(cl))
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
    
    # For simplicity, let's just return the received data as JSON
    # return cl.dict()



@router.put("/{id}")
async def put_client(id: str, client: Client):
    client_collection.find_one_and_update({"_id": ObjectId(id)}, {"$set": dict(client)})



@router.delete("/{id}")
async def delete_client(id: str):
    client_collection.find_one_and_delete({"_id": ObjectId(id)})



