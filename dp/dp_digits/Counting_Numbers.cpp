/* problem link: https://cses.fi/problemset/task/2220/
 * solution by: Raghad Islam
 * date: 10-1-2025 
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
int dp[20][2][11][2], vis[20][2][11][2];
int tc = 1;
 
int fun(int i, bool tight, int last, bool leading)
{
    if (i == s.size()) {
        return 1;
    }
 
    int &ret = dp[i][tight][last][leading];
    if (vis[i][tight][last][leading] == tc) return ret;
    vis[i][tight][last][leading] = tc;
    ret = 0;
 
    int end = (tight? s[i] - '0' : 9);
 
    for (int j = 0; j <= end; j++) {
        if (!leading && j == last) continue;
        ret += fun(i + 1, tight && (j == end), (leading && j == 0) ? 10 : j, leading && j == 0);
    }
 
    return ret;
}
 
void solve()
{
    int x; cin >> x;
    x--;
    s = to_string(x);
    int val1 = fun(0, 1, 10, 1);
 
    cin>>s;
    tc++;
    cout<<fun(0, 1, 10, 1) - val1;
}
 
signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}

