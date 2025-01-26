#include <iostream>
#include <vector>
typedef long long ll; // Fixed typedef

using namespace std;


template <class T>
class FenwickTree {
    int n;
    vector<T> bit; // Binary Indexed Tree

public:
    // Initialize Fenwick Tree
    void init(int _n) {
        this->n = _n;
        bit.assign(n, 0); // Fenwick Tree now uses 0-based indexing
    }

    // Point Update: Add value `val` at index `idx` (0-indexed)
    void add(int idx, T val) {
        for (; idx < n; idx = idx | (idx + 1)) { // Using `idx | (idx + 1)` for 0-based indexing
            bit[idx] += val;
        }
    }

    // Prefix Sum Query: Sum of elements from 0 to `idx` (0-indexed)
    T prefix_sum(int idx) {
        T sum = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) { // Using `(idx & (idx + 1)) - 1` for 0-based indexing
            sum += bit[idx];
        }
        return sum;
    }

    // Range Sum Query: Sum of elements from `l` to `r` (0-indexed)
    T range_sum(int l, int r) {
        return prefix_sum(r) - (l > 0 ? prefix_sum(l - 1) : 0);
    }

    // Point Set: Set the value at index `idx` to `val` (0-indexed)
    void point_set(int idx, T val) {
        T current_val = range_sum(idx, idx); // Get current value at index
        T diff = val - current_val;         // Find difference to update
        add(idx, diff);
    }
};

int main() {
    // Example usage
    vector<int> arr = {3, 6, 7, 4, 3, 23, 2, 2, 11, 9};
    int n = arr.size();

    FenwickTree<ll> ft;
    ft.init(n);

    // Build Fenwick Tree (add values to it)
    for (int i = 0; i < n; i++) {
        ft.add(i + 1, arr[i]); // Note: Fenwick Tree is 1-indexed
    }

    // Query the sum of range [1, 5]
    cout << "Sum of range [1, 5]: " << ft.range_sum(1, 5) << endl;

    // Add value 10 to index 2 (1-indexed)
    ft.add(2, 10); // Adds 10 to arr[1]

    // Query the sum of range [1, 5] after update
    cout << "Sum of range [1, 5] after update: " << ft.range_sum(1, 5) << endl;

    return 0;
}
