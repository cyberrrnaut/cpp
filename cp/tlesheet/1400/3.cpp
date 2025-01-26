//D. Jumping Through Segments

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<ll,ll>> vpll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << '[';
    for (int i = 0; i < sz(v) ; i++) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << ']';
}

#define debug(x) cerr << #x << " = " << x << endl

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

class Solution {
private:
bool check(vpll& arr ,ll mid){
	
    ll n =arr.size();

    ll low=0;
    ll high=0;

    for(auto it:arr){

        low=max(low-mid, it.first);
        high=min(high+mid, it.second);
        if(low>high)return false;
    }

    return true;
}	

public:
    void cyb3rnaut() {
      

      ll n;
      cin>>n;

      vector<pair<ll,ll>> arr;

      for(int i=0;i<n;i++){
        ll l;
        ll r;
        cin>>l>>r;

        arr.push_back({l,r});
      }


     ll low= 0;
     ll high= 1e9;
      ll ans=0;
     while(low<=high){
        ll mid = low + (high-low)/2;

        if(check(arr,mid)){
         ans=mid;
         high=mid-1;
        }else{
         low= mid+1;
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
        s.cyb3rnaut();
    }
}

signed main() {
    fast_io();
    solve();
    return 0;
}
