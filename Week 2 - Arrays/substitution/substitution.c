#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string clave);

int main(int argc, string argv[])
{
    // Verificar si se proporciona la clave correcta
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Valida la clave
    if (!is_valid_key(key))
    {
        return 1;
    }

    // Solicita el texto en plano al usuario
    string plaintext = get_string("plaintext: ");

    // Encripta el mensaje
    printf("ciphertext: ");
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int index = toupper(plaintext[i]) - 'A';
            char cipher = isupper(plaintext[i]) ? toupper(key[index]) : tolower(key[index]);
            printf("%c", cipher);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}

// Función para validar la clave
bool is_valid_key(string key)
{
    int length = strlen(key);

    // Comprobar la longitud de la clave
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Comprueba por caracteres no alfabéticos y letras repetidas
    int letters[26] = {0};
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (letters[index] > 0)
        {
            printf("Key must not contain repeated letters.\n");
            return false;
        }
        letters[index]++;
    }
    return true;
}