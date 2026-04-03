/*
Merge Sort Algorithm

Merge Sort is a divide and conquer sorting algorithm.

How it works:
- It divides the list into two halves.
- Each half is sorted recursively.
- The sorted halves are merged together.
- The merging step compares elements from both halves and builds a new sorted list.

This approach ensures consistent performance regardless of input order.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) due to temporary arrays used during merging.

Stability:
- Stable because equal elements preserve their original order.
*/

#include <stdio.h>
#include <stdlib.h>

static int* _merge_sort_verbose(int *arr, int n, int depth)
{
    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("merge_sort(");
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

    int mid = n / 2;

    int *left = _merge_sort_verbose(arr, mid, depth + 1);
    int *right = _merge_sort_verbose(arr + mid, n - mid, depth + 1);
    int *result = malloc(sizeof(int) * n);

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("Merging ");
    for (int i = 0; i < mid; i++)
        printf("%d ", left[i]);
    printf("and ");
    for (int i = 0; i < n - mid; i++)
        printf("%d ", right[i]);
    printf("\n");

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < mid && j < n - mid)
    {
        for (int t = 0; t < depth; t++)
            printf("  ");

        printf("Compare %d and %d\n", left[i], right[j]);

        if (left[i] <= right[j])
            result[k++] = left[i++];
        else
            result[k++] = right[j++];

        for (int t = 0; t < depth; t++)
            printf("  ");

        printf("  result now: ");
        for (int t = 0; t < k; t++)
            printf("%d ", result[t]);
        printf("\n");
    }

    while (i < mid)
        result[k++] = left[i++];

    while (j < n - mid)
        result[k++] = right[j++];

    for (int t = 0; t < depth; t++)
        printf("  ");

    printf("Merged into: ");
    for (int t = 0; t < n; t++)
        printf("%d ", result[t]);
    printf("\n");

    free(left);
    free(right);

    return result;
}

int* merge_sort_verbose(int *arr, int n)
{
    return _merge_sort_verbose(arr, n, 0);
}
