/* problem link: https://www.spoj.com/problems/PR003004/en/
 * solution by: Raghad Islam
 * date: 11-1-2025 
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
string a,b,s;
int tc = 1;
int dp[20][3][180], vis[20][3][180];

int fun(int idx, bool tight, int sum )
{
    if(idx == s.size()) return sum;
    int&ret = dp[idx][tight][sum];
    if(vis[idx][tight][sum]==tc) return ret;
    vis[idx][tight][sum]=tc;
    ret = 0;
    int end = (tight? s[idx] - '0' : 9);
    for (int i = 0; i <= end ; ++i) {
        ret += fun(idx+1, (tight && i == end),sum+i);
    }
    return ret;
}

void solve()
{
    cin>>s;
    int ans1 = fun(0,1,0);
    string tmp = s;
    tc++;
    cin>>s;
    int ans2 = fun(0,1,0);
    int c =0;
    for (int i = 0; i <tmp.size() ; ++i) {
        c += tmp[i] - '0';
    }
    cout<<ans2 - ans1 + c<<'\n';
    tc++;
}

signed main(){
    fileIO();
    fastIO();
   tests {
        solve();
    }
    return 0;
}
