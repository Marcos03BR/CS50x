#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

int main(void)
{
    // Pide al usuario las palabras
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calcula la puntuación de cada palabra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Ganador
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Puntos por cada letra de la A a la Z
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;

    // Calcula la puntuación de la palabra
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Convierte la letra a mayúscula y resta "A" para obtener el índice en POINTS
        if (isalpha(word[i]))
        {
            score += POINTS[toupper(word[i]) - 'A'];
        }
    }

    // Devuelve la puntuación final
    return score;
}