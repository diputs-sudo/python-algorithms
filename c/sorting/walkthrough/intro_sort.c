/*
IntroSort Algorithm

IntroSort is a hybrid sorting algorithm that combines
Quick Sort, Heap Sort, and Insertion Sort.

How it works:
- It begins with Quick Sort.
- If recursion depth becomes too large, it switches to Heap Sort.
- For small subarrays, it uses Insertion Sort.
- This combination guarantees both speed and worst case safety.

The depth limit is typically set to 2 x log2(n).
If that depth is exceeded, Heap Sort is used to avoid
Quick Sort worst case behavior.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) in this implementation due to extra lists.

Stability:
- Not stable.

Note:
IntroSort is used in many standard library implementations
because it provides fast average performance while also
guaranteeing O(n log n) worst case time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* heap_sort_verbose(int *arr, int n);
int* insertion_sort_verbose(int *arr, int n);
static int* _intro_sort_verbose(int *a, int n, int max_depth, int depth);

int* intro_sort_verbose(int *arr, int n)
{
    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int max_depth = 2 * ((int)log2(n) + 1);

    int *result = _intro_sort_verbose(arr, n, max_depth, 0);

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");

    return result;
}

static int* _intro_sort_verbose(int *a, int n, int max_depth, int depth)
{
    int *result = malloc(sizeof(int) * n);

    char indent[64] = "";
    for (int i = 0; i < depth; i++)
        strcat(indent, "  ");

    printf("%sIntroSort(", indent);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("), max_depth=%d\n", max_depth);

    if (n <= 16)
    {
        printf("%sUse insertion sort for small array\n", indent);
        return insertion_sort_verbose(a, n);
    }

    if (max_depth == 0)
    {
        printf("%sDepth limit reached, switch to heap sort\n", indent);
        return heap_sort_verbose(a, n);
    }

    int pivot = a[n / 2];

    int *left = malloc(sizeof(int) * n);
    int *middle = malloc(sizeof(int) * n);
    int *right = malloc(sizeof(int) * n);

    int l = 0, m = 0, r = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < pivot)
            left[l++] = a[i];
        else if (a[i] == pivot)
            middle[m++] = a[i];
        else
            right[r++] = a[i];
    }

    int *sorted_left = _intro_sort_verbose(left, l, max_depth - 1, depth + 1);
    int *sorted_right = _intro_sort_verbose(right, r, max_depth - 1, depth + 1);

    int pos = 0;

    for (int i = 0; i < l; i++)
        result[pos++] = sorted_left[i];

    for (int i = 0; i < m; i++)
        result[pos++] = middle[i];

    for (int i = 0; i < r; i++)
        result[pos++] = sorted_right[i];

    return result;
}
