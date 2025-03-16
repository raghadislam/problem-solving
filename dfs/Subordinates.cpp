/* problem link: https://cses.fi/problemset/task/1674
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
const int N = 200009;
enum {notVisited, inProgress, finished};
vector<int> adj[N];
bool visited[N];
int state[N];
bool cycle = false;
void dfs(int u, vector<int>&ans) {
    visited[u] = true;
    ans[u] = adj[u].size();
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v,ans);
        }
        ans[u] += ans[v];
    }
}
 
int first[N];
 
void solve() {
    vector<int> ans(N);
    int n; cin>>n;
    for (int i = 2; i <= n; i++) {
        int boss; cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1,ans);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
