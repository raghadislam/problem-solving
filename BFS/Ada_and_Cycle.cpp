/* problem link: https://www.spoj.com/problems/ADACYCLE/
 * solution by: Raghad Islam
 * date: 21-4-2025
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void)
{

#ifndef ONLINE_JUDGE // DLRU

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

}

void fastIO(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}

typedef long long ll;
#define tests int t; cin >> t; int o = -1; while(++o < t)
int n,m,k;
int dist[2005];

vector<int> adj[2000 + 5];

void BFS(int x) {
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            else if (dist[v] == 0) {
                dist[v] = dist[u] + 1;
                return;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x) adj[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        memset(dist, -1, sizeof(dist));
        BFS(i);
        if (dist[i]) cout << dist[i] << '\n';
        else cout << "NO WAY\n";
    }
}


signed main(){
    fileIO();
    fastIO();
 //  tests
    solve();
    return 0;
}
