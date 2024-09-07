/* problem link: https://codeforces.com/problemset/problem/408/B
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

typedef long long ll;
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)

void solve() {
    string s1,s2; cin>>s1>>s2;
    int frq[30] = {0};
    for (int i = 0; i < s1.size(); ++i) {
        frq[s1[i]-'a']++;
    }
    for (int i = 0; i < s2.size(); ++i) {
        if(!frq[s2[i]-'a']) {
            cout<<-1;
            return;
        }
    }
    int mx = 0;
    for (int i = 0; i < s2.size(); ++i) {
        frq[s2[i]-'a']--;
        if(frq[s2[i]-'a'] >= 0) mx++;
    }
    cout<<mx;

}

signed main(){
    fileIO();
    fastIO();

    // tests
    solve();

    return 0;
}