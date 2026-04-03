/*
Bucket Sort Algorithm

Bucket Sort is a distribution based sorting algorithm.

How it works:
- It divides elements into several groups called buckets.
- Each bucket holds values within a specific range.
- Elements are distributed into buckets based on their value.
- Each bucket is sorted individually.
- All buckets are combined to produce the final sorted list.

This algorithm performs well when the input values are evenly distributed.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the number of buckets.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Depends on the sorting method used inside each bucket.
*/

import java.util.*;

public class BucketSort {

    public static int[] bucketSortVerbose(int[] arr, int bucketSize) {

        if (arr == null || arr.length == 0) {
            return new int[0];
        }

        int[] a = Arrays.copyOf(arr, arr.length);
        System.out.println("Start: " + Arrays.toString(a));

        int minVal = Arrays.stream(a).min().getAsInt();
        int maxVal = Arrays.stream(a).max().getAsInt();

        System.out.println("Min: " + minVal + " Max: " + maxVal);

        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        List<List<Integer>> buckets = new ArrayList<>();
        for (int i = 0; i < bucketCount; i++) {
            buckets.add(new ArrayList<>());
        }

        System.out.println("\nCreated " + bucketCount + " buckets");

        System.out.println("\nDistributing into buckets...");
        for (int num : a) {
            int index = (num - minVal) / bucketSize;
            System.out.println("Put " + num + " into bucket " + index);
            buckets.get(index).add(num);
        }

        System.out.println("\nBuckets before sorting:");
        for (int i = 0; i < buckets.size(); i++) {
            System.out.println("Bucket " + i + ": " + buckets.get(i));
        }

        System.out.println("\nSorting each bucket and collecting...");
        List<Integer> resultList = new ArrayList<>();

        for (int i = 0; i < buckets.size(); i++) {
            List<Integer> bucket = buckets.get(i);

            System.out.println("Sort bucket " + i + ": " + bucket);

            Collections.sort(bucket);

            System.out.println("  sorted bucket " + i + ": " + bucket);

            for (int num : bucket) {
                resultList.add(num);
                System.out.println("  result: " + resultList);
            }
        }

        int[] result = resultList.stream().mapToInt(i -> i).toArray();

        System.out.println("\nSorted: " + Arrays.toString(result));
        return result;
    }

}
