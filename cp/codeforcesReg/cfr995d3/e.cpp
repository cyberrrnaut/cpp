#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
        ll n, k;
        cin >> n >> k;

        vector<pair<ll, ll>> arr(n);
        for (auto& it : arr) {
            cin >> it.first;
        }

        for (auto& it : arr) {
            cin >> it.second;
        }

        set<ll> st;

        // Coordinate compression
        for (const auto& it : arr) {
            st.insert(it.first);
            st.insert(it.second);
        }

        vector<ll> impNums(st.begin(), st.end());
        int m = impNums.size();

        vector<ll> buy(m, 0);
        vector<ll> negRev(m, 0);

        for (const auto& it : arr) {
            auto aIdx = lower_bound(impNums.begin(), impNums.end(), it.first) - impNums.begin();
            auto bIdx = lower_bound(impNums.begin(), impNums.end(), it.second) - impNums.begin();

            // Set buys till bIdx
            buy[0] += 1;
            if (bIdx + 1 < m) buy[bIdx + 1] -= 1;

            // Set negRev after aIdx
            if (aIdx + 1 < m) negRev[aIdx + 1] += 1;
            if (bIdx + 1 < m) negRev[bIdx + 1] -= 1;
        }

        // Prefix sums for `buy` and `negRev`
        for (int i = 1; i < m; i++) {
            buy[i] += buy[i - 1];
            negRev[i] += negRev[i - 1];
        }

        ll ans = 0;
        for (int i = 0; i < m; i++) {
            if (negRev[i] <= k) {
                ans = max(ans, buy[i] * impNums[i]);
            }
        }

        cout << ans << endl;
    }
};

void solve() {
    Solution s;
    ll t;
    cin >> t;
    while (t--) {
        s.stillcyb3rnaut();
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
