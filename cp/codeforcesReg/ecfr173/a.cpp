#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
     ll n;
     cin>>n;

     ll count=1;

     while(n>3){
      n/=4;
      count*=2;
     }

     cout<<count<<endl;
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
