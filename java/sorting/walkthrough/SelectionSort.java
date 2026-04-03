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

import java.util.Arrays;

public class SelectionSort {

    public static int[] selectionSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;
        int step = 1;

        System.out.println("Start: " + Arrays.toString(a));

        for (int i = 0; i < n; i++) {

            int minIdx = i;
            System.out.println("\nSelect position " + i);

            for (int j = i + 1; j < n; j++) {

                System.out.println("Step " + step + ": compare "
                        + a[j] + " and " + a[minIdx]);

                if (a[j] < a[minIdx]) {
                    minIdx = j;
                    System.out.println("  new min is "
                            + a[minIdx] + " at index " + minIdx);
                }

                step++;
            }

            if (minIdx != i) {

                System.out.println("Swap " + a[i]
                        + " and " + a[minIdx]);

                int temp = a[i];
                a[i] = a[minIdx];
                a[minIdx] = temp;

                System.out.println("  result: "
                        + Arrays.toString(a));

            } else {
                System.out.println("No swap needed");
            }
        }

        System.out.println("\nSorted: " + Arrays.toString(a));
        return a;
    }

}
