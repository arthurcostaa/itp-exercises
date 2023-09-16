#include <stdio.h>

int main()
{
    int number;

    scanf("%d", &number);

    if (number < 10) // numbers of 1 digit
    {
        printf("%d\n", number);
    }
    else if (number < 100) // numbers of 2 digits
    {
        printf("%d\n", number / 10);
        printf("%d\n", number % 10);
    }
    else if (number < 1000) // numbers of 3 digits
    {
        printf("%d\n", number / 100);
        printf("%d\n", (number % 100) / 10);
        printf("%d\n", (number % 100) % 10);
    }
    else if (number < 10000) // numbers of 4 digit
    {
        printf("%d\n", number / 1000);
        printf("%d\n", (number % 1000) / 100);
        printf("%d\n", ((number % 1000) % 100) / 10);
        printf("%d\n", ((number % 1000) % 100) % 10);
    }
    else if (number < 100000) // numbers of 5 digits
    {
        printf("%d\n", number / 10000);
        printf("%d\n", (number % 10000) / 1000);
        printf("%d\n", ((number % 10000) % 1000) / 100);
        printf("%d\n", ((((number % 10000) % 1000) % 100) / 10));
        printf("%d\n", (((number % 10000) % 1000) % 100) % 10);
    }
    else if (number == 100000)
    {
        printf("1\n0\n0\n0\n0\n0\n");
    }

    return 0;
}