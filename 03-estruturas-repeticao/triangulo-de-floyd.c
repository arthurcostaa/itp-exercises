#include <stdio.h>

int main()
{
    int num_lines;
    int number = 1;

    scanf("%d", &num_lines);

    if (num_lines <= 0)
    {
        printf("Você entrou com %d, tente de novo na próxima\n", num_lines);
    }
    else
    {
        for (int i = 1; i <= num_lines; i++)
        {
            for (int j = 0; j < i; j++)
            {
                printf("%2d ", number);
                number++;
            }
            printf("\n");
        }
    }

    return 0;
}