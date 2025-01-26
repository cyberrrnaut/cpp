#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
      ll n,m,q;
      cin>>n>>m>>q;

      vector<int>queries(q);

      for(auto &i:queries) cin>>i;

      ll L1=1;
      ll R1=0;
      ll L2=n+1;
      ll R2=n;
      

      ll L=m;
      ll R=m;
      bool sides= false;

      bool centre = queries[0]==m?false:true;

      for(int q:queries){
       
       if(!centre){
        ll jokers = 0;

        if(q>R1 && q<L2){
            R1=min(R1+1,L2-1);
            L2=max(R1+1,L2-1);
        }else if(q<=R1){
             L2=max(R1+1,L2-1);
         }else if(q>=L2){
            R1=min(R1+1,L2-1);
         }

         jokers= (R1-L1+1) + (R2-L2+1) ;

         cout<<jokers<<" "; 
        
       }else{
         
         if(q>=L && q<=R){
          sides=true;

          if(sides){
            R1=min(R1+1,L-1);
            L2=max(L2-1,R+1);
          }
         }else if(q<L){
          
          if(sides){
           L=max(R1+1,L-1);
           L2=max(R+1,L2-1); 

            if(q>R1){
             R1=min(L-1,R1+1);  
          } 
          }else{
            L=max(1LL,L-1);
          }
           
         }else if(q>R){
          
         
           if(sides){
           R=min(L2-1,R+1);
           R1=min(L-1,R1+1);  

            if(q<L2){
            L2=max(R+1,L2-1); 
          }
          }else{
            R=min(n,R+1);
          }


         }
         
         ll jokers=0;

         jokers+= R-L+1;
         if(sides){
            jokers+= (R1-L1+1) + (R2-L2+1) ;
         }

       
        
        cout<<jokers<<" "; 


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
        s.stillcyb3rnaut();
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
