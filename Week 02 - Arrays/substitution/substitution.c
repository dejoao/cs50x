#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string criptografia(string textoSimples, string key);

int main(int argc, string argv[1])
{
    string key = argv[1];
    // Mensagem executado sem nenhum argumento de linha de comando
    if (argc != 2) 
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Mensagem de chave for inválida, contem menos de 26 caracteres
    int keyTam = strlen(argv[1]);
    if (keyTam != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Mensagem de chave for inválida, existe caracterer nao alfabetico
    for (int i = 0; i < keyTam; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    // Mensagem de chave for inválida, contem letra repetidas
         for (int j = i + 1; j < keyTam; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    // Solicitar texto para ser criptografado
    string textoSimples = get_string("Plaintext: ");
    // Mostra texto criptografado
    string textoCriptografado = criptografia(textoSimples, key);
    printf("ciphertext: %s\n", textoCriptografado);
    return 0;
}
// Criptografa texto
string criptografia(string textoSimples, string key)
{
    int n = strlen(textoSimples);
    string textoCriptografado = textoSimples;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(textoSimples[i]))
        {
            char base = isupper(textoSimples[i]) ? 'A' : 'a';
            int indice = tolower(textoSimples[i]) - 'a';
            
            // Verifica se o caractere é maiúsculo ou minúsculo e realiza a substituição
            textoCriptografado[i] = isupper(textoSimples[i]) ? toupper(key[indice]) : tolower(key[indice]);
        }
        
    }
    return textoCriptografado;
}