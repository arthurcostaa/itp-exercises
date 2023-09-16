#include <stdio.h>

int main()
{
    int request_code, client_value, combo_value;

    scanf("%d %d", &request_code, &client_value);

    switch (request_code)
    {
    case 1:
        combo_value = 12;
        break;
    case 2:
        combo_value = 23;
        break;
    case 3:
        combo_value = 31;
        break;
    case 4:
        combo_value = 28;
        break;
    case 5:
        combo_value = 15;
        break;
    default:
        break;
    }

    if (client_value > combo_value)
    {
        printf("Troco = %d reais\n", client_value - combo_value);
    }
    else if (client_value < combo_value)
    {
        printf("Saldo insuficiente! Falta %d reais\n", combo_value - client_value);
    }
    else
    {
        printf("Deu certim!\n");
    }

    return 0;
}