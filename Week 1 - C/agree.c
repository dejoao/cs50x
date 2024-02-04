#include <stdio.h>
#include <cs50.h>

int main(void) {

    char c = get_char("Voce aceita? \n");

    if (c == 'y' || c == 'Y')
    {
        printf("Aceito. \n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Nao aceito. \n");   
    }
    return 0;
}