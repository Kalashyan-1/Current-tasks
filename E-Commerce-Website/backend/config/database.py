from pymongo import MongoClient

client = MongoClient("mongodb+srv://khachkalashyan2016:peqKVsNJbsGeLo2F@cluster0.b3qkvn4.mongodb.net/?retryWrites=true&w=majority")

db = client["E-Commerce"]

client_collection = db["client"]
# product_collection = db["product"]
# seller_collection = db["seller"]


