import requests

#Sends a GET request to the given URL.
response = requests.get('https://www.geeksforgeeks.org/python-programming-language/')

#Returns HTTP status code (200 = success).
print(response.status_code)

#Returns the raw HTML of the page in bytes.
print(response.content)
