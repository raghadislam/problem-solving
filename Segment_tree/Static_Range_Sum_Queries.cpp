/* problem link: https://cses.fi/problemset/task/1646
 * solution by: Raghad Islam
 * date: 21-5-2025 
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
 
    // neutral
    Node() {
        sum = 0;
    }
 
    explicit Node(int _sum) {
        sum = _sum;
    }
 
    void change(int val) {
        sum = val; // change according to the problem
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
        ans.sum = lf.sum + ri.sum;
        return ans;
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
 
    int get(int l, int r) {
        return get(l, r, 0, 0, treeSize).sum;
    }
};
 
 
 
 
void solve() {
    int n, q;
    cin >> n >> q;;
    vector<int> v(n);
    SegTree seg(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        seg.set(i, v[i]);
    }
 
    // seg.set(2, 4);
    while (q--) {
        int l,r; cin >> l >> r;
        cout << seg.get(l-1, r) << "\n";
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

