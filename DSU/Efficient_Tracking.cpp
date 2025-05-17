/* problem link: https://codeforces.com/gym/101804/problem/E
 * solution by: Raghad Islam
 * date: 17-5-2025 
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
const int N = 1e3+5;
// const int M = 1e5+5;
int roots[N];
int n, m;
void init() {
    for (int i = 0; i <= n; i++) {
        roots[i] = i;
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

vector<int> adj[N];
bool vis[N];
// map<int, int> res;
int res[N];
void dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            res[v] = u;
            dfs(v);
        }
    }
}


void solve() {
    cin >> n;
    init();
    int cnt = 0;
    int m = n*(n-1)/2;
    vector<pair<int, pair<int, int>>> edges(m + 5);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            int c; cin >> c;
            edges[cnt++] = {c, {i, j}};
        }
    }
    sort(edges.rbegin(), edges.rend());
    map<int,int>mp;
    int ans = 0;
    for (auto e : edges) {
        int u = e.second.first, v = e.second.second, c = e.first;
        if (isSameSet(u,v)) continue;
        ans += c;
        merge(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << ans <<'\n';
    for (int i = 2; i <= n; i++) {
        cout  << res[i]<< "\n";
    }
    cout << endl;
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}
