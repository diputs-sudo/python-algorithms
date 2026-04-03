"""
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
"""


def _next_power_of_two(n):
    return 1 << (n - 1).bit_length()


def _compare_and_swap(a, i, j, ascending, step):
    direction = "ascending" if ascending else "descending"
    print(f"Step {step}: compare {a[i]} and {a[j]} ({direction})")

    if (ascending and a[i] > a[j]) or (not ascending and a[i] < a[j]):
        print(f"  swap {a[i]} and {a[j]}")
        a[i], a[j] = a[j], a[i]
        print("  result:", a)
    else:
        print("  no swap")


def _bitonic_merge(a, low, count, ascending, step):
    if count > 1:
        half = count // 2
        for i in range(low, low + half):
            _compare_and_swap(a, i, i + half, ascending, step)
            step += 1

        step = _bitonic_merge(a, low, half, ascending, step)
        step = _bitonic_merge(a, low + half, half, ascending, step)

    return step


def _bitonic_sort(a, low, count, ascending, step):
    if count > 1:
        half = count // 2
        direction = "ascending" if ascending else "descending"
        print(f"\nBuild bitonic sequence from index {low} count {count} ({direction})")

        step = _bitonic_sort(a, low, half, True, step)
        step = _bitonic_sort(a, low + half, half, False, step)
        step = _bitonic_merge(a, low, count, ascending, step)

    return step


def bitonic_sort_verbose(arr):
    a = arr[:]
    n = len(a)

    print("Start:", a)

    target = _next_power_of_two(n)
    if target != n:
        print("Note: Bitonic sort works best when length is a power of two.")
        print(f"Padding array from length {n} to {target} using infinity.")
        a.extend([float("inf")] * (target - n))
        print("Working array:", a)

    _bitonic_sort(a, 0, len(a), True, 1)
    a = [x for x in a if x != float("inf")]

    print("\nSorted:", a)
    return a
