/*
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
*/

#include <iostream>
#include <vector>

using namespace std;

int _inplace_merge_verbose(vector<int>& a, int left, int mid, int right, int step) {
    int i = left;
    int j = mid;

    cout << "  Merge a[" << left << ":" << mid << "] = ";
    for (int x = left; x < mid; ++x) cout << a[x] << " ";
    cout << "and a[" << mid << ":" << right << "] = ";
    for (int x = mid; x < right; ++x) cout << a[x] << " ";
    cout << endl;

    while (i < j && j < right) {
        cout << "  Step " << step << ": compare "
             << a[i] << " and " << a[j] << endl;

        if (a[i] <= a[j]) {
            cout << "    already in order, move left pointer" << endl;
            i += 1;
        } else {
            cout << "    " << a[j] << " should come before "
                 << a[i] << endl;

            int value = a[j];
            cout << "    save " << value
                 << " and shift left block to the right" << endl;

            int k = j;
            while (k > i) {
                cout << "      shift " << a[k - 1]
                     << " from index " << k - 1
                     << " to " << k << endl;

                a[k] = a[k - 1];
                k -= 1;
            }

            a[i] = value;

            cout << "    insert " << value
                 << " at index " << i << endl;

            cout << "    result: ";
            for (int x : a) cout << x << " ";
            cout << endl;

            i += 1;
            j += 1;
            mid += 1;
        }

        step += 1;
    }

    return step;
}

int _merge_sort_inplace_verbose(vector<int>& a, int left, int right, int step) {
    if (right - left <= 1)
        return step;

    int mid = (left + right) / 2;

    cout << "\nSort a[" << left << ":" << mid << "] = ";
    for (int x = left; x < mid; ++x) cout << a[x] << " ";
    cout << endl;

    step = _merge_sort_inplace_verbose(a, left, mid, step);

    cout << "\nSort a[" << mid << ":" << right << "] = ";
    for (int x = mid; x < right; ++x) cout << a[x] << " ";
    cout << endl;

    step = _merge_sort_inplace_verbose(a, mid, right, step);

    cout << "\nMerging ranges ["
         << left << ":" << mid << "] and ["
         << mid << ":" << right << "]" << endl;

    step = _inplace_merge_verbose(a, left, mid, right, step);

    return step;
}

vector<int> merge_sort_inplace_verbose(const vector<int>& arr) {
    vector<int> a = arr;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int step = 1;
    step = _merge_sort_inplace_verbose(a, 0, a.size(), step);

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}
