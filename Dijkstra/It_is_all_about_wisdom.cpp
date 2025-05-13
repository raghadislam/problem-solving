/* problem link: https://codeforces.com/gym/100814/problem/G
 * solution by: Raghad Islam
 * date: 29-4-2025 
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
    int v, c, w;
}Node;
typedef struct input {
    int u, v, c, w;
}Input;

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.w > b.w;
    }
};

int n, m, k;
Input arr[100005];

int res = INT_MAX;

bool dijkstra(int mid) {
    vector<pair<int,int>> adj[n + 5] = {{}};
    vector<int> dist(n + 5, oo);

    for (int i = 0; i < m; i++) {
        if (arr[i].w <= mid) {
            adj[arr[i].u].push_back({arr[i].v, arr[i].c});
            adj[arr[i].v].push_back({arr[i].u, arr[i].c});
        }
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (u == n) break;
        if (cost > dist[u]) continue;

        for (auto v: adj[u]) {
            if (cost + v.second < dist[v.first]) {
                dist[v.first] = cost + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return dist[n] < k;
}

void solve() {
    cin >> n >> m >> k;
    for (int i =0; i < m; i++) {
        cin >> arr[i].u >> arr[i].v >> arr[i].c >> arr[i].w;
    }
    int l = 1, r = 1e9 + 10, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dijkstra(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}


signed main() {
    fileIO();
    fastIO();
    int t = 1; cin >> t;
    while (t--) {

        solve();
    }
    return 0;
}
