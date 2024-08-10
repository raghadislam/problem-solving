/* problem link: https://www.spoj.com/problems/SCUBADIV/
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
int needed_o,needed_n;
int dp[1001][100][100];
int arrO[1005],arrN[1005],arrW[1005];
int fun(int i,int ox, int ni)
{
    if(i==n)
    {
        if((ox <= 0) and (ni <= 0))
            return 0;
        return INT_MAX;
    }
    int&ret= dp[i][ox][ni];
    if(ret!=-1) return ret;
    int leave = fun(i+1,ox,ni);
    int take = fun(i+1,max(ox-arrO[i],0LL),max(ni-arrN[i],0LL)) + arrW[i];
    return ret = min(leave,take);
}



void solve() {
    cin>>needed_o>>needed_n;
    cin>>n;
    memset(dp,-1, sizeof dp);
    for (int i = 0; i < n; ++i) {
        cin>>arrO[i]>>arrN[i]>>arrW[i];
    }
    cout<<fun(0,needed_o,needed_n)<<"\n";
   // cout<<fun(0,0);
//    for (int i = 0; i < n; ++i) {
//        cout<<arr[i].O<<' '<<arr[i].N<<' '<<arr[i].W<<' '<<'\n';
//    }
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