import requests

# TODO: send the unique card_id
# Validation - Step 1
#card ID
card_id="1D:52:A6:A9"

url1 = "http://127.0.0.1:8000/api/validation/step1"
headers = {
    'accept': "application/json",
    'authorization': "Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsImp0aSI6IjFiMWY0ZWE5N2Q5Mzk1OWM1YmZhNTczNDBiMGQwNmVhOThlYzc0NzYyZDhiNWEyOWJhNzhiMWY3MGZmNzI3N2QyNGE3NDRiYjc4ZmU5YjRlIn0.eyJhdWQiOiIxIiwianRpIjoiMWIxZjRlYTk3ZDkzOTU5YzViZmE1NzM0MGIwZDA2ZWE5OGVjNzQ3NjJkOGI1YTI5YmE3OGIxZjcwZmY3Mjc3ZDI0YTc0NGJiNzhmZTliNGUiLCJpYXQiOjE1MTE2NDg4OTAsIm5iZiI6MTUxMTY0ODg5MCwiZXhwIjoxNTQzMTg0ODkwLCJzdWIiOiIxIiwic2NvcGVzIjpbXX0.U_RBtKhT8G1exlG5wXgIlyqT-bv8Qvpc92Un0lLtu-zctyFwoazDPWN8-kdsfY6uvrBw3Ec-kD5piGH6RbQ7eOf6njOBOzflb3OI5dYtO3xCBkxNlAAd3Vh_PvIa9uqa0V0DhryWH_QQZ-lBHcCd3eorynjRldjdbQutLbIgC6J2pOIbaTvJvbqN4x8gGUK3ZJzeAjuT5DbWgsn98E30Rt39XhEYOol1Jmr9sMlo5N30oel_IZquB5bfsdn2BTHq8O9Orz0p-ixnhQsYqpE1Ea8waAR8YSmhpLJHhU9Aiz8Z_aTCBsDMIIAwN9v9p3RCchVHW_ZFDwBN0VJVAVEr2CAnfxrajMNM2QINGK_z_-cS0_C1DokQGp2U74l0JoliFZEvZFduVSQK6XKEn2WQE9M-IvpsippmqxtKWNhJJ1ovFWEfwymkblNYMchzrSJk2nSmZaQoFeI3Au1FXjsqCWU-C_jId0b001A58_0yWrQYWxJpt8jTRFpWfYBeG53A3OZUzzYQlPRcOWU44XujVs-Bzc12hDq7lKSwd_Nm5o4iM0lEjbskAAXlbV4KEsmlCrwd3jZ_x-QYXvYh5_ewGcpQGgjvsW-Pw7KryFT7Nbg8hsLQG0ADi31snXoWjtu88ZOsksmV_8n3DWHmD5VgfORZ9_9BLEs1odiNUqZU49w",
    'cache-control': "no-cache",
    'postman-token': "4d217fbf-c062-4924-b57c-ac4c3b2d7154"
    }
response1 = requests.request("POST", url1, headers=headers)
print(response1.text)

# TODO: send the received passcode from SMS

# Validation - Step 2
url2 = "http://127.0.0.1:8000/api/validation/step2"
response2 = requests.request("POST", url2, headers=headers)
print(response2.text)