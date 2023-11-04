#include <stdio.h>

void decimal_to_binary(int num)
{
    if (num < 2)
    {
        printf("%d", num);
        return;
    }
    else
    {
        int quot, rem;

        quot = num / 2;
        rem = num % 2;

        decimal_to_binary(quot);

        printf("%d", rem);
    }
}

int main()
{
    int number;

    scanf("%d", &number);

    decimal_to_binary(number);
    printf("\n");

    return 0;
}