// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char texto[] = "André - Atacante - mil gols - campeão mundial - melhor que Pelé";
//     char *pedaco;

//     pedaco = strtok(texto, "-");

//     while (pedaco != NULL)
//     {
//         printf("%s\n", pedaco);

//         pedaco = strtok(NULL, "-");
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_INPUT 101

int *return_array_numbers(char str_numbers[], int *len_array)
{
    char *piece;
    int *numbers, len = 0;

    piece = strtok(str_numbers, " ");

    while (piece != NULL)
    {
        if (len == 0)
            numbers = malloc(sizeof(int));
        else
            numbers = realloc(numbers, sizeof(int) * (len + 1));

        numbers[len] = atoi(piece);

        piece = strtok(NULL, " ");

        len++;
        *len_array = len;
    }

    return numbers;
}

void sort_array(int len_array, int array[len_array])
{
    int aux, swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (int i = 1; i < len_array; i++)
        {
            if (array[i] < array[i - 1])
            {
                aux = array[i - 1];
                array[i - 1] = array[i];
                array[i] = aux;
                swapped = 1;
            }
        }
    }
}

void print_array(int len_array, int array[len_array])
{
    for (int i = 0; i < len_array; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    char input[LEN_INPUT], *piece;
    int len_array, *numbers;

    fgets(input, LEN_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0';

    numbers = return_array_numbers(input, &len_array);
    sort_array(len_array, numbers);
    print_array(len_array, numbers);

    free(numbers);

    return 0;
}