/* problem link: https://codeforces.com/gym/102644/problem/E
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

typedef unsigned long long ll;
#define int ll

const int MOD = 4294967296;

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


short dx[] = {-1, 1, -1, 1, -2, -2, 2, 2};
short dy[] = {-2, -2, 2, 2, -1, 1, -1, 1};

bool valid(int i, int j) {
    return (i < 8 && j < 8 && i >= 0 && j >= 0);
}



void solve() {
    int k; cin >> k;
    mint board[64][64];

    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            for (int id = 0; id < 8; ++id) {
                int x = i + dx[id];
                int y = j + dy[id];
                if (valid(x, y)) {
                    board[i*8 + j][x*8+y] += 1;
                }
            }
        }
    }

    Matrix<mint> dp(1, 65);
    dp.matrix[0][0] = 1;

    Matrix<mint> mat(65, 65);
    for(int i = 0; i < 64; ++i) {
        for(int j = 0; j < 64; ++j) {
            mat.matrix[i][j] = board[i][j];
        }
    }

    for(int i = 0; i <= 64; ++i) mat.matrix[i][64] = 1;
    mat = power(mat, k+1);
    dp = dp * mat;
    cout << dp.matrix[0][64] << endl;
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
