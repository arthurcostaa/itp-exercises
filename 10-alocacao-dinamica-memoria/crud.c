#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int age;
    char sex;
} Person;

void print_array(Person people[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s,%d,%c\n", people[i].name, people[i].age, people[i].sex);
    }
}

char *input_text()
{
    char *str = NULL;
    char c;
    int size = 0;

    while (1)
    {
        c = getchar();

        if (c == '\n')
            break;

        size++;
        str = (char *)realloc(str, sizeof(char) * size);

        str[size - 1] = c;
    }

    size++;
    str = (char *)realloc(str, sizeof(char) * size);
    str[size - 1] = '\0';

    return str;
}

Person create_person(char *name, int age, char sex)
{
    Person person;

    person.name = name;
    person.age = age;
    person.sex = sex;

    return person;
}

void insert_person(Person **people, Person person, int *len)
{
    (*people) = (Person *)realloc(*people, sizeof(Person) * ((*len) + 1));

    (*people)[*len] = person;

    (*len)++;
}

void delete_person(Person **people, Person person, int *len)
{
    int index_found = -1;

    for (int i = 0; i < *len; i++)
    {
        if (strcmp(person.name, (*people)[i].name) == 0 &&
            person.age == (*people)[i].age &&
            person.sex == (*people)[i].sex)
        {
            index_found = i;
        }
    }

    if (index_found != -1)
    {
        for (int i = index_found + 1; i < *len; i++)
        {
            strcpy((*people)[i - 1].name, (*people)[i].name);
            (*people)[i - 1].age = (*people)[i].age;
            (*people)[i - 1].sex = (*people)[i].sex;
        }

        (*len)--;

        *people = (Person *)realloc(*people, sizeof(Person) * (*len));
    }
}

Person input_data()
{
    Person person;
    char *name, sex;
    int age;

    name = input_text();
    scanf("%d", &age);
    scanf(" %c", &sex);
    getchar();

    person = create_person(name, age, sex);

    return person;
}

int main()
{
    Person *people = NULL;
    Person person;
    int len = 0;
    char cmd;

    while (1)
    {
        scanf(" %c", &cmd);
        getchar();

        if (cmd == 'p')
        {
            print_array(people, len);
            break;
        }
        else if (cmd == 'i')
        {
            person = input_data();
            insert_person(&people, person, &len);
        }
        else if (cmd == 'd')
        {
            person = input_data();
            delete_person(&people, person, &len);
        }
    }

    free(people);

    return 0;
}