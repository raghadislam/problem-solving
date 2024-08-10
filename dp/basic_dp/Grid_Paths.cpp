/* problem link: https://cses.fi/problemset/task/1638
 * solution by: Raghad Islam
 * date: 22-5-2024 
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
int dp[1009][1009];
bool vis[1009][1009];

char v[1009][1009];
int n;

bool isValid(int x)
{
    return ((x)>=0 && (x)<=n-1) ;
}

const int MOD = 1e9+7;

int fun(int i, int j)
{
    if(i == n-1 && j == n-1 && v[i][j] == '.') return 1;
    if(i > n-1 || j > n-1 || v[i][j] != '.') return 0;
    int&ret = dp[i][j];
    if(vis[i][j]) return ret;
    vis[i][j] = true;
    int ch1=0,ch2=0;
    if(isValid(j+1) && isValid(i) && v[i][j+1] == '.') ch1 = fun(i,j+1);
    if(isValid(j) && isValid(i+1) && v[i+1][j] == '.') ch2 = fun(i+1,j);
    return ret = (ch1+ch2)%(int)(1e9+7);
}


void solve() {
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>v[i][j];
        }
    }
    cout<<fun(0,0);
}

signed main(){
    fileIO();
    fastIO();
  //  tests {
        solve();
  //  }
    return 0;
}
