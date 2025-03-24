/*
 * problem link: https://codeforces.com/problemset/problem/1913/C
 * solved by: Raghad Islam
 * Date: 22-3-2025
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int binary(int temp, int cnt, int b) {
    int l = 0, r = cnt, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * b <= temp) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int m; cin >> m;
    map<int, int> freq;
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            freq[x]++;
        } else {
            int y; cin >> y;
            auto mp = freq;
            bool failed = false;
            for (int i = 29; i >= 0; i--) {
                if ((y & (1 << i)) == 0) continue;
                if (mp[i]) {
                    mp[i]--;
                } else {
                    int temp = (1 << i);
                    for (int j = i - 1; temp > 0 && j >= 0; j--) {
                        if (mp[j]) {
                            int res = binary(temp, mp[j], (1 << j));
                            if (res == -1) continue;
                            temp -= (1 << j) * res;
                            mp[j] -= res;
                        }
                    }
                    if (temp > 0) {
                        cout << "NO\n";
                        failed = true;
                        break;
                    }
                }
            }
            if (!failed) cout << "YES\n";
        }
    }
}

signed main() {
    fastIO();
    solve();
    return 0;
}

