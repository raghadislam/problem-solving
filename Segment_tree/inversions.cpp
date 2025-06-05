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

struct Node {
    int numOfOnes;

    // neutral
    Node() {
        numOfOnes = 0;
    }

    explicit Node(int val) {
        numOfOnes = val;
    }

    void change(int val) {
        numOfOnes = val;
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

    Node merge(Node &lf, Node &ri) {
        Node ans = Node();
        ans.numOfOnes = lf.numOfOnes + ri.numOfOnes;
        return ans;
    }

    void init(vector<int> &v, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < v.size())
                segData[ni] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        init(v, ni * 2 + 1, lx, mid);
        init(v, ni * 2 + 2, mid, rx);
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void init(vector<int> &arr) {
        init(arr, 0, 0, treeSize);
    }

    void set(int idx, int val, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            segData[ni].change(val);
            return;
        }

        int mid = (lx + rx) / 2;

        if (idx < mid) {
            set(idx, val, ni * 2 + 1, lx, mid);
        } else {
            set(idx, val, ni * 2 + 2, mid, rx);
        }

        segData[ni] = merge(segData[ni * 2 + 1], segData[ni * 2 + 2]);
    }

    void set(int idx, int val) {
        set(idx, val, 0, 0, treeSize);
    }

    int get(int k, int l, int r, int ni, int lx, int rx) { // 0-indexed, r not included
        if (lx == rx - 1) {
            return lx;
        }
        int mid = (lx + rx) / 2;
        if (segData[2 * ni + 1].numOfOnes > k) {
            return get(k,l,r, 2 * ni + 1, lx, mid);
        } else {
            return get(k - segData[2 * ni + 1].numOfOnes,l,r, 2 * ni + 2, mid, rx);
        }
    }

    int get(int k, int l, int r) {
        return get(k, l, r, 0, 0, treeSize);
    }

};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegTree st(n);
    st.init(arr);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int idx; cin >> idx;
            arr[idx] = 1 - arr[idx];
            st.set(idx, arr[idx]);
        }
        else if (op == 2) {
            int k; cin >> k;
            cout << st.get(k,0,n) << '\n';
        }
    }
}

signed main() {
    fileIO();
    fastIO();
    int t = 1;
  //  cin >> t;
     while(t--)
    solve();
    // }
    return 0;
}


