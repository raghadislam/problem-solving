
/* problem link: https://codeforces.com/problemset/problem/1036/C
 * solution by: Raghad Islam
 * date: 30-4-2024 
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
const int MOD = 1e9+7;
string s;
int dp[20][3][7];

int fun(int i, bool tight, int rem)
{
    if(i==s.size()) return (rem>=0);
    if(rem < 0) return 0;

    int&ret = dp[i][tight][rem];
    if(ret!=-1) return ret;
    ret = 0;
    int end = (tight? s[i] - '0': 9);
    for (int j = 0; j <= end; ++j) {
        ret += fun(i+1, tight && (j == end), rem - (j!=0));
    }
    return ret;
}

void solve()
{
    ::memset(dp,-1,sizeof dp);
    cin>>s;
    int ans1 = fun(0,1,3);
    string tmp = s;
    ::memset(dp,-1,sizeof dp);

    cin>>s;
    int ans2 = fun(0,1,3) ;
    int cnt=0;
    for (int i = 0; i <tmp.size() ; ++i) {
        if(tmp[i]!='0') cnt++;
    }
    cout<<ans2 - ans1 + (cnt<=3)<<'\n';
}

signed main(){
    fileIO();
    fastIO();
   tests {
        solve();
    }
    return 0;
}