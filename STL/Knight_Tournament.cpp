/*
 * problem link: https://codeforces.com/problemset/problem/356/A
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

bool fun(pair<int,string>p1, pair<int,string>p2) {
    return p1.first <= p2.first;
}

void solve() {
    int n, m; cin>>n >> m;
    set <int> alive;
    for (int i = 1; i <= n; ++i) {
        alive.insert(i);
    }
    vector<int> ans(n+1,0);
    while (m--) {
        int l,r,x; cin>>l>>r>>x;
        auto it = alive.lower_bound(l);
        while (it != alive.end() && (*it <= r)) {
            if(*it != x) ans[*it] = x;
            if(*it != x) {
                auto erase_it = it;
                it++;
                alive.erase(erase_it);
            }
            else it++;

        }
    }
    for (int i = 1; i <= n; ++i) {
        cout<<ans[i]<<' ';
    }
}

signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}

