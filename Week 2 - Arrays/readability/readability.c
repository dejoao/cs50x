#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calcNumFrase(string text);
int calcNumLetter(string text);
int calcPalavras(string text);

int main(void)
{
    // Recebe o texto do livro
    string text = get_string("Text: ");
    // Calcula numero de palavras
    int palavras = calcPalavras(text);
    // Calcula o numero de frases media 100 palavras
    int frase = ((float) calcNumFrase(text) / palavras) * 100;
    // Calcula o numero de letras media 100 palavras
    int letra = ((float) calcNumLetter(text) / palavras) * 100;
    // Faz o calculo "índice Coleman-Liau"
    float index = 0.0588 * letra - 0.296 * frase - 15.8;
    // Arrendonda a nota para o numero inteiro mais proximo
    int index1 = round(index);
    // Mostra o resutado
    if (index1 > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index1 < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index1);
    }
    return 0;
}
int calcNumFrase(string text)
{
    // Calcula o numero medio de frases por 100 palavras
    int numFrase = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numFrase++;
        }
    }
    return numFrase;
}
int calcNumLetter(string text)
{
    int numLetter = 0;
    // Calcula o numero letras
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!ispunct(text[i]) && !isblank(text[i]))
        {
            numLetter++;
        }
    }
    return numLetter;
}
int calcPalavras(string text)
{
    int numPalavras = 0;
    int estadoEspaco = 1; // 1 indica que o caractere anterior foi um espaço ou pontuação

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            estadoEspaco = 1;
        }
        else
        {
            if (estadoEspaco)
            {
                numPalavras++;
            }
            estadoEspaco = 0;
        }
    }
    return numPalavras;
}