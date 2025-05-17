/* problem link: https://codeforces.com/contest/1559/problem/D1
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
const int N = 1e3+5;
// const int M = 105;
int roots1[N];
int roots2[N];
int n, m1, m2;
void init(int roots[]) {
    for (int i = 0; i <= n; i++) {
        roots[i] = i;
    }
}
int getRoot(int u, int roots[]) {
    if (u == roots[u])
        return u;
    return roots[u] = getRoot(roots[u],roots);
}

void merge(int u, int v, int roots[]) {
    u = getRoot(u,roots);
    v = getRoot(v,roots);
    if (u == v)
        return;
    roots[u] = v;
}

bool isSameSet(int u, int v, int roots[]) {
    return getRoot(u,roots) == getRoot(v,roots);
}
void solve() {
    cin >> n >> m1 >> m2;
    init(roots1);
    init(roots2);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v, roots1);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v, roots2);
    }
    int ans = 0;
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i!=j && !isSameSet(i, j, roots1) && !isSameSet(i, j, roots2)) {
                ans++;
                merge(i, j, roots1);
                merge(i, j, roots2);
                v.push_back({i,j});
            }
        }
    }
    cout << ans << endl;
    for (auto x:v) {
        cout << x.first << " " << x.second << endl;
    }
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}
