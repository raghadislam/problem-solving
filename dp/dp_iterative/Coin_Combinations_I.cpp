/* problem link: https://cses.fi/problemset/task/1635
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int MOD = 1e9 + 7;
    vector<int> dp(x+1, 0);
    dp[0] = 1;
        for (int j = 1; j <= x; j++) {
            for (int i = 0; i < n; i++) {
            if (a[i] <= j) {
                dp[j] += dp[j-a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << "\n";
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
