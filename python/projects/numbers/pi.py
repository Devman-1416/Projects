#Find PI to the Nth Digit - Enter a number and have the program generate PI up to
#that many decimal places.
#Keep a limit to how far the program will go.

import math

pie = str(math.pi)


while True:
    num = int(input("Enter PI digits to print: "))

    if num > 0 and num < 18:
        break
    print("Must be Number Between 0 and 18! Try again\n")



print("Your PI is: " + str(pie[:num]))


