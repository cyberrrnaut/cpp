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
    void cyb3rnaut() {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        vector<ll> feasiblePowers;
        ll power = 1; // k^0
        while (power <= r2) {
            feasiblePowers.push_back(power);
            if (power > r2 / k) break; 
            power *= k;
        }

        ll ans = 0;

        for (ll p : feasiblePowers) {
            ll l_valid = max(l1, (l2 + p - 1) / p); // Ceil(l2 / p)
            ll r_valid = min(r1, r2 / p);          // Floor(r2 / p)

            if (l_valid <= r_valid) {
                ans += (r_valid - l_valid + 1);
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
        s.cyb3rnaut();
    }
}

signed main() {
    fast_io();
    solve();
    return 0;
}