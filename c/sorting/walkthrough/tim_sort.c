/*
TimSort Algorithm

TimSort is a hybrid sorting algorithm used in Python, Java, and many
other programming languages.

It combines ideas from insertion sort and merge sort.

How it works:
- The array is divided into small sections called runs.
- Each run is sorted using insertion sort.
- The sorted runs are merged together.
- Runs are merged repeatedly until the entire array is sorted.

This approach performs very well on real world data because
many datasets already contain partially sorted sequences.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n) when the data is nearly sorted.

Space Complexity:
- O(n) due to merging operations.

Stability:
- Stable because merging preserves order of equal elements.

Note:
This is a simplified educational version.
The industrial implementation used in Python includes
additional optimizations such as natural run detection,
stack invariants, and galloping mode.
*/

#include <stdio.h>
#include <stdlib.h>

int* insertion_sort_verbose(int *arr, int n);

const int MIN_RUN = 5;

static int _merge_verbose(int *left, int left_size, int *right, int right_size, int step_start, int *out)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int step = step_start;

    printf("  Merging ");
    for (int x = 0; x < left_size; x++)
        printf("%d ", left[x]);
    printf("and ");
    for (int x = 0; x < right_size; x++)
        printf("%d ", right[x]);
    printf("\n");

    while (i < left_size && j < right_size)
    {
        printf("  Step %d: compare %d and %d\n", step, left[i], right[j]);

        if (left[i] <= right[j])
        {
            printf("    take %d from left\n", left[i]);
            out[k++] = left[i++];
        }
        else
        {
            printf("    take %d from right\n", right[j]);
            out[k++] = right[j++];
        }

        printf("    result so far: ");
        for (int x = 0; x < k; x++)
            printf("%d ", out[x]);
        printf("\n");

        step += 1;
    }

    if (i < left_size)
    {
        printf("  Append remaining from left: ");
        for (int x = i; x < left_size; x++)
            printf("%d ", left[x]);
        printf("\n");
    }

    if (j < right_size)
    {
        printf("  Append remaining from right: ");
        for (int x = j; x < right_size; x++)
            printf("%d ", right[x]);
        printf("\n");
    }

    while (i < left_size)
        out[k++] = left[i++];

    while (j < right_size)
        out[k++] = right[j++];

    printf("  Merged result: ");
    for (int x = 0; x < left_size + right_size; x++)
        printf("%d ", out[x]);
    printf("\n");

    return step;
}

int* tim_sort_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("MIN_RUN = %d\n", MIN_RUN);
    printf("\n=== Phase 1: Sort runs with insertion sort ===\n");

    for (int start = 0; start < n; start += MIN_RUN)
    {
        int end = start + MIN_RUN;
        if (end > n)
            end = n;

        printf("\nRun from index %d to %d: ", start, end - 1);
        for (int i = start; i < end; i++)
            printf("%d ", a[i]);
        printf("\n");

        int run_size = end - start;
        int *sorted_run = insertion_sort_verbose(a + start, run_size);

        for (int i = 0; i < run_size; i++)
            a[start + i] = sorted_run[i];

        free(sorted_run);

        printf("Array after sorting this run: ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    printf("\n=== Phase 2: Merge runs ===\n");

    int size = MIN_RUN;
    int step = 1;

    while (size < n)
    {
        printf("\n--- Merge size = %d ---\n", size);

        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size;
            int right = left + 2 * size;

            if (mid > n)
                mid = n;
            if (right > n)
                right = n;

            printf("\nMerging slices a[%d:%d] and a[%d:%d]\n", left, mid, mid, right);

            int left_size = mid - left;
            int right_size = right - mid;
            int *left_part = malloc(sizeof(int) * left_size);
            int *right_part = malloc(sizeof(int) * right_size);
            int *merged = malloc(sizeof(int) * (left_size + right_size));

            for (int i = 0; i < left_size; i++)
                left_part[i] = a[left + i];
            for (int i = 0; i < right_size; i++)
                right_part[i] = a[mid + i];

            step = _merge_verbose(left_part, left_size, right_part, right_size, step, merged);

            for (int i = 0; i < left_size + right_size; i++)
                a[left + i] = merged[i];

            printf("Array after merge: ");
            for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");

            free(left_part);
            free(right_part);
            free(merged);
        }

        size *= 2;
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
