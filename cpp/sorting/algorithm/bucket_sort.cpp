/*
Bucket Sort Algorithm

Bucket Sort is a distribution based sorting algorithm.

How it works:
- It divides elements into several groups called buckets.
- Each bucket holds values within a specific range.
- Elements are distributed into buckets based on their value.
- Each bucket is sorted individually.
- All buckets are combined to produce the final sorted list.

This algorithm performs well when the input values are evenly distributed.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the number of buckets.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Depends on the sorting method used inside each bucket.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> bucket_sort_verbose(const vector<int>& arr, int bucket_size = 5) {
    if (arr.empty())
        return {};

    vector<int> a = arr;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int min_val = *min_element(a.begin(), a.end());
    int max_val = *max_element(a.begin(), a.end());

    cout << "Min: " << min_val << " Max: " << max_val << endl;

    int bucket_count = (max_val - min_val) / bucket_size + 1;
    vector<vector<int>> buckets(bucket_count);

    cout << "\nCreated " << bucket_count << " buckets" << endl;

    cout << "\nDistributing into buckets..." << endl;
    for (int num : a) {
        int index = (num - min_val) / bucket_size;
        cout << "Put " << num << " into bucket " << index << endl;
        buckets[index].push_back(num);
    }

    cout << "\nBuckets before sorting:" << endl;
    for (int i = 0; i < buckets.size(); ++i) {
        cout << "Bucket " << i << ": ";
        for (int x : buckets[i]) cout << x << " ";
        cout << endl;
    }

    cout << "\nSorting each bucket and collecting..." << endl;

    vector<int> result;
    for (int i = 0; i < buckets.size(); ++i) {
        cout << "Sort bucket " << i << ": ";
        for (int x : buckets[i]) cout << x << " ";
        cout << endl;

        sort(buckets[i].begin(), buckets[i].end());

        cout << "  sorted bucket " << i << ": ";
        for (int x : buckets[i]) cout << x << " ";
        cout << endl;

        for (int num : buckets[i]) {
            result.push_back(num);
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


vector<int> bucket_sort(const vector<int>& arr, int bucket_size = 5) {
    if (arr.empty())
        return {};

    vector<int> a = arr;

    int min_val = *min_element(a.begin(), a.end());
    int max_val = *max_element(a.begin(), a.end());

    int bucket_count = (max_val - min_val) / bucket_size + 1;
    vector<vector<int>> buckets(bucket_count);

    for (int num : a) {
        int index = (num - min_val) / bucket_size;
        buckets[index].push_back(num);
    }

    vector<int> result;
    for (auto& b : buckets) {
        sort(b.begin(), b.end());
        result.insert(result.end(), b.begin(), b.end());
    }

    return result;
}