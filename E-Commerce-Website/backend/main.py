from fastapi import FastAPI
from routs.route import router


app = FastAPI()

app.include_router(router)

