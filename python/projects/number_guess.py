import random

print("Welcome to Random Grandom Numdom Gamdom!!")
print("\nPlease enter the range for the number: Low to High: ")

num1 = int(input())
num2 = int(input())

while num1 >= num2:
    print("Error! Range backwards!")
    print("\nPlease enter the range for the number: Low to High: ")
    num1 = int(input())
    num2 = int(input())

radnum = random.randrange(num1, num2)


print("\n\nNow Guess tha Random Number! : ")
guess = int(input())


while guess != radnum:
    print("\nWrong Guess! Try again: ")
    guess = int(input())

print("You won!!!!! The Number was ",radnum)


