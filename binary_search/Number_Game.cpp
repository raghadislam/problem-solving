/* problem link: https://codeforces.com/problemset/problem/1749/C
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

bool can(int mid, multiset<int> mss) {
    multiset<int> ms2 = mss;
    for (int i = 1; i <= mid; ++i){
        // alice
        auto it = ms2.upper_bound(mid - i + 1);
        if(it == ms2.begin()) return 0;
        it--;
        ms2.erase(it);
        // bob
        int val = *ms2.begin();
        val += (mid - i +1);
        if(ms2.empty()) return 1;
        ms2.erase(ms2.begin());
        ms2.insert(val);
    }
    return 1;

}

void solve() {
    int n; cin>>n;
    multiset<int>ms;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        ms.insert(x);
    }
    multiset<int> ms2 = ms;
    int l = 0; int  r = n, ans = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        if(can(mid, ms2)) {
            ans = mid ;
            l = mid + 1;
        }
        else r = mid - 1;
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

