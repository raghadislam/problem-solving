/* problem link: https://atcoder.jp/contests/abc357/tasks/abc357_f?lang=en
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

const int MOD = 998244353;

struct Node {
    int val;
    int sumA;
    int sumB;
    int lazyA;
    int lazyB;
    bool isLazyA;
    bool isLazyB;

    // neutral
    Node() {
        val = 0;
        sumA = 0;
        sumB = 0;
        lazyA = 0;
        lazyB = 0;
        isLazyA = false;
        isLazyB = false;
    }

    explicit Node(int a, int b) {
        val = (a%MOD * b%MOD) % MOD;
        sumA = a;
        sumB = b;
        lazyA = 0;
        lazyB = 0;
        isLazyA = false;
        isLazyB = false;
    }

    void change(int _val) {
        val = _val; // change according to the problem
    }

    void updateNode(int ty, int _val, int lx, int rx) {
        int len = rx - lx;
        if (ty == 1) {
            val = (val + _val % MOD * sumB % MOD) % MOD;
            sumA = (sumA + _val % MOD * len % MOD) % MOD;
            lazyA = (lazyA + _val) % MOD;
            isLazyA = true;
        } else if (ty == 2) {
            val = (val + _val % MOD * sumA % MOD) % MOD;
            sumB = (sumB + _val % MOD * len % MOD) % MOD;
            lazyB = (lazyB + _val) % MOD;
            isLazyB = true;
        }
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
        ans.val = (lf.val% MOD + ri.val% MOD) % MOD;
        ans.sumA = (lf.sumA% MOD + ri.sumA% MOD)% MOD;
        ans.sumB = (lf.sumB% MOD + ri.sumB% MOD)% MOD;
        return ans;
    }

    void propagate(int ni, int lx, int rx) {
        if (rx - lx == 1 || (!segData[ni].isLazyA && !segData[ni].isLazyB)) return;
        int mid = (lx + rx) / 2;

        if (segData[ni].isLazyA) {
            segData[ni * 2 + 1].updateNode(1, segData[ni].lazyA, lx, mid);
            segData[ni * 2 + 2].updateNode(1, segData[ni].lazyA, mid, rx);
        }

        if (segData[ni].isLazyB) {
            segData[ni * 2 + 1].updateNode(2, segData[ni].lazyB, lx, mid);
            segData[ni * 2 + 2].updateNode(2, segData[ni].lazyB, mid, rx);
        }


        segData[ni].isLazyA = false;
        segData[ni].isLazyB = false;
        segData[ni].lazyA = 0;
        segData[ni].lazyB = 0;

    }

    void init(vector<pair<int,int>> & v, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < v.size())
                segData[ni] = Node(v[lx].first, v[lx].second);
            return;
        }
        int mid = (lx + rx) / 2;
        init(v, ni * 2 + 1, lx, mid);
        init(v, ni * 2 + 2, mid, rx);
        segData[ni] = merge(segData[2 * ni + 1],segData[2 * ni + 2]);
    }

    void init(vector<pair<int,int>> & arr) {
        init(arr,0,0,treeSize);
    }

    void update(int ty, int val, int l, int r, int ni, int lx, int rx) {
        propagate(ni, lx, rx);

        if (l >= rx || r <= lx) return;
        if (lx >= l && rx <= r) {
            segData[ni].updateNode(ty, val, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        update(ty, val, l, r, ni * 2 + 1, lx, mid);
        update(ty, val, l, r, ni * 2 + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1],segData[2 * ni + 2]);
    }
    void update(int ty, int val, int l, int r) {
        update(ty, val, l, r, 0, 0, treeSize);
    }


    Node get(int l, int r, int ni, int lx, int rx) { 
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
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    SegTree st(n);
    st.init(v);
    while (q--) {
        int op; cin >> op;
        int l, r; cin >> l >> r;
        l--;
        if (op == 1) {
            int val; cin >> val;
            st.update(1, val, l, r);
        }
        else if (op == 2) {
            int val; cin >> val;
            st.update(2, val, l, r);
        }
        else {
            cout << st.get(l, r).val << '\n';
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
