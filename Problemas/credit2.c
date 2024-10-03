#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int validador(char cartaoConvertido[]);
int caracteres (long long cartao);

long long cartao;


int main(void){
    /* Pede o numero do cartao ao usuario e verifica se tem acento, se e 
    menor que 13 digitos e se e negativo. */  
    do
    {
        cartao = get_long_long("Numero: ");
    } while (cartao < 1000000000000 || cartao < -0 || cartao > 10000000000000000);
    //Preciso converter o cartao para uma string, so assim posso manipular
    char cartaoConvertido[caracteres(cartao)];
    sprintf(cartaoConvertido, "%lli", cartao);
    
    validador(cartaoConvertido);
}

int caracteres (long long cartao){
    int count = 0;
    while (cartao != 0){
        cartao = cartao/10;
        count++;
    }
    return count;
}

int validador(char cartaoConvertido[]){
    // Inverter o numero do cartao
    int qCaracteresCartao = strlen(cartaoConvertido) + 1;
    printf("%i\n", qCaracteresCartao);
    char cartaoInvertido[qCaracteresCartao];
    int indiceCI = 0;
    int indiceCC = qCaracteresCartao - 2;

    for(int i = 0; i < qCaracteresCartao ; i++){

        cartaoInvertido[indiceCI] = cartaoConvertido[indiceCC];
        indiceCI++;
        indiceCC--;

    }
    //printf("%s\n", cartaoInvertido);

    //
}
