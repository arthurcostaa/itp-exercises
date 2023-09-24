#include <stdio.h>

void read_matrix(int rows, int cols, char matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf(" %c", &matrix[i][j]);
}

void calc_planet_statistcs(int rows,
                           int cols,
                           char matrix[rows][cols],
                           int stats[5])
{
    char cell;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cell = matrix[i][j];
            switch (cell)
            {
            case '~': // water
                stats[0] += 1;
                break;
            case 'X': // hostile species
                stats[1] += 1;
                break;
            case '^': // desert
                stats[2] += 1;
                break;
            case '*': // vegetation areas
                stats[3] += 1;
                break;
            case '.': // no natural resources
                stats[4] += 1;
            default:
                break;
            }
        }
    }
}

void analyze_planet(int rows, int cols, int stats[5])
{
    int water, hostile_species, desert, vegetation_areas, no_natural_resources;
    int territory = rows * cols;

    water = stats[0];
    hostile_species = stats[1];
    desert = stats[2];
    vegetation_areas = stats[3];
    no_natural_resources = stats[4];

    if (water >= (0.5 * territory) &&
        vegetation_areas >= (0.2 * territory) &&
        hostile_species == 0)
    {
        printf("Planeta Classe M\n");
    }
    else if (hostile_species > 0)
    {
        printf("Planeta Hostil\n");
    }
    else if (water >= 0.85 * territory)
    {
        printf("Planeta Aquático\n");
    }
    else if (desert >= 0.6 * territory)
    {
        printf("Planeta Desértico\n");
    }
    else if (vegetation_areas >= 0.65 * territory)
    {
        printf("Planeta Selvagem\n");
    }
    else
    {
        printf("Planeta Inóspito\n");
    }
}

int main()
{
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    char planet[rows][cols];
    // 0 - water (~)
    // 1 - hostile species (X)
    // 2 - desert (^)
    // 3 - vegetation areas (*)
    // 4 - no natural resources (.)
    int planet_stats[5] = {0};

    read_matrix(rows, cols, planet);
    calc_planet_statistcs(rows, cols, planet, planet_stats);
    analyze_planet(rows, cols, planet_stats);

    return 0;
}