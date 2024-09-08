/* problem link: https://codeforces.com/problemset/problem/817/C 
 * solution by: Raghad Islam
 * date: 22-8-2024 
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
int n,s;
vector<int>v;
int dp[300009][2];

int fun(int i, bool sign) {
    if(i == n) return 0;
    int&ret = dp[i][sign];
    if(ret!=-1) return ret;
    int ch1;
    if(sign) {
        ch1 = fun(i+1, 1-sign) + v[i];
    }
    else ch1 = fun(i+1, 1-sign) - v[i];
    int ch2 = fun(i+1, sign);
    return ret = max(ch1,ch2);
}

bool can(int x) {
    int num =x;
    int sum =0;
    while (num) {
        sum+=num%10;
        num/=10;
    }
    return (x-sum) >= s;
}


void solve() {
    cin>>n>>s;
    int l=1,r=n,ans =0;
    while (l<=r) {
        int mid = (l+r)/2;
        if(can(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }

    if(ans) {
        cout<<n - ans + 1;
    }
    else cout<<0;
}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
