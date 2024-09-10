/* problem link: https://codeforces.com/problemset/gymProblem/103643/D?mobile=true&locale=en
 * solution by: Raghad Islam
 * date: 2-4-2024 
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
    string s1, s2; cin>>s1>>s2;
    int firstOnly[350] ={0};
    int secondOnly[350] = {0};
    int f=0,s=0;
    for (int i = 0; i < n; ++i) {
        firstOnly[s1[i]-'a']++;
    }
    for (int i = 0; i < n; ++i) {
        secondOnly[s2[i]-'a']++;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if(firstOnly[s2[i] - 'a'] < secondOnly[s2[i] - 'a']) {
            res += abs(firstOnly[s2[i] - 'a'] - secondOnly[s2[i] - 'a']);
            firstOnly[s2[i] - 'a'] = secondOnly[s2[i] - 'a'];
        }
    }
    cout<<res;
}

signed main(){
    fileIO();
    fastIO();
    //tests
    solve();
    return 0;
}
