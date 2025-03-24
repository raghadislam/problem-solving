/* problem link: https://codeforces.com/contest/2050/problem/F
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
#define gcd(a, b) __gcd(a, b)

class SegTree {
public:
    vector<int> segTree;
    int n;

    SegTree(int size) {
        n = size;
        segTree.resize(4 * n, 0);
    }

    void build(const vector<int>& arr, int v, int l, int r) {
        if (l == r) {
            segTree[v] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, v * 2, l, mid);
            build(arr, v * 2 + 1, mid + 1, r);
            segTree[v] = gcd(segTree[v * 2], segTree[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return segTree[v];
        }
        int tm = (tl + tr) / 2;
        return gcd(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = abs(a[i + 1] - a[i]);
    }
    SegTree segTree(n - 1);
    if (n > 1) {
        segTree.build(diff, 1, 0, n - 2);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        if (l == r) {
            cout << 0 << " ";
        } else {
            int result = segTree.query(1, 0, n - 2, l, r - 1);
            cout << result << " ";
        }
    }
    cout << endl;
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
