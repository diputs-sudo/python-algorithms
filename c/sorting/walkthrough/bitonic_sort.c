/*
Bitonic Sort Algorithm

Bitonic Sort is a comparison based sorting algorithm commonly used in
parallel computing environments.

How it works:
- It recursively builds bitonic sequences.
- A bitonic sequence first increases and then decreases.
- These sequences are merged using compare and swap operations.
- Repeated merging produces a fully sorted sequence.

Classic Bitonic Sort assumes the input size is a power of two.

This educational implementation:
- Automatically pads the list to the next power of two using infinity.
- Removes the padding after sorting.
- Supports a verbose mode for visualization.

Time Complexity:
- Worst Case: O(n log^2 n)
- Average Case: O(n log^2 n)
- Best Case: O(n log^2 n)

Space Complexity:
- O(n) due to padding and recursive structure.

Stability:
- Not stable.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int _is_power_of_two(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int _next_power_of_two(int n)
{
    int p = 1;
    while (p < n)
        p <<= 1;
    return p;
}

void _compare_and_swap(double *a, int i, int j, bool ascending, bool verbose, int step)
{
    if (verbose)
    {
        const char *direction = ascending ? "ascending" : "descending";
        printf("Step %d: compare %f and %f (%s)\n", step, a[i], a[j], direction);
    }

    if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j]))
    {
        if (verbose)
            printf("  swap %f and %f\n", a[i], a[j]);

        double temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        if (verbose)
        {
            printf("  result: ");
            for (int k = 0; k < 100; k++)
            {
                if (a[k] == INFINITY)
                    break;
                printf("%f ", a[k]);
            }
            printf("\n");
        }
    }
    else
    {
        if (verbose)
            printf("  no swap\n");
    }
}

int _bitonic_merge(double *a, int low, int cnt, bool ascending, bool verbose, int step)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        for (int i = low; i < low + k; i++)
        {
            _compare_and_swap(a, i, i + k, ascending, verbose, step);
            step += 1;
        }

        step = _bitonic_merge(a, low, k, ascending, verbose, step);
        step = _bitonic_merge(a, low + k, k, ascending, verbose, step);
    }

    return step;
}

int _bitonic_sort(double *a, int low, int cnt, bool ascending, bool verbose, int step)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        if (verbose)
        {
            const char *direction = ascending ? "ascending" : "descending";
            printf("\nBuild bitonic sequence from index %d count %d (%s)\n", low, cnt, direction);
        }

        step = _bitonic_sort(a, low, k, true, verbose, step);
        step = _bitonic_sort(a, low + k, k, false, verbose, step);
        step = _bitonic_merge(a, low, cnt, ascending, verbose, step);
    }

    return step;
}

double *bitonic_sort_verbose(double *arr, int n, int *out_size)
{
    double *a = malloc(sizeof(double) * 1024);
    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");

    int target = _next_power_of_two(n);

    if (target != n)
    {
        printf("Note: Bitonic sort works best when length is a power of two.\n");
        printf("Padding array from length %d to %d using infinity.\n", n, target);

        double pad_value = INFINITY;

        for (int i = n; i < target; i++)
            a[i] = pad_value;

        printf("Working array: ");
        for (int i = 0; i < target; i++)
            printf("%f ", a[i]);
        printf("\n");
    }

    _bitonic_sort(a, 0, target, true, true, 1);

    int new_size = 0;
    for (int i = 0; i < target; i++)
    {
        if (a[i] != INFINITY)
        {
            a[new_size++] = a[i];
        }
    }

    printf("\nSorted: ");
    for (int i = 0; i < new_size; i++)
        printf("%f ", a[i]);
    printf("\n");

    *out_size = new_size;
    return a;
}
