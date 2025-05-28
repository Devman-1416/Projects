import requests

# Making a GET request
r = requests.get('https://www.amazon.com/Hobbit-Lord-Rings-Deluxe-Pocket/dp/0544445783/ref=sr_1_1?dib=eyJ2IjoiMSJ9.r-l64dKEOPD_ZLRNpEuDQo2iem4TgB5YS5lJfAbbtrD5cwFhWM226RdGdr-qke81HnwnM4_jtNiAl1_gURw-P7222Aoc2f_vnuggvH4yafROWfBopsS26zlv-dl52RwuvDPLdrVoBlrRIaB8FkyBdZFsWMS5mKmQBx9budZzKu9WTMDe5qMsbFsG9S2A1S93qIr185tQtdmFbGxKdEs7vSGFGULJE0hNGvb18Kg2mig.h5n96UN1QfOOv10x2T-SwImZjveTSyJ6wMbXg__VQhM&dib_tag=se&keywords=lotr&qid=1748394987&sr=8-1')

# check status code for response received
# success code - 200
print(r)

# print content of request
print(r.content)
