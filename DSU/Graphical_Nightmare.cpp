/* problem link: https://codeforces.com/gym/104415/problem/G
 * solution by: Raghad Islam
 * date: 18-5-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
#define int ll
const int N = 1e5+5;
vector<int> adj[N];
int dist[N];
// const int M = 1e5+5;
int roots[N];
int n, m;
void init() {
    for (int i = 0; i <= n; i++) {
        roots[i] = i;
        dist[i] = -1;
    }
}
int getRoot(int u) {
    if (u == roots[u])
        return u;
    return roots[u] = getRoot(roots[u]);
}

void merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u == v)
        return;
    roots[u] = v;
}

bool isSameSet(int u, int v) {
    return getRoot(u) == getRoot(v);
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    init();
    int cnt = 0;
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges[i] = {c, {u, v}};
        // adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    sort(edges.begin(), edges.end());
    int ans = 0, longest=0;
    for (auto e : edges) {
        int u = e.second.first, v = e.second.second, c = e.first;
        if (isSameSet(u,v)) continue;
        ans += c;
        merge(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(1);
    // for (int i = 1; i <= n; i++) {
    //     cout << dist[i] << ' ';
    // }
    int val = -1, node = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > val) {
            val = dist[i];
            node = i;
        }
    }
    init();
    BFS(node);
    cout << ans << '\n';
    cout << *max_element(dist, dist+n) << '\n';
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}
