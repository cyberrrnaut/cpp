#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
        ll n, q;
        cin >> n >> q;

        vector<pair<int, int>> ops(q);

        // Input operations
        for (int i = 0; i < q; i++) {
            int inp;
            char ch;
            cin >> inp >> ch;
            ops[i] = {inp, (ch == '+' ? 1 : 0)};
        }

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        auto getDiff = [&](int i, int j) -> int {
            int diff = 1;
            int l1 = 1, r1 = 1;
            int l2 = 2, r2 = 2;
            for (auto [snake, type] : ops) {
                if (snake == j) {
                    if (type)
                        r2++;
                    else
                        l2++;
                } else {  // snake is i
                    if (type)
                        r1++;
                    else
                        l1++;
                }
                if (r1 >= l2) {
                    l2++;
                    r2++;
                    diff++;
                }
            }
            return diff;
        };

        // Calculate the cost matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                cost[i][j] = getDiff(i, j);
            }
        }

        const int MAX_MASK = (1 << n);
        const int INF = 1e9;
        vector<vector<int>> dp(MAX_MASK, vector<int>(n, INF));

        // Base case: single snake sets
        for (int i = 0; i < n; ++i) {
            dp[(1 << i)][i] = cost[i][i];
        }

        // Iterate over all masks
        for (int mask = 1; mask < MAX_MASK; ++mask) {
            for (int i = 0; i < n; ++i) {
                if (1 & (mask >> i)) {  // Snake i is in the set
                    for (int j = 0; j < n; ++j) {
                        if (!(1 & (mask >> j))) {  // Snake j is not in the set
                            int new_mask = mask | (1 << j);
                            dp[new_mask][j] = min(dp[new_mask][j], dp[mask][i] + cost[i][j]);
                        }
                    }
                }
            }
        }

        // Find the minimum cost
        int res = INF;
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[MAX_MASK - 1][i]);
        }

        cout << res << '\n';
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
