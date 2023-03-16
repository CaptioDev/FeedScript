# Define the basic arithmetic operations
def add(a, b) -> a + b
def sub(a, b) -> a - b
def mul(a, b) -> a * b
def div(a, b) -> a / b

# Read in the user's input
print("Enter an expression: ")
expr = input()

# Parse and evaluate the expression
result = eval(expr)

# Print the result
print("Result: ", result)
