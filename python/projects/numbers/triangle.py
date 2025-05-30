#Pythagorean Triples Checker
#Allows the user to input the sides of any triangle in any order.
#Return whether the triangle is a Pythagorean Triple or not.
#Loop the program so the user can use it more than once without having
#to restart the program.

import math



def tripleCheck(x):
    if (x > 0 and isinstance(x,int)):
        return True
    else: return False

def getSide():
    while (True):
        try:
            return int(input())
        except ValueError:
            print("Invalid Input! Enter a Number.")

def theromCheck(a,b,c):
    if ((a*a) + (b*b)) == (c*c): return True
    else: return False


while (True):

    print("\nEnter Three Sides: ")
    a = getSide()
    b = getSide()
    c = getSide()


    if theromCheck(a,b,c):

        if (tripleCheck(a) and tripleCheck(b) and tripleCheck(c)):

            if (math.gcd(math.gcd(a,b), c) == 1):
                print(f"This Triangle is a Primitive Pythagorean Triple! [{a} x {b} x {c}]")

            else: print(f"This Triangle is a Pythagorean Triple! [{a} x {b} x {c}]")

        else: print(f"This Triangle is not a Pythagorean Triple! [{a} x {b} x {c}]")

    else: print("\nDosent Work in the Threom!")

    if (input("Do you wish to exit? Y/y : ").lower() == "y"):
        break


print("\nThanks for Playing!\n")
