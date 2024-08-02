
/* problem link: https://codeforces.com/problemset/problem/628/D
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
int m,d;
const int MOD = 1e9+7;
string s;
int dp[2009][3][2009];

int fun(int i, bool tight, int rem)
{
    if(i==s.size()) return (rem == 0);
    int&ret = dp[i][tight][rem];
    if(ret!=-1) return ret;
    ret = 0;
    int end = (tight? s[i] - '0' : 9);
    if(i&1) // even
    {
        if(d>end) return 0;
        ret = fun(i+1, tight && (d == end), ((rem*10) + d) % m);
    }
    else
    {
        for (int j = 0; j <= end; ++j) {
            if(j==d) continue;
            ret = add(ret,fun(i+1, tight && (j==end), ((rem * 10) + j)%m),MOD);
        }
    }
    return ret;
}

void solve()
{
    cin>>m>>d;
    ::memset(dp,-1,sizeof dp);
    cin>>s;
    int ans1 = fun(0,1,0) ;
    string tmp = s;
    ::memset(dp,-1,sizeof dp);
    cin>>s;
    int ans2 = fun(0,1,0)  ;
    bool f = 1;
    for (int i = 0; i < tmp.size(); ++i) {
        if(i&1) // even
        {
            if (tmp[i]-'0' != d) {
                f = 0;
                break;
            }
        }
        else // odd
        {
            if (tmp[i]-'0' == d) {
                f = 0;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        sum = ((sum*10) +tmp[i] - '0')%m;
    }
    if(sum) f = 0;
    cout<<sub(ans2, ans1, MOD) + (f)<<'\n';
}

signed main(){
    fileIO();
    fastIO();
	
        solve();
    return 0;
}