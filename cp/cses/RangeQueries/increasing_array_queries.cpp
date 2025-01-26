#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

template <class T>
class FenwickTree {
    int n;
    vector<T> bit; // Binary Indexed Tree

public:
    // Initialize Fenwick Tree
    void init(int _n) {
        this->n = _n;
        bit.assign(n + 1, 0); // Fenwick Tree is 1-indexed
    }

    // Point Update: Add value `val` at index `idx` (1-indexed)
    void add(int idx, T val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Prefix Sum Query: Sum of elements from 1 to `idx` (1-indexed)
    T prefix_sum(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Range Sum Query: Sum of elements from `l` to `r` (1-indexed)
    T range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }

    // Point Set: Set the value at index `idx` to `val`
    void point_set(int idx, T val) {
        T current_val = range_sum(idx, idx); // Get current value at index
        T diff = val - current_val;         // Find difference to update
        add(idx, diff);
    }
};

class Solution {
public:
    void stillcyb3rnaut() {
        ll n, q;
        cin >> n >> q;

        vector<int> arr(n + 1); // 1-indexed
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<vector<pair<int, int>>> queries(n + 1);

        for (int i = 0; i < q; i++) {
            int start, end;
            cin >> start >> end;
            queries[start].push_back({end, i});
        }

        vector<ll> prefArr(n + 1, 0);
        prefArr[1] = arr[1];
        for (int i = 2; i <= n; i++) {
            prefArr[i] = prefArr[i - 1] + arr[i];
        }

        FenwickTree<ll> ft;
        ft.init(n);

        vector<ll> queryAns(q, 0);
        vector<pair<int, int>> maxEls; // Monotonic stack

        for (int i = n; i >= 1; i--) {
            // Remove elements that are smaller than the current element
            while (!maxEls.empty() && arr[i] >= maxEls.back().first) {
                ft.point_set(maxEls.size(), 0); // Remove its contribution
                maxEls.pop_back();
            }

            // Add current element's contribution
            int len = (maxEls.empty() ? n + 1 : maxEls.back().second) - i;
            ft.point_set(maxEls.size() + 1, (ll)len * arr[i]);
            maxEls.push_back({arr[i], i});

            // Process queries for this index
            for (auto [end, qIdx] : queries[i]) {
                int low = 0, high = maxEls.size() - 1, validInd = -1;

                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (maxEls[mid].second <= end) {
                        validInd = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }

                if (validInd == -1) continue;

                ll sum1 = ft.prefix_sum(maxEls.size()) - ft.prefix_sum(validInd + 1); // left part from sart
                ll sum2 = (ll)(end - maxEls[validInd].second + 1) * maxEls[validInd].first; // last part
                ll prefSumOfRange = prefArr[end] - prefArr[i - 1];

                queryAns[qIdx] = sum1 + sum2 - prefSumOfRange;
            }
        }

        for (int i = 0; i < q; i++) {
            cout << queryAns[i] << endl;
        }
        
    }
};

void solve() {
    Solution s;
    s.stillcyb3rnaut();
}

int main() {
    fast_io();
    solve();
    return 0;
}
