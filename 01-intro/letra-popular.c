#include <stdio.h>

int main()
{
    char letter;
    int number_letter_appearances;
    float popularity_index, punctuation;

    scanf("%c %d %f", &letter, &number_letter_appearances, &popularity_index);

    punctuation = number_letter_appearances * popularity_index;
    printf("A popularidade de %c é %.1f\n", letter, punctuation);
}