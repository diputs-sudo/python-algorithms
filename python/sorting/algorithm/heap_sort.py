"""
Heap Sort Algorithm

Heap Sort is a comparison based sorting algorithm that uses a binary heap data structure.

How it works:
- It first builds a max heap from the input list.
- The largest element is stored at the root of the heap.
- The root element is swapped with the last element.
- The heap size is reduced and heap property is restored.
- This process repeats until the list is fully sorted.

This approach guarantees consistent performance.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(1) since it sorts in place.

Stability:
- Not stable.
"""


def heap_sort_verbose(arr):
    a = arr[:]
    n = len(a)

    print("Start:", a)

    def heapify(n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n:
            print(f"Compare parent {a[i]} with left child {a[left]}")
        if left < n and a[left] > a[largest]:
            largest = left

        if right < n:
            print(f"Compare current max {a[largest]} with right child {a[right]}")
        if right < n and a[right] > a[largest]:
            largest = right

        if largest != i:
            print(f"Swap {a[i]} and {a[largest]}")
            a[i], a[largest] = a[largest], a[i]
            print("  result:", a)
            heapify(n, largest)

    print("\nBuilding max heap...")
    for i in range(n // 2 - 1, -1, -1):
        heapify(n, i)

    print("\nExtracting elements...")
    for i in range(n - 1, 0, -1):
        print(f"Swap max {a[0]} with {a[i]}")
        a[0], a[i] = a[i], a[0]
        print("  result:", a)
        heapify(i, 0)

    print("\nSorted:", a)
    return a


def heap_sort(arr):
    a = arr[:]
    n = len(a)

    def heapify(n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and a[left] > a[largest]:
            largest = left
        if right < n and a[right] > a[largest]:
            largest = right

        if largest != i:
            a[i], a[largest] = a[largest], a[i]
            heapify(n, largest)

    for i in range(n // 2 - 1, -1, -1):
        heapify(n, i)

    for i in range(n - 1, 0, -1):
        a[0], a[i] = a[i], a[0]
        heapify(i, 0)

    return a