#include <stdio.h>
#include <string.h>

#define PARTY_NUMBER 10
#define MAX_LEN_PARTY_NAME 10

typedef struct
{
    int party_number;
    char party_name[MAX_LEN_PARTY_NAME];
    int num_votes;
} Party;

void print_winners(int total_valid_votes,
                   Party first,
                   Party second)
{
    float percent_first =
        ((float)first.num_votes / (float)total_valid_votes) * 100;
    float percent_second =
        ((float)second.num_votes / (float)total_valid_votes) * 100;

    printf("VENCEDOR: %s (%d votos = %.2f%)",
           first.party_name,
           first.num_votes,
           percent_first);
    printf("\nVICE: %s (%d votos = %.2f%)\n",
           second.party_name,
           second.num_votes,
           percent_second);
}

void read_parties(int num_parties, Party parties[num_parties])
{
    for (int i = 0; i < num_parties; i++)
    {
        scanf("%d %[^\n]",
              &parties[i].party_number,
              parties[i].party_name);
        getchar();
        parties[i].num_votes = 0;
    }
}

int read_votes(int num_votes,
               int votes[num_votes],
               int num_parties,
               Party parties[num_votes])
{
    int vote;
    int valid_votes = 0;

    for (int i = 0; i < num_votes; i++)
    {
        scanf("%d", &vote);
        for (int j = 0; j < num_parties; j++)
        {
            if (vote == parties[j].party_number)
            {
                valid_votes++;
                parties[j].num_votes++;
            }
        }
    }

    return valid_votes;
}

void compute_votes(int num_parties,
                   Party *most_voted,
                   Party *second_most_voted,
                   Party parties[num_parties])
{
    int swapped = 1;
    Party aux;

    while (swapped)
    {
        swapped = 0;
        for (int i = 1; i < num_parties; i++)
        {
            if (parties[i].num_votes > parties[i - 1].num_votes)
            {
                aux = parties[i - 1];
                parties[i - 1] = parties[i];
                parties[i] = aux;
                swapped = 1;
            }
        }
    }

    *most_voted = parties[0];
    *second_most_voted = parties[1];
}

int main()
{
    int num_votes, num_parties, valid_votes;
    Party most_voted, second_most_voted;

    scanf("%d", &num_parties);

    Party parties[num_parties];

    read_parties(num_parties, parties);

    scanf("%d", &num_votes);

    int votes[num_votes];

    valid_votes = read_votes(num_votes, votes, num_parties, parties);

    compute_votes(num_parties,
                  &most_voted,
                  &second_most_voted,
                  parties);

    print_winners(valid_votes, most_voted, second_most_voted);

    return 0;
}