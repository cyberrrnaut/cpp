#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);
 
template <class T>
class SegmentTree {
    int n;
    vector<T> st;

public:
    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    T comb(T a, T b) {
        return min( a , b );
    }

    void build(int start, int end, int node, vector<T>& arr) {
        if (start == end) {
            st[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(start, mid, 2 * node + 1, arr);
        build(mid + 1, end, 2 * node + 2, arr);

        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }

    void build(vector<T>& arr) {
        build(0, n - 1, 0, arr);
    }

    T query(int start, int end, int l, int r, int node) {
        if (start > r || end < l) return INT_MAX;

        if (start >= l && end <= r) return st[node];

        int mid = (start + end) / 2;

        T q1 = query(start, mid, l, r, 2 * node + 1);
        T q2 = query(mid + 1, end, l, r, 2 * node + 2);

        return comb(q1, q2);
    }

    T query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    // Original full `update` function
    void update(int start, int end, int node, int index, int value) {
        if (start == end) {
            st[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid)
            update(start, mid, 2 * node + 1, index, value);
        else
            update(mid + 1, end, 2 * node + 2, index, value);

        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }

    // Shortened `update` function
    void update(int index, int value) {
        update(0, n - 1, 0, index, value);
    }
};


 

class Solution {
public:
    void stillcyb3rnaut() {
        ll n, q;
        cin >> n >> q;

        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        SegmentTree<ll> st;
 
        st.init(n);
 
        st.build(arr);

       

        for (int i = 0; i < q; i++) {
            ll type, start, end;

            cin >> type >> start >> end;

            ll stAns = 0LL;
             if (type == 1) {
                ll ind = start - 1;
                ll val = end;

                st.update(ind, val);
             } else { // type == 2
                start--;
                end--;

                stAns = st.query(start, end);
                 
                
                    cout << stAns << endl;
                
               
            }
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

