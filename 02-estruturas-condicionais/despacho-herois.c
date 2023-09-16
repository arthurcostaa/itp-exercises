#include <stdio.h>

int main()
{
    int number_of_heroes, hero_class, monster;

    scanf("%d %d %d", &number_of_heroes, &hero_class, &monster);

    switch (monster)
    {
    case 1: // Lobo
        (hero_class >= 2) || (hero_class == 1 && number_of_heroes >= 3)
            ? printf("Heróis vencerão!\n")
            : printf("Melhor chamar Saitama!\n");
        break;
    case 2: // Tigre
        (hero_class >= 3) || (hero_class == 2 && number_of_heroes >= 3)
            ? printf("Heróis vencerão!\n")
            : printf("Melhor chamar Saitama!\n");
        break;
    case 3: // Demônio
        (hero_class >= 4) || (hero_class == 3 && number_of_heroes >= 3)
            ? printf("Heróis vencerão!\n")
            : printf("Melhor chamar Saitama!\n");
        break;
    case 4: // Dragão
        (hero_class == 5) || (hero_class == 4 && number_of_heroes >= 3)
            ? printf("Heróis vencerão!\n")
            : printf("Melhor chamar Saitama!\n");
        break;
    case 5: // Divindade
        hero_class == 5
            ? printf("Heróis vencerão!\n")
            : printf("Melhor chamar Saitama!\n");
        break;
    default:
        break;
    }

    return 0;
}