import requests
from bs4 import BeautifulSoup


response = requests.get('https://www.geeksforgeeks.org/python-programming-language/')

# Converts the HTMl into readable structure
soup = BeautifulSoup(response.content, 'html.parser')

print(soup.prettify())
