/*
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
*/

#include <iostream>
#include <vector>

using namespace std;


vector<int> heap_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    // heapify function
    function<void(int, int)> heapify = [&](int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n) {
            cout << "Compare parent " << a[i]
                 << " with left child " << a[left] << endl;
        }
        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n) {
            cout << "Compare current max " << a[largest]
                 << " with right child " << a[right] << endl;
        }
        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest != i) {
            cout << "Swap " << a[i] << " and " << a[largest] << endl;
            swap(a[i], a[largest]);

            cout << "  result: ";
            for (int x : a) cout << x << " ";
            cout << endl;

            heapify(n, largest);
        }
    };

    cout << "\nBuilding max heap..." << endl;
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i);
    }

    cout << "\nExtracting elements..." << endl;
    for (int i = n - 1; i > 0; --i) {
        cout << "Swap max " << a[0] << " with " << a[i] << endl;
        swap(a[0], a[i]);

        cout << "  result: ";
        for (int x : a) cout << x << " ";
        cout << endl;

        heapify(i, 0);
    }

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}


vector<int> heap_sort(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    function<void(int, int)> heapify = [&](int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }
        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(n, largest);
        }
    };

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(i, 0);
    }

    return a;
}