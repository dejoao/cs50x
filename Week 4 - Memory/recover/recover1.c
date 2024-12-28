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

    int indice = 0;

    //Loop para ler os dados do cartao de memoria
    while(fread(dados_lidos, 1, bloco, card) == bloco){
        
        if(dados_lidos[indice] == 0xff){
            if(dados_lidos[indice + 1] == 0xd8){
                if(dados_lidos[indice + 2] == 0xff){
                    if(dados_lidos[indice + 3] == 0xe0 || 0xe1 || 0xe2 || 0xe3 || 0xe4 || 0xe5 || 0xe6 || 0xe7 || 0xe8 || 0xe9 || 0xea || 0xeb || 0xec || 0xed || 0xee || 0xef){
                        FILE *imagem = fopen("001.jpg", "w");
                        //Usar funcao fwrite para pegar o bytes do cartao e escrever no arquivo jpeg criado
                    }
                }
            }
        }
        indice++;  
    }

}
//tres primeiro bytes: 0xff 0xd8 0xff. opcoes do quarto byte 0xe0 0xe1 0xe2 0xe3 0xe4 0xe5 0xe6 0xe7 0xe8 0xe9 0xea 0xeb 0xec 0xed 0xee, ou 0xef.
//Fix linha 38 da para melhorar e nome dos arquivos 