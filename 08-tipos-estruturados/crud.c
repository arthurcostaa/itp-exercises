#include <stdio.h>
#include <string.h>

#define MAX_LEN_NAME 51

typedef struct
{
    char name[MAX_LEN_NAME];
    int age;
    char sex;
} Person;

void print_person(Person person)
{
    printf("%s,%d,%c\n", person.name, person.age, person.sex);
}

void print_array(Person people[], int len)
{
    for (int i = 0; i < len; i++)
    {
        print_person(people[i]);
    }
}

Person input_data()
{
    Person person;
    char sex, name[MAX_LEN_NAME];
    int age;

    fgets(name, MAX_LEN_NAME, stdin);
    name[strlen(name) - 1] = '\0';
    scanf("%d", &age);
    scanf(" %c", &sex);
    getchar();

    strcpy(person.name, name);
    person.sex = sex;
    person.age = age;

    return person;
}

Person create(char name[], char sex, int age)
{
    Person person;

    strcpy(person.name, name);
    person.sex = sex;
    person.age = age;

    return person;
}

int insert(Person people[], Person person, int len)
{
    strcpy(people[len].name, person.name);
    people[len].sex = person.sex;
    people[len].age = person.age;

    len++;
    return len;
}

int delete(Person people[], Person person, int len)
{
    int index_found = -1;
    for (int i = 0; i < len; i++)
    {
        if (strcmp(people[i].name, person.name) == 0 &&
            people[i].sex == person.sex &&
            people[i].age == person.age)
            index_found = i;
    }

    if (index_found != -1)
    {
        for (int j = index_found + 1; j < len; j++)
        {
            strcpy(people[j - 1].name, people[j].name);
            people[j - 1].sex = people[j].sex;
            people[j - 1].age = people[j].age;
        }

        strcpy(people[len].name, "");
        people[len].sex = '\0';
        people[len].age = 0;

        len--;
        return len;
    }
    else
        return -1;
}

int main()
{
    Person people[100] = {0};
    Person person;
    int len = 0, result;
    char cmd = '\0';

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
            result = insert(people, person, len);
            len = result;
        }
        else if (cmd == 'd')
        {
            person = input_data();
            result = delete (people, person, len);
            if (result == -1)
                continue;
            else
                len = result;
        }
    }

    return 0;
}