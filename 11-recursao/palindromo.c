#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// When I use this function the lop platform gives me a run-time error
// char *input()
// {
//     char *string = NULL;
//     char character;
//     int size = 0;

//     while (1)
//     {
//         character = getchar();

//         if (character == '\n')
//             break;

//         size++;
//         string = (char *)realloc(string, sizeof(char) * size);
//         string[size - 1] = character;
//     }

//     size++;
//     string = (char *)realloc(string, sizeof(char) * size);
//     string[size - 1] = '\0';

//     return string;
// }

char *remove_spaces(char *text)
{
    int len = (int)strlen(text);
    char *new_text = (char *)malloc(sizeof(char) * (len + 1));

    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] != ' ')
        {
            new_text[j] = text[i];
            j++;
        }
    }

    new_text[j] = '\0';

    return new_text;
}

int is_palindrome(char *text, int start, int end)
{
    if (start >= end)
        return 1;

    if (text[start] != text[end])
        return 0;

    return is_palindrome(text, start + 1, end - 1);
}

int palindrome(char *text)
{
    char *new_text = remove_spaces(text);

    if (is_palindrome(new_text, 0, strlen(new_text) - 1))
    {
        free(new_text);
        return 1;
    }
    else
    {
        free(new_text);
        return 0;
    }

    free(new_text);

    return 1;
}

int main()
{
    char *text = malloc(sizeof(char) * 100);
    int len;

    // text = input();
    scanf("%[^\n]*%c", text);

    int result = palindrome(text);
    printf(result
               ? "O texto \"%s\" é palíndromo\n"
               : "O texto \"%s\" não é palíndromo\n",
           text);

    free(text);

    return 0;
}