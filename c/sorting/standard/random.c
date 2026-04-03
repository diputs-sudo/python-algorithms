#include <stdlib.h>
#include <time.h>

void seed_random()
{
    srand((unsigned int)time(NULL));
}

int* random_int_array(int n, int min_value, int max_value)
{
    int *result = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        result[i] = min_value + rand() % (max_value - min_value + 1);
    return result;
}

double* random_double_array(int n, double min_value, double max_value)
{
    double *result = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++)
    {
        double ratio = (double)rand() / (double)RAND_MAX;
        result[i] = min_value + ratio * (max_value - min_value);
    }
    return result;
}
