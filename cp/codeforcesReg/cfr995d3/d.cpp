#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
        ll n, x, y;

        cin >> n >> x >> y;

        vector<int> arr(n);

        ll sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr.begin(), arr.end());

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int num = arr[i];

            ll remainingSum = sum - num;

            ll lowerTarget = remainingSum - y;
            ll upperTarget = remainingSum - x;

            auto lower = lower_bound(arr.begin(), arr.end(), lowerTarget);
            auto upper = upper_bound(arr.begin(), arr.end(), upperTarget);

            int count = (upper - lower);

            if (num >= lowerTarget && num <= upperTarget) {
                count--;
            }

            ans += count;
        }

        cout << ans / 2 << endl;
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
