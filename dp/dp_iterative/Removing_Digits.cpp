/* problem link: https://cses.fi/problemset/task/1637
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
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        vector<int> v;
        while (tmp) {
            v.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int j = 0; j < v.size(); j++) {
            if (i >= v[j]) {
                dp[i] = min(dp[i], dp[i-v[j]] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
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
