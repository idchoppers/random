#include <stdio.h>

int main(void) {
    
    /*
    Make an array (a) that contains 4 data points.
    */
    int a[] = {1, 2, 3, 4}; 
    /*
    Make integer i equal to 0.
    */
    int i = 0;

    /*
    The for form: for (initializer; condition; step) {body}. For starts the initializer, then checks the condition, if the condition holds, then the body
    is executed and, lastly, execute the step. After that the loop checks the condition and so on.
    */
    for (i = 0; i < 4; i++) {
        printf("%d\n", a[i]);
    }

    /*
    The program should print 1-4 in new lines and stop.
    */
    return 0;
}