    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;

    #define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

    class Solution {
    public:
        void stillcyb3rnaut() {
            int n, k;
            cin >> n >> k;

            vector<int> arr(n);
            for (int &i : arr) cin >> i;

            sort(arr.begin(), arr.end());

            int i = 0, j = n - 1;
            int ans = 0;

            while (i < j) {
                int sum = arr[i] + arr[j];

                if (sum == k) {
                    ans++;
                    i++;
                    j--;
                } else if (sum < k) {
                    i++;
                } else {
                    j--;
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
