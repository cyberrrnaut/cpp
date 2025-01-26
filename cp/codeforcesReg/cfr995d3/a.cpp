#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void cyb3rnaut() {
     
     int n;
     cin>>n;

     int diff=0;

     vector<int> a(n),b(n);

     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=0;i<n;i++)cin>>b[i];

             for(int i=0;i<n-1;i++){
                if(a[i]>b[i+1]){
                    diff+=a[i]-b[i+1];
                }
             }

     diff+=a[n-1];

     cout<<diff<<endl;
        
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
