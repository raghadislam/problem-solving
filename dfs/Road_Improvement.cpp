/* problem link: https://codeforces.com/contest/638/problem/C
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
bool visited[N];
map<pair<int,int>,int> mp;
vector<int> adj[N];
vector<int> days[N];
vector<pair<int,int>> colors[N];
void dfs(int u, int parentColor) {
    visited[u] = true;
    int curColor = 0;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (curColor == parentColor) {
                curColor++;
            }
            colors[curColor].push_back(make_pair(u, v));
            dfs(v, curColor);
            curColor++;
        }
    }
}
void solve() {
    cin >> n;
    m = n-1;
    for(int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[make_pair(u,v)] = i+1;
        mp[make_pair(v,u)] = i+1;
    }
    int numOdDays = 0;
    for (int i = 1; i <= n; i++) {
        numOdDays = max(numOdDays, (int)adj[i].size());
    }
    dfs(1, -1);
    cout << numOdDays << '\n';
    for (int i = 0; i < numOdDays; i++) {
        cout << colors[i].size() << ' ';
        for (auto p : colors[i]) {
            cout << mp[{p.first, p.second}] <<' ';
        }
        cout << '\n';
    }
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
