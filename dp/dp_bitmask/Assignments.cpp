/* problem link: https://www.spoj.com/problems/ASSIGN/en/
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
int sub(int a, int b, int mod){
    return ((a%mod) - (b%mod) + mod) % mod;
}

int add(int a, int b, int mod){
    return ((a%mod) + (b%mod)) % mod;
}
int tc = 1;
const int N = 20;
int dp[N+4][(1<<N) + 4];
int vis[N+4][(1<<N) + 4];
vector<vector<int>> v(25, vector<int>(25));
int n;

int fun(int student, int mask) {

    if(student == n && __builtin_popcount(mask) == n) return 1;
    if(student == n) return 0;
    int&ret = dp[student][mask];
    if(ret!=-1) return ret;
    ret = 0;

    //ret = -1e18;
    for (int subject = 0; subject < n; ++subject) {
        if((v[student][subject] == 1) && (mask & (1<<subject))==0)
        {
            ret += fun(student + 1, (mask | (1<<subject)));
        }
    }
    return ret;
}

void solve() {
    ::memset(dp,-1,sizeof dp);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    cout<<fun(0,0)<<'\n';
    tc++;
}

signed main(){
    fileIO();
    fastIO();
   tests {
        solve();
    }
    return 0;
}
