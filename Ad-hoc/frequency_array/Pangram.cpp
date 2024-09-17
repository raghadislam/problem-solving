/* problem link: https://codeforces.com/problemset/problem/1669/B
 * solution by: Raghad Islam
 * date: 2-8-2024 
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
    string s; cin>>s;
    int frq[400]= {0};
    for (int i = 0; i < n; ++i) {
        frq[s[i]]++;
    }
    for (int i = 0; i < 26; ++i) {
        if(frq['a' + i] == 0 && frq['A' + i] == 0) {
            cout <<"NO";
            return;
        }
    }
    cout<<"YES";
}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
