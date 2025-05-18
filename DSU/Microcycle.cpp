/* problem link: https://codeforces.com/contest/1927/problem/F
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
const int N = 2e5+5;
const int M = 2e5+5;
int roots[N];

pair<int,int>last; int last_c = INT_MAX;
vector<int> adj[N];
bool vis[N];

bool f = 0;
vector<int> ans;
int n, m;
void init() {
    for (int i = 0; i <= n; i++) {
        roots[i] = i;
        adj[i].clear();
        vis[i] = false;
    }
    last_c = INT_MAX;
    f = 0;
    ans.clear();
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


void dfs(int u) {
    vis[u] = true;
    if (u == last.second) {
        f = 1;
        ans.push_back(u);
        return;
    }
    for (int v : adj[u]) {
        if (!vis[v]) {

            dfs(v);

            if (f) {
                ans.push_back(u);
                return;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    init();

    pair<int, pair<int,int>> edges[m+1];
    for (int i = 0; i < m; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    sort(edges, edges + m);
    reverse(edges, edges + m);

    for (int i = 0; i < m; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int c = edges[i].first;
        if (!isSameSet(u, v)) {
            merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            if (c < last_c) {
                last = edges[i].second;
                last_c = c;
            }
        }
    }
    dfs(last.first);
    if (ans.size() == 0) dfs(last.first);
    cout << last_c << ' ' << ans.size() << '\n';
    for (auto x : ans) cout << x << " ";
    cout << '\n';
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  cin>>t;
    while (t--)
        solve();

    return 0;
}
