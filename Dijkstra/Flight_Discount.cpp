/* problem link: https://cses.fi/problemset/task/1195
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
 
typedef struct node {
    int w, u, used;
}Node;
 
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.w > b.w;
    }
};
 
int n, m;
vector<pair<int,int>> adj[100005];
int par[100005];
vector<vector<int>> dist(100005, vector<int>(2,oo));
 
void dijkstra(int src) {
    priority_queue<Node, vector<Node>, cmp>pq;
    pq.push({0, src, 0});
    dist[src][0] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().u;
        int cost = pq.top().w;
        int used = pq.top().used;
        pq.pop();
 
        if (cost > dist[u][used]) continue;
        for (auto node: adj[u]) {
            if (node.second + cost < dist[node.first][used]) {
                dist[node.first][used] = node.second + cost;
                pq.push({dist[node.first][used], node.first, used});
            }
            if (used == 0) {
                int new_cost = cost + node.second/2;
                if (new_cost < dist[node.first][1]) {
                    dist[node.first][1] = new_cost;
                    pq.push({dist[node.first][1], node.first, 1});
                }
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
    cout << dist[n][1] << endl;

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

