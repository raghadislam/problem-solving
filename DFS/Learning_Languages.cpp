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
int z = 0;

vector<int> adj[N];
bool vis[N];
void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;

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
                adj[l].push_back(r);
                adj[r].push_back(l);
                l = r;
            }
        }
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            c++;
        }
    }
    if (z == c) {
        cout << c;
    }
    else {cout << c - 1;}

}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}

