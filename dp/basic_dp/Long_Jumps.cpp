/* problem link: https://codeforces.com/problemset/problem/1472/C
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
vector<int> dp;


int fun(int i) {
    if(i>=n) return 0;
    int&ret = dp[i];
    if(ret!=-1) return ret;
    return ret = v[i] + fun(i+v[i]);
}


void solve() {
    cin >> n;
    v.resize(n);
    dp.assign(n+2,-1);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        mx = max(mx,fun(i));
    }
    cout<<mx<<'\n';
}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}
