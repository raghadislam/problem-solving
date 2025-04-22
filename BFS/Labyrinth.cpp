/* problem link: https://cses.fi/problemset/task/1193
 * solution by: Raghad Islam
 * date: 19-4-2025
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
int n,m;
int dist[1005][1005];
char grid[1005][1005];
int val = 1;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
//          d  l  r  u

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

vector<char> ans;
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
            if(valid(tx, ty) && grid[tx][ty] != '#' && dist[tx][ty] == -1) {
                q.push({tx, ty});
                dist[tx][ty] = dist[p.first][p.second] + 1;
            }
        }
    }

}

void solve() {
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    int st_x, st_y, en_x, en_y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                st_x = i;
                st_y = j;
            }
            else if (grid[i][j] == 'B') {
                en_x = i;
                en_y = j;
            }
        }
    
    BFS(st_x, st_y);

    if (dist[en_x][en_y] != -1) {
        cout << "YES" << endl;
        cout << dist[en_x][en_y] << endl;
        int x = en_x, y = en_y;
        int d = dist[x][y];
        string s;
        while (d) {
            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(dist[tx][ty] == (d - 1)) {
                    d = d - 1;
                    x = tx;
                    y = ty;
                    if ( i == 0 ) s.push_back('D');
                    else if (i == 1) s.push_back('L');
                    else if (i == 2) s.push_back('R');
                    else if (i == 3) s.push_back('U');
                    break;
                }
            }
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'D') cout << 'U';
            else if (s[i] == 'L') cout << 'R';
            else if (s[i] == 'R') cout << 'L';
            else if (s[i] == 'U') cout << 'D';
        }
    }
    else {
        cout << "NO" << endl;
    }
}


signed main(){
    fileIO();
    fastIO();
 //  tests
    solve();
    return 0;
}
