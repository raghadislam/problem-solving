/* problem link: https://codeforces.com/problemset/problem/1042/B
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
int n,m;
vector<int> p;
vector<string>v;
int dp[1009][2][2][2];

int fun(int i, bool A, bool B, bool C) {
    if(i==n) {
        if(A and B and C) return 0;
        return 1e9;
    }
    int&ret = dp[i][A][B][C];
    if(ret !=-1) return ret;
    bool a = false, b = false, c = false;
    if(v[i].find('A') != std::string::npos) a = true;
    if(v[i].find('B') != std::string::npos) b = true;
    if(v[i].find('C') != std::string::npos) c = true;
    int ch1 = fun(i+1, a || A, b || B, c || C) + p[i];
    int ch2 = fun(i+1, A, B, C);
    return ret = min(ch1,ch2);

}


void solve() {
    cin >> n;
    p.resize(n); v.resize(n);
    memset(dp,-1,sizeof dp);

    for (int i = 0; i < n; ++i) {
        cin>>p[i]>> v[i];
    }
    int res = fun(0,0,0,0);
    if(res == 1e9) cout<<-1;
    else cout<< res;

}

signed main(){
    fileIO();
    fastIO();
 //   tests
    solve();
    return 0;
}
