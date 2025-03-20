/* problem link: https://codeforces.com/contest/29/problem/C
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
int const N = 100005;
int n,m;
map<int, bool> visited;
map<int,vector<int>> adj;
int f = 0;
vector<int> v1;
vector<int> v2;
int start;
void dfs(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            int x = v;
            if (f == 0) {
                v1.push_back(v);
            }
            else {
                v2.push_back(v);
            }
            dfs(v);
            if (u == start) f = 1;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        start = u;
    }
    // cout << start << endl;
    v1.push_back(start);
    dfs(start);
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    // cout << '\n';
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
