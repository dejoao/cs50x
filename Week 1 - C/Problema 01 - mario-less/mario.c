#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;

    do
    {
        size = get_int("Size:");
    }
    while (size < 1);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}