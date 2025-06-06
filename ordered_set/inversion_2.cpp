/* problem link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
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
    ordered_set o_set;
    for (int i = 0; i < n; i++) {
        o_set.insert(i+1);
    }
    vector<int> v(n);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = n-1; i >= 0; i--) {
        int vv = v[i];
        int idx = (i+1) - vv - 1;
        int val = *o_set.find_by_order(idx);
        ans.push_back(val);
        o_set.erase(val);
    }
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
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
