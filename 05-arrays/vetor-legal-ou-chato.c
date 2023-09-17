#include <stdio.h>

void read_values(int length, int vector[])
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &vector[i]);
    }
}

int is_even(int number)
{
    return number % 2 == 0 ? 1 : 0;
}

int is_nice_vector(int length, int vector[])
{
    int is_nice = 1;

    for (int i = 1; i < length; i++)
    {
        if (is_even(vector[i] - vector[i - 1]))
        {
            continue;
        }
        else
        {
            is_nice = 0;
            break;
        }
    }

    return is_nice;
}

int main()
{
    int length;
    scanf("%d", &length);

    int vector[length];

    read_values(length, vector);

    is_nice_vector(length, vector)
        ? printf("Legal\n")
        : printf("Chato\n");

    return 0;
}