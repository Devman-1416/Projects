# This is How to Comment


#Indentation Is important for how it runs blocks of code!!!
name , age = "Devin", 26

if ( 5 > 2):
    print(name,"  is  ", age)

#Variables dont need any sort of type

x , y , z = 1.1,"Hello",5

    #Can cast
x = str(3)    # x will be '3'
y = int(3)    # y will be 3
z = float(3)  # z will be 3.0

    #String can be Delcared two Ways
x = 'Hello'
x = "Hello"

    #Varable Naming
myvar = "John"
my_var = "John"
_my_var = "John"
myVar = "John"
MYVAR = "John"
myvar2 = "John"

    # varables not in functions are globals, in functions local
    # Global variables acan be used in and out of functions
    #To make global variable in function

def myfunc():
  global x
  x = "fantastic"

myfunc()

print("Python is " + x)