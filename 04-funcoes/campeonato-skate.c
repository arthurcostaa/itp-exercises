#include <stdio.h>

int calculate_score(int score1, int score2, int score3)
{
    // in the middle
    if ((score1 >= score2 && score1 <= score3) ||
        (score1 <= score2 && score1 >= score3))
    {
        return score1;
    }
    // at the beggining
    else if ((score2 >= score1 && score2 <= score3) ||
             (score2 <= score1 && score2 >= score3))
    {
        return score2;
    }
    // at the end
    else
    {
        return score3;
    }
}

int calculate_day_score()
{
    int score1, score2, score3;
    int day_score;

    scanf("%d %d %d", &score1, &score2, &score3);
    day_score = calculate_score(score1, score2, score3);

    return day_score;
}

int calculate_final_score()
{
    int day1, day2, day3;
    int final_score;

    day1 = calculate_day_score();
    day2 = calculate_day_score();
    day3 = calculate_day_score();

    final_score = calculate_score(day1, day2, day3);

    return final_score;
}

void winner(int score_skater_a, int score_skater_b)
{
    if (score_skater_a == score_skater_b)
    {
        printf("empate\n");
    }
    else if (score_skater_a > score_skater_b)
    {
        printf("A\n");
    }
    else
    {
        printf("B\n");
    }
}

int main()
{
    int score_skater_a, score_skater_b;

    score_skater_a = calculate_final_score();
    score_skater_b = calculate_final_score();
    winner(score_skater_a, score_skater_b);

    return 0;
}