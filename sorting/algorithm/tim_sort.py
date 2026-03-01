"""
TimSort Algorithm

TimSort is a hybrid sorting algorithm used in Python, Java, and many
other programming languages.

It combines ideas from insertion sort and merge sort.

How it works:
- The array is divided into small sections called runs.
- Each run is sorted using insertion sort.
- The sorted runs are merged together.
- Runs are merged repeatedly until the entire array is sorted.

This approach performs very well on real world data because
many datasets already contain partially sorted sequences.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n) when the data is nearly sorted.

Space Complexity:
- O(n) due to merging operations.

Stability:
- Stable because merging preserves order of equal elements.

Note:
This is a simplified educational version.
The industrial implementation used in Python includes
additional optimizations such as natural run detection,
stack invariants, and galloping mode.
"""


from algorithm.insertion_sort import insertion_sort, insertion_sort_verbose

MIN_RUN = 5


def _merge_verbose(left, right, step_start=1):
    result = []
    i = j = 0
    step = step_start

    print(f"  Merging {left} and {right}")

    while i < len(left) and j < len(right):
        print(f"  Step {step}: compare {left[i]} and {right[j]}")
        if left[i] <= right[j]:
            print(f"    take {left[i]} from left")
            result.append(left[i])
            i += 1
        else:
            print(f"    take {right[j]} from right")
            result.append(right[j])
            j += 1
        print("    result so far:", result)
        step += 1

    if i < len(left):
        print(f"  Append remaining from left: {left[i:]}")
    if j < len(right):
        print(f"  Append remaining from right: {right[j:]}")

    result.extend(left[i:])
    result.extend(right[j:])

    print("  Merged result:", result)
    return result, step


def tim_sort_verbose(arr):
    a = arr[:]
    n = len(a)

    print("Start:", a)
    print(f"MIN_RUN = {MIN_RUN}")

    print("\n=== Phase 1: Sort runs with insertion sort ===")
    for start in range(0, n, MIN_RUN):
        end = min(start + MIN_RUN, n)
        print(f"\nRun from index {start} to {end - 1}: {a[start:end]}")
        sorted_run = insertion_sort_verbose(a[start:end])
        a[start:end] = sorted_run
        print("Array after sorting this run:", a)

    print("\n=== Phase 2: Merge runs ===")
    size = MIN_RUN
    step = 1

    while size < n:
        print(f"\n--- Merge size = {size} ---")
        for left in range(0, n, 2 * size):
            mid = min(left + size, n)
            right = min(left + 2 * size, n)

            left_part = a[left:mid]
            right_part = a[mid:right]

            print(f"\nMerging slices a[{left}:{mid}] and a[{mid}:{right}]")
            merged, step = _merge_verbose(left_part, right_part, step)
            a[left:right] = merged
            print("Array after merge:", a)

        size *= 2

    print("\nSorted:", a)
    return a


def _merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result


def tim_sort(arr):
    a = arr[:]
    n = len(a)

    for start in range(0, n, MIN_RUN):
        end = min(start + MIN_RUN, n)
        a[start:end] = insertion_sort(a[start:end])

    size = MIN_RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(left + size, n)
            right = min(left + 2 * size, n)

            a[left:right] = _merge(a[left:mid], a[mid:right])

        size *= 2

    return a