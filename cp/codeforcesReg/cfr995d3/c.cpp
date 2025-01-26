#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
     
     ll n,m,k;

     cin>>n>>m>>k;

     vector<int> mArr(m);
     vector<int> kArr(k);

     for(int i=0;i<m;i++){
        cin>>mArr[i];
     }

     for(int  i=0;i<k;i++)cin>>kArr[i];

     
     vector<int> questions(n+1,0);

     for(int i=0;i<k;i++){
        questions[kArr[i]]=1;
     }

      int missing=-1;
      int missingCount=0;
      
      for(int i=1;i<questions.size();i++){
        if(questions[i]==0){
            missingCount++;
            missing=i;
        }
      }

      if(missingCount>1){
        for(int i=0;i<m;i++){
            cout<<0;
           
        }
         cout<<endl;
            return;
      }
      

      if(missingCount==0){
        for(int i=0;i<m;i++){
            cout<<1;
           
        }
         cout<<endl;
            return;
      }


     

      for(int i=0;i<m;i++){
        if(mArr[i]==missing){
            cout<<1;
        }else{
            cout<<0;
        }
      }
     

     cout<<endl;
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
