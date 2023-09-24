#include <stdio.h>

int calculate_height(int length)
{
    return (length / 3) * 2;
}

int calculate_bet(int length,
                  int height,
                  int flag[height][length],
                  char color)
{
    int bet_value = 0;
    int color_length = length / 3;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < color_length; j++)
        {
            // G - 0, Y - 1, R - 2
            int aux = j;

            if (color == 'G')
                aux += 0 * color_length;
            else if (color == 'Y')
                aux += 1 * color_length;
            else if (color == 'R')
                aux += 2 * color_length;

            bet_value += flag[i][/*j*/ aux];
        }
    }

    return bet_value;
}

void make_senegal_flag(int length,
                       int height,
                       int flag[height][length],
                       int initial_value)
{
    int color_length = length / 3;
    for (int i = 0; i < length; i += color_length)
    {
        initial_value++;
        for (int j = 0; j < color_length; j++)
        {
            for (int k = 0; k < height; k++)
            {
                flag[k][j + i] = initial_value;
            }
        }
    }
}

int main()
{
    int length, height, initial_value, bet_value;
    char color;

    scanf("%d %d %c", &length, &initial_value, &color);
    height = calculate_height(length);

    int senegal_flag[height][length];

    make_senegal_flag(length, height, senegal_flag, initial_value);

    bet_value = calculate_bet(length,
                              height,
                              senegal_flag,
                              color);

    printf("%d\n", bet_value);

    return 0;
}