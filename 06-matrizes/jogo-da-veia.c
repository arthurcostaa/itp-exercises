#include <stdio.h>
#define EMPTY_SPACE '.'

void read_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf(" %c", &board[i][j]);
}

int win_game(char board[3][3])
{
    // Diagonal
    if ((board[0][0] != '.' &&
         board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] != '.' &&
         board[0][2] == board[1][1] && board[0][2] == board[2][0]))
    {
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        // Horizontal
        if (board[i][0] != EMPTY_SPACE &&
            (board[i][0] == board[i][1] && board[i][0] == board[i][2]))
        {
            return 1;
        }

        // Vertical
        if (board[0][i] != EMPTY_SPACE &&
            (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
        {
            return 1;
        }
    }

    return 0;
}

int valide_move(int row, int col, char board[3][3])
{
    if (board[row - 1][col - 1] == EMPTY_SPACE)
        return 1;
    else
        return 0;
}

void make_move(int row, int col, char move, char board[3][3])
{
    if (valide_move(row, col, board))
    {
        board[row - 1][col - 1] = move;
        if (win_game(board))
            printf("Boa jogada, vai vencer!\n");
        else
            printf("Continua o jogo.\n");
        board[row - 1][col - 1] = EMPTY_SPACE;
    }
    else
    {
        printf("Jogada inválida!\n");
    }
}

void play_game(int num_matches, char board[3][3])
{
    int row, col;
    char move;

    for (int i = 0; i < num_matches; i++)
    {
        scanf("%d %d %c", &row, &col, &move);
        make_move(row, col, move, board);
    }
}

int main()
{
    int num_matches;
    char tic_tac_toe_board[3][3];

    read_board(tic_tac_toe_board);

    scanf("%d", &num_matches);

    play_game(num_matches, tic_tac_toe_board);

    return 0;
}