/* problem link: https://www.spoj.com/problems/DISQUERY/
 * solution by: Raghad Islam
 * date: 25-7-2025 
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

const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;

struct LCA {
    int n, lg;
    vector<vector<pair<int,int>>> adj;
    vector<int> depth;
    vector<vector<int>> up, qu1, qu2;

    LCA(int sz) {
        n = sz, lg = __lg(sz);
        depth = vector<int>(n + 1);
        adj = vector<vector<pair<int,int>>>(n + 1);
        up = vector<vector<int>>(n + 1, vector<int>(lg + 1) );
        qu1 = vector<vector<int>>(n + 1, vector<int>(lg + 1) );
        qu2 = vector<vector<int>>(n + 1, vector<int>(lg + 1) );
    }

    int query1(int a, int b) {
        return min(a,b);
    }

    int query2(int a, int b) {
        return max(a,b);
    }

    int path1(int a, int dist) { // a -> node, dist -> distance from the node to the lca
        int ans = INT_MAX;
        for (int i = lg; i >= 0; --i) {
            if (dist >= (1 << i)) {
                ans = query1(ans, qu1[a][i]);
                a = up[a][i];
                dist -= (1 << i);
            }
        }
        return ans;
    }

    int path2(int a, int dist) { // a -> node, dist -> distance from the node to the lca
        int ans = INT_MIN;
        for (int i = lg; i >= 0; --i) {
            if (dist >= (1 << i)) {
                ans = query2(ans, qu2[a][i]);
                a = up[a][i];
                dist -= (1 << i);
            }
        }
        return ans;
    }

    void build(int u, int p) {
        up[u][0] = p;
        for (int i = 1; i <= lg; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
            qu1[u][i] = query1(qu1[u][i - 1], qu1[up[u][i - 1]][i - 1]);
            qu2[u][i] = query2(qu2[u][i - 1], qu2[up[u][i - 1]][i - 1]);
        }
        for (auto[v, c] : adj[u]) {
            if (v == up[u][0]) continue;
            depth[v] = depth[u] + 1;
            qu1[v][0] = c;
            qu2[v][0] = c;
            build(v, u);
        }
    }

    int kthAncestor(int a, int k) {
        if (depth[a] < k) return -1;
        for (int i = lg; i >= 0; --i)
            if ( k >= (1 << i) ) a = up[a][i], k -= (1 << i);
        return a;
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int k = depth[a] - depth[b];
        for (int i = lg; i >= 0; --i)
            if ( k & (1 << i) ) a = up[a][i];

        if (a == b) return a;

        for (int i = lg; i >= 0; --i)
            if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
        return up[a][0];
    }

    int distance(int a, int b) {
        int c = lca(a, b);
        int x = depth[a] - depth[c];
        int y = depth[b] - depth[c];
        return x + y;
    }

    bool isOnPath(int u, int v, int c) { // does node c exist in the path between u and v
        int lca1 = lca(u, v);
        int lca2 = lca(u, c);
        int lca3 = lca(v, c);
        return lca1 == c or (lca2 == lca1 and lca3 == c) or (lca3 == lca1 and lca2 == c);
    }

    int calc1(int u, int v) {
        int c = lca(u, v);
        int distU = distance(u, c);
        int distV = distance(v, c);

        int ans = min(path1(u, distU) , path1(v, distV)); // change the operation according what needed
        return ans;
    }
    int calc2(int u, int v) {
        int c = lca(u, v);
        int distU = distance(u, c);
        int distV = distance(v, c);

        int ans = max(path2(u, distU) , path2(v, distV)); // change the operation according what needed
        return ans;
    }

    int kthNode(int u, int v, int k) { // kth node in the path between u and v
        // k should be  0-indexed
        int c = lca(u, v);
        int distU = distance(u, c);
        int dist = distance(u, v);

        if (k <= distU)
            return kthAncestor(u, k);
        else
            return kthAncestor(v, dist - k);
    }
};

void solve() {
    int n, q; cin >> n;
    LCA lca(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c; cin >> u >> v >> c;
        lca.adj[u].push_back({v,c});
        lca.adj[v].push_back({u,c});
    }
    lca.build(1, 0);
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca.calc1(u, v) << ' ' << lca.calc2(u,v) << '\n';
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
