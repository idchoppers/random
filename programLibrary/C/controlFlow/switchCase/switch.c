#include <stdio.h>

int main(void) {
    
    int i = 10;

    /*
    For an integer value, switch acts like multiple if statements where the different cases represent the different values of the integer. Every case is 
    essentially a label.
    */
    switch (i) {
        case 1:

            puts("i is 1.");
            break; /* Break is mandatory for every case. */

        case 2:

            puts("i is 2.");
            break;

        default:

            puts("i is neither 1 or 2.");
            break;

    }

    /*
    Cases 1 and 2 both would mean "if (i == 1)" and "if (i == 2)" and default would mean "if (i == anything else)" If multiple if else statements are needed
    then using switch is a better solution as it is easier for humans to read, shortens the length of your code, and is faster to compile. The outcome should 
    be the default case, but modifying i to be either 1 or 2 will activate the respective case.
    */
    return 0;
    
}