/* problem link: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
 * solution by: Raghad Islam
 * date: 7-7-2025 
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
    int val;
    int lazyD;
    int lazyAdd;
    bool isLazy;

    // neutral
    Node() {
        val = 0;
        lazyD = 0;
        lazyAdd = 0;
        isLazy = false;
    }

    explicit Node(int _val) {
        val = _val;
        lazyD = 0;
        lazyAdd = 0;
        isLazy = false;
    }

    void change(int _val) {
        val = _val; // change according to the problem
    }

    void updateNode(int add, int d, int lx, int rx) {
        int len = rx - lx;
        int rangeSum = (rx * (rx - 1)/ 2) - (lx * (lx - 1)/ 2);
        val += d * rangeSum + add * len;
        lazyD += d;
        lazyAdd += add;
        isLazy = true;
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
        ans.val = lf.val + ri.val;
        return ans;
    }

    void propagate(int ni, int lx, int rx) {
        if (rx - lx == 1 || !segData[ni].isLazy) return;
        int mid = (lx + rx) / 2;

        segData[ni * 2 + 1].updateNode(segData[ni].lazyAdd, segData[ni].lazyD, lx, mid);
        segData[ni * 2 + 2].updateNode(segData[ni].lazyAdd, segData[ni].lazyD, mid, rx);

        segData[ni].isLazy = false;
        segData[ni].lazyD = segData[ni].lazyAdd = 0;

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

    void update(int a, int d, int l, int r, int ni, int lx, int rx) {
        propagate(ni, lx, rx);

        if (l >= rx || r <= lx) return;
        if (lx >= l && rx <= r) {
            segData[ni].updateNode(a, d, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        update(a, d, l, r, ni * 2 + 1, lx, mid);
        update(a, d, l, r, ni * 2 + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1],segData[2 * ni + 2]);
    }
    void update(int a, int d, int l, int r) {
        update(a, d, l, r, 0, 0, treeSize);
    }


    Node get(int l, int r, int ni, int lx, int rx) { // 0-indexed, r not included
        propagate(ni, lx, rx);

        if (l >= rx || r <= lx) return Node();
        if (lx >= l && rx <= r) return segData[ni];

        int mid = (lx + rx) / 2;
        Node lf = get(l, r, ni * 2 + 1, lx, mid);
        Node ri = get(l, r, ni * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    Node get(int l, int r) {
        return get(l, r, 0, 0, treeSize);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n+1,0);
    // for (int i = 1; i <= n; i++) cin >> v[i];
    SegTree st(n);
    st.init(v);
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, a, d; cin >> l >> r >> a >> d;
            st.update((a - (d*(l-1))), d, l-1, r);
        }
        else {
            int id; cin >> id;
            cout << st.get(id-1,id).val << '\n';
        }
    }
}

signed main(){
    fileIO();
    fastIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
