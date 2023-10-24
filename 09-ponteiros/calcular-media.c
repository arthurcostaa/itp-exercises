#include <stdio.h>

void calculate_average(int *num1, int *num2)
{
    int average, remainder;

    average = (*num1 + *num2) / 2;
    remainder = (*num1 + *num2) % 2;

    if (*num1 < *num2)
    {
        *num1 = average;
        *num2 = remainder;
    }
    else
    {
        *num2 = average;
        *num1 = remainder;
    }
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    calculate_average(&a, &b);

    printf("A = %d\nB = %d\n", a, b);

    return 0;
}