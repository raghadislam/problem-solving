
/* problem link: https://codeforces.com/problemset/problem/580/D
 * solution by: Raghad Islam
 * date: 30-6-2024 
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
int sub(int a, int b, int mod){
    return ((a%mod) - (b%mod) + mod) % mod;
}

int add(int a, int b, int mod){
    return ((a%mod) + (b%mod)) % mod;
}
int n,m,k;
const int MOD = 1e9+7;
string s;
int dp[19][1<<19];
vector<int>v;
int sat[19][19];

int fun(int last, int mask)
{
    if(__builtin_popcount(mask) == m) return 0;
    int&ret = dp[last][mask];
    if(ret!=-1) return ret;
    ret = 0;
    for (int i = 0; i < n ; ++i) {
        if((mask & (1<<i)) == 0)
        {
            ret = max(ret, fun(i,(mask | (1<<i))) + v[i] + sat[last][i]);
        }
    }
    return ret;
}

void solve()
{
    ::memset(dp,-1,sizeof dp);
    cin>>n>>m>>k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    for (int i = 0; i < k; ++i) {
        int x,y,c; cin>>x>>y>>c;
        x--,y--;
        sat[x][y] = c;
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, fun(i,(1<<i)) + v[i]);
    }
    cout<<mx;
}

signed main(){
    fileIO();
    fastIO();
  // tests {
        solve();
  //  }
    return 0;
}