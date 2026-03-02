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

import java.util.*;

public class IntroSort {

    public static int[] introSortVerbose(int[] arr) {
        System.out.println("Start: " + Arrays.toString(arr));

        int maxDepth = 2 * (32 - Integer.numberOfLeadingZeros(arr.length));
        int[] result = introSortVerboseRecursive(
                Arrays.copyOf(arr, arr.length),
                maxDepth,
                0
        );

        System.out.println("\nSorted: " + Arrays.toString(result));
        return result;
    }

    private static int[] introSortVerboseRecursive(
            int[] a,
            int maxDepth,
            int depth
    ) {

        String indent = new String(new char[depth]).replace("\0", "  ");
        System.out.println(indent + "IntroSort("
                + Arrays.toString(a)
                + "), max_depth=" + maxDepth);

        if (a.length <= 16) {
            System.out.println(indent + "Use insertion sort for small array");
            return InsertionSort.insertionSort(a);
        }

        if (maxDepth == 0) {
            System.out.println(indent + "Depth limit reached, switch to heap sort");
            return HeapSort.heapSort(a);
        }

        int pivot = a[a.length / 2];

        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for (int value : a) {
            if (value < pivot) {
                left.add(value);
            } else if (value == pivot) {
                middle.add(value);
            } else {
                right.add(value);
            }
        }

        int[] leftSorted = introSortVerboseRecursive(
                left.stream().mapToInt(i -> i).toArray(),
                maxDepth - 1,
                depth + 1
        );

        int[] rightSorted = introSortVerboseRecursive(
                right.stream().mapToInt(i -> i).toArray(),
                maxDepth - 1,
                depth + 1
        );

        return concatenate(leftSorted,
                middle.stream().mapToInt(i -> i).toArray(),
                rightSorted);
    }

    public static int[] introSort(int[] arr) {
        int maxDepth = 2 * (32 - Integer.numberOfLeadingZeros(arr.length));
        return introSortRecursive(
                Arrays.copyOf(arr, arr.length),
                maxDepth
        );
    }

    private static int[] introSortRecursive(int[] a, int maxDepth) {

        if (a.length <= 16) {
            return InsertionSort.insertionSort(a);
        }

        if (maxDepth == 0) {
            return HeapSort.heapSort(a);
        }

        int pivot = a[a.length / 2];

        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for (int value : a) {
            if (value < pivot) {
                left.add(value);
            } else if (value == pivot) {
                middle.add(value);
            } else {
                right.add(value);
            }
        }

        return concatenate(
                introSortRecursive(left.stream().mapToInt(i -> i).toArray(), maxDepth - 1),
                middle.stream().mapToInt(i -> i).toArray(),
                introSortRecursive(right.stream().mapToInt(i -> i).toArray(), maxDepth - 1)
        );
    }

    private static int[] concatenate(int[] left, int[] middle, int[] right) {

        int[] result = new int[left.length + middle.length + right.length];

        int index = 0;

        for (int value : left) {
            result[index++] = value;
        }

        for (int value : middle) {
            result[index++] = value;
        }

        for (int value : right) {
            result[index++] = value;
        }

        return result;
    }
}