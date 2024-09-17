/* problem link: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/G
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
int const N = 1e3;

void solve() {
    int v[N + 1][N + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            v[i][j] = 0;
        }
    }
    int n, q;
    cin >> n >> q;
    while (n--) {
        int h, w;
        cin >> h >> w;
        v[h][w] += h * w;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            v[i][j] = v[i][j - 1] + v[i - 1][j] + v[i][j] - v[i - 1][j - 1];
        }
    }
    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        int ans = v[hs][ws] - v[hb - 1][ws] - v[hs][wb - 1] + v[hb - 1][wb - 1];
        cout << ans << '\n';
    }
}

signed main(){
    fileIO();
    fastIO();
    tests
        solve();
    return 0;
}

