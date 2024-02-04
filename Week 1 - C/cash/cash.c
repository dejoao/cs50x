#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int change;

    // Solicitar valor de troco ao usuário até que a entrada seja válida
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 1);

    // Inicializar contador de moedas
    int coins = 0;

    // Contar o número mínimo de moedas necessárias
    while (change >= 25)
    {
        change -= 25;
        coins++;
    }

    while (change >= 10)
    {
        change -= 10;
        coins++;
    }

    while (change >= 5)
    {
        change -= 5;
        coins++;
    }

    while (change >= 1)
    {
        change -= 1;
        coins++;
    }

    // Imprimir o número mínimo de moedas necessárias
    printf("%d\n", coins);
}
