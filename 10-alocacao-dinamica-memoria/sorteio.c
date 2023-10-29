#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input()
{
    char *str = NULL;
    char c;
    int size = 0;

    while (1)
    {
        c = getchar();

        if (c == '\n')
            break;

        size++;
        str = (char *)realloc(str, sizeof(char) * size);

        str[size - 1] = c;
    }

    size++;
    str = (char *)realloc(str, sizeof(char) * size);
    str[size - 1] = '\0';

    return str;
}

void print_array(char **names, int *indexes, int len)
{
    int rand_index;

    for (int i = 0; i < len; i++)
    {
        rand_index = indexes[i];
        printf("%s\n", names[rand_index]);
    }
}

int *random_indexes(int len, int seed)
{
    int random_number, size = 0;
    int *indexes = (int *)malloc(sizeof(int) * len);
    int is_used;

    srand(seed);

    while (size < len)
    {
        random_number = rand() % len;

        is_used = 0;
        for (int i = 0; i < size; i++)
        {
            if (random_number == indexes[i])
            {
                is_used = 1;
                break;
            }
        }

        if (is_used)
            continue;

        indexes[size] = random_number;
        size++;
    }

    return indexes;
}

char **read_names(int *len)
{
    char **names_array = NULL;
    int size = 0;
    char *name;

    while (1)
    {
        name = input();

        if (strcmp(name, "acabou") == 0)
            break;

        size++;
        names_array = (char **)realloc(names_array, sizeof(char *) * size);

        names_array[size - 1] = name;
    }

    *len = size;

    return names_array;
}

int main()
{
    int len, seed;
    int *indexes;
    char **array_names;

    array_names = read_names(&len);

    scanf("%d", &seed);

    indexes = random_indexes(len, seed);

    print_array(array_names, indexes, len);

    return 0;
}