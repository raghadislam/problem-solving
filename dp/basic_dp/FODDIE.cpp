/* problem link: https://www.spoj.com/problems/FOODIE/en/
 * solution by: Raghad Islam
 * date: 24-5-2024 
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
int n,k;
vector<int> v;
int dp[109][1009];
bool vis[109][1009];

int fun(int i, int kk)
{
    if(i>=n) return 0;
    int&ret = dp[i][kk];
    if(vis[i][kk]) return ret;
    vis[i][kk] = true;
    int ch1 =0,ch2=0;
    ch1 = fun(i+1,kk);
    if(kk>=v[i]) ch2 = fun(i+1,kk-v[i]) + v[i];
    return ret = max(ch1,ch2);
}

void solve() {
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        int r,x,sum=0; cin>>r;
        for (int j = 0; j < r; ++j) {
            cin>>x;
            sum+=x;
        }
        v.push_back(sum);
    }
    cout<<fun(0,k)<<'\n';
}

signed main(){
    fileIO();
    fastIO();
   tests {
       v.clear();
        ::memset(vis,0,sizeof vis);
        solve();
   }
    return 0;
}
