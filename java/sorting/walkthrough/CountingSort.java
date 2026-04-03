/*
Counting Sort Algorithm

Counting Sort is a non comparison based sorting algorithm.

How it works:
- It counts how many times each value appears in the input.
- It stores those counts in a separate array.
- It rebuilds the sorted list using the stored frequencies.

This algorithm works best when the range of input values is not very large.

Time Complexity:
- Worst Case: O(n + k)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the range of values.

Space Complexity:
- O(k) due to the counting array.

Stability:
- This basic version is not stable.
- A modified version can be made stable.
*/

import java.util.*;

public class CountingSort {

    public static int[] countingSortVerbose(int[] arr) {

        if (arr == null || arr.length == 0) {
            return new int[0];
        }

        int[] a = Arrays.copyOf(arr, arr.length);
        System.out.println("Start: " + Arrays.toString(a));

        int maxVal = Arrays.stream(a).max().getAsInt();
        System.out.println("Max value: " + maxVal);

        int[] count = new int[maxVal + 1];

        System.out.println("\nCounting occurrences...");
        for (int num : a) {
            count[num]++;
            System.out.println("Count[" + num + "] -> " + count[num]);
        }

        System.out.println("\nCount array: " + Arrays.toString(count));

        List<Integer> resultList = new ArrayList<>();

        System.out.println("\nBuilding sorted array...");
        for (int value = 0; value < count.length; value++) {
            int freq = count[value];

            if (freq > 0) {
                System.out.println("Add " + value + " x " + freq);
            }

            for (int i = 0; i < freq; i++) {
                resultList.add(value);
                System.out.println("  result: " + resultList);
            }
        }

        int[] result = resultList.stream().mapToInt(i -> i).toArray();

        System.out.println("\nSorted: " + Arrays.toString(result));
        return result;
    }

}
