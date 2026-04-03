/*
Counting Sort Algorithm

Counting Sort is a non comparison based sorting algorithm.

How it works:
- It counts how many times each value appears in the input.
- It stores those counts in a separate array.
- It rebuilds the sorted list using the stored frequencies.

This algorithm works best when the range of input values is not very large.

Time Complexity:
- Worst Case: O(n + k)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the range of values.

Space Complexity:
- O(k) due to the counting array.

Stability:
- This basic version is not stable.
- A modified version can be made stable.
*/

#include <stdio.h>
#include <stdlib.h>

int* counting_sort_verbose(int *arr, int n, int *out_size)
{
    if (n == 0)
    {
        *out_size = 0;
        return NULL;
    }

    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    int max_val = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max_val)
            max_val = a[i];

    printf("Max value: %d\n", max_val);

    int *count = calloc(max_val + 1, sizeof(int));

    printf("\nCounting occurrences...\n");
    for (int i = 0; i < n; i++)
    {
        count[a[i]] += 1;
        printf("Count[%d] -> %d\n", a[i], count[a[i]]);
    }

    printf("\nCount array: ");
    for (int i = 0; i <= max_val; i++)
        printf("%d ", count[i]);
    printf("\n");

    int *result = malloc(sizeof(int) * n);
    int pos = 0;

    printf("\nBuilding sorted array...\n");

    for (int value = 0; value <= max_val; value++)
    {
        int freq = count[value];

        if (freq > 0)
            printf("Add %d x %d\n", value, freq);

        for (int j = 0; j < freq; j++)
        {
            result[pos++] = value;

            printf("  result: ");
            for (int k = 0; k < pos; k++)
                printf("%d ", result[k]);
            printf("\n");
        }
    }

    printf("\nSorted: ");
    for (int i = 0; i < pos; i++)
        printf("%d ", result[i]);
    printf("\n");

    *out_size = pos;
    return result;
}
