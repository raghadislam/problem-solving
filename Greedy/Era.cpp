/*
 * problem link: https://codeforces.com/problemset/problem/1604/A
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

void solve() {
    int n; cin>>n;
    int x;
    int ans = 0;
    int i = 1;
    while (n--) {
        cin>>x;
        if(x > i) {
            ans += (x - i );
            i = x + 1;
        }
        else i++;
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
