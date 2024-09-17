/* problem link: https://codeforces.com/problemset/problem/474/B
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
    int n; cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    for (int i = 1; i < n; ++i) {
        v[i] += v[i-1];
    }
    int q; cin>>q;
    while (q--) {
        int x; cin>>x;
        cout << lower_bound(v.begin(),v.end(),x) - v.begin() + 1 << '\n';
    }
}

signed main(){
    fileIO();
    fastIO();
   //tests
        solve();
    return 0;
}

