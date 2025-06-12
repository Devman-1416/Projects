#Factors of a Number
#Define a function that creates a list of all the numbers that are factors of the user's number.
#For example, if the function is called factor, factor(36) should return [1, 2, 3, 4, 6, 9, 12, 18, 36].
#The numbers in your list should be sorted from least to greatest, and 1 and the original number should be included.
#Remember to consider negative numbers as well as 0.
#Bonus:

#Have the program print the factors of the user's number in a comma-separated string, without a comma after the last number, and without the brackets of a Python list.
#If the user's number is prime, note it.

def factor(num):

    factors = []
    count = 1

    while count <= abs(num):

        if (num % count) == 0:
           factors.append(count)

           if (num < 0):
               factors.insert(0,-abs(count))

        count +=1
    if (num < 0):
        lenght = int((len(factors) / 2))
        factors.insert(lenght,0)

    else: factors.insert(0,0)

    print (factors)


factor(-133)

