/*
Don't try to compile this, this is just a notes and definitions file.
*/

/*
C programs consist of these things:

Data types definitions (structures, new types, etc.) They are based on other existing types.
Create a new name for an integer type:
*/

typedef int new_type_name;
new_type_name x;

/*
X is now type "new_type_name" which is an integer.

Global variables (declared outside of functions). Simply declare a variable with a constant value outside of a function.
*/

int global_var = 56;

/*
Functions. The example below takes an integer "a" and returns its square.
*/

int square( int a ) {return a * a;}

/* Multiline comments like this one */

// Single line comments (only in C99 and later)

/*
Preprocessor and compiler directives. like #include or #define, most start with '#'
*/

#define CATS_COUNT 42
#define ADD(x, y) (X) + (y)

/*
Every action is a statement. Statements are always seperated by semicolons. The actions are performed sequentially. Functions can't be defined inside of other
functions. Statements can declare variables and data types local to the function, or perform actions. A special case is a block between curly braces {}, which is
used to group statements. 
*/

/*
Note on printf() Printf takes formats like %d (prints an integer), and %f (prints a floating point number). puts() does not use these. Try to use printf() for
format specific printing only and use puts() for everything else. Do this because of security flaws.
*/

/*
C typing: weak, and static

Static typing:
All types are known in compile time. Whether you use variables, literals, or complex expressions, which evaluates to some data, its type will be known.

Weak typing:
A data element can be converted to another type when appropriate. Ex: 1 + 1.0 = ? 1 is an integer and 1.0 is a floating point number, and that means
that they cannot be added together. If they were both either floating of integer types, then they can be added together.
*/

/*
All types in C will fall into these categories:

Integer numbers (int, char ...)

Floating point numbers (double and float)

Pointer types

Composite types: structures and unions

Enumerations
*/