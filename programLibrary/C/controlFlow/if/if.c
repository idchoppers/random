#include <stdio.h>

int main(void) {

    /*
    Make integer i and set it's value to 45.
    */
    int i;
    i = 42; /* Change this to see what the else does */

    /*
    If i has a value equal to 45, then it will say that it is.
    */
    if(i == 45) {
        printf("i is equal to 45\n");
    }

    /*
    If can be used multiple times.
    */
    if(i == 42) {
        printf("i is equal to life\n");
    }
    
    /*
    It i isn't equal to 45, then say it isn't, and print what it really is.
    */
    else {
        printf("i isn't equal to 45, and it is actually equal to %d\n", i);
    }

    /*
    Return because main is a void function.
    */
    return 0;
}