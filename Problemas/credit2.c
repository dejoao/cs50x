#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int validador(string cartao[]);
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
    // um loop que multiplique por dois a cada 2 digitos, comecando do penultimo
    
    validador(cartaoConvertido);
}

int caracteres (string cartao[]){
    int count = 0;
    while (cartao != 0){
        cartao = cartao/10;
        count++;
    }
    return count;
}

int validador(string cartao[]){

    //printf("%i", caracteres(cartao));
    // um loop que multiplique por dois a cada 2 digitos, comecando do penultimo
    int qCaracteres = caracteres(cartao);
    long long cartaoSeparado[qCaracteres / 2];
    int indiceCS = 0;
    for(int i = 0; i < (caracteres(cartao) - 1) / 2; i++){

        long long cartaoSeparado[indiceCS] = stroll(cartao[qCaracteres], NULL, 10);
        qCaracteres + 2;

    }
    return qCaracteres;

}
/*na funcao validador estou recebendo uma string, a cada dois digitos tenho que
pegar e converter em long long e multiplicar por dois e guardar em uma
variavel separada*/