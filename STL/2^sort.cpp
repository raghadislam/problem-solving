/* problem link: https://codeforces.com/problemset/problem/1692/G
 * solved by: Raghad Islam
 * Date: 28-1-2024 
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
    int n,k; cin>>n>>k;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    int cnt=1;
    vector<int>vv;
    for (int i = 1; i < n; ++i) {
        if(v[i] > (v[i-1]/2)) cnt++;
        else {
            if(cnt)
                vv.push_back(cnt);
            cnt = 1;
          //  i++;
        }
    }
    if(cnt) vv.push_back(cnt);
    int ans = 0;
    for (long long i : vv) {
        ans += max(0LL,i - k);
    }
    cout<<ans<<'\n';
}

signed main(){
    fileIO();
    fastIO();
   tests
        solve();
    return 0;
}

