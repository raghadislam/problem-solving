
/* problem link: https://atcoder.jp/contests/dp/tasks/dp_d
 * solution by: Raghad Islam
 * date: 30-3-2024
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
#define tests int t; cin >> t; int k = -1; while(++k < t)

int n,cap,dp[100][100005];
int caps[1000],val[1000];
int func(int i, int c)
{
    if(i==n) return 0;
    int&ret = dp[i][c];
    if(ret!=-1) return  ret;
    int leave = func(i+1,c);
    int take =0;
    if(c>=caps[i]) take = func(i+1,c-caps[i])+val[i];
    return ret = max(take,leave);
}

void solve() {
    cin>>n>>cap;
    for (int i = 0; i < n; ++i) {
        cin>>caps[i]>>val[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<func(0,cap);
}

signed main(){
    fileIO();
    fastIO();
  //  tests {
    // cout<<"Case "<<j+1<<": ";
    solve();
   //  }
    return 0;
}