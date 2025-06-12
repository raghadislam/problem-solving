/* problem link: https://codeforces.com/problemset/problem/514/D
 * solution by: Raghad Islam
 * date: 12-6-2025 
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

int n,m,k;
struct Node {
    // int types[6] = {0};
    vector<int> types = {0,0,0,0,0,0,0,0,0,0};

    // neutral
    Node() {
        types.assign(20, 0);
    }

    explicit Node(vector<int> &v) {
        for (int i = 0; i < m; i++) {
            types[i] = v[i];
        }
    }

    void change(int val) {
        // min = val; // change according to the problem
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
        for (int i = 0; i < m; i++) {
            ans.types[i] = max(lf.types[i], ri.types[i]);
        }
        return ans;
    }

    void init(vector<vector<int>> & v, int ni, int lx, int rx) {
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

    void init(vector<vector<int>> & arr) {
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
        if (lx >= l && rx <= r) return segData[ni];

        int mid = (lx + rx) / 2;
        Node lf = get(l, r, ni * 2 + 1, lx, mid);
        Node ri = get(l, r, ni * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    vector<int> get(int l, int r) {
        return get(l, r, 0, 0, treeSize).types;
    }
};




void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    SegTree st(n);
    st.init(v);

    int l = 0, mx_len = -1;
    vector<int> ans;
    for (int  r = 1; r <= n; r++) {
        vector<int> vec = st.get(l, r);
        int cnt = 0;
        for (int  i = 0; i < m; i++) {
            cnt += vec[i];
        }
        while (cnt > k) {
            l++;
            vec = st.get(l, r);
            cnt = 0;
            for (int  i = 0; i < m; i++) {
                cnt += vec[i];
            }
        }
        if (r-l > mx_len) {
            mx_len = r - l;
            ans = vec;
        }
    }
    for (int  i = 0; i < m; i++) {
        cout << ans[i] << " ";
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
