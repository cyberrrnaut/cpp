#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
         int n;
         cin>>n;

      string str;
      cin>>str;

   
      
      int sCount=0;
      int pCount=0;
      set<char>st;


      for(int i=0;i<n;i++){
        if(str[i]=='s'){
            sCount++;
        }else if(str[i]=='p'){
            pCount++;
        }
         st.insert(str[i]);
      }

       
      if(st.size()==1 ){   //only .. or ..pp
          cout<<"YES"<<endl;
        return;
      }

      if(sCount==0 || pCount==0){
          cout<<"YES"<<endl;
        return; 
      }

      if(str[0]!='s' && str[n-1]!='p'){
           cout<<"NO"<<endl;
        return;
      }

     

      if(str[0]=='s'){
         if(sCount==1){
             cout<<"YES"<<endl;
             return;
         }
      }
       if(str[n-1]=='p'){
        if(pCount==1){
             cout<<"YES"<<endl;
             return;
         }
      }

     cout<<"NO"<<endl;
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
