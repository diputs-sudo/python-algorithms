/*
Bubble Sort Algorithm

Bubble Sort is a simple comparison-based sorting algorithm.

How it works:
- It repeatedly steps through the list.
- Compares adjacent elements.
- Swaps them if they are in the wrong order.
- After each full pass, the largest unsorted element
  "bubbles up" to its correct position at the end.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n^2) (without optimization)
*/

#include <iostream>
#include <vector>
using namespace std;

void print_array(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> bubble_sort_verbose(vector<int> arr) {
    int n = arr.size();
    int step = 1;

    cout << "Start: ";
    print_array(arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Step " << step << ": compare "
                 << arr[j] << " and " << arr[j+1] << endl;

            if (arr[j] > arr[j + 1]) {
                cout << "  swap " << arr[j] << " and "
                     << arr[j+1] << endl;

                swap(arr[j], arr[j + 1]);

                cout << "  result: ";
                print_array(arr);
            } else {
                cout << "  no swap" << endl;
            }
            step++;
        }
    }

    cout << "Sorted: ";
    print_array(arr);
    return arr;
}

vector<int> bubble_sort(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}