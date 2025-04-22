/* problem link: https://usaco.org/index.php?page=viewproblem2&cpid=944#
 * solution by: Raghad Islam
 * date: 14-3-2025 
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
pair<long long, long long> arr[100005];
bool visited[100005];

struct Bounds {
    long long minx, maxx, miny, maxy;
};

Bounds dfs(int u) {
    visited[u] = true;
    Bounds b = {arr[u].first, arr[u].first, arr[u].second, arr[u].second};
    for (int v : adj[u]) {
        if (!visited[v]) {
            Bounds sub = dfs(v);
            b.minx = min(b.minx, sub.minx);
            b.maxx = max(b.maxx, sub.maxx);
            b.miny = min(b.miny, sub.miny);
            b.maxy = max(b.maxy, sub.maxy);
        }
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            Bounds b = dfs(i);
            long long perimeter = 2 * ((b.maxx - b.minx) + (b.maxy - b.miny));
            ans = min(ans, perimeter);
        }
    }

    cout << ans << "\n";
}

