/* problem link: https://codeforces.com/contest/1702/problem/G2
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
    vector<vector<int>> adj;
    vector<int> depth;
    vector<vector<int>> up, qu;

    LCA(int sz) {
        n = sz, lg = __lg(sz);
        depth = vector<int>(n + 1);
        adj = vector<vector<int>>(n + 1);
        up = vector<vector<int>>(n + 1, vector<int>(lg + 1) );
        qu = vector<vector<int>>(n + 1, vector<int>(lg + 1) );
    }

    int query(int a, int b) {
        return 0;
    }

    int path(int a, int dist) {
        int ans = 0;
        for (int i = lg; i >= 0; --i) {
            if (dist >= (1 << i)) {
                ans = query(ans, qu[a][i]);
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
            qu[u][i] = query(qu[u][i - 1], qu[up[u][i - 1]][i - 1]);
        }
        for (int v : adj[u]) {
            if (v == up[u][0]) continue;
            depth[v] = depth[u] + 1;
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

    bool isOnPath(int u, int v, int c) {
        int lca1 = lca(u, v);
        int lca2 = lca(u, c);
        int lca3 = lca(v, c);
        return lca1 == c or (lca2 == lca1 and lca3 == c) or (lca3 == lca1 and lca2 == c);
    }

    int calc(int u, int v) {
        int c = lca(u, v);
        int distU = distance(u, c);
        int distV = distance(v, c);

        int ans = path(u, distU) + path(v, distV);
        return ans;
    }

    int kthNode(int u, int v, int k) {
        // k should be  0-indexed
        int c = lca(u, v);
        int distU = distance(u, c);
        int dist = distance(u, v);

        if (k <= distU)
            return kthAncestor(u, k);
        else
            return kthAncestor(v, dist - k);
    }
    bool isAncestor(int u, int v) {
        return lca(u, v) == u;
    }
};

void solve() {
    int n;
    cin >> n;
    LCA lca(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lca.adj[u].push_back(v);
        lca.adj[v].push_back(u);
    }
    lca.build(1, 0);
    int m; cin >> m;

    while (m--) {
        int k; cin >> k;
        vector<int> a(k);
        int mx = -1;
        int farthest;
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            if (lca.depth[a[i]] > mx) {
                mx = lca.depth[a[i]];
                farthest = a[i];
            }
        }

        int other;
        int dist = -1;
        for (int i = 0; i < k; ++i) {
            int d = lca.distance(a[i], farthest);
            if (d > dist) {
                dist = d;
                other = a[i];
            }
        }

        bool flag = true;
        for (int i = 0; i < k; ++i) {
            if (!lca.isOnPath(other, farthest, a[i])) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
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
