/*
Bitonic Sort Algorithm

Bitonic Sort is a comparison based sorting algorithm commonly used in
parallel computing environments.

How it works:
- It recursively builds bitonic sequences.
- A bitonic sequence first increases and then decreases.
- These sequences are merged using compare and swap operations.
- Repeated merging produces a fully sorted sequence.

Classic Bitonic Sort assumes the input size is a power of two.

This educational implementation:
- Automatically pads the list to the next power of two using infinity.
- Removes the padding after sorting.
- Supports a verbose mode for visualization.

Time Complexity:
- Worst Case: O(n log^2 n)
- Average Case: O(n log^2 n)
- Best Case: O(n log^2 n)

Space Complexity:
- O(n) due to padding and recursive structure.

Stability:
- Not stable.
*/

import java.util.*;

public class BitonicSort {

    private static int nextPowerOfTwo(int n) {
        return 1 << (32 - Integer.numberOfLeadingZeros(n - 1));
    }

    private static void compareAndSwap(
            int[] a,
            int i,
            int j,
            boolean ascending,
            boolean verbose,
            int step
    ) {

        if (verbose) {
            String direction = ascending ? "ascending" : "descending";
            System.out.println("Step " + step + ": compare "
                    + a[i] + " and " + a[j]
                    + " (" + direction + ")");
        }

        if ((ascending && a[i] > a[j]) ||
            (!ascending && a[i] < a[j])) {

            if (verbose) {
                System.out.println("  swap " + a[i] + " and " + a[j]);
            }

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            if (verbose) {
                System.out.println("  result: "
                        + Arrays.toString(a));
            }
        } else {
            if (verbose) {
                System.out.println("  no swap");
            }
        }
    }

    private static int bitonicMerge(
            int[] a,
            int low,
            int cnt,
            boolean ascending,
            boolean verbose,
            int step
    ) {

        if (cnt > 1) {
            int k = cnt / 2;

            for (int i = low; i < low + k; i++) {
                compareAndSwap(a, i, i + k, ascending, verbose, step);
                step++;
            }

            step = bitonicMerge(a, low, k, ascending, verbose, step);
            step = bitonicMerge(a, low + k, k, ascending, verbose, step);
        }

        return step;
    }

    private static int bitonicSortRecursive(
            int[] a,
            int low,
            int cnt,
            boolean ascending,
            boolean verbose,
            int step
    ) {

        if (cnt > 1) {
            int k = cnt / 2;

            if (verbose) {
                String direction = ascending ? "ascending" : "descending";
                System.out.println("\nBuild bitonic sequence from index "
                        + low + " count " + cnt
                        + " (" + direction + ")");
            }

            step = bitonicSortRecursive(a, low, k, true, verbose, step);
            step = bitonicSortRecursive(a, low + k, k, false, verbose, step);
            step = bitonicMerge(a, low, cnt, ascending, verbose, step);
        }

        return step;
    }

    public static int[] bitonicSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        System.out.println("Start: " + Arrays.toString(a));

        int target = nextPowerOfTwo(n);

        if (target != n) {
            System.out.println("Note: Bitonic sort works best when length is a power of two.");
            System.out.println("Padding array from length "
                    + n + " to " + target
                    + " using infinity.");

            a = Arrays.copyOf(a, target);

            for (int i = n; i < target; i++) {
                a[i] = Integer.MAX_VALUE;
            }

            System.out.println("Working array: "
                    + Arrays.toString(a));
        }

        bitonicSortRecursive(a, 0, a.length, true, true, 1);

        List<Integer> cleaned = new ArrayList<>();
        for (int value : a) {
            if (value != Integer.MAX_VALUE) {
                cleaned.add(value);
            }
        }

        int[] result = cleaned.stream().mapToInt(x -> x).toArray();

        System.out.println("\nSorted: "
                + Arrays.toString(result));

        return result;
    }

}
