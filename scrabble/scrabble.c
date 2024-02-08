#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Score do game
int score[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calc_score(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

}

int calc_score(string word)
{
    int n;
    //Preciso mostrar cada caractere em sua representação numerica ASCII
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //Usar comando if, else para transforma letras maisculas e minusculas
    }
    

}