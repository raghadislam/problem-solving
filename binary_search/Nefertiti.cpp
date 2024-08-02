/* problem link: https://codeforces.com/group/Rilx5irOux/contest/530044/problem/N
*  this problem is the problem 'N' in the 8th day of 2023 ECPC qualification
*  date: 2-8-2024
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
#define MOD 1000000007

ll fastPower(ll n, ll p, ll mod) {
    if (p <= 0) return 1;
    ll res = fastPower(n, p / 2, mod);
    res = (res * res) % mod;
    if (p % 2 != 0) {
        res = (res * n) % mod;
    }
    return res;
}


string BinaryNum;
int dp[33][3][33];

string binary(int n){
    string s;
    while(n){
        s.push_back(char((n%2) + '0'));
        n /= 2;
    }
    reverse(s.begin(),s.end());
    return s;
}

bool is_prime(ll num) {
    if (num == 2) return true;
    if (num < 2 || !(num % 2)) return false;

    for (ll i = 3; i * i <= num; i += 2) {
        if (!(num % i)) return false;
    }

    return true;
}

int func(int idx, int tight, int cnt){
    if(idx == BinaryNum.size()) return is_prime(cnt);

    int & ret = dp[idx][tight][cnt];
    if(~ret) return ret;
    ret = 0;

    int end = tight ? BinaryNum[idx] - '0' : 1;
    for (int i = 0; i <= end; ++i) {
        ret += func(idx + 1, tight && (i == end), cnt + i);
    }
    return ret;
}
void solve(){
    int n; cin >> n;

    int l = 0, r = 10000000000, ans, mid;
    while(l <= r){
        mid = l + (r - l)/2;
        BinaryNum = binary(mid);
        memset(dp, -1, sizeof(dp));
        if(func(0,1,0) >= n){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << endl;

}

signed main() {
    fileIO();
    fastIO();

    int t; cin>>t;
    while (t--)
    solve();

    return 0;
}