#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cs50.h"

int main(int argc, char *argv[]){

    string nome_imagem = argv[1];

    //Verificacao se passar mais de um argumento
    if (argc != 2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    //Verificacao abrir imagem para leitura
    FILE *card = fopen("card.raw", "r");
    if(card == NULL){

        printf("Error\n");
        return 1;

    }

    int bloco = 512;

    //Bufer para armazenar os dados lido
    uint8_t dados_lidos[bloco];

    int contador = 0;
    char nome_jpeg[8];
    FILE *imagem = NULL;

    //Loop para ler os dados do cartao de memoria
    while(fread(dados_lidos, 1, bloco, card) == bloco){
        
        if((dados_lidos[0] == 0xff && dados_lidos[1] == 0xd8 && dados_lidos[2] == 0xff && (dados_lidos[3] >= 0xe0 && dados_lidos[3] <= 0xef))){
            //fecha jpeg anterior, se houver
            if(imagem != NULL){
                fclose(imagem);
            }

            //cria o novo jpeg    
            sprintf(nome_jpeg, "%03i.jpg", contador);
            imagem = fopen(nome_jpeg, "w");
            contador++;
        }
        
        //escreve os dados no jpeg
        if(imagem != NULL){
            fwrite(dados_lidos, 1, bloco, imagem);
        }
    }

    // Fecha o último arquivo
    if (imagem != NULL) {
    fclose(imagem);
    }
}