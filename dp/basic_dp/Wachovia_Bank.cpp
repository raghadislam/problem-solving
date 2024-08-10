/* problem link: https://www.spoj.com/problems/WACHOVIA/en/
 * solution by: Raghad Islam
 * date: 16-4-2024 
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
int n;
//vector<vector<int>>v(100005,vector<int>(3,0));
int k;
int w[1005];
int v[1005];
int dp[1009][1009];
int c = 0;
int fun(int i,int cap)
{
    if(i==n) return 0;
    int&ret= dp[i][cap];
    if(ret!=-1) return ret;
    int leave = fun(i+1,cap);
    int take = INT_MIN;
    if(cap>=w[i]) take = fun(i+1,cap-w[i]) + v[i];
    return ret = max(leave,take);
}



void solve() {
    cin>>k>>n;
    memset(dp,-1, sizeof dp);
    for (int i = 0; i < n; ++i) {
        cin>>w[i]>>v[i];
    }
    cout<<"Hey stupid robber, you can get "<<fun(0,k)<<".\n";
   // cout<<fun(0,0);
}

signed main(){
    fileIO();
    fastIO();
    tests {
    // cout<<"Case "<<j+1<<": ";
    solve();
     }
    return 0;
}