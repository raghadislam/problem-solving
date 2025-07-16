/* problem link: https://codeforces.com/problemset/problem/1970/C3
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
int depth[N];
bool dp[N];
int root;

void dfs(int u,int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u] = dp[u] || !dp[v];
    }
}

int res[N];
void calc(int u,int p) {
    res[u] = dp[u];
    int c = 0;
    for(int v : adj[u]) {
        c+= !dp[v];
    }
    for(int v : adj[u]) {
        if(v == p) continue;
        int tmp = dp[v];

        if (c == 1) {
            if (dp[v] == 0) dp[u] = 0;
            else dp[u] = 1;
        } else {
            dp[u] = (c > 1);
        }
        dp[v] = dp[v] || !dp[u];

        calc(v, u);

        dp[v] = tmp;
        dp[u] = dp[u] || !dp[v];
    }
}

void solve() {
    cin >> n >> t;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1   ,0);
    calc(1,0);
    while (t--) {
        int v; cin >> v;
        cout << (res[v] ? "Ron" : "Hermione")<< "\n";
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
