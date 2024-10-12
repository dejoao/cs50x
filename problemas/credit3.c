#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int caracteres(long long cartao);
int validador (char cartaoConvertido[]);

long long cartao;

int main(void){

     /* Pede o numero do cartao ao usuario e verifica se tem acento, se e 
    menor que 13 digitos e se e negativo. */  
    do
    {
        cartao = get_long_long("Numero: ");
    } while (cartao < 1000000000000 || cartao < -0 || cartao > 10000000000000000);
    
    //converter o cartao para uma string
    char cartaoConvertido[caracteres(cartao)];
    sprintf(cartaoConvertido, "%lli", cartao);

    validador(cartaoConvertido);

}

int caracteres(long long cartao){
    int count = 0;
    while (cartao != 0){
        cartao = cartao/10;
        count++;
    }
    return count - 1;
}

int validador (char cartaoConvertido[]){

    int mCartao = caracteres(cartao) / 2;
    char separados[mCartao];
    int indiceS = 0;
    int indiceC = caracteres(cartao) - 1;

    /*Separar a cada dois digitos comecando do penultimo, guardar em um 
    string */
    for(int i = 0; i < mCartao; i++){
        separados[indiceS] = cartaoConvertido[indiceC];
        indiceS++;
        indiceC -= 2;
    }
    printf("%i\n", caracteres(cartao));
    printf("%s\n", separados);

    //Multiplicar por dois cada digito separado e, somar tudo
    int resultadoMS = 0;

    for (int i = 0; i < mCartao; i++){
        int q = separados[i] - '0';
        q *= 2;
        resultadoMS += q;
        //separadosConvertido[i] = q + '0';
    }
    printf("%i\n", resultadoMS);
    
    //Transformar o restante dos numeros em long long tambem
    char restantes[mCartao];
    int indiceR = 0;
    int indiceC2 = caracteres(cartao);

    for(int i =0; i < caracteres(cartao); i++){
        restantes[indiceR] = cartaoConvertido[indiceC2];
        indiceR++;
        indiceC2 -= 2;
    }
    //printf("%s", restantes);

    //Somar o restante com o resultado da outra parte
    int restanteS = 0;

    for (int i = 0; i < mCartao + 1; i++){
        int q = restantes[i] - '0';
        restanteS += q;
        //separadosConvertido[i] = q + '0';
    }
    printf("%i\n", restanteS);

}

/*
------------------------
   __                  
   \ \  __ _  ___      
    \ \/ _` |/ _ \ 
 /\_/ / (_| | (_) |
 \___/ \__,_|\___/ 

------------------------                         
*/