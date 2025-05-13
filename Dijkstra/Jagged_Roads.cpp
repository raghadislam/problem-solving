/* problem link: https://codeforces.com/gym/104415/problem/J
 * solution by: Raghad Islam
 * date: 1-5-2025 
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
int n, m;
vector<pair<int,int> > adj[100005];
double tiredness[100005];

void dijkstra(int s) {
    priority_queue<pair<double,int>, vector<pair<double,int> >, greater<pair<double,int> > > pq;
    pq.push({0, s});
    tiredness[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        double t = pq.top().first;
        pq.pop();
        if (tiredness[u] < t) continue;
        if (u == n) return;
        for (auto v: adj[u]) {
            if (tiredness[v.first] > (t + log(v.second) / log(7))) {
                tiredness[v.first] = (t + log(v.second) / log(7));
                pq.push({tiredness[v.first], v.first});
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    fill(tiredness, tiredness + n + 1, oo);
    dijkstra(1);
    cout << fixed << setprecision(15) << tiredness[n] << "\n";
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



