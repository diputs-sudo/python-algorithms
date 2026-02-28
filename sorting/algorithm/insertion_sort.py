"""
Insertion Sort Algorithm

Insertion Sort is a simple comparison based sorting algorithm.

How it works:
- It builds the sorted list one element at a time.
- It takes the next element and compares it with elements before it.
- Larger elements are shifted to the right.
- The current element is inserted into its correct position.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n) when the list is already sorted.

Space complexity:
- O(1) since it sorts in place.
"""

def insertion_sort_verbose(arr):
    a = arr[:] 
    step = 1

    print("Start:", a)

    for i in range(1, len(a)):
        key = a[i]
        j = i - 1

        print(f"\nTake element {key} at index {i}")

        while j >= 0 and a[j] > key:
            print(f"Step {step}: compare {a[j]} and {key} -> shift {a[j]} right")
            a[j + 1] = a[j]
            print("  result:", a)
            j -= 1
            step += 1

        a[j + 1] = key
        print(f"Insert {key} at position {j+1}")
        print("  result:", a)

    print("\nSorted:", a)
    return a


def insertion_sort(arr):
    a = arr[:]  

    for i in range(1, len(a)):
        key = a[i]
        j = i - 1

        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1

        a[j + 1] = key

    return a