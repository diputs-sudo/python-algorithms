/*
Heap Sort Algorithm

Heap Sort is a comparison based sorting algorithm that uses a binary heap data structure.

How it works:
- It first builds a max heap from the input list.
- The largest element is stored at the root of the heap.
- The root element is swapped with the last element.
- The heap size is reduced and heap property is restored.
- This process repeats until the list is fully sorted.

This approach guarantees consistent performance.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(1) since it sorts in place.

Stability:
- Not stable.
*/

#include <stdio.h>
#include <stdlib.h>

/* Verbose heapify */
void heapify_verbose(int *a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
        printf("Compare parent %d with left child %d\n", a[i], a[left]);

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n)
        printf("Compare current max %d with right child %d\n", a[largest], a[right]);

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        printf("Swap %d and %d\n", a[i], a[largest]);

        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        printf("  result: ");
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");

        heapify_verbose(a, n, largest);
    }
}

int* heap_sort_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("\nBuilding max heap...\n");
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_verbose(a, n, i);

    printf("\nExtracting elements...\n");

    for (int i = n - 1; i > 0; i--)
    {
        printf("Swap max %d with %d\n", a[0], a[i]);

        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        printf("  result: ");
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");

        heapify_verbose(a, i, 0);
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
