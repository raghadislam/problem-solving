/* problem link: https://codeforces.com/group/Rilx5irOux/contest/534682/problem/J
 * solution by: Raghad Islam
 * date: 30-6-2025 
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
#define int long long
const int MAX_N = 1e5 + 5;
const int MAX_A = 1e6 + 5;

int block_size;

struct Query {
    int l, r, x, z, idx;
    bool operator<(const Query& other) const {
        int block_a = l / block_size;
        int block_b = other.l / block_size;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

struct Node {
    int sum;

    Node() {
        sum = 0;
    }

    explicit Node(int val) {
        sum = val;
    }

    void change(int val) {
        sum = val;
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

    Node merge(const Node &lf, const Node &ri) {
        return Node(lf.sum + ri.sum);
    }

    void set(int idx, int val, int ni, int lx, int rx) {
        if (lx == rx - 1) {
            segData[ni].change(val);
            return;
        }
        int mid = (lx + rx) / 2;
        if (idx < mid) set(idx, val, 2 * ni + 1, lx, mid);
        else set(idx, val, 2 * ni + 2, mid, rx);
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void set(int idx, int val) {
        set(idx, val, 0, 0, treeSize);
    }

    Node get(int l, int r, int ni, int lx, int rx) {
        if (l >= rx || r <= lx) return Node();
        if (lx >= l && rx <= r) return segData[ni];
        int mid = (lx + rx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r) { // [l, r)
        return get(l, r, 0, 0, treeSize).sum;
    }
};


int A[MAX_N];
int freq[MAX_A];
int freq_cnt[MAX_N];

void add(int idx, SegTree& st) {
    int val = A[idx];
    int f = freq[val];
    freq_cnt[f]--;
    if (f > 0) st.set(f, freq_cnt[f] > 0 ? 1 : 0);

    freq[val]++;
    freq_cnt[freq[val]]++;
    st.set(freq[val], freq_cnt[freq[val]] > 0 ? 1 : 0);
}

void remove(int idx, SegTree& st) {
    int val = A[idx];
    int f = freq[val];
    freq_cnt[f]--;
    if (f > 0) st.set(f, freq_cnt[f] > 0 ? 1 : 0);

    freq[val]--;
    freq_cnt[freq[val]]++;
    st.set(freq[val], freq_cnt[freq[val]] > 0 ? 1 : 0);
}

void solve() {
    int n;
    cin >> n;
    block_size = sqrt(n);

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r, x, z;
        cin >> l >> r >> x >> z;
        queries[i] = {l - 1, r - 1, x, z, i};
    }

    sort(queries.begin(), queries.end());
    SegTree st(n + 5);
    vector<string> answers(q);

    int currL = 0, currR = -1;

    for (const auto& query : queries) {
        while (currL > query.l) add(--currL, st);
        while (currR < query.r) add(++currR, st);
        while (currL < query.l) remove(currL++, st);
        while (currR > query.r) remove(currR--, st);

        int cnt = st.get(query.x, query.z + 1);
        int need = query.z - query.x + 1;
        answers[query.idx] = (cnt == need ? "YES" : "NO");
    }

    for (int i = 0; i < answers.size(); ++i) {
        cout << answers[i] << "\n";
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
