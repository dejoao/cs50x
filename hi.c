#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    //String manipulada, esta ao contrario
    printf("%c%c%c\n", words[0][2], words[0][1], words[0][0]);
    printf("%c%c%c\n", words[1][2], words[1][1], words[1][0]);

}