/* problem link: https://codeforces.com/problemset/problem/103/B
 * solution by: Raghad Islam
 * date: 2-12-2023 
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

int dx_all[8] = { 1, 0, -1, 0, 1, 1, -1, -1 },
        dy_all[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dx[4] = { 1, 0, -1, 0 },
        dy[4] = { 0, 1, 0, -1 };

typedef long long ll;
#define int ll
#define all(x) x.begin(),x.end()

int n, m;
vector<vector<int>>adj;
vector<int>vis;

bool isCyclic(int u, int p){
    vis[u] = 1;
    for(auto v : adj[u]){
        if (vis[v] && v != p)   return true;
        else if (!vis[v]) {
            if (isCyclic(v, u)) return true;
        }
    }
    return false;
}

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}




void solve(int t) {
    cin >> n >> m;

    if(n == 1 && m == 0)
    {
        cout << "NO" << '\n';
        return;
    }   
    adj.resize(n + 1), vis.resize(n + 1);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }

    if(cnt > 1){
        cout << "NO";

        return;
    }
    vis.resize(n + 1); 
    vis.clear();
    cout << ((isCyclic(u, -1) && n == m) ? "FHTAGN!" : "NO");

}

signed main() {
    fastIO(); fileIO();
    int tests = 1, t = 1; 
    while(tests--) {
        solve(t);
        t++;
    }
    return 0;
}