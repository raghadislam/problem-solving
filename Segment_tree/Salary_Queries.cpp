/* problem link: https://cses.fi/problemset/task/1144
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
    int salary;

    // neutral
    Node() {
        salary = 0;
    }

    explicit Node(int val) {
        salary = val;
    }

    void change(int val) {
        salary += val; // change according to the problem
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
        ans.salary = lf.salary + ri.salary;
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
        return get(l, r, 0, 0, treeSize).salary;
    }
};

enum {
    questionMark,
    exclamationMark,
};
vector<int> comp;

int id(int x) {
    return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        comp.push_back(v[i]);
    }

    vector<array<int,3>> queries(q);
    for (int i = 0; i < q; i++) {
        char op; cin >> op;
        if (op == '?') {
            queries[i][0] = questionMark;
            int a, b;
            cin >> a >> b;
            queries[i][1] = a;
            queries[i][2] = b;
            comp.push_back(a);
            comp.push_back(b);
        }
        else {
            queries[i][0] = exclamationMark;
            int k, x;
            cin >> k >> x;
            queries[i][1] = k;
            queries[i][2] = x;
            comp.push_back(x);
        }
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    SegTree st = SegTree(comp.size());
    for (int i = 0; i < n; ++i) {
        st.set(id(v[i]), 1);
    }
    for (int i = 0; i < q; ++i) {
        int op = queries[i][0];
        if (op == questionMark) {
            int a = queries[i][1];
            int b = queries[i][2];
            a = id(a);
            b = id(b);
            cout << st.get(a, b + 1) << '\n';
        }
        else {
            int k = queries[i][1] - 1;
            int x = queries[i][2];
            int Old = id(v[k]);
            int New = id(x);
            st.set(Old, -1);
            st.set(New, 1);
            v[k] = x;
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
