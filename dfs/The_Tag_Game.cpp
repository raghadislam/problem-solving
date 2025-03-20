/* problem link: https://codeforces.com/contest/813/problem/C
 * solution by: Raghad Islam
 * date: 20-3-2025 
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
int const N = 200005;
int n,m,x;
bool visited1[N];
bool visited2[N];
vector<int> adj[N];
pair<int,int> dist[N];
void dfs1(int u, int i) {
    dist[u].second =  i;
    visited1[u] = true;
    for (int v : adj[u]) {
        if (!visited1[v]) {
            dfs1(v, i + 1);
        }
    }
}
void dfs2(int u, int i) {
    dist[u].first =  i;
    visited2[u] = true;
    for (int v : adj[u]) {
        if (!visited2[v]) {
            dfs2(v, i + 1);
        }
    }
}
void solve() {
    cin >> n >> x;
    m = n-1;
    for(int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(x,0);
    int ans=0;
    for(int i=1; i<=n; i++){
        if(dist[i].first<dist[i].second){
            ans=max(ans, dist[i].second);
        }
    }
    cout << ans * 2 << '\n';
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
