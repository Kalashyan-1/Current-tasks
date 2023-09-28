from models.client import Client

def individual_serial(client: Client) -> dict:
    return {
        "id": str(client.get("_id", "")),
        "name": client.get("name", ""),
        "email": client.get("email", ""),
        "password": client.get("password", ""),
        "address": client.get("address", ""),
        "phone_number": client.get("phone_number", ""),
        "orders": client.get("orders", []),
    }


def list_serial(clients) -> list:
    return [individual_serial(client) for client in clients]