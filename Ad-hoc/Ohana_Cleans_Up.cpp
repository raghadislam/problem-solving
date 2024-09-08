/* problem link: https://codeforces.com/problemset/problem/554/B
 * solution by: Raghad Islam
 * date: 3-8-2024 
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
 
void solve() {
    int n; cin>>n;
    map<string, int>mp;
    int mxRows = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin>>s;
        mp[s]++;
        mxRows= max(mxRows,mp[s]);
    }
    cout<<mxRows;
}
 
signed main(){
    fileIO();
    fastIO();
    //tests
    solve();
    return 0;
}
