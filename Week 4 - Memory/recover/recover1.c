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

    //int indice = 0;

    //Loop para ler os dados do cartao de memoria
    while(fread(dados_lidos, 1, bloco, card) == bloco){
        int indice = 0;

        if(dados_lidos[indice] == 0xff){
            if(dados_lidos[indice + 1] == 0xd8){
                if(dados_lidos[indice + 2] == 0xff){
                    if(dados_lidos[indice + 3] == 0xe0 || dados_lidos[indice + 3] ==  0xe1 || dados_lidos[indice + 3] ==  0xe2 || dados_lidos[indice + 3] ==  0xe3 || dados_lidos[indice + 3] ==  0xe4 || dados_lidos[indice + 3] ==  0xe5 || dados_lidos[indice + 3] ==  0xe6 || dados_lidos[indice + 3] ==  0xe7 || dados_lidos[indice + 3] ==  0xe8 || dados_lidos[indice + 3] ==  0xe9 || dados_lidos[indice + 3] ==  0xea || dados_lidos[indice + 3] ==  0xeb || dados_lidos[indice + 3] ==  0xec || dados_lidos[indice + 3] ==  0xed || dados_lidos[indice + 3] ==  0xee || dados_lidos[indice + 3] ==  0xef){
                        FILE *imagem = fopen("001.jpg", "w");
                        //Usar funcao fwrite para pegar o bytes do cartao e escrever no arquivo jpeg criado
                        fwrite(dados_lidos, 1, bloco, imagem);
                    }
                }
            }
        }
        indice++;
         
    }
    fclose(imagem);

    if(fread(dados_lidos, 1, bloco, card) < bloco){
        
        while(fread(dados_lidos, 1, bloco, card) == bloco){
            int indice = 0;

            if(dados_lidos[indice] == 0xff){
                if(dados_lidos[indice + 1] == 0xd8){
                    if(dados_lidos[indice + 2] == 0xff){
                        if(dados_lidos[indice + 3] == 0xe0 || dados_lidos[indice + 3] ==  0xe1 || dados_lidos[indice + 3] ==  0xe2 || dados_lidos[indice + 3] ==  0xe3 || dados_lidos[indice + 3] ==  0xe4 || dados_lidos[indice + 3] ==  0xe5 || dados_lidos[indice + 3] ==  0xe6 || dados_lidos[indice + 3] ==  0xe7 || dados_lidos[indice + 3] ==  0xe8 || dados_lidos[indice + 3] ==  0xe9 || dados_lidos[indice + 3] ==  0xea || dados_lidos[indice + 3] ==  0xeb || dados_lidos[indice + 3] ==  0xec || dados_lidos[indice + 3] ==  0xed || dados_lidos[indice + 3] ==  0xee || dados_lidos[indice + 3] ==  0xef){
                            FILE *imagem = fopen("002.jpg", "w");
                            //Usar funcao fwrite para pegar o bytes do cartao e escrever no arquivo jpeg criado
                            fwrite(dados_lidos, 1, bloco, imagem);
                        }
                    }
                }
            }
            indice++;
         
        }
    }  

}
//Preciso nomear os aquivos jpeg criados dinamicamente, é o proximo passo para avançar
//Fix linha 38 da para melhorar, e nome dos arquivos 