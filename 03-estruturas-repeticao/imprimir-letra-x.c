#include <stdio.h>

int main()
{
    int number_of_lines;
    char letter;

    scanf("%d %c", &number_of_lines, &letter);

    for (int i = 1; i <= number_of_lines - 1; i++)
    {
        for (int j = 1; j <= number_of_lines - 1; j++)
        {
            if (i == j || i + j == number_of_lines)
            {
                printf("%c", letter);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}