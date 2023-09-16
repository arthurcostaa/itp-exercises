#include <stdio.h>

int main()
{
    double max_time, athlete_time;
    int series, num_athletes;

    num_athletes = 0;
    series = 0;

    scanf("%lf", &max_time);

    do
    {
        scanf("%lf", &athlete_time);
        if (athlete_time <= max_time && athlete_time != -1)
        {
            num_athletes++;
        }
    } while (athlete_time != -1.0);

    series = num_athletes % 8 == 0 ? num_athletes / 8 : (num_athletes / 8) + 1;

    printf("%d %d\n", num_athletes, series);

    return 0;
}