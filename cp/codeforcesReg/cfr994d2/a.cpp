#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
      int n;
      cin>>n;
      vector<int>arr(n);

      for(int i=0;i<n;i++) cin>>arr[i];

        int subArrayCount=0;
    if(arr[0]!=0) subArrayCount++;

      for(int i=1;i<n;i++){
        if(arr[i]!=0 && arr[i-1]==0){
          subArrayCount++;
        }
      }
    
    if(subArrayCount==0){
        cout<<0<<endl;
    }else if(subArrayCount==1){
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
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
