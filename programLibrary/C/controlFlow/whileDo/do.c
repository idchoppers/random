#include <stdio.h>

int main(void) {

    /*
    Make integer i and assign it a value of 7.
    */
    int i;
    i = 7;

    /*
    Do executes the loop body before checking the condition. 
    */
    do {
        printf("i is now %d\n", i);
        i--;
    } 
    while (i > 0);

    /*
    Program should print 7 lines while decrementing the value of i after each print. It should end at "i is now 1" 
    This is because it will print and then decrement, and once 1 is 0, it will check the condition, and because the condition
    isn't true, then it wont execute the loop body.
    */
    return 0;
}