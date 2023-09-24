#include <stdio.h>

void print_matrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Colored output
            // https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
            matrix[i][j] % 2 == 0
                ? printf("\033[1;92m%d \033[0m", matrix[i][j])  // GREEN
                : printf("\033[1;91m%d \033[0m", matrix[i][j]); // RED

            // No colored output
            // printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generate_pyramid(int len, int matrix[len][len])
{
    int end;
    int value = 1;

    int init_loop = 0;
    int end_loop = len;

    if (len % 2 == 1)
        end = (len - 1) / 2;
    else
        end = (len / 2) - 1;

    while (end >= 0)
    {
        for (int i = init_loop; i < end_loop; i++)
        {
            for (int j = init_loop; j < end_loop; j++)
            {
                matrix[i][j] = value;
            }
        }

        end--;
        init_loop++;
        end_loop--;
        value++;
    }
}

int main()
{
    int length;

    scanf("%d", &length);

    int pyramid[length][length];

    generate_pyramid(length, pyramid);
    print_matrix(length, length, pyramid);

    return 0;
}