/* problem link: https://codeforces.com/contest/35/problem/C
 * solution by: Raghad Islam
 * date: 22-4-2025
 */

#include <bits/stdc++.h>
using namespace std;
void fileIO(void)
{


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


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
int dist[2005][2005];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<pair<int,int>>v;

bool valid(int i, int j) {
    return (i > 0 && i <= n && j > 0 && j <= m);
}
pair<int,int> last;
void BFS() {
    queue<pair<int,int>>q;
    for (int i = 0; i < k; i++) {
        q.push(v[i]);
        dist[v[i].first][v[i].second] = 0;
        last = v[i];
    }
    while(!q.empty()) {
        pair<int,int>p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x1 = p.first + dx[i];
            int y1 = p.second + dy[i];
            if(valid(x1,y1) && dist[x1][y1] == -1) {
                dist[x1][y1] = dist[p.first][p.second] + 1;
                q.push({x1,y1});
                last = {x1,y1};
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    cin >> k;
    v.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
    }
    memset(dist, -1, sizeof(dist));
    BFS();
    cout << last.first << ' ' << last.second << endl;

}



signed main(){
    fileIO();
    fastIO();
  // tests
    solve();
    return 0;
}
