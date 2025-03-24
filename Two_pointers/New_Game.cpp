/*
 * problem link: https://codeforces.com/contest/2025/problem/C
 * solved by: Raghad Islam
 * Date: 24-3-2025
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
#define MAX (int)(1e5 + 10)
//int freq[MAX];

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> deck(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> deck[i];
        mp[deck[i]]++;
    }

    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end());

    int cnt = 0, left = 0, cntK = 0, mx = 0;
    for (int right = 0; right < v.size(); ++right) {
        if((right == 0) || (v[right].first - v[right - 1].first == 1)) {
            cnt += v[right].second;
            cntK = right - left + 1;

        }
        else if((v[right].first - v[right - 1].first != 1)) {
            cnt = v[right].second;
            cntK = 1;
            left = right;
          //  cntK = right - left + 1;
        }

        while (cntK > k) {
            cnt -= v[left].second;
            left++;
            cntK = right - left + 1;
        }

        mx = max(mx, cnt);
    }

    cout << mx << '\n';
}



signed main(){
    fileIO();
    fastIO();
    tests
  solve();
    return 0;
}
