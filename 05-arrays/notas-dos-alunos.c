#include <stdio.h>

void read_students_data(int total_students,
                        int students_id[],
                        float students_grades[])
{
    for (int i = 0; i < total_students; i++)
    {
        scanf("%d - %f", &students_id[i], &students_grades[i]);
    }
}

void analise_students_grades(int total_students,
                             int students_id[],
                             float students_grades[],
                             int passed[],
                             int retake[],
                             int failed[])
{
    for (int i = 0; i < total_students; i++)
    {
        students_grades[i] >= 7
            ? (passed[i] = students_id[i])
            : (passed[i] = 0);
        students_grades[i] < 5
            ? (failed[i] = students_id[i])
            : (failed[i] = 0);
        (students_grades[i] >= 5 && students_grades[i] < 7)
            ? (retake[i] = students_id[i])
            : (retake[i] = 0);
    }
}

void print_grades_by_id(int total_students,
                        int students_id[],
                        float students_grades[])
{
    int first = 1;

    for (int i = 0; i < total_students; i++)
    {
        if (students_id[i] != 0)
        {
            first ? first = 0 : printf(", ");
            printf("%d (%.1f)", students_id[i], students_grades[i]);
        }
    }
    printf("\n");
}

void print_students_result(int total_students,
                           float students_grades[],
                           int passed[],
                           int retake[],
                           int failed[])
{
    printf("Aprovados: ");
    print_grades_by_id(total_students, passed, students_grades);

    printf("Recuperação: ");
    print_grades_by_id(total_students, retake, students_grades);

    printf("Reprovados: ");
    print_grades_by_id(total_students, failed, students_grades);
}

int main()
{
    int total_students;

    scanf("%d", &total_students);

    int students_id[total_students];
    float students_grades[total_students];

    int passed[total_students];
    int retake[total_students];
    int failed[total_students];

    read_students_data(total_students, students_id, students_grades);
    analise_students_grades(total_students,
                            students_id,
                            students_grades,
                            passed,
                            retake,
                            failed);
    print_students_result(total_students,
                          students_grades,
                          passed,
                          retake,
                          failed);
}