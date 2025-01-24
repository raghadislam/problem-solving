/* problem link: https://atcoder.jp/contests/dp/tasks/dp_o
 * solution by: Raghad Islam
 * date: 8-1-2025 
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
int add(int a, int b, int mod){
    return ((a%mod) + (b%mod)) % mod;
}
int dp[22][(1<<21) + 4];
vector<vector<int>> v(25, vector<int>(25));
int n;

int fun(int man, int bitmask) {
    if(man == n && __builtin_popcount(bitmask) == n) return 1;
    
    int&ret = dp[man][bitmask];
    if(ret!=-1) return ret;
    ret = 0;

    for (int women = 0; women < n; ++women) {
        if((v[man][women] == 1) && ((bitmask & (1<<women))==0))
        {
            ret = add(ret,fun(man+1, (bitmask | (1<<women))),(int)1e9+7);
        }
    }
    return ret;
}

void solve() {
    ::memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    cout<<fun(0,0);
}

signed main(){
    fileIO();
    fastIO();
        solve();
    return 0;
}
