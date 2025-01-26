#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
        ll n;
        cin >> n;

        vector<ll> arr(n);
        int unique = 1;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] != 1 && arr[i] != -1) {
                unique = arr[i];
            }
        }

        set<ll> ans;
        ans.insert(0);

        // Insert all integers in range [l, r] into the set
        auto ins = [&](int l, int r) -> void {
            for (int i = l; i <= r; i++) {
                ans.insert(i);
            }
        };

        // Compute min and max subarray sums
        auto getMaxMin = [&](vector<ll>& arr) -> pair<int, int> {
            int L = 0, R = 0;
            int mini = 0, maxi = 0, pref = 0;
            
            for (int i = 0; i < n; i++) {
                if (abs(arr[i]) != 1) break;

                pref += arr[i];
                L = min(L, pref - maxi);
                R = max(R, pref - mini);
                mini = min(mini, pref);
                maxi = max(maxi, pref);
            }

            return {L, R};
        };

        // Find the index of the unique element
        auto getUniqueInd = [&](vector<ll>& arr) -> int {
            for (int i = 0; i < n; i++) {
                if (abs(arr[i]) != 1) return i;
            }
            return -1;
        };

        // Compute max and min sums involving the unique element
        auto getMaxMinofX = [&](vector<ll>& arr) -> pair<int, int> {
            int L = 0, R = 0;
            int pref = 0;
            int uniqueInd= getUniqueInd(arr);
            for (int i = uniqueInd + 1; i < n; i++) {
                pref += arr[i];
                L = min(L, pref);
                R = max(R, pref);
            }

            return {L, R};
        };

        // Process left and right parts
        auto leftSide = getMaxMin(arr);
        reverse(arr.begin(), arr.end());
        auto rightSide = getMaxMin(arr);

        ins(leftSide.first, leftSide.second);
        ins(rightSide.first, rightSide.second);

        // If there is a unique element, adjust ranges
        if (unique != 1) {
            int uniqueInd = getUniqueInd(arr);
            auto leftPart = getMaxMinofX(arr);
            reverse(arr.begin(), arr.end());
            auto rightPart = getMaxMinofX(arr);

            ins(unique + leftPart.first + rightPart.first,
                unique + leftPart.second + rightPart.second);
        }

        // Print the result
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
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
