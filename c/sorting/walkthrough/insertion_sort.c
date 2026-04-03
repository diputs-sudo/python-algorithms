/*
Insertion Sort Algorithm

Insertion Sort is a simple comparison based sorting algorithm.

How it works:
- It builds the sorted list one element at a time.
- It takes the next element and compares it with elements before it.
- Larger elements are shifted to the right.
- The current element is inserted into its correct position.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n) when the list is already sorted.

Space complexity:
- O(1) since it sorts in place.
*/

#include <stdio.h>
#include <stdlib.h>

int* insertion_sort_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);
    int step = 1;

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        printf("\nTake element %d at index %d\n", key, i);

        while (j >= 0 && a[j] > key)
        {
            printf("Step %d: compare %d and %d -> shift %d right\n", step, a[j], key, a[j]);

            a[j + 1] = a[j];

            printf("  result: ");
            for (int k = 0; k < n; k++)
                printf("%d ", a[k]);
            printf("\n");

            j -= 1;
            step += 1;
        }

        a[j + 1] = key;

        printf("Insert %d at position %d\n", key, j + 1);

        printf("  result: ");
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
