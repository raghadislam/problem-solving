/* problem link: https://cses.fi/problemset/task/1667
 * solution by: Raghad Islam
 * date: 17-4-2025
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
int n,m;
vector <int> adj[N];
int p[N];
int dis[N];
void BFS(int x) {
    queue<int> q;
    q.push(x);
    memset(dis,-1,sizeof(dis));
    dis[x] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if(dis[v] == -1) {
                p[v] = u;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
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
    BFS(1);
    // for(int i = 1; i <= n; i++) {
    //     cout << dis[i] << " ";
    // }
    if (dis[n] == -1) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << dis[n] + 1 << '\n';
    vector<int> ans;
    int cnt = dis[n];
    int ch = n;
    while(cnt--) {
        ans.push_back(p[ch]);
        ch = p[ch];
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << n ;
 
}
signed main(){
    fileIO();
    fastIO();
  // tests
    solve();
    return 0;
}

