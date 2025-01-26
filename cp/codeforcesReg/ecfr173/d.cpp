#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
     
     ll l,r,g;
     cin>>l>>r>>g;

     ll L= (l+g-1)/g;
     ll R= r/g;

     if(L==R){
        if(L==1){
            cout<<g<<" "<<g<<endl;
            return;
        }
        cout<<-1<<" "<<-1<<endl;
            return;
     }

     ll left=-1;
     ll right=-1;
     ll size=0;
     bool flag =false;

     for(ll i=L;i<=min(R,L+200);i++){

         for(ll j=R;j>=max(i,L);j--){
            if(__gcd(i,j)==1){
                 flag=true;
                if((j-i+1) >size){
                    size= j-i+1;  
                left=i;
                right=j;
                }
              
                break;
            }
        }
     }


     if(flag){
      cout<<left*g<<" "<<right*g<<endl;
     }else{
    cout<<-1<<" "<<-1<<endl;
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
