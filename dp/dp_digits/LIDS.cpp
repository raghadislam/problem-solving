/* problem link: https://toph.co/p/lids
 * solution by: Raghad Islam
 * date: 21-1-2025 
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

int n, j, a[10], b[10];
int dp[10][2][2][2][11][11];

int fun(int i, bool f, bool ff, bool lead, int last, int total) {
    if (i == n) return total == j;

    int &ret = dp[i][f][ff][lead][last + 1][total];
    if (ret != -1) return ret;
    ret = 0;

    int l = a[i], r = b[i];
    if (f) r = 9;
    if (ff) l = 0;

    for(int d = l; d <= r; ++d) {
        ret += fun(i + 1, (f || d < r), (ff || d > l), (lead || d), last, total);
        if (!lead && d == 0) continue;
        if (d > last) ret += fun(i + 1, (f || d < r), (ff || d > l), (lead || d), d, total + 1);
    }
    return ret;
}

void solve(int o) {
    cout << "Case " << 1+o << ": ";
    string s1, s2;
    cin >> s1 >> s2;
    while(s1.size() < s2.size()) s1 = '0' + s1;
    n = s1.size();

    for(int i = 0; i < n; ++i) a[i] = s1[i] - '0';
    for(int i = 0; i < n; ++i) b[i] = s2[i] - '0';

    int ans = 0;
    for(j = 1; j <= 10; ++j) {
        memset(dp, -1, sizeof dp);
        int t = fun(0, 0, 0, 0, -1, 0);
        if (t == 0) {
            --j; break;
        }
        ans = t;
    }
    cout << j << ' ' << ans << '\n';
}

signed main(){
    // fileIO();
    fastIO();
    tests
    solve(o);
    return 0;
}
