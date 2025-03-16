/* problem link: https://cses.fi/problemset/task/1666
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
const int N = 100005;
vector<int> adj[N];
bool visited[N];
vector<int> ans;
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
void solve() {
    int n,m; cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin>>v>>u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size() - 1<<endl;
    if (ans.size() > 1) {
        for(int i = 0; i < ans.size() - 1; i++) {
            cout << ans[i] <<' ' << ans[i + 1] << endl;
        }
    }

}
signed main(){
    fileIO();
    fastIO();
    // tests
    solve();
    return 0;
}
