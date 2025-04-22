/* problem link: https://codeforces.com/contest/242/problem/C
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
int X0,Y0,X1,Y1, n;
map<int,vector<pair<int,int>>>mp;
map<pair<int,int>,int> dist;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
bool valid(int i, int j) {
    return (i >= 1 && i <= (int)(1e9) && j >= 1 && j <= (int)(1e9));
}

void BFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int r = p.first + dx[i];
            int c = p.second + dy[i];
            if (r == X1 && c == Y1) {
                dist[{r, c}] = dist[p] + 1;
                return;
            }
            if (valid(r, c) && dist.count({r, c}) == 0) {
                bool allow = false;
                auto it = mp.find(r);
                if (it != mp.end()) {
                    auto &segments = it->second;
                    auto seg = upper_bound(segments.begin(), segments.end(), make_pair(c, LLONG_MAX));
                    if (seg != segments.begin()) {
                        seg--;
                        if (c >= seg->first && c <= seg->second) allow = true;
                    }
                }
                if (allow) {
                    dist[{r, c}] = dist[p] + 1;
                    q.push({r, c});
                }
            }
        }
    }
}

void solve() {
    vector<pair<int,int>> v;
    cin >> X0 >> Y0 >> X1 >> Y1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        mp[r].push_back({a, b});
    }
    for (auto &[r, vec] : mp) {
        sort(vec.begin(), vec.end());
        vector<pair<int, int>> merged;
        for (auto [a, b] : vec) {
            if (merged.empty() || a > merged.back().second + 1) {
                merged.push_back({a, b});
            } else {
                merged.back().second = max(merged.back().second, b);
            }
        }
        mp[r] = merged;
    }
    BFS({X0,Y0});
    if (dist.count({X1,Y1})) cout << dist[{X1,Y1}];
    else cout << -1;
    // for (int i = 1; i <= 10; i++) {
    //     for (pair vec: mp[i]) {
    //         cout << i << " " << vec.first << " " << vec.second << endl;
    //     }
    // }
}
signed main(){
    fileIO();
    fastIO();
  // tests
    solve();
    return 0;
}
