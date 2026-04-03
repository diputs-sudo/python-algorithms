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

import java.util.Arrays;

public class BubbleSort {

    public static void bubbleSortVerbose(int[] arr) {
        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;
        int step = 1;

        System.out.println("Start: " + Arrays.toString(a));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                System.out.println("Step " + step + ": compare "
                        + a[j] + " and " + a[j+1]);

                if (a[j] > a[j + 1]) {
                    System.out.println("  swap " + a[j]
                            + " and " + a[j+1]);

                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;

                    System.out.println("  result: "
                            + Arrays.toString(a));
                } else {
                    System.out.println("  no swap");
                }
                step++;
            }
        }

        System.out.println("Sorted: " + Arrays.toString(a));
    }

}
