/* problem link: https://codeforces.com/contest/2050/problem/B
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

#define ll long long
#define int ll
#define tests int t; cin >> t; while(t--)

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        total += v[i];
    }

    if (total % n != 0) {
        cout << "NO\n";
        return;
    }
    int val = total / n;
    int gamb = 0;
    int x = 0;
    for (int i = 0; i < n; i += 2) {
        if (v[i] > val) x += (v[i] - val);
        else if (v[i] < val) x -= (val - v[i]);
    }
    if (x != 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; i += 2) {
        if (v[i] > val) x += (v[i] - val);
        else if (v[i] < val) x -= (val - v[i]);
    }
    if (x != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
    fileIO();
    fastIO();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
