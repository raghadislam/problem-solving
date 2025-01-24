/* problem link: https://codeforces.com/contest/1800/problem/C2
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
    priority_queue<int>pq;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        if(!x && !pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        else pq.push(x);
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

