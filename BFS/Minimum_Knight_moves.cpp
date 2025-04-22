/* problem link: https://www.spoj.com/problems/NAKANJ/
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
string s1,s2;
int X1,Y1,X2,Y2;
int dist[8][8];
int dx[] = {2, -2, 2, -2, 1, 1, -1, -1};
int dy[] = {1, 1, -1, -1, 2, -2, 2, -2};
bool valid(int i, int j) {
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

void BFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int r = p.first + dx[i];
            int c = p.second + dy[i];
            if (valid(r,c) && dist[r][c] == -1) {
                dist[r][c] = dist[p.first][p.second] + 1;
                q.push({r,c});
            }
            if (r == X2 && c == Y2) {
                return;
            }
        }
    }
}

void solve() {
    cin >> s1 >> s2;

    X1 = s1[1] - '0' - 1;
    Y1 = s1[0] - 'a';
    X2 = s2[1] - '0' - 1;
    Y2 = s2[0] - 'a';
    memset(dist, -1, sizeof(dist));
    BFS({X1,Y1});
    cout << dist[X2][Y2] << "\n";
}
signed main(){
    fileIO();
    fastIO();
   tests
    solve();
    return 0;
}
