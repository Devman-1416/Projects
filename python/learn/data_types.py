x = 1    # int
y = 2.8  # float
z = 1j   # complex

    # Get type
print(type(x))
print(type(y))
print(type(z))

#casting
c = complex(x)

# For random num
import random

print(random.randrange(1, 10))

#string can use ""  or '', for use inside string need opistie
print("Hello")
print('Hello')

    # Single and Multi Line string

a = "Hello"
print(a)

a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""
print(a)

    #Strings are arrays


for x in "banana":
  print(x)

    #string length
a = "Hello, World!"
print(len(a))

    # Check certain things in string
txt = "The best things in life are free!"
print("free" in txt)

txt = "The best things in life are free!"
print("expensive" not in txt)

#Slicing You can return a range of characters by using the slice syntax.
#uses Indexes

b = "Hello, World!"
print(b[2:5])

b = "Hello, World!"
print(b[-5:-2])

#modify string
b = "Hello, World!"
print(b[-5:-2])
