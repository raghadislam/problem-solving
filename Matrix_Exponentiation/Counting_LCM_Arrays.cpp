/*
 * Link: https://cses.fi/problemset/task/3169/
 * Solution by: Raghad Islam
 * Date: 20-7-2025
 */

#include <bits/stdc++.h>
using namespace std;
 
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
typedef long long ll;
#define int ll
 
const int MOD = 1e9+7;
 
struct mint {
    int value;
    mint(int v = 0) { value = v % MOD; if(value < 0) value += MOD; }
    mint(int a, int b) : value(0) { *this += a; *this /= b; }
 
    mint& operator+=(mint const& b) { value += b.value; if(value >= MOD) value -= MOD; return *this; }
    mint& operator-=(mint const& b) { value -= b.value; if(value < 0) value += MOD; return *this; }
    mint& operator*=(mint const& b) { value = 1ll * value * b.value % MOD; return *this; }
 
    friend mint power(mint a, long long e) {
        mint res = 1; while(e) { if(e & 1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend mint inv(mint a) { return power(a, MOD - 2); }
 
    mint &operator/=(mint const& b) { return *this *= inv(b); }
    friend mint operator+(mint a, mint const b) { return a += b; }
    friend mint operator-(mint a, mint const b) { return a -= b; }
    friend mint operator-(mint const a) { return 0 - a; }
    friend mint operator*(mint a, mint const b) { return a *= b; }
    friend mint operator/(mint a, mint const b) { return a /= b; }
    friend ostream& operator<<(ostream& os, mint const& a) { return os << a.value; }
    friend bool operator==(mint const &a, mint const& b) { return a.value == b.value; }
    friend bool operator!=(mint const& a, mint const& b) { return a.value != b.value; }
};
 
template<class T>
struct Matrix {
    int n, m;
    vector<vector<T>> matrix;
 
    Matrix(int _n, int _m) {
        n = _n, m = _m;
        matrix.assign(n, vector<T>(m));
    }
 
    Matrix operator *(const Matrix &b) {
        int r = n, c = b.m, k = m;
        Matrix res(r, c);
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                for(int o = 0; o < k; ++o)
                    res.matrix[i][j] += matrix[i][o] * b.matrix[o][j];
        return res;
    }
 
 
    friend Matrix power(Matrix mat, long long p) {
        if(p == 0) {
            Matrix ones(mat.n, mat.n);
            for(int i = 0; i < mat.n; ++i)
                ones.matrix[i][i] = 1;
            return ones;
        }
 
        Matrix ret = power(mat * mat, p / 2);
        if(p&1) ret = ret * mat;
 
        return ret;
    }
 
    void display() {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) cout << matrix[i][j] << ' ';
            cout << "\n";
        }
    }
};
 
vector<int> get_divisors(ll num) {
 
    vector<int> divisors;
 
    ll i;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) {
            divisors.push_back(i);
            divisors.push_back(num / i);
        }
    }
    if((i * i) == num) divisors.push_back(i);
 
    return divisors;
}
 
 
vector<pair<long long, int>> factorize(long long k) {
    vector<pair<long long, int>> factors;
    if (k == 1) {
        return factors;
    }
    long long temp = k;
    for (long long i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            int cnt = 0;
            while (temp % i == 0) {
                cnt++;
                temp /= i;
            }
            factors.push_back({i, cnt});
        }
    }
    if (temp > 1) {
        factors.push_back({temp, 1});
    }
    return factors;
}
 
void solve() {
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, int>> factors = factorize(k);
    mint ans = mint(1);
    for (auto &pr : factors) {
        long long e = pr.second;
        if (n == 1) {
            ans = (ans * (e + 1));
        } else {
            Matrix<mint> M(2,2);
            M.matrix = {{0, 1}, {e, 1}};
            Matrix<mint> M_exp(2,2);
            M_exp = power(M, n - 1);
            Matrix<mint> dp(1, 2);
            dp.matrix = {{e, 1}};
            // long long v0 = e % MOD;
            // long long v1 = 1;
            dp = dp * M_exp;
            // mint new_v0 = (M_exp.matrix[0][0] * v0 + M_exp.matrix[1][0] * v1);
            // mint new_v1 = (M_exp.matrix[0][1] * v0 + M_exp.matrix[1][1] * v1);
            mint ways = (dp.matrix[0][0] + dp.matrix[0][1]);
            ans = (ans * ways);
        }
    }
    cout << ans << '\n';
}
 
signed main(){
    fileIO();
    fastIO();
    int t = 1; cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}
