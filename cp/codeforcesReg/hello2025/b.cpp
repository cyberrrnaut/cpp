#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
      ll n,k;
      cin>>n>>k;

      map<int,int>mpp;

      for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        mpp[inp]++;
      }

      if(k==0){
        cout<<mpp.size()<<endl;
        return;
      }

      if(k>=n){
        cout<<1<<endl;
        return;
      }

      vector<pair<int, int>> vec(mpp.begin(), mpp.end());

    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; //sorting values or freqs ascending

     });
     
     for(auto& [num,freq]:vec){
        if(freq<=k){
            k-=freq;
            freq= 0;
        }else{
            break;
        }
     }

     ll ans=0;

      for(auto [num,freq]:vec){
        if(freq>0){
         ans++;
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
        s.stillcyb3rnaut();
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
