from pydantic import BaseModel
from typing import List

class Client(BaseModel):
    name: str
    email: str  # Username or email for authentication
    password: str  # Hashed password for security
    address: str  # Shipping address
    phone_number: str  # Contact number
    orders: List[str]  # List of order IDs (if you use string IDs)

   
