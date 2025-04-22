/* problem link: https://www.spoj.com/problems/PT07Y/en/
 * solution by: Raghad Islam
 * date: 19-11-2023 
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
int const N = 1000005;
bool visited[N];
int temp[N];
int there_is_tolt_at[N];
int subtree_sum[N];
vector<int> adj[N];
int root, cut1 = -1, cut2 = -1, total=0;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    if (cnt == 1 && m == n - 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
