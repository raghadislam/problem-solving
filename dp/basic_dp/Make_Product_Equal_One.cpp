/* problem link: https://codeforces.com/problemset/problem/1206/B
 * solution by: Raghad Islam
 * date: 22-8-2024 
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
#define ll long long
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
int n,m;
vector<int> v;
vector<pair<int,int>> pi;
vector<vector<int>> dp(100009,vector<int>(3,-1));
map<int,int>mp;

int fun(int i, int res) {
    if(i==n) {
        if(res == -1) return 1e9;
        return 0;
    }
    int x;
    if(res == -1) x = 0;
    else x = 1;
    if(dp[i][x] != -1) return dp[i][x];
    int ch1 = fun(i+1,res) + abs(v[i] - 1);
    int ch2 = fun(i+1, res*-1) + + abs(-1 - v[i]);
    return dp[i][x] = min(ch1,ch2);
}


void solve() {
    cin >> n;
    mp[-1] = 0;
    mp[1] = 1;

    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    cout<<fun(0,1);

}

signed main(){
    fileIO();
    fastIO();
 //   tests
    solve();
    return 0;
}
