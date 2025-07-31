/* problem link: https://cses.fi/problemset/task/1654
 * solution by: Raghad Islam
 * date: 27-7-2025 
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
 
// B -> number of bits
const int B = 20, M = 1 << B;
 
// subset contribute to its superset
void solveSub(vector<int>& dp) {
    for (int i = 0; i < B; ++i)
        for (int m = 0; m < M; ++m)
            if ( m & (1 << i) )
                dp[m] += dp[m ^ (1 << i)];
}
 
// superset contribute to its subset
void solveSup(vector<int>& dp) {
    for (int i = 0; i < B; ++i)
        for (int m = M - 1; ~m; --m)
            if ( m & (1 << i) )
                dp[m ^ (1 << i)] += dp[m];
}
 
void solve() {
    int n; cin >> n;
    vector<int> dp1(M);
    vector<int> dp2(M);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
         cin >> x[i];
        dp1[x[i]]++;
        dp2[x[i]]++;
    }
    solveSub(dp1);
    solveSup(dp2);
    for (int i = 0; i < n; ++i) {
        cout << dp1[x[i]] << ' ';
        cout << dp2[x[i]] << ' ';
        cout << n - dp1[x[i] ^ (M-1)] << '\n';
    }
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
