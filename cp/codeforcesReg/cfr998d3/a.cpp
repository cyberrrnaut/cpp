#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
     int a1,a2,a4,a5;
     cin>>a1>>a2>>a4>>a5;

     int possibility1 = a1+a2;
     int possibility2= a4-a2;
     int possibility3= a5-a4;

     set<int> possibilities;

     possibilities.insert(possibility1);
     possibilities.insert(possibility2);
     possibilities.insert(possibility3);

     if(possibilities.size()==1){
        cout<<3;
     }else if(possibilities.size()==2){
        cout<<2;
     }else{//3
       cout<<1;
     }

     cout<<endl;
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
