/* problem link: https://codeforces.com/problemset/problem/236/A 
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
    string s; cin>>s;
    int frq[30] = {0};
    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(frq[s[i] - 'a'] == 0) res++;
        frq[s[i] - 'a']++;
    }
    if(res & 1LL) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
}

signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}

