/* problem link: https://codeforces.com/problemset/problem/509/C
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
int b;
int dp[351][2][309];
int vis[351][2][309];
int rc = 1;
string s,Next;

bool fun(int idx, bool greater, int sum)
{
    if (idx == s.size()) {
        if (greater && sum == b) return 1;
        return 0;
    }
    if (sum > b) return 0;

    int&ret = dp[idx][greater][sum];
    if(vis[idx][greater][sum]==rc)
        return ret;
    vis[idx][greater][sum] = rc;

    int start = (greater? 0 : s[idx] - '0');
    ret = 0;
    for (int i = start; i <= 9; ++i) {
        ret |= fun(idx + 1, greater || (i > s[idx] - '0'), sum + i) ;
    }
    return ret;
}


void build(int idx, bool greater, int sum)
{
    if (idx == s.size()) {
        return ;
    }
    if (sum > b) return ;

    int &ans = dp[idx][greater][sum];
    int res = 0;

    int start = (greater? 0 : s[idx] - '0');
    for (int i = start; i <= 9; ++i) {
        
        res |= fun(idx + 1, greater || (i > s[idx] - '0'), sum + i) ;
        
        if (res == ans) {
            Next.push_back((char)(i + '0'));
            build(idx + 1, greater || (i > s[idx] - '0'), sum + i) ;
            break;
        }
        
    }
}

void solve() {
    int n; cin >> n;
    while (n--) {
        cin >> b;
        fun(0,0,0);
        build(0,0,0);
  //      cout<<Next<<endl;
        int j = 0;
        while (Next[j] == '0') j++;
        for (; j < Next.size(); j++) { cout << Next[j];}
        cout<<'\n';
        s = Next;
        Next.clear();
        rc++;

    }
}

signed main(){
    fileIO();
    fastIO();
    for(int i = 0; i <= 350; i++) {
        s.push_back('0');
    }
    solve();
    return 0;
}
