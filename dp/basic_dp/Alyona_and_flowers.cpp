/* problem link: https://codeforces.com/group/isP4JMZTix/contest/424304/problem/A
 * solution by: Raghad Islam
 * date: 16-8-2024 
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
vector<int> dp;
 
 
int fun(int ii) {
    if(ii==m) return 0;
    if(dp[ii] !=-1) return dp[ii];
    int take = 0, leave = 0;
    take = fun(ii+1) + v[pi[ii].second] - (pi[ii].first == 0 ? 0 : v[pi[ii].first - 1] );
    leave = fun(ii+1);
    return dp[ii] = max(take,leave);
}
 
 
void solve() {
    cin >> n >> m;
    v.resize(n);
    pi.resize(m);
    dp.assign(m,-1);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    for (int i = 1; i < n; ++i) {
        v[i] += v[i-1];
    }
    for (int i = 0; i < m; ++i) {
        cin>>pi[i].first>>pi[i].second;
        pi[i].first--;
        pi[i].second--;
    }
    int mx = fun(0);
    cout<<mx;
}
 
signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}