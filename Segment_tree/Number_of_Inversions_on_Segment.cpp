/* problem link: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
 * solution by: Raghad Islam
 * date: 10-6-2025 
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
    int inv;
    vector <int> freq = vector <int> (41, 0);

    // neutral
    Node() {
        inv = 0;
        // for (int & i : freq) i = 0;
        for (int i = 0; i < 41; i++) freq[i] = 0;
    }

    explicit Node(int val) {
        // inv = val;
        freq[val] = 1;
        inv = 0;
    }

    void change(int val, int oldVal) {
        freq[val]++;
        freq[oldVal]--;
        // inv += val; // change according to the problem
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
        ans.inv = lf.inv + ri.inv;

        for (int i = 40; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                ans.inv += 1LL * lf.freq[i] * ri.freq[j];
            }
            ans.freq[i] = lf.freq[i] + ri.freq[i];
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

    void set(int idx, int val, int oldVal, int ni, int lx, int rx) { // 0-indexed

        // leaf
        if (lx == rx - 1) {
            segData[ni].change(val, oldVal);
            return;
        }

        int mid = (lx + rx) / 2;

        if (idx < mid) {
            set(idx, val, oldVal, ni*2 + 1, lx, mid);

        } else {
            set(idx, val, oldVal, ni*2 + 2, mid, rx);
        }

        segData[ni] = merge(segData[ni * 2 + 1], segData[ni * 2 + 2]);
    }

    void set (int idx, int val, int oldVal) {
        set(idx, val, oldVal, 0, 0, treeSize);
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
        return get(l, r, 0, 0, treeSize).inv;
    }

};

void solve() {
    int n,q; cin >> n >> q;
    vector<int> v(n);
    vector<int>ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegTree st(n+1);
    st.init(v);
    // cout << st.get(0, 5);


    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.get(l, r+1) << '\n';
        }
        else {
            int idx, val; cin >> idx >> val;
            idx--;
            st.set(idx, val, v[idx]);
            v[idx] = val;
        }
    }
}


signed main(){
    fileIO();
    fastIO();
    int t = 1;// cin >> t;
 //   while(t--)
        solve();
    return 0;
}
