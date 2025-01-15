// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Representa um nó em uma tabela de hash
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Escolher o número de buckets na tabela de hash
const unsigned int N = 26 * 4;

// variavel para contar quantas palavras tem - funcao size
int quantidade_palavras = 0;

// Hash table
node *table[N];
struct node *novo_no;

// Retorna true se a palavra estiver no dicionário, caso contrário, false
bool check(const char *word)
{
    int indice = hash(word);

    // Percorre a lista
    node *atual = table[indice];
    while (atual != NULL)
    {
        // Se encontrar a palavra
        if (strcasecmp(word, atual->word) == 0)
        {
            return true;
        }
        // Avança para o próximo nó
        atual = atual->next;
    }

    // Se a palavra não for encontrada
    return false;
}

// Hashes de palavra para um número
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        c = tolower(c);
        hash = ((hash << 5) + hash) + c;
    }

    int resultado = hash % N;
    // printf("%i", resultado);
    return resultado;
}

// Carrega o dicionário na memória, retornando true se for bem-sucedido, caso contrário, false
bool load(const char *dictionary)
{
    // Abrir dicionario
    FILE *arquivo = fopen(dictionary, "r");
    if (arquivo == NULL)
    {
        return false;
    }
    // ler cada string dentro do arquivo
    char palavra[LENGTH + 1];
    while (fscanf(arquivo, "%s", palavra) == 1)
    {
        // colocar um contador aqui
        quantidade_palavras++;
        // Criar espaço para um novo nó de tabela hash
        novo_no = malloc(sizeof(struct node));
        if (novo_no == NULL)
        {
            free(novo_no);
            return false;
        }
        // Copie a palavra para o novo nó
        strcpy(novo_no->word, palavra);
        // Hash a palavra para obter o seu valor de hash
        int indice_hash = hash(novo_no->word);
        // Insira o novo nó na tabela de hash (usando o índice especificado pelo seu valor de hash)
        novo_no->next = table[indice_hash];
        table[indice_hash] = novo_no;
    }
    fclose(arquivo);

    // TODO
    return true;
}

// Retorna o número de palavras no dicionário se carregadas, caso contrário, 0 se ainda não
// carregadas
unsigned int size(void)
{
    // TODO
    return quantidade_palavras;
}

// Descarrega o dicionário da memória, retornando true se for bem-sucedido, caso contrário, false
bool unload(void)
{
    // Percorre todos os índices da tabela de hash
    for (int i = 0; i < N; i++)
    {
        node *atual = table[i];

        // Libera cada nó na lista encadeada
        while (atual != NULL)
        {
            node *temp = atual;
            atual = atual->next;
            free(temp);
        }
    }

    return true;
}