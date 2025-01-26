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

     for(int i=0;i<n;i++)cin>>arr[i];
      
      bool flag=false;
     for(int i=0;i<n-1;i++){
      if( (2*arr[i]>arr[i+1]) && (2*arr[i+1]>arr[i])  ){
        flag=true;
        break;
      }
     }
    
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

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
