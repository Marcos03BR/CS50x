#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Solicita al usuario un texto
    string text = get_string("Text: ");

    // Cuenta el número de letras, palabras y oraciones en el texto
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calcula el índice de Coleman-Liau
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Grado de dificultad
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    int length = strlen(text);

    for (int i = 0, n = strlen(text); i < length; i++)
    {
        // Comprobar si el caracter actual es un espacio y el anterior no lo es
        if (i > 0 && text[i] == ' ' && text[i - 1] != ' ')
        {
            count++;
        }
    }
    // Cuenta la última palabra si el texto no termina con un espacio
    if (length > 0 && text[length - 1] != ' ')
    {
        count++;
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        // Comprueba si el caracter es un punto final, signo de interrogación o exclamación
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}