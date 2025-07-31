/* problem link: https://cses.fi/problemset/task/1638
 * solution by: Raghad Islam
 * date: 26-7-2025 
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
 
bool valid(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= n;
}
 
void solve() {
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    vector<vector<char>> v(n+1, vector<char>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    const int MOD = 1e9 + 7;
    if (v[n][n] == '.')
        dp[n][n] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (v[i][j] == '*') continue;
            if (valid(i+1, j) && v[i+1][j] == '.') {
                dp[i][j] += dp[i+1][j];
                dp[i][j] %= MOD;
            }
            if (valid(i, j+1) && v[i][j+1] == '.') {
                dp[i][j] += dp[i][j+1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[1][1] << "\n";
}


signed main(){
    fileIO();
    fastIO();
    int t = 1;// cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}
