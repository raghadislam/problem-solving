/* problem link: https://codeforces.com/problemset/problem/580/C
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
int n, m;
vector<int> adj[N];
bool visited[N];
int state[N];
bool cycle = false;
int cats[N];
// int res = 0;

int dfs(int u, int numOfCats) {
    visited[u] = true;
    if (numOfCats + cats[u] > m) {
        return 0;
    }
    if (cats[u] == 0) {
        numOfCats = 0;
    }
    else numOfCats += cats[u];

    int res = 0;
    for (int v : adj[u]) {
        if (!visited[v]) {
            res += dfs(v, numOfCats);
        }
    }
    int gain = (adj[u].size() == 1 && u!=1);
    return res + gain;
}


void solve() {
    cin>>n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    for(int i = 0; i < n-1; i++) {
        int v, u;
        cin>>v>>u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    cout << dfs(1,0) << endl;

}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
