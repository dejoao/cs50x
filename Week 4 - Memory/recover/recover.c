#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //Aceite uma unica linha de comando
    char *argumento = argv[1];
    char *VerificacaoCard = "card.raw";
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    //Abra o cartao de memoria
    FILE *card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Error\n");
        return 1;
    }
    //Buffer para um bloco de dados
    int bloco = 512;
    uint8_t buffer[bloco];

    //Crie jpegs a partir dos dados
    while(fread(buffer, 1, bloco, &card) == bloco)
    {
        
        
    }
    
}