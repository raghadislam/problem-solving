/* problem link: https://codeforces.com/contest/1996/problem/C
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

typedef long long ll;
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)

int mul(int a, int b, int mod){
    return ((a%mod) * (b%mod)) % mod;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    a = " " + a; b = " " + b;
    vector<vector<int>> freq_a(n + 1, vector<int>(26, 0));
    vector<vector<int>> freq_b(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            freq_a[i][j] = freq_a[i - 1][j];
            freq_b[i][j] = freq_b[i - 1][j];
        }
        freq_a[i][a[i] - 'a']++;
        freq_b[i][b[i] - 'a']++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;

        vector<int> A(26, 0);
        vector<int> B(26, 0);

        for (int i = 0; i < 26; ++i) {
            A[i] = freq_a[r][i] - freq_a[l - 1][i];
            B[i] = freq_b[r][i] - freq_b[l - 1][i];
        }

        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (A[i] > B[i]) {
                res += A[i] - B[i];
            }
        }

        cout << res << '\n';
    }
}

signed main(){
    fileIO();
    fastIO();

    tests
    solve();

    return 0;
}