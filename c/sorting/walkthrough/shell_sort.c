/*
Shell Sort Algorithm

Shell Sort is an optimization of insertion sort.

How it works:
- It starts by comparing elements that are far apart using a gap value.
- The gap is gradually reduced after each pass.
- Elements are partially sorted at each gap level.
- When the gap becomes 1, the algorithm performs a final insertion sort pass.

This approach moves elements closer to their correct positions early,
which improves performance compared to regular insertion sort.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: depends on the gap sequence and is often around O(n^1.5)
- Best Case: better than O(n^2) depending on input and gap sequence.

Space Complexity:
- O(1) since it sorts in place.

Stability:
- Not stable in general.
*/

#include <stdio.h>
#include <stdlib.h>

int* shell_sort_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);
    int step = 1;

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    int gap = n / 2;

    while (gap > 0)
    {
        printf("\n=== Gap = %d ===\n", gap);

        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;

            printf("\nTake element %d at index %d\n", temp, i);

            while (j >= gap)
            {
                printf("Step %d: compare %d and %d\n", step, a[j - gap], temp);

                if (a[j - gap] > temp)
                {
                    printf("  shift %d from index %d to %d\n", a[j - gap], j - gap, j);

                    a[j] = a[j - gap];

                    printf("  result: ");
                    for (int k = 0; k < n; k++)
                        printf("%d ", a[k]);
                    printf("\n");

                    j -= gap;
                }
                else
                {
                    printf("  no shift needed\n");
                    break;
                }

                step += 1;
            }

            a[j] = temp;

            printf("Insert %d at index %d\n", temp, j);
            printf("  result: ");
            for (int k = 0; k < n; k++)
                printf("%d ", a[k]);
            printf("\n");
        }

        gap /= 2;
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
