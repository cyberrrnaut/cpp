#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {

private:
    int f(int l, int r, vector<int>& arr) {
        if (l > r) return 0;  // Invalid range
        if (l == r) return 0; // Base case: Single element

        int size = r - l + 1; // Size of the current segment
        int ans = 0;

        if (size % 2 == 0) {
            int mid = l + (size / 2) - 1;
            ans += f(l, mid, arr);       // Left half
            ans += f(mid + 1, r, arr);  // Right half
        } else {
            int mid = l + size / 2;     // Middle element for odd size
            ans += arr[mid];            // Include the middle element
            ans += f(l, mid - 1, arr);  // Left half
            ans += f(mid + 1, r, arr);  // Right half
        }

        return ans;
    }

public:
    void cyb3rnaut() {
        ll n, k;
        cin >> n >> k; // Read n and k
        
        vector<int> arr(n + 1); // Initialize array with size n+1 (1-based indexing)

        for (int i = 1; i <= n; i++) {
            arr[i] = i + 1; // Initialize arr[i] = i + 1
        }

        cout << f(1, n, arr) << endl; // Call the recursive function
    }
};

void solve() {
    Solution s;
    ll t;
    cin >> t;
    while (t--) {
        s.cyb3rnaut();
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
