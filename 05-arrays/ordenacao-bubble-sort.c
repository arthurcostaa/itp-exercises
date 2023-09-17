#include <stdio.h>

void print_vector_values(int length, int vector[])
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void read_vector_values(int length, int vector[])
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &vector[i]);
    }
}

void bubble_sort(int length, int vector[])
{
    int aux, swapped = 1;

    while (swapped)
    {
        swapped = 0;
        print_vector_values(length, vector);
        for (int i = 1; i < length; i++)
        {
            if (vector[i - 1] > vector[i])
            {
                aux = vector[i - 1];
                vector[i - 1] = vector[i];
                vector[i] = aux;
                swapped = 1;
            }
        }
    }
}

int main()
{
    int length;
    scanf("%d", &length);

    int vector[length];
    read_vector_values(length, vector);

    bubble_sort(length, vector);

    return 0;
}