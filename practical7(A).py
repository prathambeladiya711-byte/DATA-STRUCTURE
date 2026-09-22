# prac 7.1

try:
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))

    result = a / b
    print("Result =", result)

except ZeroError:
    print("Error: Cannot divide by zero.")