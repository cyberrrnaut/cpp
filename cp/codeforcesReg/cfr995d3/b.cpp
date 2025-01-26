#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
      ll n, a,b,c;

      cin>>n>>a>>b>>c;

      ll sum= a+b+c;

      ll divTimes= (n+sum-1) / sum; //2
      
      ll actualTimes= divTimes*3; // 6
      
      ll extraPath = sum*divTimes; // 18

      if(extraPath-c < n){
        cout<<actualTimes<<endl;
        return;
      }

         if(extraPath- (b+c) < n){
        cout<<actualTimes-1<<endl; //6-1 =5 
        return;
      }

        if(extraPath- (a+b+c) < n){
        cout<<actualTimes-2<<endl;
        return;
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
