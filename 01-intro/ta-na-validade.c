#include <stdio.h>

int main()
{
    int expire_days, days, months, years;

    scanf("%d", &expire_days);

    years = expire_days / 365;
    expire_days -= years * 365;

    months = expire_days / 30;
    expire_days -= months * 30;

    days = expire_days;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", years, months, days);
}