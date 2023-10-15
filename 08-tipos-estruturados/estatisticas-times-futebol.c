#include <stdio.h>
#include <string.h>

#define MAX_LEN_NAME_TEAM 51

typedef struct
{
    char name[MAX_LEN_NAME_TEAM];
    int goals_for;
    int goals_against;
} Team;

void read_teams(Team *teams, int num_teams)
{
    for (int i = 0; i < num_teams; i++)
    {
        fgets(teams[i].name, MAX_LEN_NAME_TEAM, stdin);
        teams[i].name[strlen(teams[i].name) - 1] = '\0';

        scanf("%d", &teams[i].goals_for);

        scanf("%d", &teams[i].goals_against);
        getchar();
    }
}

void print_teams(Team *teams, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d - %s\n", i + 1, teams[i].name);
        printf("Gols marcados: %d\n", teams[i].goals_for);
        printf("Gols sofridos: %d\n", teams[i].goals_against);
    }
}

void sort_teams(Team *teams, int length)
{
    Team aux;
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (int i = 1; i < length; i++)
        {
            if (teams[i - 1].goals_for < teams[i].goals_for)
            {
                aux = teams[i - 1];
                teams[i - 1] = teams[i];
                teams[i] = aux;
                swapped = 1;
            }
        }
    }
}

int main()
{
    char team_name[MAX_LEN_NAME_TEAM];
    int goals_for, goals_against, num_teams;

    scanf("%d", &num_teams);
    getchar();

    Team teams[num_teams];

    read_teams(teams, num_teams);

    sort_teams(teams, num_teams);

    print_teams(teams, num_teams);

    return 0;
}