/*
Bucket Sort Algorithm

Bucket Sort is a distribution based sorting algorithm.

How it works:
- It divides elements into several groups called buckets.
- Each bucket holds values within a specific range.
- Elements are distributed into buckets based on their value.
- Each bucket is sorted individually.
- All buckets are combined to produce the final sorted list.

This algorithm performs well when the input values are evenly distributed.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the number of buckets.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Depends on the sorting method used inside each bucket.
*/

#include <stdio.h>
#include <stdlib.h>

int compare_double(const void *a, const void *b)
{
    double x = *(double *)a;
    double y = *(double *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

double* bucket_sort_verbose(double *arr, int n, int bucket_size, int *out_size)
{
    if (n == 0)
    {
        *out_size = 0;
        return NULL;
    }

    double *a = malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");

    double min_val = a[0];
    double max_val = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    printf("Min: %f Max: %f\n", min_val, max_val);

    int bucket_count = ((int)(max_val - min_val) / bucket_size) + 1;

    double **buckets = malloc(sizeof(double*) * bucket_count);
    int *sizes = calloc(bucket_count, sizeof(int));

    for (int i = 0; i < bucket_count; i++)
        buckets[i] = malloc(sizeof(double) * n);

    printf("\nCreated %d buckets\n", bucket_count);

    printf("\nDistributing into buckets...\n");

    for (int i = 0; i < n; i++)
    {
        int index = ((int)(a[i] - min_val)) / bucket_size;
        printf("Put %f into bucket %d\n", a[i], index);
        buckets[index][sizes[index]++] = a[i];
    }

    printf("\nBuckets before sorting:\n");
    for (int i = 0; i < bucket_count; i++)
    {
        printf("Bucket %d: ", i);
        for (int j = 0; j < sizes[i]; j++)
            printf("%f ", buckets[i][j]);
        printf("\n");
    }

    printf("\nSorting each bucket and collecting...\n");

    double *result = malloc(sizeof(double) * n);
    int pos = 0;

    for (int i = 0; i < bucket_count; i++)
    {
        printf("Sort bucket %d: ", i);
        for (int j = 0; j < sizes[i]; j++)
            printf("%f ", buckets[i][j]);
        printf("\n");

        qsort(buckets[i], sizes[i], sizeof(double), compare_double);

        printf("  sorted bucket %d: ", i);
        for (int j = 0; j < sizes[i]; j++)
            printf("%f ", buckets[i][j]);
        printf("\n");

        for (int j = 0; j < sizes[i]; j++)
        {
            result[pos++] = buckets[i][j];

            printf("  result: ");
            for (int k = 0; k < pos; k++)
                printf("%f ", result[k]);
            printf("\n");
        }
    }

    printf("\nSorted: ");
    for (int i = 0; i < pos; i++)
        printf("%f ", result[i]);
    printf("\n");

    *out_size = pos;
    return result;
}
