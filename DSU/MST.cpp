/* problem link: https://www.spoj.com/problems/MST/en/
 * solution by: Raghad Islam
 * date: 13-5-2025 
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
const int N = 1e4+5;
const int M = 1e5+5;
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

vector<pair<int, pair<int, int>>> edges(M);
void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = {c, {u, v}};
    }
    int ans = 0;
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        int u = e.second.first, v = e.second.second, c = e.first;
        if (isSameSet(u,v)) continue;
        ans += c;
        merge(u, v);
    }
    cout << ans;
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}

