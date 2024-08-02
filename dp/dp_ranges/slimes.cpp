
/* problem link: https://atcoder.jp/contests/dp/tasks/dp_n?lang=en
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
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
int n; vector<int>v,pref;

int dp[500][500];

int fun(int l,int r)
{
    if(l>=r) return 0;
    int&ret = dp[l][r];
    if(ret!=-1) return ret;
    int sum =1e15;
    for (int i = l; i <r ; ++i) {
        sum = min(sum, fun(l,i)+ fun(i+1,r));
    }
    return ret = sum + pref[r] - (l? pref[l-1] : 0);
}

void solve() {
    cin>>n;
    memset(dp,-1,sizeof dp);
    v.resize(n);
    pref.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    pref[0] = v[0];
    for (int i = 1; i < n; ++i) {
        pref[i] += pref[i-1] + v[i];
    }

    cout<<fun(0,n-1);
}

signed main(){
    fileIO();
    fastIO();
   // tests {
        // cout<<"Case "<<j+1<<": ";
        solve();
//    }
    return 0;
}
