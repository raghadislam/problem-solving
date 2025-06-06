/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
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
const int N = 3e4 + 5;
int roots[N];
int n, m;
int arr[N];
void init() {
    for (int i = 0; i <= n; i++) {
        roots[i] = i;
        arr[i] = 1;
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
    arr[v]+=arr[u];
}

bool isSameSet(int u, int v) {
    return getRoot(u) == getRoot(v);
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        merge(u, v);
    }
    cout << *max_element(arr, arr + n + 1) << "\n";
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  cin>>t;
    while (t--)
        solve();

    return 0;
}

