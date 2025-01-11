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
    int hash = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        hash += word[1];
    }
    return hash % (N - 1);
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
    while(fscan(arquivo, "%s", char palavra[LENGTH + 1]))
    {
        //Criar espaço para um novo nó de tabela hash
        node novo_no = malloc(sizeof(node)); //fazer verificacao malloc
        if (novo_no == NULL)
        {
            return false;
        }
        //Copie a palavra para o novo nó
        strcpy(novo_no->word, palavra);
        //Hash a palavra para obter o seu valor de hash
        int indice_hash = hash(novo_no->word);
        //Insira o novo nó na tabela de hash (usando o índice especificado pelo seu valor de hash)
        novo_no->next = table[indice_hash];
        table[indice_hash] = novo_no;

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
