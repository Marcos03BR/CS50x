#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pedir el numero de tarjeta
    long num = get_long("Number: ");
    int sum1 = 0;
    int sum2 = 0;
    int count = 0;
    int digit;
    long temp_num = num;
    int fdigit = 0;

    // Procesar los digitos desde el final
    while (num > 0)
    {
        // Sacar el ultimo
        digit = num % 10;
        sum1 += digit;
        num /= 10;
        count++;

        // Sacar el siguiente
        if (num > 0)
        {
            digit = (num % 10) * 2;
            sum2 += (digit % 10) + (digit / 10);
            num /= 10;
            count++;
        }
    }

    while (temp_num > 100)
    {
        temp_num /= 10;
    }
    fdigit = temp_num;

    // Sumar las dos sumas y verificar si termina en 0
    if ((sum1 + sum2) % 10 == 0)
    {
        // Determina la tarjeta
        if ((count == 15) && (fdigit == 34 || fdigit == 37))
        {
            printf("AMEX\n");
        }
        else if ((count == 16) && (fdigit >= 51 && fdigit <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 13 || count == 16) && (fdigit / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}