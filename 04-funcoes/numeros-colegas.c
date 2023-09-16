#include <stdio.h>
#include <stdlib.h>

int sum_of_divisors(int number)
{
    int sum = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int are_comrade_numbers(int number1, int number2)
{
    if (abs(sum_of_divisors(number1) - number2) <= 2 &&
        abs(sum_of_divisors(number2) - number1) <= 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int number1, number2;

    scanf("%d %d", &number1, &number2);

    if (are_comrade_numbers(number1, number2))
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}