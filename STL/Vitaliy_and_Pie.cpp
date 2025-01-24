/* problem link: https://codeforces.com/problemset/problem/525/A
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
    string s; cin>>s;
    map<int,int>mp;
    int ans = 0;
    int diff = (int)('a' - 'A');
    for(int i = 0; i < 2 * n - 2;  ++i) {
        if(i%2 == 0) {
            mp[s[i]]++;
        }
        else {
            if(mp[s[i] + diff] == 0) {
                ans++;
            }
            else mp[s[i] + diff]--;
        }

    }
    cout<<ans;
}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}

