#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);

class Solution {
public:
    void stillcyb3rnaut() {
     
     int n,m;
     cin>>n>>m;

     vector<vector<int>>deck(n,vector<int>());

     for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            int inp;
            cin>>inp;

            deck[i].push_back(inp);

        }

        sort(deck[i].begin(),deck[i].end());
     }

     vector<pair<int,int>>permutation;
    
  //   set<int> present;
//present.insert(-1);
 
     for(int i=0;i<n;i++){
        // if( present.count(deck[i][0])){
        //     cout<<-1<<endl;
        //     return;
        // } 
        // present.insert(deck[i][0]);

        permutation.push_back({deck[i][0], i+1}); // el, ind
     }

     sort(permutation.begin(), permutation.end());
     
       
       for(int col=1;col<m;col++){
              vector<pair<int,int>> tempPermutation;
            
            // present.clear();    
              for(int row=0;row<n;row++){
            // if( present.count(deck[row][col])){
            //       cout<<-1<<endl;
            //     return;
            //  } 
            //   present.insert(deck[row][col]);

                 tempPermutation.push_back({deck[row][col], row+1});
              }
            
                 sort(tempPermutation.begin(), tempPermutation.end());
           for(int i=0;i<permutation.size();i++){
            if(permutation[i].second != tempPermutation[i].second){
                cout<<-1<<endl;
                return;
            }
           }
       }
    

      for(auto[els, ind]:permutation){
        cout<<ind<<" ";
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
