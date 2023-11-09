#include <stdio.h>

void print_matrix(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void read_matrix(int matrix[9][9])
{
    char cell;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf(" %c", &cell);

            if (cell == '*')
                matrix[i][j] = 0;
            else
                matrix[i][j] = cell - '0';
        }
    }
}

int check_number(int matrix[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
        if (matrix[row][i] == num || matrix[i][col] == num)
            return 0;

    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i + start_row][j + start_col] == num)
                return 0;

    return 1;
}

int solve_sudoku(int matrix[9][9])
{
    int row, col;

    int is_empty = 0;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (matrix[row][col] == 0)
            {
                is_empty = 1;
                break;
            }
        }

        if (is_empty)
            break;
    }

    if (!is_empty)
        return 1;

    for (int i = 1; i <= 9; i++)
    {
        if (check_number(matrix, row, col, i))
        {
            matrix[row][col] = i;

            if (solve_sudoku(matrix))
                return 1;

            matrix[row][col] = 0;
        }
    }

    return 0;
}

int main()
{
    int sudoku_matrix[9][9] = {0};

    read_matrix(sudoku_matrix);

    solve_sudoku(sudoku_matrix)
        ? print_matrix(sudoku_matrix)
        : printf("Não tem solução!\n");
}