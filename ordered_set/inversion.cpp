/* problem link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
 * solution by: Raghad Islam
 * date: 6-6-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    ordered_set o_set;
    int sz = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cout << sz - o_set.order_of_key(v[i]) << ' ';
        o_set.insert(v[i]);
        sz++;
    }

}

signed main(){
    fileIO();
    fastIO();
    int t = 1;// cin >> t;
 //   while(t--)
        solve();
    return 0;
}
