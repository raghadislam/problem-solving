/* problem link: https://codeforces.com/contest/278/problem/C
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
const int N = 105;
const int M = 105;
int roots[N];
vector<int> lang[M];
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

int z = 0;

void solve() {
    cin >> n >> m;
    init();

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        if (k == 0) z++;
        else {
            for (int j = 0; j < k; j++) {
                int l; cin >> l;
                lang[l].push_back(i);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int sz = lang[i].size();
        if (sz > 1) {
            int l = lang[i][0];
            for (int j = 1; j < sz; j++) {
                int r = lang[i][j];
                merge(l, r);
                l = r;
            }
        }
    }
    int freq[n+1] = {0};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int p = getRoot(i);
        if (freq[p] == 0) {
            freq[p]++;
            ans++;
        }
    }
    if (z == ans) cout << ans;
    else cout << ans - 1;

}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}

