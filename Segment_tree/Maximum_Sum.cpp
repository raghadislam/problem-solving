/* problem link: https://www.spoj.com/problems/KGSS/
 * solution by: Raghad Islam
 * date: 22-5-2025 
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
    int sum;
    int i;
    int j;
    int vi;
    int vj;

    // neutral
    Node() {
        sum = INT_MIN;
        vi = INT_MIN;
        vj = INT_MIN;
        i = -1;
        j = -1;
    }

    explicit Node(int _sum, int idx) {
        sum = _sum;
        vi = _sum;
        vj = _sum;
        i = idx;
        j = idx;
    }

    void change(int val) {
        sum = val; // change according to the problem
        vi = val;
        vj = val;
        // i = -1;
        // j = -1;
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
        int ii, jj, mx = INT_MIN, vii = INT_MIN, vjj = INT_MIN;
        // take the left as the answer
        if ((lf.i != lf.j) && (lf.j != -1) && (lf.i != -1)) {
            if (lf.vi + lf.vj > mx) {
                mx = lf.vi + lf.vj;
                ii = lf.i;
                jj = lf.j;
                vii = lf.vi;
                vjj = lf.vj;
            }
        }
        if ((ri.i != ri.j) && (ri.j != -1) && (ri.i != -1)) {
            if (ri.vi + ri.vj > mx) {
                mx = ri.vi + ri.vj;
                ii = ri.i;
                jj = ri.j;
                vii = ri.vi;
                vjj = ri.vj;
            }
        }
        if (max(lf.vi, lf.vj) + max(ri.vi, ri.vj) > mx) {
            // ii -> maximum from lf, jj -> maximum from ri
            mx = max(lf.vi, lf.vj) + max(ri.vi, ri.vj);
            if (lf.vi > lf.vj) {
                ii = lf.i;
                vii = lf.vi;
            } else {
                ii = lf.j;
                vii = lf.vj;
            }
            if (ri.vi > ri.vj) {
                jj = ri.i;
                vjj = ri.vi;
            } else {
                jj = ri.j;
                vjj = ri.vj;
            }
        }

        ans.i = ii;
        ans.j = jj;
        ans.vi = vii;
        ans.vj = vjj;
        ans.sum = mx;

        // ans.sum = lf.sum + ri.sum;
        return ans;
    }

    void init(vector<int> & v, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < v.size())
                segData[ni] = Node(v[lx], lx);
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

    Node get(int l, int r, int ni, int lx, int rx) { // 0-indexed, r not included
        if (l >= rx || r <= lx) return Node();
        Node x = segData[ni];
        if (lx >= l && rx <= r) return x;

        int mid = (lx + rx) / 2;
        Node lf = get(l, r, ni * 2 + 1, lx, mid);
        Node ri = get(l, r, ni * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, treeSize).sum;
    }
};




void solve() {
    int n, q;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    // for (int i = 0; i < n; i++) cout << v[i] << ' ';
    SegTree st(n+1);
    st.init(v);
    cin >> q;
    // cout << st.get(0, n) << endl;
    // // cout << st.get(0, 2) << endl;
    // // cout << st.get(0, 0) << endl;
    while (q--) {
        char ty; cin >> ty;
        if (ty == 'Q') {
            int x, y; cin >> x >> y;
            cout << st.get(x - 1, y) << endl;
        } else {
            int i, x; cin >> i >> x;
            st.set(i - 1, x);
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
