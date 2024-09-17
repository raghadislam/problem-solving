/* problem link: https://codeforces.com/problemset/problem/961/B
 * solution by: Raghad Islam
 * date: 2-8-2024 
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
    vector<int>v(n); vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    vector<int> part(n+9,0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
        if(s[i] == 0) {
            part[i] = v[i];
        }
        else res += v[i];
    }
    for (int i = 1; i < n; ++i) {
        part[i] += part[i - 1];
    }
    int mx = part[k-1];
    for (int i = 1; i <= n - k ; ++i) {
        mx = max(mx, part[i + k - 1] - part[i - 1]);
    }
    cout << res + mx ;

}

signed main(){
    fileIO();
    fastIO();
   //tests
        solve();
    return 0;
}

