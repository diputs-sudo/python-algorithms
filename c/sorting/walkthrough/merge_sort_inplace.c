/*
Merge Sort with In Place Stable Merge Algorithm

This version of merge sort performs merging without using
an additional temporary array.

How it works:
- The array is recursively divided into two halves.
- Each half is sorted recursively.
- The two halves are merged in place.
- When an element from the right half is smaller,
  elements in the left half are shifted to make space.
- This preserves stability while avoiding extra merge storage.

This implementation is educational and focuses on clarity
rather than performance.

Time Complexity:
- Worst Case: O(n^2) due to repeated shifting during in place merge.
- Average Case: O(n^2)
- Best Case: O(n log n) when minimal shifting occurs.

Space Complexity:
- O(1) extra space for merging.
- O(log n) recursion stack space.

Stability:
- Stable because equal elements maintain relative order.
*/

#include <stdio.h>
#include <stdlib.h>

static int _inplace_merge_verbose(int *a, int left, int mid, int right, int step, int n)
{
    int i = left;
    int j = mid;

    printf("  Merge a[%d:%d] = ", left, mid);
    for (int x = left; x < mid; x++)
        printf("%d ", a[x]);
    printf("and a[%d:%d] = ", mid, right);
    for (int x = mid; x < right; x++)
        printf("%d ", a[x]);
    printf("\n");

    while (i < j && j < right)
    {
        printf("  Step %d: compare %d and %d\n", step, a[i], a[j]);

        if (a[i] <= a[j])
        {
            printf("    already in order, move left pointer\n");
            i += 1;
        }
        else
        {
            int value = a[j];
            int k = j;

            printf("    %d should come before %d\n", a[j], a[i]);
            printf("    save %d and shift left block to the right\n", value);

            while (k > i)
            {
                printf("      shift %d from index %d to %d\n", a[k - 1], k - 1, k);
                a[k] = a[k - 1];
                k -= 1;
            }

            a[i] = value;

            printf("    insert %d at index %d\n", value, i);
            printf("    result: ");
            for (int x = 0; x < n; x++)
                printf("%d ", a[x]);
            printf("\n");

            i += 1;
            j += 1;
            mid += 1;
        }

        step += 1;
    }

    return step;
}

static int _merge_sort_inplace_verbose(int *a, int left, int right, int step, int n)
{
    if (right - left <= 1)
        return step;

    int mid = (left + right) / 2;

    printf("\nSort a[%d:%d] = ", left, mid);
    for (int x = left; x < mid; x++)
        printf("%d ", a[x]);
    printf("\n");

    step = _merge_sort_inplace_verbose(a, left, mid, step, n);

    printf("\nSort a[%d:%d] = ", mid, right);
    for (int x = mid; x < right; x++)
        printf("%d ", a[x]);
    printf("\n");

    step = _merge_sort_inplace_verbose(a, mid, right, step, n);

    printf("\nMerging ranges [%d:%d] and [%d:%d]\n", left, mid, mid, right);
    step = _inplace_merge_verbose(a, left, mid, right, step, n);

    return step;
}

int* merge_sort_inplace_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    _merge_sort_inplace_verbose(a, 0, n, 1, n);

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
