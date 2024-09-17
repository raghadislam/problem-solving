/* problem link: https://codeforces.com/problemset/problem/368/B
 * solution by: Raghad Islam
 * date: 28-7-2024 
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

int freq[100005];
void solve() {
    int n,m; cin>>n>>m;
    int x;
    int res[n+9];
    res[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin>>x;
        res[i] = 0;
        if(freq[x] == 0) {
            freq[x] = i;
            res[i] = 1;
        }
        else {
            res[i] = 1;
            res[freq[x]] = 0;
            freq[x] = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }
    while (m--) {
        int l;
        cin >> l;
        cout<<res[n] - res[l-1]<<'\n';
    }


}

signed main(){
    fileIO();
    fastIO();
  //  tests
        solve();
    return 0;
}
