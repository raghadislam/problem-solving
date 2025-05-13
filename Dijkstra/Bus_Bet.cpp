/* problem link: https://codeforces.com/gym/103797/problem/B
 * solution by: Raghad Islam
 * date: 2-5-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
#define int ll
const int oo = 1e18;
const int N = 5 * 1e5 + 5;
vector<vector<pair<int,int> > > adj(N);
// int dist[N];
int n, m, T;

bool dijkstra(int mid) {
    vector<int> dist(n + 1, oo);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int t = pq.top().first;
        pq.pop();

        if (t > dist[u]) continue;
        if (u == n) break;
        for (auto v : adj[u]) {
            if (v.second >= mid) {
                if (dist[v.first] > t + v.second) {
                    dist[v.first] = t + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
    }
    return dist[n] <= T;
}

void solve() {
    cin >> n >> m >> T;
    int r = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        r = max(r, w);
    }
    int l = 0, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dijkstra(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    if (ans == -1) cout << "He is taking an uber.";
    else cout << ans << "\n";
}


signed main() {
    fileIO();
    fastIO();
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

