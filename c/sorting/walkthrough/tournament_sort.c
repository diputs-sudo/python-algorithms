/*
Tournament Sort Algorithm

Tournament Sort is a comparison based sorting algorithm inspired by
a knockout tournament structure.

How it works:
- Elements are placed in the leaves of a binary tree.
- Each internal node stores the minimum of its two children.
- The root always contains the smallest element in the structure.
- The minimum element is extracted and replaced with infinity.
- The tree is updated from the leaf to the root.
- The process repeats until all elements are extracted.

This approach simulates repeatedly selecting the minimum efficiently.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) due to the tournament tree structure.

Stability:
- Not stable in general.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int _next_power_of_two(int n)
{
    int size = 1;

    while (size < n)
        size <<= 1;

    return size;
}

static void _build_tree(double *arr, int n, double *tree, int offset)
{
    for (int i = 0; i < 2 * offset; i++)
        tree[i] = INFINITY;

    for (int i = 0; i < n; i++)
        tree[offset + i] = arr[i];

    for (int i = offset - 1; i > 0; i--)
    {
        if (tree[2 * i] < tree[2 * i + 1])
            tree[i] = tree[2 * i];
        else
            tree[i] = tree[2 * i + 1];
    }
}

static void _update_tree(double *tree, int index)
{
    int i = index / 2;

    while (i >= 1)
    {
        if (tree[2 * i] < tree[2 * i + 1])
            tree[i] = tree[2 * i];
        else
            tree[i] = tree[2 * i + 1];

        i /= 2;
    }
}

double* tournament_sort_verbose(double *arr, int n)
{
    double *a = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");

    int offset = _next_power_of_two(n > 0 ? n : 1);
    double *tree = malloc(sizeof(double) * (2 * offset));

    _build_tree(a, n, tree, offset);

    printf("\nInitial tournament tree as array:\n");
    printf("[ ");
    for (int i = 0; i < 2 * offset; i++)
        printf("%f ", tree[i]);
    printf("]\n");

    double *result = malloc(sizeof(double) * n);

    for (int step = 1; step <= n; step++)
    {
        double winner = tree[1];

        printf("\nStep %d: current winner is %f\n", step, winner);

        result[step - 1] = winner;

        int i = 1;
        while (i < offset)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (tree[left] == winner)
                i = left;
            else
                i = right;
        }

        printf("  Winner found at leaf index %d, replacing with infinity\n", i);

        tree[i] = INFINITY;
        _update_tree(tree, i);

        printf("  Tree after update:\n");
        printf("  [ ");
        for (int j = 0; j < 2 * offset; j++)
            printf("%f ", tree[j]);
        printf("]\n");

        printf("  Result so far: ");
        for (int j = 0; j < step; j++)
            printf("%f ", result[j]);
        printf("\n");
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%f ", result[i]);
    printf("\n");

    free(a);
    free(tree);

    return result;
}
