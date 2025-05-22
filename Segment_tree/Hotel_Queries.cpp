/* problem link: https://cses.fi/problemset/task/1143
 * solution by: Raghad Islam
 * date: 21-5-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
#define int ll

struct Node {
    int mx;

    // neutral
    Node() {
        mx = INT_MIN;
    }

    explicit Node(int _sum) {
        mx = _sum;
    }

    void change(int val) {
        mx = val; // change according to the problem
    }
};

struct SegTree {
    int treeSize;
    vector<Node> segData;

    explicit SegTree(int arraySize) {
        treeSize = 1;
        while (treeSize < arraySize) treeSize *= 2;
        segData.assign(treeSize * 2, Node());
    }

    // change this function according to the problem
    Node merge(Node & lf, Node & ri) {
        Node ans = Node();
        ans.mx = max(lf.mx, ri.mx);
        return ans;
    }

    void init(vector<int> & v, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < v.size())
                segData[ni] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        init(v, ni * 2 + 1, lx, mid);
        init(v, ni * 2 + 2, mid, rx);
        segData[ni] = merge(segData[2 * ni + 1],segData[2 * ni + 2]);
    }

    void init(vector<int> & arr) {
        init(arr,0,0,treeSize);
    }

    void set(int idx, int val, int ni, int lx, int rx) { // 0-indexed

        // leaf
        if (lx == rx - 1) {
            segData[ni].change(val);
            return;
        }

        int mid = (lx + rx) / 2;

        if (idx < mid) {
            set(idx, val, ni*2 + 1, lx, mid);

        } else {
            set(idx, val, ni*2 + 2, mid, rx);
        }

        segData[ni] = merge(segData[ni * 2 + 1], segData[ni * 2 + 2]);
    }

    void set (int idx, int val) {
        set(idx, val, 0, 0, treeSize);
    }

    int get(int l, int r, int val, int ni, int lx, int rx) { // 0-indexed, r not included
        if (l >= rx || r <= lx || segData[ni].mx < val) return -1;
        // if (lx >= l && rx <= r) return segData[ni];
        if (lx == rx - 1) return lx;

        int mid = (lx + rx) / 2;
        int lf = get(l, r, val, ni * 2 + 1, lx, mid);
        if (lf != -1) return lf;
        return get(l, r, val, ni * 2 + 2, mid, rx);
    }

    int get(int l, int r, int val) {
        return get(l, r, val, 0, 0, treeSize);
    }
};




void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> hotels(n);
    vector<int> groups(m);
    for(int i = 0; i < n; ++i) {
        cin >> hotels[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> groups[i];
    }
    SegTree st(n);
    st.init(hotels);

    for ( int i = 0; i < m; ++i ) {
        int required = groups[i];
        int idx = st.get(0, n, required);
        cout << idx + 1 << " ";
        if (idx != -1) {
            hotels[idx] -= required;
            st.set(idx, hotels[idx]);
        }
    }

}

signed main(){
    fileIO();
    fastIO();
    int t = 1;// cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
