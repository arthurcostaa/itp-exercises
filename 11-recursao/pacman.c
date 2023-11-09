#include <stdio.h>

void read_matrix(int rows, int cols, char matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf(" %c", &matrix[i][j]);
}

void print_matrix(int rows, int cols, char matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%c", matrix[i][j]);
        printf("\n");
    }
}

void find_pacman(int *pacman_x,
                 int *pacman_y,
                 int rows,
                 int cols,
                 char matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 'C')
            {
                *pacman_x = i;
                *pacman_y = j;
            }
        }
}

int count_dots_eaten(int pacman_row,
                     int pacman_col,
                     int rows,
                     int cols,
                     char matrix[rows][cols])
{
    if (pacman_row < 0 || pacman_row >= rows ||
        pacman_col < 0 || pacman_col >= cols ||
        matrix[pacman_row][pacman_col] == '*' ||
        matrix[pacman_row][pacman_col] == 'M' ||
        matrix[pacman_row][pacman_col] == ' ')
    {
        return 0;
    }

    if (matrix[pacman_row][pacman_col] == '.')
    {
        matrix[pacman_row][pacman_col] = ' ';
    }

    return (matrix[pacman_row][pacman_col] == ' ' ? 1 : 0) +
           count_dots_eaten(pacman_row - 1, pacman_col, rows, cols, matrix) +
           count_dots_eaten(pacman_row + 1, pacman_col, rows, cols, matrix) +
           count_dots_eaten(pacman_row, pacman_col - 1, rows, cols, matrix) +
           count_dots_eaten(pacman_row, pacman_col + 1, rows, cols, matrix);
}

int main()
{
    int rows, cols;
    int pacman_row, pacman_col;
    int dots_eaten = 0;

    scanf("%d %d", &rows, &cols);

    char matrix[rows][cols];

    read_matrix(rows, cols, matrix);
    find_pacman(&pacman_row, &pacman_col, rows, cols, matrix);
    dots_eaten = count_dots_eaten(pacman_row, pacman_col, rows, cols, matrix);

    printf("Total de bolinhas devoradas: %d\n", dots_eaten);
    printf("Mapa final:\n");
    print_matrix(rows, cols, matrix);
}