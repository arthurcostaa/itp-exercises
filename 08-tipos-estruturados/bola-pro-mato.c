#include <stdio.h>
#include <string.h>

#define LEN_TEAM_NAME 51
#define LEN_INPUT 200
#define NUM_TEAMS_LIBERTADORES 6
#define NUM_TEAMS_RELEGATION 4

typedef struct
{
    char name[LEN_TEAM_NAME];
    int wins, draws, losses, goals_for, goals_against;
    int points, matches, goal_difference;
} Team;

void print_teams_data(int num_teams, Team teams[])
{
    int points, matches, goal_difference;

    printf("Tabela do campeonato:");
    printf("\nNome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");

    for (int i = 0; i < num_teams; i++)
    {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n",
               teams[i].name,
               teams[i].points,
               teams[i].matches,
               teams[i].wins,
               teams[i].draws,
               teams[i].losses,
               teams[i].goals_for,
               teams[i].goals_against,
               teams[i].goal_difference);
    }

    printf("\nTimes na zona da libertadores:\n");
    for (int i = 0; i < NUM_TEAMS_LIBERTADORES; i++)
        printf("%s\n", teams[i].name);

    printf("\nTimes rebaixados:\n");
    for (int i = num_teams - 1; i >= num_teams - 4; i--)
        printf("%s\n", teams[i].name);
}

void read_teams_data(int num_teams, Team teams[])
{
    char input[LEN_INPUT];

    for (int i = 0; i < num_teams; i++)
    {
        fgets(input, sizeof(input), stdin);

        sscanf(input, "%[^;]; %d %d %d %d %d",
               teams[i].name,
               &teams[i].wins,
               &teams[i].draws,
               &teams[i].losses,
               &teams[i].goals_for,
               &teams[i].goals_against);

        teams[i].goal_difference = teams[i].goals_for - teams[i].goals_against;
        teams[i].points = teams[i].wins * 3 + teams[i].draws;
        teams[i].matches = teams[i].wins + teams[i].draws + teams[i].losses;
    }
}

void sort_teams(int num_teams, Team teams[])
{
    Team aux;

    // bubble sort
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 1; i < num_teams; i++)
        {
            if ((teams[i - 1].points < teams[i].points) ||
                (teams[i - 1].points == teams[i].points &&
                 teams[i - 1].wins < teams[i].wins) ||
                (teams[i - 1].points == teams[i].points &&
                 teams[i - 1].wins == teams[i].wins &&
                 teams[i - 1].goal_difference < teams[i].goal_difference))
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
    int num_teams;

    scanf("%d", &num_teams);
    getchar();

    Team teams[num_teams];

    read_teams_data(num_teams, teams);
    sort_teams(num_teams, teams);
    print_teams_data(num_teams, teams);

    return 0;
}