/* problem link: https://codeforces.com/contest/378/problem/C
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
int n,m,k, s, targ;
char maze[508][508];
bool vis[508][508];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool valid(int i, int j) {
    return (i >= 0 && i < 500 && j >= 0 && j < 500);
}
int cnt = 0;
void BFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    cnt++;
    while (!q.empty()) {
        int cc = cnt;
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (cnt == targ) {
                return;
            }
            int r = p.first + dx[i];
            int c = p.second + dy[i];
            if (valid(r,c) && vis[r][c] == 0 && maze[r][c] == '.') {
                vis[r][c] = 1;
                q.push({r,c});
                cnt++;
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    int x, y;
    bool f = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                s++;
                if (f) {
                    f = 0;
                    x = i, y = j;
                }
            }
        }
    }
    targ= s - k;
    BFS({x,y});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                if (vis[i][j]) cout << maze[i][j];
                else cout << 'X';
            }
            else cout << maze[i][j];
        }
        cout << endl;
    }

}
signed main(){
    fileIO();
    fastIO();
 //  tests
    solve();
    return 0;
}
