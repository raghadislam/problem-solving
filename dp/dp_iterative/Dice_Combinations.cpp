/* problem link: https://cses.fi/problemset/task/1633
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

void solve() {
    int n;
    cin >> n;
    int dp[n+1] = {0};
    dp[0] = 1;
    const int MOD = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i>=j && j <= 6; j++) {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
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
