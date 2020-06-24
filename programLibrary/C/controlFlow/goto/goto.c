#include <stdio.h>

int main(void) {
    /*
    NOTE: goto should be used as least as possible in programming for two things: 1)It is hard for humans to read and 2)It is hard for
    computers to read. If your program uses multiple labels and goto statements, it will be harder to see the flow of your program, and compilers also
    take longer to compile this code because it is harder to maintain. 

    Nonetheless, it is always good to learn things like goto to learn what not to do, and some of the history of programming.
    */

    int i;
    int j;
    /*
    The for loops will constantly increase i and j by one until they both reach 100.
    */
    for (i = 0; i < 100; i++)

    for (j = 0; j < 100; j++) {
        /*
        While the variables are increasing and multiplying, this if else statement is constantly checking if the answer equals 432 or not, and if it does,
        then it will execute the goto statement to break the loop
        */
        if (i * j == 432) {
            goto end;
        }
        else
        {
            printf("%d * %d != 432\n", i, j);
        }
        
    }
    end:

    /*
    This will print what i multiplied by j equals, if at any time the result is 432. Them the goto end will execute to cancel the loop.
    Breaking from several nested cycles is a common use of goto, but that is something that says bad design, this is because the inner loops can
    be abstracted in different functions.
    */
    return 0;
}