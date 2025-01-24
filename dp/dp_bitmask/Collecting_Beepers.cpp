/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1437
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
int n;
int X[12], Y[12];
int dis[12][12], dp[12][1<<12];

int fun(int pos, int mask)
{
    if(mask == (1<<(n+1))-1)
        return dis[pos][0];
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    int ans=1e18;
    for(int i=0; i<=n; i++){
        if(i!=pos && !(mask & (1<<i))){
            ans=min(ans, dis[pos][i]+fun(i, mask | (1<<i)));
        }
    }
    return dp[pos][mask]=ans;
}

void solve()
{
    int xs, ys;
    cin >> xs >> ys;
    cin >> X[0] >> Y[0];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> X[i] >> Y[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dis[i][j]=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
        }
    }
    memset(dp, -1, sizeof dp);
    int ans=fun(0, 1);
    cout << "The shortest path has length "<< ans << '\n';
}
signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}
