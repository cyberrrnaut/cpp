//G1. Dances
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
    ll n,m;
    cin>>n>>m;
    
    vll a(n), b(n);
    
    a[0]= 1;
    
    for(ll i=1;i<n;i++){
    cin>>a[i];    
    }
    
    for(ll i=0;i<n;i++){
    cin>>b[i];    
    }
    
    sort(b.begin(),b.end());
    ll ans =n;
    for(ll i=0;i<n;i++){
        
        auto it =upper_bound(b.begin(),b.end(), a[i]);
        
        if(it != b.end()){
            ans--;
           b.erase(it);
            
        }
    }
    
    
    cout<<ans<<endl;
    
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