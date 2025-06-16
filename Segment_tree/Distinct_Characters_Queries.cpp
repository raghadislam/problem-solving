/* problem link: https://codeforces.com/problemset/problem/1234/D
 * solution by: Raghad Islam
 * date: 16-6-2025 
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
    vector<int> data;

    // Node() : data(26, 0) {}
    // neutral
    Node() {
        data.assign(26, 0);
    }

    explicit Node(int val) : data(26, 0) {
        data[val] = 1;
    }

    void change(int c, int val) {
        data[c] =  val; // change according to the problem
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
        for (int i = 0; i < 26; i++) {
            if (lf.data[i] == 1 || ri.data[i] == 1) {
                ans.data[i] = 1;
            }
        }
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

    void set(int old, int idx, int val, int ni, int lx, int rx) { // 0-indexed

        // leaf
        if (lx == rx - 1) {
            segData[ni].change(old, 0);
            segData[ni].change(val, 1);
            return;
        }

        int mid = (lx + rx) / 2;

        if (idx < mid) {
            set(old, idx, val, ni*2 + 1, lx, mid);

        } else {
            set(old, idx, val, ni*2 + 2, mid, rx);
        }

        segData[ni] = merge(segData[ni * 2 + 1], segData[ni * 2 + 2]);
    }

    void set (int old, int idx, int val) {
        set(old, idx, val, 0, 0, treeSize);
    }

    Node get(int l, int r, int ni, int lx, int rx) { // 0-indexed, r not included
        if (l >= rx || r <= lx) return Node();
        if (lx >= l && rx <= r) return segData[ni];

        int mid = (lx + rx) / 2;
        Node lf = get(l, r, ni * 2 + 1, lx, mid);
        Node ri = get(l, r, ni * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r) {
        vector<int> v = get(l, r, 0, 0, treeSize).data;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += v[i];
        }
        return ans;
    }
};



void solve() {
    string s; cin >> s;
    int sz = s.size();
    vector<int> v(sz);
    for (int i = 0; i < sz; i++) {
        v[i] = s[i] - 'a';
    }
    SegTree st(sz);
    st.init(v);

    int op;
    int q; cin >> q;
    while (q--) {
        cin >> op;
        if (op == 1) {
            int pos;
            char c; cin >> pos >> c;
            pos--;
            st.set(v[pos], pos,c - 'a');
            v[pos] = c - 'a';
        }
        else {
            int l, r; cin >> l >> r;
            l--;
            cout << st.get(l, r) << endl;
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
