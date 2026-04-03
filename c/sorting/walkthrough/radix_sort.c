/*
Radix Sort Algorithm

Radix Sort is a non comparison based sorting algorithm.

How it works:
- It processes numbers digit by digit.
- It groups numbers based on the current digit.
- It starts from the least significant digit.
- It moves toward the most significant digit.
- After processing all digits, the list becomes sorted.

This version uses base 10 buckets and works for non negative integers.

Time Complexity:
- Worst Case: O(d x (n + k))
- Average Case: O(d x (n + k))
- Best Case: O(d x (n + k))

Here n is the number of elements, d is the number of digits,
and k is the range of each digit which is 0 to 9 in base 10.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Stable when bucket collection preserves order.
*/

#include <stdio.h>
#include <stdlib.h>

int* radix_sort_verbose(int *arr, int n)
{
    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    printf("Start: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    if (n == 0)
        return a;

    int max_num = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max_num)
            max_num = a[i];

    int exp = 1;

    while (max_num / exp > 0)
    {
        printf("\nSorting by digit at exp = %d\n", exp);

        int buckets[10][n];
        int sizes[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int digit = (a[i] / exp) % 10;
            printf("Put %d in bucket %d\n", a[i], digit);
            buckets[digit][sizes[digit]++] = a[i];
        }

        int pos = 0;

        for (int i = 0; i < 10; i++)
        {
            if (sizes[i] > 0)
            {
                printf("Bucket %d -> ", i);
                for (int j = 0; j < sizes[i]; j++)
                    printf("%d ", buckets[i][j]);
                printf("\n");
            }

            for (int j = 0; j < sizes[i]; j++)
                a[pos++] = buckets[i][j];
        }

        printf("After collecting: ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        exp *= 10;
    }

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return a;
}
