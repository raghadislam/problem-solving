/* problem link: https://codeforces.com/problemset/problem/52/C
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



struct Node {
    int val;
    int lazy;
    bool isLazy;

    Node() {
        val = 1e18;
        lazy = 0;
        isLazy = false;
    }

    explicit Node(int _val) {
        val = _val;
        lazy = 0;
        isLazy = false;
    }

    void change(int _val) {
        val = _val;
    }

    void updateNode(int _val, int lx, int rx) {
        val += _val;
        lazy += _val;
        isLazy = true;
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
        ans.val = min(lf.val, ri.val);
        return ans;
    }

    void propagate(int ni, int lx, int rx) {
        if (rx - lx == 1 || !segData[ni].isLazy) return;
        int mid = (lx + rx) / 2;

        segData[ni * 2 + 1].updateNode(segData[ni].lazy, lx, mid);
        segData[ni * 2 + 2].updateNode(segData[ni].lazy, mid, rx);

        segData[ni].isLazy = false;
        segData[ni].lazy = 0;

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

    void update(int val, int l, int r, int ni, int lx, int rx) {
        propagate(ni, lx, rx);

        if (l >= rx || r <= lx) return;
        if (lx >= l && rx <= r) {
            segData[ni].updateNode(val, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        update(val, l, r, ni * 2 + 1, lx, mid);
        update(val, l, r, ni * 2 + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1],segData[2 * ni + 2]);
    }
    void update(int val, int l, int r) {
        update(val, l, r, 0, 0, treeSize);
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

    int get(int l, int r) {
        return get(l, r, 0, 0, treeSize).val;
    }
};


void solve() {
    int n, m; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> m;
    SegTree st(n);
    st.init(v);
    while (m--) {
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) nums.push_back(num);
        if (nums.size() == 2) {
            int l = nums[0], r = nums[1];
            if (r < l) {
                int mn = st.get(l, n);
                mn = min(mn, st.get(0, r + 1));
                cout << mn << '\n';
            }
            else
                cout << st.get(l,r+1) << '\n';
        }
        else {
            int l = nums[0], r = nums[1], val = nums[2];
            if (r < l) {
                st.update(val, l, n);
                st.update(val, 0, r+1);
            }
            else
                st.update(val, l, r+1);
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
