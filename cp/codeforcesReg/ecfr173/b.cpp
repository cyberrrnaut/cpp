#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
        ll n, d;
        cin >> n >> d;

        cout << 1 << " ";


        if ( d%3==0 || n>=3 ) { 
            cout << 3 << " ";
        }


        if (d == 5 || d == 0) {
            cout << 5 << " ";
        }

        
        if(d%7==0  || n>=3){
           cout << 7 << " ";
        }

        if ( n>=6 || (n>=3 && d%3==0) || d%9==0 ){
            cout << 9 << " ";
        }

        cout << endl;
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
