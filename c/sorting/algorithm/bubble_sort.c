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

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void bubble_sort_verbose(int arr[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = arr[i];

    int step = 1;

    printf("Start: ");
    print_array(a, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("Step %d: compare %d and %d\n", step, a[j], a[j+1]);
            if (a[j] > a[j + 1]) {
                printf("  swap %d and %d\n", a[j], a[j+1]);
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                printf("  result: ");
                print_array(a, n);
            } else {
                printf("  no swap\n");
            }
            step++;
        }
    }

    printf("Sorted: ");
    print_array(a, n);
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}