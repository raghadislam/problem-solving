/* problem link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
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
#define int ll

// ordered set
// To use it we must comment the #define int ll
//
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//  ordered_set o_set;
//  o_set.insert(num);
// Finding the count of elements less than or equal to num
//  o_set.order_of_key(num)
//  Deleting 2 from the set if it exists
// if (o_set.find(2) != o_set.end())
//     o_set.erase(o_set.find(2));
// Finding the second smallest element
// in the set using * because
//  find_by_order returns an iterator
// *(o_set.find_by_order(1))

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
        value += val; // change according to the problem
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

    Node get(int l, int r, int ni, int lx, int rx) { // 0-indexed, r not included
        if (l >= rx || r <= lx) return Node();
        if (lx >= l && rx <= r) return segData[ni];

        int mid = (lx + rx) / 2;
        Node lf = get(l, r, ni * 2 + 1, lx, mid);
        Node ri = get(l, r, ni * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, treeSize).value;
    }
};

void solve() {
    int n; cin >> n;
    SegTree st(n+1);
    // vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << st.get(x + 1, n+1) << ' ';
        st.set(x, 1);
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
