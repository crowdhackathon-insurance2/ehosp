import requests

url = "http://127.0.0.1:8000/api/v1/validation"

payload = "{\n\t\"card_id\": \"CARD_ID\"\n}"
headers = {
    'content-type': "application/json",
    'cache-control': "no-cache",
    'postman-token': "72771834-06a3-03ef-6ffd-36d3a6e90927"
    }

response = requests.request("POST", url, data=payload, headers=headers)

print(response.text)