/* problem link: https://codeforces.com/problemset/problem/377/A
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

int n, m, k;
vector<vector<char>>grid;
vector<vector<bool>>vis;
vector<pair<int, int>>idx;

bool valid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m) && !vis[x][y];
}

void dfs(int x, int y, char taken) {
    vis[x][y] = true;
    idx.emplace_back(x, y);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(valid(nx, ny) && grid[nx][ny] == taken) {
            dfs(nx, ny, taken);
        }
    }
}



void solve(int t) {
    cin >> n >> m >> k;
    grid.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];

            if(grid[i][j] == '#'){
                vis[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!vis[i][j]) {
                dfs(i, j, grid[i][j]);
            }
        }
    }
   
 int sz ; 
 sz = idx.size();
    for (int i = sz - 1; i >= 0 && k; --i) {
        k--;
        grid[idx[i].first][idx[i].second] = 'X';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    fastIO(); fileIO();
    int tests = 1, t = 1; //cin>>tests;
    while(tests--) {
        solve(t);
        t++;
    }
    return 0;
}