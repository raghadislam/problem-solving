/* problem link: https://cses.fi/problemset/task/1192
 * solution by: Raghad Islam
 * date: 22-3-2025 
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
int const N = 1005;
int n,m;
// bool visited[N];
bool visited[N][N];
// map<pair<int, int>, vector<pair<int,int>>> adj;
vector<pair<int,int>> adj[N][N];
 
// vector<pair<int,int>> adj[N];
char grid[N][N];
 
void dfs(pair<int,int> u) {
    visited[u.first][u.second] = true;
    for(auto v : adj[u.first][u.second]) {
        if(!visited[v.first][v.second]) {
            dfs(v);
        }
    }
}
 
void solve() {
 
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (i - 1 >= 0) {
                    if (grid[i - 1][j] == '.') {
                        adj[i-1][j].push_back({i,j});
                        adj[i][j].push_back({i-1,j});
                    }
                }
                if (j-1 >= 0) {
                    if (grid[i][j - 1] == '.') {
                        adj[i][j-1].push_back({i,j});
                        adj[i][j].push_back({i,j-1});
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                cnt++;
                dfs({i,j});
            }
        }
    }
    cout << cnt << endl;
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
