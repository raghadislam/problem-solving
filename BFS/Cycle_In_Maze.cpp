/* problem link: https://codeforces.com/contest/769/problem/C
 * solution by: Raghad Islam
 * date: 21-4-2025
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void)
{

#ifndef ONLINE_JUDGE // DLRU

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
int n,m,k;
int dist[1005][1005];
char grid[1005][1005];
int val = 1;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

string ans;
void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = p.first + dx[i];
            int ty = p.second + dy[i];
            if(valid(tx, ty) && grid[tx][ty] != '*' && dist[tx][ty] == -1) {
                q.push({tx, ty});
                dist[tx][ty] = dist[p.first][p.second] + 1;
            }
        }
    }
}

string res;

void solve() {
    cin >> n >> m >> k;
    if (k&1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    memset(dist, -1, sizeof(dist));
    int st_x, st_y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') {
                st_x = i;
                st_y = j;
            }
        }

    BFS(st_x, st_y);

    int x = st_x, y = st_y;
    for (int i = 0; i < k; i++)
    {
        int ok = 0;
        for(int j = 0; j < 4; j++)
        {
            int xx = x + dx[j];
            int yy = y + dy[j];
            if (valid(xx,yy) && dist[xx][yy]!= -1 && dist[xx][yy] <= k - (i + 1))
            {
                res.push_back(dir[j]);
                x = xx;
                y = yy;
                ok = 1;
                break;
            }
        }
        if (!ok)
        {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    cout << res << endl;
}


signed main(){
    fileIO();
    fastIO();
 //  tests
    solve();
    return 0;
}
