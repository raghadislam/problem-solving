/* problem link: https://cses.fi/problemset/task/1194
 * solution by: Raghad Islam
 * date: 22-4-2025
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
// #define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
int n,m,k;
char grid[1005][1005];
int dist1[1005][1005];
int dist2[1005][1005];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};
pair<int,int> A;
vector<pair<int,int>>mons;
vector<pair<int,int>>ext;
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
pair<int,int> last;
void BFS() {
    queue<pair<int,int>>q;
    for (int i = 0; i < mons.size(); i++) {
        q.push(mons[i]);
        dist1[mons[i].first][mons[i].second] = 0;
    }
    while(!q.empty()) {
        pair<int,int>p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (valid(x,y) && dist1[x][y] == -1 && grid[x][y] != '#') {
                dist1[x][y] = dist1[p.first][p.second] + 1;
                q.push({x,y});
            }
        }
    }
    // ------------------
    q.push(A);
    dist2[A.first][A.second] = 0;
    while(!q.empty()) {
        pair<int,int>p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (valid(x,y) && (dist2[x][y] == -1) && (grid[x][y] != '#') && (((dist2[p.first][p.second] + 1) < dist1[x][y]) || dist1[x][y] == -1)) {
                dist2[x][y] = dist2[p.first][p.second] + 1;
                q.push({x,y});
                if (y == 0 || y == m-1 || x == 0 || x == n-1) return;
            }
        }
    }

}


void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') mons.push_back({i,j});
            if (grid[i][j] == 'A') A = {i,j};
            if (grid[i][j] == '.' && ((i == 0) || (i == n-1) || (j == 0) || (j == m-1))) ext.push_back({i,j});
        }
    }
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
    if (A.first == 0 || A.first == n-1 || A.second == 0 || A.second == m-1) {
        cout << "YES\n" << 0 << "\n";
        return;
    }
    BFS();

    for(int i = 0; i < ext.size(); i++) {
        if (dist2[ext[i].first][ext[i].second] != -1) {
            cout << "YES\n";
            int d = dist2[ext[i].first][ext[i].second];
            cout << d << "\n";
            string s;
            int x = ext[i].first;
            int y = ext[i].second;
            while(d--) {
                for (int i = 0; i < 4; i++) {
                    int xn = x + dx[i];
                    int yn = y + dy[i];
                    if (valid(xn,yn) && (dist2[xn][yn] == d)) {
                        s += dir[i];
                        x = xn;
                        y = yn;
                        break;
                    }
                }
            }
            reverse(s.begin(), s.end());
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'L') s[i] = 'R';
                else if (s[i] == 'R') s[i] = 'L';
                else if (s[i] == 'U') s[i] = 'D';
                else if (s[i] == 'D') s[i] = 'U';
            }
            cout << s << "\n";

            return;
        }
    }
    cout << "NO\n";
}



signed main(){
    fileIO();
    fastIO();
  // tests
    solve();
    return 0;
}
