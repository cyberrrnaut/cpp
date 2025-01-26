#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll, ll> mll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    for (int i = 0; i < sz(v); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << ']';
}

#define debug(x) cerr << #x << " = " << x << endl

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

class Solution {
public:
    void cyb3rnaut(const vector<int>& dp) {
        int n;
        cin >> n;

        // Safeguard: Ensure `n` does not exceed precomputed range
        if (n < 1 || n > 1e5) {
            cout << "Invalid input\n";
            return;
        }

        cout << dp[n] << endl;
    }
};

void solve() {
    Solution s;

    // Precomputing the dp array
    vector<int> dp(1e5 + 1);

    int l = 1;
    int range = 1;
    int val = 1;
    dp[l]=val;
    l++;
    while (l <= 1e5) {
        // Update current range
        range = (2 * range )+ 2;    
        val++;
        while (l <= 1e5 && l <= range) {
            
            dp[l] = val;
            l++;
        }
    }

 

    ll t;
    cin >> t;
    while (t--) {
        s.cyb3rnaut(dp);
    }
}

signed main() {
    fast_io();
    solve();
    return 0;
}