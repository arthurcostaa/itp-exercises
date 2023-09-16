#include <stdio.h>

float calculateAverage(char type, float grade1, float grade2, float grade3)
{
    switch (type)
    {
    case 'A':
        return (grade1 + grade2 + grade3) / 3.0;
        break;
    case 'P':
        return (grade1 * 4 + grade2 * 5 + grade3 * 6) / 15.0;
        break;
    default:
        break;
    }
}

int main()
{
    char type;
    float grade1, grade2, grade3;
    float average;

    scanf("%c %f %f %f", &type, &grade1, &grade2, &grade3);

    average = calculateAverage(type, grade1, grade2, grade3);
    printf("Média %.2f\n", average);

    return 0;
}