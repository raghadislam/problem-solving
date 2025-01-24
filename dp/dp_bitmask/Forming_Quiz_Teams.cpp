/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1852
 * solution by: Raghad Islam
 * date: 18-1-2025 
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
int n;
int c = 1;
const int MAX = 17;
pair<int, int> v[MAX];
double dp[1 << MAX];

double distance(int i, int j) {
    return sqrt(pow(v[i].first - v[j].first, 2) +
                pow(v[i].second - v[j].second, 2));
}

double fun(int mask) {

    if (mask == (1 << (2*n)) - 1) return 0;
    if (dp[mask] >= 0) return dp[mask];

    int f = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (!(mask & (1 << i))) {
            f = i;
            break;
        }
    }
    double res = DBL_MAX;

    for (int i = f + 1; i < 2 * n; i++) {
        if (!(mask & (1 << i))) {
            int newMask = (mask | (1 << i) | (1 << f));
            res = min(res, distance(f, i) + fun(newMask));
        }
    }
    return dp[mask] = res;

}

void solve() {
    while (cin >> n && n != 0) {
        for (int i = 0; i < 2 * n; i++) {
            string s; cin >> s;
            int x, y; cin >> x >> y;
            v[i].first = x;
            v[i].second = y;
        }
        memset(dp, -1, sizeof(dp));
        cout << fixed << setprecision(2) << "Case " << c++ << ": "<< fun(0) << "\n";
    }
}

signed main(){
    fileIO();
    fastIO();
    solve();
    return 0;
}
