/* problem link: https://codeforces.com/contest/767/problem/C
 * solution by: Raghad Islam
 * date: 14-3-2025 
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
int const N = 1000005;
bool visited[N];
int temp[N];
int there_is_tolt_at[N];
int subtree_sum[N];
vector<int> adj[N];
int root, cut1 = -1, cut2 = -1, total=0;

void dfs(int u) {
    vector<int> tolts;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            if (there_is_tolt_at[v]) {
                tolts.push_back(there_is_tolt_at[v]);
            }
            subtree_sum[u] += subtree_sum[v];
        }
    }
    subtree_sum[u] += temp[u];
    if (subtree_sum[u] == total/3) {
        there_is_tolt_at[u] = u;
    }
    if (!tolts.empty() && subtree_sum[u] == (2*total / 3) && u != root) {
        cut1 = tolts[0];
        cut2 = u;
    }
    if (tolts.size() > 1) {
        cut1 = tolts[0];
        cut2 = tolts[1];
        // cout << cut1 << " " << cut2 << endl;
        // exit(0);
    }
    if (there_is_tolt_at[u] == 0 && !tolts.empty()) {
        there_is_tolt_at[u] = tolts[0];
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int p; cin >> p >> temp[i];
        if (p)
            adj[p].push_back(i);
        else root = i;
        total += temp[i];
    }
    if (total%3) {
        cout << -1;
        return;
    }
    dfs(root);
    if (cut1 == -1 || cut2 == -1) {
        cout << -1;
    }
    else
        cout << cut1 << " " << cut2;

    // dfs()
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
