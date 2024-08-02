/* problem link: https://atcoder.jp/contests/dp/tasks/dp_b?lang=en
 * solution by: Raghad Islam
 * date: 3-11-2023 
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
vector<int>v;
int n,k;
int dp[200009];
int vis[200009];
int fun(int i)
{
    if(i==n-1) return 0;
    int&ret = dp[i];
    if(vis[i]) return ret;
    vis[i] = true;
    int ch1 =INT_MAX,ch2=INT_MAX,ch = INT_MAX;
    for (int j = 1; j <= k; ++j) {
        if(i+j<n)
        ch = min(ch, fun(i+j) + abs(v[i] - v[i+j]));
    }
    return ret = ch;
}

void solve() {
    cin>>n>>k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    cout<<fun(0);

}

signed main(){
    fileIO();
    fastIO();
  //  tests {
        solve();
  //  }
    return 0;
}
