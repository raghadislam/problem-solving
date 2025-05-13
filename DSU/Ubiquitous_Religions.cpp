/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
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
const int N = 5e4 + 5;
int roots[N];
int n, m, t = 0;
int cnt = 0;
void init() {
    for (int i = 0; i <= n; i++)
        roots[i] = i;
    cnt = 0;
    t++;
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
    cnt++;
}

bool isSameSet(int u, int v) {
    return getRoot(u) == getRoot(v);
}

void solve(){
    while (cin >> n >> m, n || m) {
        init();
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            merge(u, v);
        }
        set<int>s;
        for (int i = 1; i <= n; i++) {
            s.insert(getRoot(i));
        }
        cout << "Case " << t <<": " << s.size() << '\n';
    }
}

signed main() {
    fileIO();
    fastIO();

    int t = 1; // cin>>t;
    while (t--)
        solve();

    return 0;
}

