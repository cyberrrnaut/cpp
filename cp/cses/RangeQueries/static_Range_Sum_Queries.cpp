#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);
 

class Solution {
public:
    void stillcyb3rnaut() {
      ll n,q;
      cin>>n>>q;

      vector<ll>arr(n);

      for(int i=0;i<n;i++){
      	cin>>arr[i];
      }
      vector<ll>prefArr(n+1);
      prefArr[0]=arr[0];

      for(int i=1;i<n;i++){
        prefArr[i]=prefArr[i-1]+arr[i];	
      }

       for(int i=0;i<q;i++){
       	int start,end;
       	cin>>start>>end;
        start--;
        end--;
        ll sum;
        
         if(start==0){
         	 sum = prefArr[end]- 0LL;

         }else{
         	   sum = prefArr[end]-prefArr[start-1];
         }
         

         cout<<sum<<endl;

       }
          
    }
};

void solve() {
    Solution s;
    s.stillcyb3rnaut();
}

int main() {
    fast_io();
    solve();
    return 0;
}

