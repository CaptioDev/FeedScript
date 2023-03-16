# FeedScript Basics:
A simple mathematical programming language

# Variables:
To define a variable in FeedScript, you would use the var keyword followed by the variable name and an initial value (if desired):

var x = 10;
var y = 2.5;
Note that in FeedScript, variables can hold either integer or floating-point values, but not both at the same time.

# Expressions:
FeedScript supports basic arithmetic and logical expressions using the standard operators:

var sum = x + y;
var product = x * y;
var quotient = x / y;
var remainder = x % y;

var greater_than = x > y;
var less_than = x < y;
var equal_to = x == y;

# Control Structures:
FeedScript provides if-else statements for conditional execution:

if (x > y) {
    fs_println("x is greater than y");
} else {
    fs_println("x is less than or equal to y");
}

FeedScript also provides while loops for iterative execution:

while (x > 0) {
    fs_println(x);
    x = x - 1;
}

# Functions:
You can define your own functions in FeedScript using the function keyword:

function square(x) {
    return x * x;
}

var result = square(3);
fs_println(result); // prints "9"

# Input and Output:
To print a string to the console, you can use the fs_print() or fs_println() functions from stdlib.h:

fs_println("Hello, world!");

To read input from the console, you can use the fs_read_*() functions from stdlib.h:

var x = fs_read_int();

# Extra:
Ignore the .cproject, and .project files. Those are for Eclipse IDE configurations. GitHub reads the .fs file as GLSL (OpenGL Shading Language), .fs means FeedScript (In this case). .Settings and .VsCode folders are for other programs. .Settings is Eclipse IDE and .VsCode is VScode
