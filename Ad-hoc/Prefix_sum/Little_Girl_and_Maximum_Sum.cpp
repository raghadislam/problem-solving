/* problem link: https://codeforces.com/problemset/problem/276/C
 * solution by: Raghad Islam
 * date: 6-8-2024 
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
    int n,q; cin>>n>>q;
    vector<int>v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    vector<int>idx(n+1);
    vector<pair<int,int>>que(q);
    vector<pair<int,int>> partial(n+1);
    partial[0].first = 0;
    for (int i = 1; i <= n; ++i) {
        partial[i].first = 0;
        partial[i].second = i;
    }
    int i=0;
    while (q--) {
        cin>>que[i].first>>que[i].second;
        partial[que[i].first].first++;
        partial[que[i].second + 1].first--;
        i++;
    }
    for (int j = 1; j <= n; ++j) {
        partial[j].first += partial[j-1].first;
    }
    sort(partial.rbegin(),partial.rend());
    vector<int> final(n+1);
    for(int j = 0; j < n; j++) {
        final[partial[j].second] = v[j];
    }
    for (int i = 1; i <= n; i++) {
        final[i] += final[i-1];
    }
    int res = 0;
    for(int i = 0; i < que.size(); i++) {
        res += final[que[i].second] - final[que[i].first - 1];
    }
    cout<<res;
}

signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}
