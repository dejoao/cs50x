#include <cs50.h>
#include <stdio.h>

int main(void) {
    int x = get_int("Qual x?");
    int y = get_int("Qual y?");

    if (x < y)
    {
        printf("x e menor que y \n");
    }
    
    return 0;
}