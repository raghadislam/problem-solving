/* problem link: https://codeforces.com/contest/1272/problem/E
 * solution by: Raghad Islam
 * date: 22-4-2025
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
// #define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int left = i - a[i];
        if (left >= 0) {
            adj[left].push_back(i);
        }
        int right = i + a[i];
        if (right < n) {
            adj[right].push_back(i);
        }
    }

    vector<int> res(n, -1);
    queue<int> q;

    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    if (!odd.empty()) {
        vector<int> dist(n, -1);
        queue<int> q;
        for (int node : odd) {
            dist[node] = 0;
            q.push(node);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0 && dist[i] != -1) {
                res[i] = dist[i];
            }
        }
    }

    if (!even.empty()) {
        vector<int> dist(n, -1);
        queue<int> q;
        for (int node : even) {
            dist[node] = 0;
            q.push(node);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1 && dist[i] != -1) {
                res[i] = dist[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

}



signed main(){
    fileIO();
    fastIO();
  // tests
    solve();
    return 0;
}
