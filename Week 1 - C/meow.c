#include <stdio.h>
#include <cs50.h>

int main(void) {

    /* int i = 0;
    while (i < 3) {

        printf("meow \n");
        i++;

    } */

    void meow(void); {

        printf("Meow!\n");
    }

    for (int i = 0; i < 3; i++)
    {
        meow();
    }
    
}