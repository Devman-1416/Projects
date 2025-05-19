def add(n1, n2):
    return n1 + n2

def multi(n1, n2):
    return n1 * n2

def sub(n1, n2):
    return n1 - n2

def div(n1, n2):
    return n1 / n2

print("--------------Calculator---------------\n")
current_num = 0

# Endless Loop
while True:
    if current_num == 0:
        while True:
            try:
                num1, sigh, num2 = input("Enter expression: ").split()
                num1 = float(num1)
                num2 = float(num2)

                if sigh not in ['+', '-', '*', '/']:
                    raise ValueError("Invalid operator")
                break  # Valid input, exit loop
            except ValueError:
                print("Not Valid Expression! Try Again.")
    else:
        clear = input("Enter C to Clear: ")
        if clear.lower() == "c":
            current_num = 0
            continue

        while True:
            try:
                # Use f-string to include current number in prompt
                sigh, num2 = input(f"Current Number: {current_num} ").split()
                num2 = float(num2)
                num1 = current_num

                if sigh not in ['+', '-', '*', '/']:
                    raise ValueError("Invalid operator")
                break  # Valid input, exit loop
            except ValueError:
                print("Not Valid Expression! Try Again.")

    if sigh == '+':
        result = add(num1, num2)
    elif sigh == '*':
        result = multi(num1, num2)
    elif sigh == '-':
        result = sub(num1, num2)
    elif sigh == '/':
        result = div(num1, num2)

    current_num = result
    print("\n", result)
