#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
        string str;
        cin >> str;

        int n = str.length();

        int targetSize = n;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                targetSize = i;
                break;
            }
        }
        targetSize = n - targetSize;

        if (targetSize == 0) {
            cout << 1 << " " << n << " " << n << " " << n << endl;
            return;
        }

        bitset<64> fullNum(str);

        ll maxXOR = 0;
        int l = 1, r = targetSize;

        ll currentXOR = 0;
        for (int i = 0; i < targetSize; i++) {
            currentXOR = (currentXOR << 1) | (str[i] - '0');
        }

        maxXOR = fullNum.to_ullong() ^ currentXOR;

        for (int i = 1; i <= (n - targetSize-1); i++) {

            currentXOR = (currentXOR << 1) | (str[i + targetSize - 1] - '0');
            currentXOR &= (1 << targetSize) - 1;  

            ll currentSubXOR = fullNum.to_ullong() ^ currentXOR;


            if (currentSubXOR > maxXOR) {
                maxXOR = currentSubXOR;
                l = i + 1;  // 1-based index
                r = l + targetSize - 1;
            }
        }


        cout << 1 << " " << n << " " << l << " " << r << endl;
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
