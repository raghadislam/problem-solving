/* problem link: https://codeforces.com/problemset/problem/313/B
 * solution by: Raghad Islam
 * date: 1-7-2024 
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
    int q;
    string s; cin>>s;
    int n = s.size();
    vector<int>v(n,0);
    for (int i = 0; i < n - 1; ++i) {
        if(s[i] == s[i+1]) v[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        v[i] += v[i-1];
    }
    cin>>q;
    while (q--) {
        int l,r; cin>>l>>r;
        l--,r--;
        cout<< v[r-1] - (l==0 ? 0 : v[l-1])<<'\n';
    }
}

signed main(){
    fileIO();
    fastIO();
   //tests
        solve();
    return 0;
}

