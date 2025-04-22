/* problem link: https://codeforces.com/problemset/problem/1661/B
 * solution by: Raghad Islam
 * date: 17-4-2025
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void)
{

#ifndef ONLINE_JUDGE

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
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
int n,m,k, s, targ;
const int MOD = 32768;
int dist[32768 + 5];
int vis[32768 + 5];
int val = 1;
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};
// bool valid(int i, int j) {
//     return (i >= 0 && i < 500 && j >= 0 && j < 500);
// }
int cnt = 0;
int BFS(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    vis[start] = val;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int ch1 = (2 * p) % MOD;
        int ch2 = (p + 1) % MOD;
        if (vis[ch1] != val) {
            dist[ch1] = dist[p] + 1;
            q.push(ch1);
            vis[ch1] = val;
        }
        if (vis[ch2] != val) {
            dist[ch2] = dist[p] + 1;
            q.push(ch2);
            vis[ch2] = val;
        }
        if (ch1 == 0 || ch2 == 0) return dist[0];
    }
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cout << BFS(v[i]) << ' ';
        val++;
    }
}
signed main(){
    fileIO();
    fastIO();
 //  tests
    solve();
    return 0;
}
