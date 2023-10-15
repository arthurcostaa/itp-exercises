#include <stdio.h>
#include <string.h>

typedef struct
{
    char model[40];
    int memory;
    float processor, camera, baterry;
} Smartphone;

void print_phone(Smartphone phone)
{
    printf("Modelo: %s\n", phone.model);
    printf("Memoria: %dGB\n", phone.memory);
    printf("Processador: %.2fGhz\n", phone.processor);
    printf("Camera: %.2fMPixels\n", phone.camera);
    printf("Bateria: %.2fmA\n", phone.baterry);
    printf("\n");
}

int register_smartphone(int num_registered, Smartphone phones[])
{
    char model[40];
    int memory;
    float processor, camera, baterry;

    scanf(" %[^\n]", &model);
    scanf("%d %f %f %f", &memory, &processor, &camera, &baterry);

    strcpy(phones[num_registered].model, model);
    phones[num_registered].memory = memory;
    phones[num_registered].processor = processor;
    phones[num_registered].camera = camera;
    phones[num_registered].baterry = baterry;

    num_registered++;

    return num_registered;
}

int search_smartphone(int num_registered,
                      Smartphone phones[],
                      Smartphone min_req)
{
    int num_phones_found = 0;

    for (int i = 0; i < num_registered; i++)
    {
        if (phones[i].memory >= min_req.memory &&
            phones[i].processor >= min_req.processor &&
            phones[i].camera >= min_req.camera &&
            phones[i].baterry >= min_req.baterry)
        {
            num_phones_found++;
            print_phone(phones[i]);
        }
    }

    return num_phones_found;
}

int main()
{
    char answer;
    int num_phones_registered = 0, num_phones_found;
    Smartphone phones[100];
    Smartphone min_req;

    while (1)
    {
        scanf(" %c", &answer);

        if (answer == 'n')
            break;

        num_phones_registered = register_smartphone(
            num_phones_registered,
            phones);
    }

    scanf("%d %f %f %f",
          &min_req.memory,
          &min_req.processor,
          &min_req.camera,
          &min_req.baterry);

    num_phones_found = search_smartphone(num_phones_registered,
                                         phones,
                                         min_req);

    printf("%d smartphones encontrados.\n", num_phones_found);

    return 0;
}