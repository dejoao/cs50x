// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Representa um nó em uma tabela de hash
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Escolher o número de buckets na tabela de hash
const unsigned int N = 26;

// Hash table
node *table[N];

// Retorna true se a palavra estiver no dicionário, caso contrário, false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes de palavra para um número
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Carrega o dicionário na memória, retornando true se for bem-sucedido, caso contrário, false
bool load(const char *dictionary)
{
    // Abrir dicionario
    FILE *arquivo = fopen(dictionary, "r");
    if(arquivo == NULL)
    {
        return false;
    }
    // ler cada string dentro do arquivo
    while(fscan(arquivo, "%s", word))
    {
        // criar no para cada string
        char *word1 = malloc(LENGTH + 1);
        if(word1 == NULL)
        {
            return false;
        }
        char *strcpy(word1, word);
        hash(word1)
    }
    fclose(arquivo);
    


    // TODO
    return false; 
}

// Retorna o número de palavras no dicionário se carregadas, caso contrário, 0 se ainda não carregadas
unsigned int size(void)
{
    // TODO
    return 0;
}

// Descarrega o dicionário da memória, retornando true se for bem-sucedido, caso contrário, false
bool unload(void)
{
    // TODO
    return false;
}
