/* problem link:  https://atcoder.jp/contests/dp/tasks/dp_v
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
const int N = 1e5 + 5;
vector<int> adj[N];
int sum[N];
int dp[N];
int res[N];
int mod;

int mx = 0;

void dfs(int u,int p) {
    dp[u] = 1;
    for(int v: adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u] = (dp[u]%mod * dp[v]%mod)%mod;
    }
    dp[u] = (dp[u]%mod + 1)%mod;
}

void calc(int u,int p) {
    res[u] = (dp[u] - 1 + mod) % mod;
    int n = adj[u].size();
    vector<int> pref(n + 1, 1), suffix(n + 2, 1);
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] * dp[adj[u][i]] % mod;
        suffix[n-i] = suffix[n-i+1] * dp[adj[u][n-i-1]] % mod;
    }
    for (int i = 0; i < n; i++) {
        int v = adj[u][i];
        if (v != p) {
            int oldV = dp[v], oldU = dp[u];
            dp[u] = (pref[i] * suffix[i+2] % mod + 1) % mod;
            dp[v] = (oldV - 1 + mod) % mod * dp[u] % mod;
            dp[v] = (dp[v] + 1) % mod;


            calc(v, u);


            dp[v] = oldV;
            dp[u] = oldU;
        }
    }
}

void solve() {
    int n; cin >> n >> mod;
    for(int i = 0; i <n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    calc(1,0);
    for (int i = 1; i <= n; i++)
        cout << res[i] << endl;}

signed main(){
    fileIO();
    fastIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
