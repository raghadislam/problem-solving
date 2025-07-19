/* problem link: https://codeforces.com/contest/1187/problem/E
 * solution by: Raghad Islam
 * date: 17-7-2025 
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
int n, t;
const int N = 2e5 + 5;
vector<int> adj[N];
int subTreeSz[N];
int dp[N];
int root;

// void subTree(int u,int p) {
//     subTreeSz[u] = 1;
//     for(int v : adj[u]) {
//         if(v == p) continue;
//         subTree(v, u);
//         subTreeSz[u] += subTreeSz[v];
//     }
// }

void dfs(int u,int p) {
    subTreeSz[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        subTreeSz[u] += subTreeSz[v];
        dp[u] += dp[v] + subTreeSz[v];
    }
}

int res[N];
void calc(int u,int p) {
    res[u] = dp[u];
    for(int v : adj[u]) {
        if(v == p) continue;

        subTreeSz[u] -= subTreeSz[v];
        dp[u] -= dp[v] + subTreeSz[v];

        subTreeSz[v] += subTreeSz[u];
        dp[v] += dp[u] + subTreeSz[u];

        calc(v, u);

        subTreeSz[v] -= subTreeSz[u];
        dp[v] -= dp[u] + subTreeSz[u];
        subTreeSz[u] += subTreeSz[v];
        dp[u] += dp[v] + subTreeSz[v];

    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }

    dfs(1,0);
    calc(1,0);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, res[i]);
    }
    cout << mx << '\n';
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
