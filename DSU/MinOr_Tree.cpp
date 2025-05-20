/* problem link: https://codeforces.com/problemset/problem/1624/G
 * solution by: Raghad Islam
 * date: 19-5-2025 
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

typedef struct edge {
    int u, v;
    int w;
}Edge;

Edge edges[M];
int roots[N];
bool without[35];
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


int  kruskal() {
    int take[M] = {0};
    init();
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        bool f = 1;
        for (int bit = 0; bit <= 32; bit++) {
            if ((without[bit]) && (w & (1LL << bit))) {
                f = 0;
                break;
            }
        }
        if (f) merge(u, v);
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (!isSameSet(u, v)) return 0;
    }
    return 1;
}

void solve() {

    cin >> n >> m;
    init();
    for (int i = 0; i < 35; i++) {
        without[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int ans = 0;
    for (int i = 32; i >= 0; i--) {
        without[i] = true;
        if (kruskal() == 0) {
            without[i] = false;
            ans |= (1LL << i);
        }
    }

    cout << ans << '\n';
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  cin>>t;
    while (t--)
        solve();

    return 0;
}
