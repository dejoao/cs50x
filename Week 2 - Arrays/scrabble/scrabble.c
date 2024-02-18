#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Tabela com os pontos do jogo, onde a = 1 ponto, b = 3 pontos assim por diante
int table[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Menção da funçao que calcula os pontos
int calc_score(string word);

int main(void)
{

    //Pede ao usuario as strings
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Mostr quem é o ganhador
    int score1 = calc_score(word1);
    int score2 = calc_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 win!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 win!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}
int calc_score(string word)
{
    int score = 0;
    //calcula a pontuação de cada caractere
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            score += table[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += table[word[i] - 'a'];
        }
    }
    return score;
}