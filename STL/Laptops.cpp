/* problem link: https://codeforces.com/problemset/problem/456/A
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
    int n; cin>>n;
    vector<pair<int,int>>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    for (int i = 1; i < n; ++i) {
        if(v[i].second < v[i-1].second) {
            cout<<"Happy Alex";
            return;
        }
    }
    cout<<"Poor Alex";
}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}

