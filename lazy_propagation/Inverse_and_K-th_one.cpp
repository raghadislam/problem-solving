/* problem link: https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/B
 * solution by: Raghad Islam
 * date: 27-6-2025 
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

const int MOD = 1000000007;

struct Node {
    int val;
    int lazy;
    bool isLazy;

    Node() {
        val = 0;
        lazy = 0;
        isLazy = false;
    }

    explicit Node(int _val) {
        val = _val;
        lazy = 0;
        isLazy = false;
    }

    void change(int _val) {
        val = _val;
    }

    void updateNode(int _val, int lx, int rx) {
        val = (rx - lx) - val;
        lazy = _val;
        isLazy = !isLazy;
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

    Node merge(Node & lf, Node & ri) {
        Node ans = Node();
        ans.val = lf.val + ri.val;
        return ans;
    }

    void propagate(int ni, int lx, int rx) {
        if (rx - lx == 1 || !segData[ni].isLazy) return;
        int mid = (lx + rx) / 2;

        segData[ni * 2 + 1].updateNode(segData[ni].lazy, lx, mid);
        segData[ni * 2 + 2].updateNode(segData[ni].lazy, mid, rx);

        segData[ni].isLazy = false;
        segData[ni].lazy = 0;

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

    void update(int val, int l, int r, int ni, int lx, int rx) {
        propagate(ni, lx, rx);

        if (l >= rx || r <= lx) return;
        if (lx >= l && rx <= r) {
            segData[ni].updateNode(val, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        update(val, l, r, ni * 2 + 1, lx, mid);
        update(val, l, r, ni * 2 + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1],segData[2 * ni + 2]);
    }
    void update(int val, int l, int r) {
        update(val, l, r, 0, 0, treeSize);
    }


    int get(int k, int l, int r, int ni, int lx, int rx) { 
        propagate(ni, lx, rx);
        if (rx - lx == 1 ) return lx;

        int mid = (lx + rx) / 2;
        if (segData[ni * 2 + 1].val >= k) {
            return get(k, l, r, ni * 2 + 1, lx, mid);
        }
        return get(k - segData[ni * 2 + 1].val, l, r, ni * 2 + 2, mid, rx);
    }

    int get(int k, int l, int r) {
        return get(k, l, r, 0, 0, treeSize);
    }
};




void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n, 0);
    SegTree st(n);
    // st.init(v);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            st.update(1,l,r);
        }
        else {
            int k; cin >> k;
            cout << st.get(k+1, 0, n)<< endl;
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
