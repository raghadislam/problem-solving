/* problem link: https://codeforces.com/problemset/problem/445/B
 * solution by: Raghad Islam
 * date: 13-5-2025 
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
const int N = 55;
int n, m;

vector<int> adj[N];
bool visited[N];
int c = 0;
void dfs(int u){
    visited[u] = true;
    c++;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            c = 0;
            dfs(i);
            int x = c;
            if (x > 0)
                ans *= (1LL << (c-1));
        }
    }
    cout << ans;
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}
