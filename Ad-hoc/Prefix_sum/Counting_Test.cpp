/* problem link: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/C
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
    int n,q; cin>>n>>q;
    string s; cin>>s;

    int v[30][n+20] = {0};
    for(int c = 0; c < 26; ++c) {
        for(int i = 0; i < n; ++i){
            v[c][i] = 0;
            if(s[i] == ('a' + c)) {
                v[c][i] = 1;
            }
        }
        for(int i = 1; i < n; ++i){
            v[c][i] += v[c][i-1];
        }
    }

    while (q--) {
        int l, r;
        char C;
        cin >> l >> r >> C;
        int c = C - 'a';
        l--; r--;
        int start = l / n, end = r / n;
        int startPos = l % n, endPos = r % n;
        int ans = 0;

        if (start == end) {
            ans += v[c][endPos] - (startPos > 0 ? v[c][startPos - 1] : 0);
        } else {
            ans += v[c][n - 1] - (startPos > 0 ? v[c][startPos - 1] : 0);
            ans += v[c][endPos];

            int cycles = end - start - 1;
            if (cycles >= 0) {
                ans += cycles * v[c][n - 1];
            }
        }

        cout << ans << '\n';
    }
 //   cout<<"2\n4\n3\n3\n2";

}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}

