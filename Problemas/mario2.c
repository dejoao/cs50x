#include <stdio.h>

int piramide(int tamanho);
int espaco (int quantidade);

int tamanhoPiramide;
int quantidadeHastag = 1;

int main (void){

    //Pedir o tamanho da piramide
    do
    {
        printf("Altura: ");
        scanf("%i", &tamanhoPiramide);
    } while (tamanhoPiramide < 1);

    //Algoritmo da piramide
    int quantidadeespaco = tamanhoPiramide - 1;
    for (int i = 0; i < tamanhoPiramide; i++)
    {
        espaco (quantidadeespaco);
        piramide(quantidadeHastag);
        quantidadeHastag++;
        quantidadeespaco--;
    }
    
}

int piramide(int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("#");
    }
    printf("\n");
}

int espaco (int quantidade){
    for (int i = 0; i < quantidade; i++)
    {
        printf(" ");
    }
}