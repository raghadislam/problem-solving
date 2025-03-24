/*
 * problem link: https://codeforces.com/problemset/problem/1978/C
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    iota(num.begin(), num.end(), 1);

    int indx = 1, mx = 0;
    for (int i = n - 1; i >= 0; --i) {
        mx += abs(num[i] - indx);
        indx++;
    }

    if (n == 1) {
        if (k == 0) {
            cout << "Yes\n" << num[0] << '\n';
        } else {
            cout << "No\n";
        }
        return;
    }

    if (k & 1 || k > mx) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        if (k == mx) {
            for (int i = n; i >= 1; --i) cout << i << ' ';
            cout << '\n';
            return;
        }

        k /= 2;
        for (int i = 0; k > 0; ++i) {
            int dist = n - 1 - 2 * i;
            if (k > dist) {
                swap(num[i], num[n - 1 - i]);
                k -= dist;
            } else {
                swap(num[i], num[k + i]);
                k = 0;
            }
        }

        for (auto x : num) cout << x << ' ';
        cout << '\n';
    }
}

signed main() {
    fastIO();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

