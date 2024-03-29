#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num;

    do
    {
        num = get_int("Number of blocks between 1 and 8 ");
    }
    while (num < 1 || num > 8);

    // Piramide
    for (int i = 0; i < num; i++)
    {
        // Espacios
        for (int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }

        // Izquierda
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");

        // Derecha
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}