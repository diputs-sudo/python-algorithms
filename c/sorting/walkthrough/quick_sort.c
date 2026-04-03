/*
Quick Sort Algorithm

Quick Sort is a divide and conquer sorting algorithm.

How it works:
- It selects a pivot element from the list.
- It partitions the remaining elements into three groups.
- Elements smaller than the pivot go to the left group.
- Elements equal to the pivot stay in the middle group.
- Elements greater than the pivot go to the right group.
- The left and right groups are sorted recursively.
- The final result is the combination of left, middle, and right groups.

This algorithm is usually very fast in practice.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) in this implementation due to extra lists.

Stability:
- Not stable in general.
*/

#include <stdio.h>
#include <stdlib.h>

static int* _quick_sort_verbose(int *arr, int n, int depth)
{
    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("quick_sort(");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf(")\n");

    if (n <= 1)
    {
        int *result = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            result[i] = arr[i];
        return result;
    }

    int pivot = arr[n / 2];

    for (int i = 0; i < depth; i++)
        printf("  ");
    printf("Pivot: %d\n", pivot);

    int *left = malloc(sizeof(int) * n);
    int *middle = malloc(sizeof(int) * n);
    int *right = malloc(sizeof(int) * n);
    int l = 0;
    int m = 0;
    int r = 0;

    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < depth; t++)
            printf("  ");

        printf("Compare %d with pivot %d\n", arr[i], pivot);

        if (arr[i] < pivot)
        {
            left[l++] = arr[i];
            for (int t = 0; t < depth; t++)
                printf("  ");
            printf("  -> go left: ");
            for (int t = 0; t < l; t++)
                printf("%d ", left[t]);
            printf("\n");
        }
        else if (arr[i] > pivot)
        {
            right[r++] = arr[i];
            for (int t = 0; t < depth; t++)
                printf("  ");
            printf("  -> go right: ");
            for (int t = 0; t < r; t++)
                printf("%d ", right[t]);
            printf("\n");
        }
        else
        {
            middle[m++] = arr[i];
            for (int t = 0; t < depth; t++)
                printf("  ");
            printf("  -> go middle: ");
            for (int t = 0; t < m; t++)
                printf("%d ", middle[t]);
            printf("\n");
        }
    }

    int *sorted_left = _quick_sort_verbose(left, l, depth + 1);
    int *sorted_right = _quick_sort_verbose(right, r, depth + 1);
    int *result = malloc(sizeof(int) * n);
    int pos = 0;

    for (int i = 0; i < l; i++)
        result[pos++] = sorted_left[i];
    for (int i = 0; i < m; i++)
        result[pos++] = middle[i];
    for (int i = 0; i < r; i++)
        result[pos++] = sorted_right[i];

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("Combined result: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(left);
    free(middle);
    free(right);
    free(sorted_left);
    free(sorted_right);

    return result;
}

int* quick_sort_verbose(int *arr, int n)
{
    return _quick_sort_verbose(arr, n, 0);
}
