/*
Bubble Sort Algorithm

Bubble Sort is a simple comparison-based sorting algorithm.

How it works:
- It repeatedly steps through the list.
- Compares adjacent elements.
- Swaps them if they are in the wrong order.
- After each full pass, the largest unsorted element
  "bubbles up" to its correct position at the end.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n^2) (without optimization)
*/

#include <stdio.h>
#include <stdlib.h>

double* bubble_sort_verbose(double *arr, int n)
{
    double *a = malloc(sizeof(double) * n);
    int step = 1;

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf("Step %d: compare %f and %f\n", step, a[j], a[j+1]);

            if (a[j] > a[j + 1])
            {
                printf("  swap %f and %f\n", a[j], a[j+1]);

                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                printf("  result: ");
                for (int k = 0; k < n; k++)
                    printf("%f ", a[k]);
                printf("\n");
            }
            else
            {
                printf("  no swap\n");
            }

            step += 1;
        }
    }

    printf("Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");

    return a;
}
