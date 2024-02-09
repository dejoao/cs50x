#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calcNumFrase(string text);
int calcNumLetter(string text);
int calcPalavras(string text);


int main(void)
{
    //Recebe o texto do livro
    string text = get_string("Text: ");
    //Calcula numero de palavras
    int palavras = calcPalavras(text);
    //Calcula o numero de frases, media por 100 palavras
    int frase = calcNumFrase(text) / palavras * 100;;
    //Calcula o numero de letras, media por 100 palasvras
    int letra = calcNumLetter(text) / palavras * 100;;
    //Faz o calculo "índice Coleman-Liau"
    float index = 0.0588 * letra - 0.296 * frase - 15.8;
    //Arrendonda a nota para o numero inteiro mais proximo
    int grade = round(index);
    //Mostra o resutado
    if (grade > 16)
    {
        printf("Grade 16+");
    } 
    else if (grade < 1)
    {
        printf("Before Grade 1");
    } 
    else 
    {
        printf("Grade %d", grade);
    }
}
int calcNumFrase(string text)
{
    //Calcula o numero medio de frases por 100 palavras
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
    //Calcula o numero medio de letras por 100 palasvras
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (ispunct(text[i]) || isblank(text[i]))
        {
           
        }
        else
        {
            numLetter++;
        }
    }
    return numLetter;
}
int calcPalavras(string text)
{
    int numPalavras = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]) || text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numPalavras++;
        }
    }
    return numPalavras;
}