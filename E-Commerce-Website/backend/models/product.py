from pydantic import BaseModel
from typing import List

class Product(BaseModel):
    name: str
    description: str
    price: float
    seller_id: str  # Reference to the seller's ID (string representation)
    category: str
    quantity_available: int
    images: List[str]  # List of image URLs

    class Config:
        orm_mode = True
