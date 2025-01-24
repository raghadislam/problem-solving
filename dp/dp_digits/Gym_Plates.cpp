/* problem link: https://codeforces.com/gym/104493/problem/A
 * solution by: Raghad Islam
 * date: 21-1-2025 
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
int n;
vector<int> v;
int dp[101][3][3][3][3][3][3][3][3][3][3];
int vis[101][3][3][3][3][3][3][3][3][3][3];
int rc = 1;

int fun(int i, int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9) {

    if (i == n) return 0;

    int&ret = dp[i][i0][i1][i2][i3][i4][i5][i6][i7][i8][i9];
    if (vis[i][i0][i1][i2][i3][i4][i5][i6][i7][i8][i9] == rc) return ret;
    vis[i][i0][i1][i2][i3][i4][i5][i6][i7][i8][i9] = rc;

    int num = v[i];
    int i_0 = i0, i_1 = i1, i_2 = i2, i_3 = i3, i_4 = i4, i_5 = i5, i_6 = i6, i_7 = i7, i_8 = i8, i_9 = i9;
    bool f = 0;
    while (num) {
        int d  = num % 10;
        num = num / 10;
        if (d == 0) i_0++;
        else if (d == 1) i_1++;
        else if (d == 2) i_2++;
        else if (d == 3) i_3++;
        else if (d == 4) i_4++;
        else if (d == 5) i_5++;
        else if (d == 6) i_6++;
        else if (d == 7) i_7++;
        else if (d == 8) i_8++;
        else if (d == 9) i_9++;
    }

    int take = 0, leave = 0;
    leave = fun(i+1, i0, i1, i2, i3, i4, i5, i6, i7, i8, i9);
    if ((i_0 < 3) && (i_1 < 3) && (i_2 < 3) && (i_3 < 3) && (i_4 < 3) && (i_5 < 3) && (i_6 < 3) && (i_7 < 3)&& (i_8 < 3) && (i_9 < 3)) {
        take = fun(i+1, i_0, i_1, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9) + v[i];
    }
    return ret = max(leave,take);
}



void solve() {
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << fun(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)<<'\n';
    rc++;
}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}

