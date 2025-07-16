/* problem link:https://cses.fi/problemset/task/1133
 * solution by: Raghad Islam
 * date: 16-7-2025 
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
int n;
const int N = 2e5 + 5;
vector<int> adj[N];
int subTreeSize[N];
int distSum[N];
int res[N];

void dfs(int u, int p) {
    subTreeSize[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subTreeSize[u] += subTreeSize[v];
        distSum[u] += distSum[v] + subTreeSize[v];
    }
}


void calc(int u, int p) {
    res[u] = distSum[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        subTreeSize[u] -= subTreeSize[v];
        distSum[u] -= distSum[v] + subTreeSize[v];

        subTreeSize[v] += subTreeSize[u];
        distSum[v] += distSum[u] + subTreeSize[u];

        calc(v, u);

        subTreeSize[v] -= subTreeSize[u];
        distSum[v] -= distSum[u] + subTreeSize[u];

        subTreeSize[u] += subTreeSize[v];
        distSum[u] += distSum[v] + subTreeSize[v];
    }
}


void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    calc(1, -1);
    for (int i = 1; i <= n; i++) {
        // calc(i, -1);
        cout << res[i] << ' ';
    }
}

signed main(){
    fileIO();
    fastIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
