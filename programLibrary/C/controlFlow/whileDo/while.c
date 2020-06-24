#include <stdio.h>

int main(void) {
    
    /*
    Make integer i and make it equal to 0.
    */
    int i;
    i = 0;

    /*
    Loop will continue while i doesn't equal 10. 
    */
    while(i < 10) {

        /*
        Print i's value, print a new line, and increase the value by 1.
        */

        /* i++; */
        printf("i is now %d\n", i);
        i++;
    }

    /*
    Return 0 since main is void.
    */
    return 0;

    /*
    The program will print i's value and increase it repeatedly until i's value equals 10. This will not print "i is now 10" because this program
    increases i after it prints. If it increased i before it prints, then it will print "i is now 10."
    */
}