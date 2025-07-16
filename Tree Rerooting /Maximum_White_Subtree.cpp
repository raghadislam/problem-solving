/* problem link: https://codeforces.com/problemset/problem/1324/F
 * solution by: Raghad Islam
 * date: 7-7-2025 
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

vector<int> dp, sz, res, col;
vector<vector<int>> adj;

void dfs (int u, int p) {
    dp[u] = col[u] == 1 ? 1 : -1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] += dp[v] > 0 ? dp[v] : 0;
    }
}

void calc (int u, int p) {
    res[u] = dp[u];
    for (auto v : adj[u]) {
        if (v == p) continue;
        // v is the root
        if (dp[v] > 0) {
            dp[u] -= dp[v];
        }
        if (dp[u] > 0) {
            dp[v] += dp[u];
        }
        calc(v, u);

        if (dp[u] > 0) {
            dp[v] -= dp[u];
        }
        if (dp[v] > 0) {
            dp[u] += dp[v];
        }
    }
}



void solve() {
    int n; cin >> n;
    dp.resize(n + 1);
    sz.resize(n + 1);
    adj.resize(n + 1);
    res.resize(n + 1);
    col.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> col[i];

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    calc(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
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
