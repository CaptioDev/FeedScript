# Prompt the user for input
print("Enter a mathematical expression using +, -, *, and / operators:")

# Read in the user's input
expr = input()

# Parse and evaluate the expression
try:
    result = eval(expr)
except ZeroDivisionError:
    print("Error: Division by zero")
    exit(1)

# Print the result
print("Result:", result)
