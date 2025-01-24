/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2467
 * solution by: Raghad Islam
 * date: 21-1-2025 
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
int n,m;
int dp[11][1<<10][101];
int vis[11][1<<10][101];
int rc = 1;
int MOD = 1000000007;
vector<int>v;

int fun(int digit, int mask, int cnt)
{
    if (cnt > m) return 0;


    int&ret = dp[digit][mask][cnt];
    if (ret != -1) return ret;

    ret = 0;
    if(__builtin_popcount(mask) == n)
    {
        ret++;
    }

    if (digit + 1 < n) {
        ret += fun(digit+1, (mask | (1 << (digit + 1))), cnt+1);
        ret %= MOD;
    }
    if (digit-1 >= 0) {
        ret += fun(digit-1, (mask | (1 << (digit - 1))), cnt+1);
        ret %= MOD;
    }
    return ret;
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for (int i = 1; i < n; i++) {
        res+= fun(i,(1 << i),1);
        res %= MOD;
    }
    cout << res<<'\n';
}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}
