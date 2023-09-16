#include <stdio.h>

int main()
{
    int teams, total_athletes;
    int running, jumping, throwing;
    char subscription;

    running = 0;
    jumping = 0;
    throwing = 0;

    scanf("%d", &teams);

    for (int i = 0; i < teams; i++)
    {
        do
        {
            scanf(" %c", &subscription);
            switch (subscription)
            {
            case 'S': // Salto
                jumping++;
                break;
            case 'C': // Corrida
                running++;
                break;
            case 'L': // Lançamento
                throwing++;
                break;
            }
        } while (subscription != 'F');
    }

    total_athletes = jumping + running + throwing;

    printf("%d %d %d %d\n", running, jumping, throwing, total_athletes);

    return 0;
}