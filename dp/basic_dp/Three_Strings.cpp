/* problem link: https://codeforces.com/contest/2050/problem/E
 * solution by: Raghad Islam
 * date: 24-3-2025
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

#define ll long long
#define int ll
#define tests int t; cin >> t; while(t--)

int dp[1001][1001];
string a, b, c;
int fun(int i, int j) {
    if (i == a.size() && j == b.size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int res = INT_MAX;

    if (i < a.size()) {
        int change = (a[i] != c[i + j]);
        res = min(res, fun(i + 1, j) + change);
    }
    if (j < b.size()) {
        int change = (b[j] != c[i + j]);
        res = min(res, fun(i, j + 1) + change);
    }
    return dp[i][j] = res;
}

void solve() {
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));

    cout << fun(0, 0) << '\n';
}

signed main() {
    fileIO();
    fastIO();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
