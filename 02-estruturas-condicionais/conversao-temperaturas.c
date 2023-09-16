#include <stdio.h>

int main()
{
    char scale;
    double temperature, celsius, kelvin, fahrenheit;

    scanf("%lf %c", &temperature, &scale);

    switch (scale)
    {
    case 'C':
        celsius = temperature;
        kelvin = celsius + 273.15;
        fahrenheit = celsius * 1.8 + 32;
        break;
    case 'F':
        fahrenheit = temperature;
        celsius = (fahrenheit - 32) / 1.8;
        kelvin = celsius + 273.15;
        break;
    case 'K':
        kelvin = temperature;
        celsius = kelvin - 273.15;
        fahrenheit = celsius * 1.8 + 32;
    default:
        break;
    }

    printf("Celsius: %.2lf\n", celsius);
    printf("Farenheit: %.2lf\n", fahrenheit);
    printf("Kelvin: %.2lf\n", kelvin);

    return 0;
}