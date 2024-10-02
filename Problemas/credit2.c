#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int validador(char cartaoConvertido[]);

long long cartao;


int main(void){
    /* Pede o numero do cartao ao usuario e verifica se tem acento, se e 
    menor que 13 digitos e se e negativo. */  
    do
    {
        cartao = get_long_long("Numero: ");
    } while (cartao < 1000000000000 || cartao < -0 || cartao > 10000000000000000);
    //Preciso converter o cartao para uma string, so assim posso manipular
    int *indice;
    indice = malloc(sizeof(long long));
    char cartaoConvertido[*indice];
    sprintf(cartaoConvertido, "%lli", cartao);
    
    validador(cartaoConvertido);
    //free(indice);
}

int validador(char cartaoConvertido[]){
    // Inverter o numero do cartao
    char cartaoInvertido[strlen(cartaoConvertido)];
    int indiceCI = 0;
    int indiceCC = strlen(cartaoConvertido);

    for(int i = 0; i < strlen(cartaoConvertido) ; i++){

        cartaoInvertido[indiceCI] = cartaoConvertido[indiceCC];
        indiceCI++;
        indiceCC--;

    }
    printf("%s", cartaoInvertido);
}
/* Tenho que inverter a string; Na parte de converter o long long em string
"deu certo", preciso ve onde vou colocar o free para liberar a memoria.   */
