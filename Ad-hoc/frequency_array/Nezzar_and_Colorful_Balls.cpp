/* problem link: https://codeforces.com/problemset/problem/1478/A
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
#define ll long long
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
// int n,s;
// vector<int>v;
// int dp[300009][2];
//
// int fun(int i, bool sign) {
//     if(i == n) return 0;
//     int&ret = dp[i][sign];
//     if(ret!=-1) return ret;
//     int ch1;
//     if(sign) {
//         ch1 = fun(i+1, 1-sign) + v[i];
//     }
//     else ch1 = fun(i+1, 1-sign) - v[i];
//     int ch2 = fun(i+1, sign);
//     return ret = max(ch1,ch2);
// }

int n,s;
ll dp[20][200][2];
vector<int> digits;
int ans=0;

ll fun(int pos, int sum, int tight, int num) {
    if (pos == digits.size()) {
        int x = (s <= num - sum);
        return x;
    }

    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }

    ll res = 0;
    int end = (tight ? digits[pos] : 9);

    for (int digit = 0; digit <= end; digit++) {
        res += fun(pos + 1, sum + digit, tight && (digit == end), num*10 + digit);
    }

    return dp[pos][sum][tight] = res;
}

void solve() {
    int n; cin>>n;
    int arr[100];
    int frq[101] = {0};
    int colors = 0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        frq[arr[i]]++;
        if(frq[arr[i]] > colors) colors++;
    }
    cout << colors <<'\n';
}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}


