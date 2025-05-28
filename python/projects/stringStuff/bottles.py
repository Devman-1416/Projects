#99 Bottles
#Create a program that prints out every line to the song "99 bottles of beer on the wall."

#Do not use a list for all of the numbers, and do not manually type them all in. Use a built in function instead.
#Besides the phrase "take one down," you may not type in any numbers/names of numbers directly into your song lyrics.
#Remember, when you reach 1 bottle left, the word "bottles" becomes singular.

import time

def lyrics(numBottles):
    bottles = 'bottles'


    print("\n")
    print(f"{numBottles} {bottles} of beer on the wall.\n")
    time.sleep(1)

    print(f"{numBottles} {bottles} of beer.")
    time.sleep(1)

    numBottles -= 1
    if numBottles == 1: bottles = 'bottle'

    print(f"Take one down, pass it around! \n{numBottles} {bottles} of beer on the wall!!\n\n")
    return numBottles


numBottles = 99

while True:
    numBottles = lyrics(numBottles)
    time.sleep(2)
    if numBottles == 0: break

print ("\nEnd of Song!\n")
