

/* problem link: https://codeforces.com/problemset/gymProblem/101028/I
 * solution by: Raghad Islam
 * date: 26-4-2023
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
//#define int ll
#define int unsigned int
#define tests int t; cin >> t; int o = -1; while(++o < t)
int sub(int a, int b, int mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

int add(int a, int b, int mod) {
    return ((a % mod) + (b % mod)) % mod;
}
int tc = 1;
const int N = 12;
int dp[N + 4][(1 << N) + 4][100];
vector<vector<int>> v(25, vector<int>(25));
int n, k;

int fun(int idx, int mask, int sum) {

    if (sum > k) return 0;
    if (idx == n && sum == k) return 1;
    if (idx == n) return 0;
    int& ret = dp[idx][mask][sum];
    if (ret != -1) return ret;
    ret = 0;

    //ret = -1e18;
    for (short pos = n - 1; pos >= 0; --pos) {
        if ((mask & (1 << pos)) == 0)
        {
            int x = (pos + 1);
            int y = (1 << x) - 1;
            int z = ~y;
            z = z & mask;
            int ans = __builtin_popcount(z);
            ret += fun(idx + 1, (mask | (1 << pos)), sum + ans);
        }
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    ::memset(dp, -1, sizeof dp);
    cout << fun(0, 0, 0) << '\n';
}

signed main() {
    fileIO();
    fastIO();
    tests{
         solve();
    }
    return 0;
}