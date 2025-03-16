/* problem link: https://codeforces.com/contest/727/problem/A
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
const int N = 200009;
int a,b;
map<int,int> visited;
vector<int> ans;

int dfs(int u) {
    visited[u] = true;
    if (u == b) return 1;
    int v1 = 2*u, v2 = u*10 + 1;
    if (v1 > b && v2 > b)
        return 0;
    int ret = 0;
    if (v1 <= b && !visited[v1]) {
        ret |= dfs(v1);
    }
    if (v2 <= b && !visited[v2]) {
        ret |= dfs(v2);
    }
    if (ret == 1) {
        ans.push_back(u);
    }
    return ret;
}


void solve() {
    cin >> a >> b;
    int res = dfs(a);
    if (res) {
        cout << "YES\n";
        cout << ans.size() + 1 << endl;
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << b;
    }
    else {
        cout << "NO";
    }
}
signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
