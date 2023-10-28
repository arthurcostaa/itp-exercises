#include <stdio.h>
#include <string.h>

#define MAX_LEN_ACTION 20

void print_report(int hunger,
                  int thirst,
                  int bathroom,
                  int sleep,
                  int boredom)
{
    printf("Status final:\n");
    printf("Fome: %d\n", hunger);
    printf("Sede: %d\n", thirst);
    printf("Banheiro: %d\n", bathroom);
    printf("Sono: %d\n", sleep);
    printf("Tédio: %d\n", boredom);
}

void warning(int hunger,
             int thirst,
             int bathroom,
             int sleep,
             int boredom)
{
    if (hunger > 0 && hunger <= 15)
        printf("Alerta: fome está com valor baixo\n");
    if (thirst > 0 && thirst <= 15)
        printf("Alerta: sede está com valor baixo\n");
    if (bathroom > 0 && bathroom <= 15)
        printf("Alerta: banheiro está com valor baixo\n");
    if (sleep > 0 && sleep <= 15)
        printf("Alerta: sono está com valor baixo\n");
    if (boredom > 0 && boredom <= 15)
        printf("Alerta: tédio está com valor baixo\n");
}

int game_over(int hunger,
              int thirst,
              int bathroom,
              int sleep,
              int boredom)
{
    if (hunger == 0)
    {
        printf("Game Over! Morreu de fome\n");
        return 1;
    }
    else if (thirst == 0)
    {
        printf("Game Over! Morreu de sede\n");
        return 1;
    }
    else if (bathroom == 0)
    {
        printf("Game Over! Morreu apertado...\n");
        return 1;
    }
    else if (sleep == 0)
    {
        printf("Game Over! Morreu dormindo...\n");
        return 1;
    }
    else if (boredom == 0)
    {
        printf("Game Over! Morreu deprimido...\n");
        return 1;
    }
    else
        return 0;
}

void read_action(char action[MAX_LEN_ACTION])
{
    char text[MAX_LEN_ACTION];

    fgets(text, MAX_LEN_ACTION, stdin);
    text[strcspn(text, "\n")] = '\0';
    strcpy(action, text);
}

int simulate_sims(int *hunger,
                  int *thirst,
                  int *bathroom,
                  int *sleep,
                  int *boredom)
{
    char action[MAX_LEN_ACTION];
    read_action(action);

    if (strcmp(action, "comer") == 0)
    {
        *hunger = *hunger + 30 > 100 ? 100 : *hunger + 30;
        *bathroom = *bathroom - 15 < 0 ? 0 : *bathroom - 15;
        *thirst = *thirst - 5 < 0 ? 0 : *thirst - 5;
        *sleep = *sleep - 5 < 0 ? 0 : *sleep - 5;
        *boredom = *boredom - 5 < 0 ? 0 : *boredom - 5;
    }
    else if (strcmp(action, "beber") == 0)
    {
        *thirst = *thirst + 30 > 100 ? 100 : *thirst + 30;
        *bathroom = *bathroom - 20 < 0 ? 0 : *bathroom - 20;
        *hunger = *hunger - 5 < 0 ? 0 : *hunger - 5;
        *sleep = *sleep - 5 < 0 ? 0 : *sleep - 5;
        *boredom = *boredom - 5 < 0 ? 0 : *boredom - 5;
    }
    else if (strcmp(action, "dormir") == 0)
    {
        *sleep = *sleep + 80 > 100 ? 100 : *sleep + 80;
        *boredom = *boredom + 30 > 100 ? 100 : *boredom + 30;
        *thirst = *thirst - 30 < 0 ? 0 : *thirst - 30;
        *bathroom = *bathroom - 30 < 0 ? 0 : *bathroom - 30;
        *hunger = *hunger - 30 < 0 ? 0 : *hunger - 30;
    }
    else if (strcmp(action, "se aliviar") == 0)
    {
        *bathroom = 100;
        *hunger = *hunger - 5 < 0 ? 0 : *hunger - 5;
        *sleep = *sleep - 5 < 0 ? 0 : *sleep - 5;
        *thirst = *thirst - 5 < 0 ? 0 : *thirst - 5;
        *boredom = *boredom - 5 < 0 ? 0 : *boredom - 5;
    }
    else if (strcmp(action, "jogar videogame") == 0)
    {
        *boredom = *boredom + 80 > 100 ? 100 : *boredom + 80;
        *hunger = *hunger - 20 < 0 ? 0 : *hunger - 20;
        *sleep = *sleep - 20 < 0 ? 0 : *sleep - 20;
        *thirst = *thirst - 20 < 0 ? 0 : *thirst - 20;
        *bathroom = *bathroom - 20 < 0 ? 0 : *bathroom - 20;
    }

    if (game_over(*hunger, *thirst, *bathroom, *sleep, *boredom))
        return 0;
    else
    {
        warning(*hunger, *thirst, *bathroom, *sleep, *boredom);
        return 1;
    }
}

int main()
{
    int hunger, thirst, bathroom, sleep, boredom;
    int actions;

    scanf("%d %d %d %d %d", &hunger, &thirst, &bathroom, &sleep, &boredom);
    scanf("%d", &actions);
    getchar();

    for (int i = 0; i < actions; i++)
    {
        int result = simulate_sims(&hunger,
                                   &thirst,
                                   &bathroom,
                                   &sleep,
                                   &boredom);
        if (result == 0)
            break;
    }

    print_report(hunger, thirst, bathroom, sleep, boredom);

    return 0;
}