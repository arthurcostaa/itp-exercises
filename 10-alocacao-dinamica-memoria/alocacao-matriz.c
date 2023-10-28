#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rows, cols;
    int **matrix;
} Matrix;

Matrix *create_matrix(int rows, int cols)
{
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->matrix = (int **)malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++)
        matrix->matrix[i] = (int *)malloc(sizeof(int) * cols);

    return matrix;
}

void read_matrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->cols; j++)
            scanf("%d", &matrix->matrix[i][j]);
}

void print_matrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
            printf("%d ", matrix->matrix[i][j]);
        printf("\n");
    }
}

void destroy_matrix(Matrix **matrix)
{
    for (int i = 0; i < (*matrix)->rows; i++)
        free((*matrix)->matrix[i]);

    free((*matrix)->matrix);

    free(*matrix);

    *matrix = NULL;
}

int main()
{
    int rows, cols;
    Matrix *matrix;

    scanf("%d %d", &rows, &cols);

    matrix = create_matrix(rows, cols);

    read_matrix(matrix);
    print_matrix(matrix);
    destroy_matrix(&matrix);

    if (matrix == NULL)
        printf("OK\n");

    return 0;
}