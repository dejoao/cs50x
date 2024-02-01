#include <stdio.h>
#include <cs50.h>

int add(int a, int b);

int main(void){

    int x = get_int("Qual valor x?\n");
    int y = get_int("Qual valor y?\n");

    printf("%i\n", add(x, y));

}

int add(int a, int b){

    return a + b;

}