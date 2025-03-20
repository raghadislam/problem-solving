/* problem link: https://usaco.org/index.php?page=viewproblem2&cpid=644
 * solution by: Raghad Islam
 * date: 22-3-2025 
 */
#include <bits/stdc++.h>
using namespace std;

void fileIO(void)
{

#ifndef ONLINE_JUDGE

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

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
int const N = 3005;
int n,m;
bool visited[N];
vector<int> adj[N];
int freq[N];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c = 0;
    int el = 0;
    vector<int> v;
    for(int j = 0; j < n; j++) {
        for(int i = 1; i <= n; i++) {
            if (freq[i]) {
                continue;
            }
            if(!visited[i]) {
                c++;
                dfs(i);
            }
        }
        if (c==1) {
            cout << "YES\n";
        }
        else cout << "NO\n";
        c = 0;
        memset(visited, 0, sizeof(visited));
        cin >> el;
        v = adj[el];
        adj[el].clear();
        freq[el] = 1;
    }
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
