#include <stdio.h>

int main(void) {
    
    /*
    Cases don't have to have breaks, and this creates a cool "hack." One of the most famous examples is Duff's device.
    */
    int x = 1;

    switch (x) {

        /*
        If x is either 0, 1, or 10, then it will pass all of the cases and print both lines, but if x is 15, it wont print first case, it will print only the
        last case.
        */
        case 0:
        case 1:
        case 10:
            puts("First case: x is 0, 1 or 10.");
            /* No break */
        case 15:
            puts("Second case: x is 0, 1, 10 or 15.");
            break;
    }

    return 0;
}