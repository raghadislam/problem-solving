/* problem link: https://codeforces.com/problemset/problem/1025/A
 * solution by: Raghad Islam
 * date: 3-8-2024 
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
    int frq[30] = {0};
    for (int i = 0; i < n; ++i) {
        frq[s[i] - 'a']++;
        if(frq[s[i] - 'a'] > 1) {
            cout << "Yes";
            return;
        }
    }
    if(n==1)
        cout<<"Yes";
    else
        cout << "No";
}

signed main(){
    fileIO();
    fastIO();
    //tests
    solve();
    return 0;
}

