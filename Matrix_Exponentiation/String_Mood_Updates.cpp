/* problem link: https://codeforces.com/gym/102644/problem/H
 * solution by: Raghad Islam
 * date: 19-7-2025 
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
// #define int ll

const int MOD = 1e9+7;

struct Node {
    // Matrix<int> m;
    int m[2][2];
    // neutral
    Node() {
        m[0][0] = 1;
        m[0][1] = 0;
        m[1][0] = 0;
        m[1][1] = 1;
    }


    explicit Node(char c){
        if (c == '?') {
            m [0][0] = 19;
            m [0][1] = 7;
            m [1][0] = 6;
            m [1][1] = 20;
        }
        else if (c == 'A' || c == 'O' || c == 'U' || c == 'E' || c == 'I' ) {
            m [0][0] = 0;
            m [0][1] = 1;
            m [1][0] = 1;
            m [1][1] = 0;
        }
        else if (c == 'H') {
            m [0][0] = 1;
            m [0][1] = 0;
            m [1][0] = 1;
            m [1][1] = 0;
        }
        else if (c == 'S' || c == 'D') {
            m [0][0] = 0;
            m [0][1] = 1;
            m [1][0] = 0;
            m [1][1] = 1;
        }
        else {
            m [0][0] = 1;
            m [0][1] = 0;
            m [1][0] = 0;
            m [1][1] = 1;
        }
    }

    void change(char c) {
        if (c == '?') {
            m [0][0] = 19;
            m [0][1] = 7;
            m [1][0] = 6;
            m [1][1] = 20;
        }
        else if (c == 'A' || c == 'O' || c == 'U' || c == 'E' || c == 'I' ) {
            m [0][0] = 0;
            m [0][1] = 1;
            m [1][0] = 1;
            m [1][1] = 0;
        }
        else if (c == 'H') {
            m [0][0] = 1;
            m [0][1] = 0;
            m [1][0] = 1;
            m [1][1] = 0;
        }
        else if (c == 'S' || c == 'D') {
            m [0][0] = 0;
            m [0][1] = 1;
            m [1][0] = 0;
            m [1][1] = 1;
        }
        else {
            m [0][0] = 1;
            m [0][1] = 0;
            m [1][0] = 0;
            m [1][1] = 1;
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

    // change this function according to the problem
    Node merge(Node & lf, Node & ri) {
        Node ans = Node();
        // ans.min = min(lf.min , ri.min);
        ans.m[0][0] = (1LL * lf.m[0][0] * ri.m[0][0] + 1LL * lf.m[0][1] * ri.m[1][0])%MOD;
        ans.m[0][1] = (1LL * lf.m[0][0] * ri.m[0][1] + 1LL * lf.m[0][1] * ri.m[1][1])%MOD;
        ans.m[1][0] = (1LL * lf.m[1][0] * ri.m[0][0] + 1LL * lf.m[1][1] * ri.m[1][0])%MOD;
        ans.m[1][1] = (1LL * lf.m[1][0] * ri.m[0][1] + 1LL * lf.m[1][1] * ri.m[1][1])%MOD;
        // ans.m = lf.m * ri.m;
        return ans;
    }

    void init(vector<char> & v, int ni, int lx, int rx) {
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

    void init(vector<char> & arr) {
        init(arr,0,0,treeSize);
    }

    void set(int idx, char val, int ni, int lx, int rx) { // 0-indexed

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

    void set (int idx, char val) {
        set(idx, val, 0, 0, treeSize);
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
        return get(l, r, 0, 0, treeSize).m[0][0];
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<char> v(n);
    string s; cin >> s;
    for(int i = 0; i < n; ++i) v[i] = s[i];
    SegTree st(n);
    st.init(v);
    cout << st.get(0, n) << "\n";
    while(q--) {
        int idx; cin >> idx;
        char c ; cin >> c;
        st.set(idx-1, c);
        cout << st.get(0, n) << "\n";
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
