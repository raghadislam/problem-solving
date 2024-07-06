
/* problem link: https://vjudge.net/problem/UVA-10003
 * solution by: Raghad Islam
 * date: 25-4-2024 
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
//#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)

#define N 60
int dp[N][N];
bool vis[N][N];
int n,l; vector<int> v,pref;

//int fun(int l, int r)
//{
//    if(l>=r) return 0;
//
//    int mn = INT_MAX;
//    for (int i = l; i < r ; ++i) {
//        mn = min(mn, fun(l,i)+fun(i+1,r));
//    }
//    return mn + pref[r] - (l? pref[l-1] : 0);
//}

int fun(int l,int r)

{
    if(l>=r-1) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int mn = INT_MAX;
    for (int i = l+1; i <r ; ++i) {
        mn = min(mn, fun(l,i)+fun(i,r)); // 25  50  75  100
    }
    return dp[l][r] = mn + v[r] - v[l];
}


void solve() {
    while (1) {
        cin >> l;
        if (!l) break;
        cin >> n;
        v.clear();
        v.resize(n + 2);
        ::memset(dp,-1, sizeof dp);
        v[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        v[n + 1] = l; // 25 50 75 100

        cout <<"The minimum cutting is "<< fun(0, n + 1)<<'.'<<'\n';
    }
}

signed main(){
    fileIO();
    fastIO();
   // tests {
      //   cout<<"Case "<<o+1<<": ";
        solve();
 //   }
    return 0;
}
