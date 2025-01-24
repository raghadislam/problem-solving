/* problem link: https://codeforces.com/problemset/problem/1602/B
 * solved by: Raghad Islam
 * Date: 24-2-2024 
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
    vector<vector<int>> v(n+20,vector<int>(n+20,0));
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin>>v[0][i];
        mx = max(mx,v[0][i]);
    }
    vector<int>freq(2009);
    for (int i = 0; i < n; ++i) {
        freq[v[0][i]]++;
    }
    int j = 1;
    while (1) {
        for (int i = 0; i < n; ++i) {
            v[j][i] = freq[v[j-1][i]];
        }
        bool f = 1;
        for (int i = 0; i < n; ++i) {
            if(v[j][i] != v[j-1][i]) {
                f = 0;
                break;
            }
        }
        if(f) break;
        freq.assign(2009,0);
        for (int i = 0; i < n; ++i) {
            freq[v[j][i]]++;
        }
        j++;
    }
    int q; cin>>q;
    while (q--) {
        int x,k; cin>>x>>k;
        if(k > j) k = j;
        cout<<v[k][x-1]<<'\n';
    }

}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}

