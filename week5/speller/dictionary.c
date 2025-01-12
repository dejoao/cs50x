// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Representa um nó em uma tabela de hash
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Escolher o número de buckets na tabela de hash
const unsigned int N = 26;

//variavel para contar quantas palavras tem - funcao size
int quantidade_palavras = 0;

// Hash table
node *table[N];

// Retorna true se a palavra estiver no dicionário, caso contrário, false
bool check(const char *word)
{
    int indice = hash(word);

    if(strcasecmp(word, table[indice]->word) == 0)
    {
        return true;
    }else
    {
        return false;
    }
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
    char palavra[LENGTH + 1];
    while(fscanf(arquivo, "%s", palavra))
    {
        //colocar um contador aqui
        quantidade_palavras++;
        //Criar espaço para um novo nó de tabela hash
        struct node *novo_no = malloc(sizeof(struct node));
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
    return quantidade_palavras;
}

// Descarrega o dicionário da memória, retornando true se for bem-sucedido, caso contrário, false  \ PRECISO RESOLVER ISSO AQUI
bool unload(void)
{
    free(struct *novo_no);
    novo_no = NULL
    if (novo_no == NULL)
    {
        return true;
    }else
    {
        return false;
    }
}
