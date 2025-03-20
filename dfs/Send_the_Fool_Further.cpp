/* problem link: https://codeforces.com/contest/802/problem/J
 * solution by: Raghad Islam
 * date: 14-3-2025 
 */
#include <bits/stdc++.h>
using namespace std;

void fileIO(void)
{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

}

void fastIO(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}

typedef long long ll;
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
int const N = 109;
int n;
bool visited[N];
int cost[N][N];
vector<int> adj[N];
int dfs(int u) {
    visited[u] = true;
    int ans = 0;
    for (int v : adj[u]) {
        if (!visited[v]) {
            ans = max(ans, dfs(v) + cost[u][v]);
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v] = c;
        cost[v][u] = c;
    }
    cout << dfs(0) << endl;
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
