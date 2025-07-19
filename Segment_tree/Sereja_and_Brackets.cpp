/* problem link: https://codeforces.com/problemset/problem/380/C
 * solution by: Raghad Islam
 * date: 20-6-2024 
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

string s;

struct Node {
    int open;
    int closed;
    int complete;

    Node() {
        open = 0;
        closed = 0;
        complete = 0;
    }

    explicit Node(int val) {
        complete = 0;
        if (val) {
            open = 1;
            closed = 0;
        } else {
            open = 0;
            closed = 1;
        }
    }

    void change(int c, int val) {
      //  data[c] =  val; // change according to the problem
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
        ans.complete = lf.complete + ri.complete;
        int complete = min(lf.open, ri.closed);
        ans.open = lf.open + ri.open - complete;
        ans.closed = lf.closed + ri.closed - complete;
        ans.complete += complete;
        return ans;
    }

    void init(vector<int> & v, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < s.size())
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
        return get(l, r, 0, 0, treeSize).complete;
    }
};

// #define endl '\n'



void solve() {
    cin >> s;
    int sz = s.size();
    vector<int> v(sz);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') v[i] = 1;
        else if (s[i] == ')') v[i] = 0;
    }
    SegTree st(sz);
    st.init(v);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--;
        cout << st.get(l, r) * 2 << '\n';
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
