/* problem link: https://cses.fi/problemset/task/1724
 * solution by: Raghad Islam
 * date: 12-7-2025 
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
const int INF = 2e18;

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
        matrix.assign(n, vector<T>(m, INF));
    }

    Matrix operator *(const Matrix &b) {
        int r = n, c = b.m, k = m;
        Matrix res(r, c);
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                for(int o = 0; o < k; ++o) {
                    int tmp = matrix[i][o] + b.matrix[o][j];
                    if (tmp < res.matrix[i][j]) {
                        res.matrix[i][j] = tmp;
                    }
                }
        return res;
    }


    friend Matrix power(Matrix mat, long long p) {
        if(p == 0) {
            Matrix ones(mat.n, mat.n);
            for(int i = 0; i < mat.n; ++i)
                ones.matrix[i][i] = 0;
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

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        int x = min(c, adjMatrix[a][b]);
        adjMatrix[a][b] = min(c, adjMatrix[a][b]);
    }

    Matrix<int> dp(1, n);
    dp.matrix[0][0] = 1;;

    Matrix<int> mat(n,n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            mat.matrix[i][j] = adjMatrix[i][j];
    }

    mat = power(mat, k);
    dp = dp * mat;

    if (dp.matrix[0][n - 1] == INF) cout << "-1\n";
    else cout << dp.matrix[0][n - 1] - 1 << '\n';
}

signed main(){
    fileIO();
    fastIO();
    int t = 1; //cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
