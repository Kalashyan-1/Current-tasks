from pydantic import BaseModel
from typing import List

class Seller(BaseModel):
    username: str  # Username or email for authentication
    password: str  # Hashed password for security
    company_name: str
    address: str  # Business address
    phone_number: str  # Contact number
    products: List[str]  # List of product IDs (string representation)

    class Config:
        orm_mode = True
