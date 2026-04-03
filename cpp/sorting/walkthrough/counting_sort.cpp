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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> counting_sort_verbose(const vector<int>& arr) {
    if (arr.empty())
        return {};

    vector<int> a = arr;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int max_val = *max_element(a.begin(), a.end());
    cout << "Max value: " << max_val << endl;

    vector<int> count(max_val + 1, 0);

    cout << "\nCounting occurrences..." << endl;
    for (int num : a) {
        count[num] += 1;
        cout << "Count[" << num << "] -> " << count[num] << endl;
    }

    cout << "\nCount array: ";
    for (int c : count) cout << c << " ";
    cout << endl;

    vector<int> result;

    cout << "\nBuilding sorted array..." << endl;
    for (size_t value = 0; value < count.size(); ++value) {
        int freq = count[value];

        if (freq > 0)
            cout << "Add " << value << " x " << freq << endl;

        for (int i = 0; i < freq; ++i) {
            result.push_back(static_cast<int>(value));

            cout << "  result: ";
            for (int x : result) cout << x << " ";
            cout << endl;
        }
    }

    cout << "\nSorted: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return result;
}
