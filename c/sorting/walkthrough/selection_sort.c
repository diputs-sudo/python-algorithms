/*
Selection Sort Algorithm

Selection Sort is a simple comparison based sorting algorithm.

How it works:
- It divides the list into a sorted portion and an unsorted portion.
- It repeatedly finds the smallest element from the unsorted portion.
- It swaps that element with the first unsorted position.
- The sorted portion grows one element at a time from the beginning.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n^2)

Space Complexity:
- O(1) since it sorts in place.
*/

#include <stdio.h>
#include <stdlib.h>

int* selection_sort_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);
    int step = 1;

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        int min_idx = i;

        printf("\nSelect position %d\n", i);

        for (int j = i + 1; j < n; j++)
        {
            printf("Step %d: compare %d and %d\n", step, a[j], a[min_idx]);

            if (a[j] < a[min_idx])
            {
                min_idx = j;
                printf("  new min is %d at index %d\n", a[min_idx], min_idx);
            }

            step += 1;
        }

        if (min_idx != i)
        {
            printf("Swap %d and %d\n", a[i], a[min_idx]);

            int temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;

            printf("  result: ");
            for (int j = 0; j < n; j++)
                printf("%d ", a[j]);
            printf("\n");
        }
        else
        {
            printf("No swap needed\n");
        }
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
