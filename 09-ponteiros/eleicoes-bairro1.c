#include <stdio.h>

#define NUM_CANDIDATES 10

void read_votes(int num_votes, int votes[num_votes])
{
    for (int i = 0; i < num_votes; i++)
        scanf("%d", &votes[i]);
}

void compute_votes(int num_votes,
                   int votes[num_votes],
                   int *most_voted,
                   int *second_most_voted)
{
    int votes_by_candidates[NUM_CANDIDATES] = {0};
    int num_most_voted, num_second_most_voted;

    for (int i = 0; i < num_votes; i++)
        votes_by_candidates[votes[i] - 1] += 1;

    num_most_voted = votes_by_candidates[0];
    *most_voted = 0 + 1;

    for (int i = 1; i < NUM_CANDIDATES; i++)
    {
        if (votes_by_candidates[i] > num_most_voted)
        {
            *most_voted = i + 1;
            num_most_voted = votes_by_candidates[i];
        }
    }

    num_second_most_voted = votes_by_candidates[0];
    *second_most_voted = 0 + 1;

    for (int i = 1; i < NUM_CANDIDATES; i++)
    {
        if (votes_by_candidates[i] > num_second_most_voted &&
            votes_by_candidates[i] < num_most_voted)
        {
            *second_most_voted = i + 1;
            num_second_most_voted = votes_by_candidates[i];
        }
    }
}

int main()
{
    int num_votes, most_voted, second_most_voted;

    scanf("%d", &num_votes);

    int votes[num_votes];

    read_votes(num_votes, votes);

    compute_votes(num_votes, votes, &most_voted, &second_most_voted);

    printf("%d %d\n", most_voted, second_most_voted);

    return 0;
}