/* problem link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
 * solution by: Raghad Islam
 * date: 6-6-2025 
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


struct Node {
    int value;

    // neutral
    Node() {
        value = 0;
    }

    explicit Node(int val) {
        value = val;
    }

    void change(int val) {
        value = val; // change according to the problem
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
        ans.value = lf.value + ri.value;
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

    int get(int k, int l, int r, int ni, int lx, int rx) { // 0-indexed, r not included
        // if (l >= rx || r <= lx) return Node();
        // if (lx >= l && rx <= r) return segData[ni];
        if (lx == rx - 1) return lx;

        int mid = (lx + rx) / 2;
        if (segData[ni * 2 + 1].value > k)
            return get(k, l, r, ni * 2 + 1, lx, mid);
        else return get(k - segData[ni * 2 + 1].value, l, r, ni * 2 + 2, mid, rx);
        // return merge(lf, ri);
    }

    int get(int k, int l, int r) {
        return get(k, l, r, 0, 0, treeSize);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegTree st(n);
    for (int i = 0; i < n; i++) { // 0 -> n-1
        st.set(i, 1);
    }
    vector<int> ans;
    for (int i = n-1; i >= 0; i--) {
        int k = (i+1) - v[i] - 1;
        int val = st.get(k, 0, n);
        ans.push_back(val+1);
        st.set(val, 0);
    }
    for (int o = ans.size() - 1; o >= 0; o--) {
        cout << ans[o] << ' ';
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
