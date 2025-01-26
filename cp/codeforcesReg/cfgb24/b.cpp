#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
     
     for(int i=0;i<=9;i++){
        for( int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                cout<<i<<" "<<j<<' '<<k;
                 cout<<endl;
            }
        }
        
     }
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
