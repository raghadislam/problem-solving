/* problem link: https://atcoder.jp/contests/dp/tasks/dp_u
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

int add(int a, int b, int mod){
    return ((a%mod) + (b%mod)) % mod;
}
int dp[(1<<17) + 4];
vector<vector<int>> v(25, vector<int>(25));
vector<int>score((1 << 16) + 5);
int n;

int fun(int mask) {

    if(mask == 0) return 0;
    
    int&ret = dp[mask];
    if(ret!=-1) return ret;
    ret = -1e19;

    for (int submask = mask; submask ; submask = (submask-1)&mask) {
        ret = max(ret, fun(mask^submask) + score[submask]);
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
    for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if((mask & (1<<i)) && (mask & (1<<j)))
                {
                    score[mask] += v[i][j];
                }
            }
        }
    }
    cout<<fun((1<<n)-1);
}

signed main(){
    fileIO();
    fastIO();
  // tests {
        solve();
  //  }
    return 0;
}
