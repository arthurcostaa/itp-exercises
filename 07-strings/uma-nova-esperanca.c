#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN_KEY 5
#define MAX_LEN_TXT 201

const char K[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};

const char S[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' ',
    '\0'};

bool validate_key(char key[MAX_LEN_KEY])
{
    if ((int)strlen(key) > 4)
        return false;

    for (int i = 0; i < (int)strlen(key); i++)
    {
        int not_found = 1;
        for (int j = 0; j < (int)strlen(K); j++)
        {
            if (key[i] == K[j])
            {
                not_found = 0;
                break;
            }
        }

        if (not_found)
            return false;
    }

    return true;
}

bool validate_text(char plain_text[MAX_LEN_TXT])
{
    // Search text with invalid characters
    for (int i = 0; i < (int)strlen(plain_text); i++)
    {
        int not_found = 1;

        for (int j = 0; j < (int)strlen(S); j++)
        {
            if (plain_text[i] == S[j])
            {
                not_found = 0;
                break;
            }
        }

        if (not_found)
            return false;
    }

    return true;
}

int encrypt_message(char key[MAX_LEN_KEY],
                    char plain_text[MAX_LEN_TXT],
                    char encrypted_text[MAX_LEN_TXT])
{
    if (!validate_key(key))
    {
        printf("Chave invalida!\n");
        return 0;
    }

    if (!validate_text(plain_text))
    {
        printf("Caractere invalido na entrada!\n");
        return 0;
    }

    int index_key = 0;

    for (int i = 0; i < (int)strlen(plain_text); i++)
    {
        int S_index_char;
        for (int j = 0; j < (int)strlen(S); j++)
        {
            if (plain_text[i] == S[j])
            {
                S_index_char = j;
                break;
            }
        }

        int encrypted_char_index = S_index_char + (key[index_key] - '0');

        if (encrypted_char_index < (int)strlen(S))
            encrypted_text[i] = S[encrypted_char_index];
        else if (encrypted_char_index >= (int)strlen(S))
        {
            encrypted_char_index -= (int)strlen(S);
            encrypted_text[i] = S[encrypted_char_index];
        }

        if (index_key == 3)
            index_key = 0;
        else
            index_key++;
    }

    return 1;
}

int main()
{
    char key[MAX_LEN_KEY] = {0};
    char plain_text[MAX_LEN_TXT] = {0};
    char encrypted_text[MAX_LEN_TXT] = {0};

    scanf("%[^\n]", key);
    getchar();
    scanf("%[^\n]", plain_text);

    encrypt_message(key, plain_text, encrypted_text)
        ? printf("%s\n", encrypted_text)
        : 0;

    return 0;
}