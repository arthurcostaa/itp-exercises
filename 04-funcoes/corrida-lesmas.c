#include <stdio.h>

int speed_level(int speed)
{
    if (speed < 10)
    {
        return 1;
    }
    else if (speed >= 20)
    {
        return 3;
    }
    else
    {
        return 2;
    }
}

void print_level(int speed)
{
    printf("Level %d\n", speed_level(speed));
}

int main()
{
    int quantity, speed, max;

    max = 0;

    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++)
    {
        scanf("%d", &speed);

        if (speed > max)
        {
            max = speed;
        }
    }

    print_level(max);

    return 0;
}