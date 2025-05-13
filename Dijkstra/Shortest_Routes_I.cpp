/* problem link: https://cses.fi/problemset/task/1671
 * solution by: Raghad Islam
 * date: 26-4-2025 
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
vector<pair<int,int>> adj[100005];
int par[100005];
vector<int> dist(100005, oo);
 
void dijkstra(int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0, src});
    dist[src] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
 
        if (cost > dist[u]) continue;
        for (auto node: adj[u]) {
            if (node.second + cost < dist[node.first]) {
                dist[node.first] = node.second + cost;
                pq.push({dist[node.first], node.first});
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

}
 
 
signed main() {
    fileIO();
    fastIO();
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
