"""
Radix Sort Algorithm

Radix Sort is a non comparison based sorting algorithm.

How it works:
- It processes numbers digit by digit.
- It groups numbers based on the current digit.
- It starts from the least significant digit.
- It moves toward the most significant digit.
- After processing all digits, the list becomes sorted.

This version uses base 10 buckets and works for non negative integers.

Time Complexity:
- Worst Case: O(d x (n + k))
- Average Case: O(d x (n + k))
- Best Case: O(d x (n + k))

Here n is the number of elements, d is the number of digits,
and k is the range of each digit which is 0 to 9 in base 10.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Stable when bucket collection preserves order.
"""


def radix_sort_verbose(arr):
    a = arr[:]
    print("Start:", a)

    max_num = max(a)
    exp = 1

    while max_num // exp > 0:
        print(f"\nSorting by digit at exp = {exp}")
        buckets = [[] for _ in range(10)]

        for num in a:
            digit = (num // exp) % 10
            print(f"Put {num} in bucket {digit}")
            buckets[digit].append(num)

        a = []
        for i, bucket in enumerate(buckets):
            if bucket:
                print(f"Bucket {i} -> {bucket}")
            a.extend(bucket)

        print("After collecting:", a)
        exp *= 10

    print("\nSorted:", a)
    return a


def radix_sort(arr):
    a = arr[:]
    if not a:
        return a

    max_num = max(a)
    exp = 1

    while max_num // exp > 0:
        buckets = [[] for _ in range(10)]
        for num in a:
            digit = (num // exp) % 10
            buckets[digit].append(num)

        a = []
        for bucket in buckets:
            a.extend(bucket)

        exp *= 10

    return a