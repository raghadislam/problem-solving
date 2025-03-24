/* problem link: https://codeforces.com/contest/2025/problem/D
 * solution by: Raghad Islam
 * date: 24-3-2025 
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

#define tests int t; cin >> t; int o = -1; while(++o < t)
#define MAX (int)(1e5 + 10)
int dp[5009][5009];

void solve() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> Strength(n+1);
    vector<vector<int>> Intelligence(n+1);
    vector<int> points;

    int ze = -1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x == 0) {
            points.push_back(i);
            ze = i;
            continue;
        }
        if(ze != -1) {
            if(x > 0)
                Intelligence[ze].push_back(x);
            else
                Strength[ze].push_back(-x);
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(Intelligence[i].begin(), Intelligence[i].end());
        sort(Strength[i].begin(), Strength[i].end());
    }

    int total = m;
    for(int i = 0; i <= m + 1; i++)
    {
        dp[m][i] = 0;
    }

    for(int i = m - 1; i >= 0; i--) {
        for(int str = 0; str <= m; str++) {
            int inte = total - str - 1;

            int cnt = upper_bound(Intelligence[points[i]].begin(), Intelligence[points[i]].end(), inte) - Intelligence[points[i]].begin();
            cnt += upper_bound(Strength[points[i]].begin(), Strength[points[i]].end(), str + 1) - Strength[points[i]].begin();
            dp[i][str] = dp[i+1][str + 1] + cnt;

            inte = total - str;

            cnt = upper_bound(Intelligence[points[i]].begin(), Intelligence[points[i]].end(), inte) - Intelligence[points[i]].begin();
            cnt += upper_bound(Strength[points[i]].begin(), Strength[points[i]].end(), str) - Strength[points[i]].begin();
            dp[i][str] = max(dp[i+1][str] + cnt, dp[i][str]);
        }
        total--;
    }

    cout << dp[0][0];
}



signed main(){
    fileIO();
    fastIO();
  //  tests
  solve();
    return 0;
}
