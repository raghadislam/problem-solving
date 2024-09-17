/* problem link: https://codeforces.com/problemset/problem/363/B
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
    vector<int>v(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    int mn = INT_MAX, mnidx = INT_MAX;
    for(int i = 1; i <= n - k + 1; ++i) {
        if(v[i + k - 1] - v[i - 1] < mn) {
            mn = v[i + k - 1] - v[i - 1];
            mnidx = i;
        }
    }
    cout << mnidx;
}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
