/* problem link: https://codeforces.com/problemset/problem/1005/D
 * solution by: Raghad Islam
 * date: 3-1-2025 
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

string s;
int dp[(int)(2e5 + 9)][4], vis[(int)(2e5 + 9)][4];

int fun(int i, int sum)
{
    if(i==s.size()) return (sum==0);
    if(vis[i][sum]) return dp[i][sum];
    vis[i][sum] = 1;
    int ch1 = fun(i + 1, (sum + s[i] - '0')%3);
    int ch2 = (sum == 0)+fun(i+1,  (s[i] - '0')%3) ;
    return dp[i][sum] = max(ch1,ch2);
}

void solve()
{
    cin>>s;
    cout<<fun(1,(s[0]-'0')%3);
}

signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}
