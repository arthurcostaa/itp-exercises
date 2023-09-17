#include <stdio.h>

void read_elements(int len, int set[])
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &set[i]);
    }
}

void bubble_sort(int length, int vector[])
{
    int aux, swapped = 1;

    while (swapped)
    {
        swapped = 0;
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

void concat_arrays(int len_set_a,
                   int len_set_b,
                   int set_a[],
                   int set_b[],
                   int set_union[])
{
    int index = 0;

    for (int i = 0; i < len_set_a; i++)
    {
        set_union[index++] = set_a[i];
    }

    for (int i = 0; i < len_set_b; i++)
    {
        set_union[index++] = set_b[i];
    }

    bubble_sort(len_set_a + len_set_b, set_union);
}

void symmetric_difference(int len_set, int set[])
{
    for (int i = 0; i < len_set; i++)
    {
        if (set[i] == set[i + 1])
            continue;
        else if (set[i - 1] == set[i])
            continue;
        else
            printf("%d ", set[i]);
    }
    printf("\n");
}

int main()
{
    int len_set_a, len_set_b;

    scanf("%d %d", &len_set_a, &len_set_b);

    int set_a[len_set_a],
        set_b[len_set_b];
    int sym_diff_ab[len_set_a + len_set_b];

    read_elements(len_set_a, set_a);
    read_elements(len_set_b, set_b);

    concat_arrays(len_set_a, len_set_b, set_a, set_b, sym_diff_ab);
    symmetric_difference(len_set_a + len_set_b, sym_diff_ab);
}
