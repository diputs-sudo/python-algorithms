"""
Merge Sort with In Place Stable Merge Algorithm

This version of merge sort performs merging without using
an additional temporary array.

How it works:
- The array is recursively divided into two halves.
- Each half is sorted recursively.
- The two halves are merged in place.
- When an element from the right half is smaller,
  elements in the left half are shifted to make space.
- This preserves stability while avoiding extra merge storage.

This implementation is educational and focuses on clarity
rather than performance.

Time Complexity:
- Worst Case: O(n^2) due to repeated shifting during in place merge.
- Average Case: O(n^2)
- Best Case: O(n log n) when minimal shifting occurs.

Space Complexity:
- O(1) extra space for merging.
- O(log n) recursion stack space.

Stability:
- Stable because equal elements maintain relative order.
"""


def _inplace_merge_verbose(a, left, mid, right, step):
    i = left
    j = mid

    print(f"  Merge a[{left}:{mid}] = {a[left:mid]} and a[{mid}:{right}] = {a[mid:right]}")

    while i < j and j < right:
        print(f"  Step {step}: compare {a[i]} and {a[j]}")

        if a[i] <= a[j]:
            print("    already in order, move left pointer")
            i += 1
        else:
            print(f"    {a[j]} should come before {a[i]}")
            value = a[j]
            print(f"    save {value} and shift left block to the right")

            k = j
            while k > i:
                print(f"      shift {a[k - 1]} from index {k - 1} to {k}")
                a[k] = a[k - 1]
                k -= 1

            a[i] = value
            print(f"    insert {value} at index {i}")
            print("    result:", a)

            i += 1
            j += 1
            mid += 1

        step += 1

    return step


def _merge_sort_inplace_verbose(a, left, right, step):
    if right - left <= 1:
        return step

    mid = (left + right) // 2

    print(f"\nSort a[{left}:{mid}] = {a[left:mid]}")
    step = _merge_sort_inplace_verbose(a, left, mid, step)

    print(f"\nSort a[{mid}:{right}] = {a[mid:right]}")
    step = _merge_sort_inplace_verbose(a, mid, right, step)

    print(f"\nMerging ranges [{left}:{mid}] and [{mid}:{right}]")
    return _inplace_merge_verbose(a, left, mid, right, step)


def merge_sort_inplace_verbose(arr):
    a = arr[:]
    print("Start:", a)

    _merge_sort_inplace_verbose(a, 0, len(a), 1)

    print("\nSorted:", a)
    return a
