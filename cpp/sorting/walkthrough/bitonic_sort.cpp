/*
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
*/

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int _next_power_of_two(int n) {
    return 1 << (32 - __builtin_clz(n - 1));
}

void _compare_and_swap(vector<int>& a, int i, int j, bool ascending, int step) {
    const char* direction = ascending ? "ascending" : "descending";
    cout << "Step " << step << ": compare "
         << a[i] << " and " << a[j]
         << " (" << direction << ")" << endl;

    if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j])) {
        cout << "  swap " << a[i] << " and " << a[j] << endl;
        swap(a[i], a[j]);
        cout << "  result: ";
        for (int value : a) cout << value << " ";
        cout << endl;
    } else {
        cout << "  no swap" << endl;
    }
}

int _bitonic_merge(vector<int>& a, int low, int cnt, bool ascending, int step) {
    if (cnt > 1) {
        int k = cnt / 2;

        for (int i = low; i < low + k; i++) {
            _compare_and_swap(a, i, i + k, ascending, step);
            step += 1;
        }

        step = _bitonic_merge(a, low, k, ascending, step);
        step = _bitonic_merge(a, low + k, k, ascending, step);
    }

    return step;
}

int _bitonic_sort(vector<int>& a, int low, int cnt, bool ascending, int step) {
    if (cnt > 1) {
        int k = cnt / 2;
        const char* direction = ascending ? "ascending" : "descending";

        cout << "\nBuild bitonic sequence from index "
             << low << " count " << cnt
             << " (" << direction << ")" << endl;

        step = _bitonic_sort(a, low, k, true, step);
        step = _bitonic_sort(a, low + k, k, false, step);
        step = _bitonic_merge(a, low, cnt, ascending, step);
    }

    return step;
}

vector<int> bitonic_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int n = (int)a.size();

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int target = _next_power_of_two(n);
    if (target != n) {
        cout << "Note: Bitonic sort works best when length is a power of two." << endl;
        cout << "Padding array from length " << n
             << " to " << target
             << " using infinity." << endl;

        a.resize(target, numeric_limits<int>::max());

        cout << "Working array: ";
        for (int x : a) cout << x << " ";
        cout << endl;
    }

    _bitonic_sort(a, 0, (int)a.size(), true, 1);

    vector<int> result;
    for (int value : a) {
        if (value != numeric_limits<int>::max()) {
            result.push_back(value);
        }
    }

    cout << "\nSorted: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return result;
}
