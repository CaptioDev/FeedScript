# FeedScript
FeedScript is a programming language designed for numeric computation and data processing. It is a high-level language with a syntax similar to popular programming languages like C and Python, but with a focus on mathematical operations and functions.

# Installation
To use FeedScript, you will need to check the interpreter.c and .h files in this GitHub.

# Usage
FeedScript files have the extension .fscript. To run a FeedScript program, you need to call the interpreter and pass the path to the file as an argument. Here's an example:

feedscript my_program.fscript
Language Basics
Data Types
FeedScript supports two main data types: int for integers and float for floating-point numbers.

# Variables
In FeedScript, you can declare variables using the let keyword, followed by the variable name and its value. Here's an example:

let x = 10;
let y = 3.14;

# Operators
FeedScript supports a range of mathematical operators, including:

+ addition
- subtraction
* multiplication
/ division
% modulo
Here's an example:

let x = 10;
let y = 3;
let z = x + y * 2;

# Functions
FeedScript supports user-defined functions. You can declare a function using the def keyword, followed by the function name, its parameters (if any), and its body. Here's an example:

def multiply(x, y) {
    return x * y;
}
You can call a function by its name, followed by its arguments in parentheses. Here's an example:

let x = 10;
let y = 3;
let z = multiply(x, y);

# Input and Output
FeedScript provides functions for input and output. The print function outputs text to the console, while the read_int and read_float functions read input from the user. Here's an example:

let x = read_int();
let y = read_float();
print("x = " + x + ", y = " + y);
Examples
Here are some examples of FeedScript programs:

Example 1: Compute the sum of two numbers

let x = 10;
let y = 20;
let z = x + y;
print(z);

Example 2: Compute the factorial of a number

def factorial(n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

let x = read_int();
let y = factorial(x);
print(y);

Example 3: Generate a Fibonacci sequence

def fibonacci(n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

let x = read_int();
for (let i = 0; i < x; i++) {
    let y = fibonacci(i);
    print(y);
}

# Conclusion
FeedScript is a powerful language for mathematical computation and data processing. Its simple syntax and user-friendly functions make it easy to learn and use. Try it out for yourself and see what you can create!
