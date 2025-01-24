/*
 * problem link: https://codeforces.com/problemset/problem/1579/B
 * solved by: Raghad Islam
 * Date: 1-7-2024
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

int val = -1e9;

void solve() {
    int n; cin>>n;
    vector<int>v(n);
    vector<pair<pair<int,int>,int>> ans;
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    for (int i = 0; i < n; ++i) {
        int d = min_element(v.begin() + i, v.end()) - v.begin();
        int value = v[d];
        d -= i;
        if(d) ans.emplace_back(make_pair(i+1, n), d);
        for (int j = 0; j < d; ++j) {
            v.push_back(*(v.begin() + i));
            v.erase(v.begin()+i);
        }
    }
    cout<< ans.size()<<'\n';
    for (auto & an : ans) {
        cout<<an.first.first<<' '<<an.first.second<<' '<<an.second<<'\n';
    }


}

signed main(){
    fileIO();
    fastIO();
 tests
     solve();
    return 0;
}
