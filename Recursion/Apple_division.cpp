
/* problem link: https://cses.fi/problemset/task/1623
 * solution by: Raghad Islam
 * date: 3-11-2023 
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
#define tests int t; cin >> t; int k = -1; while(++k < t)

const ll MOD = 1000000007;
vector<int> v;
int n,m,res=INT_MAX,totalSum=0;
void rec (int i, int sum)
{
    if(i==n)
    {
        int x = abs(totalSum - 2*sum);
        if(x<res) res = x;
        return ;
    }
    rec(i+1,sum);
    rec(i+1,sum+v[i]);
}

void solve() {
    cin>>n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        totalSum+=v[i];
    }
    rec(0,0);
    cout<<res;

}

signed main(){
    fileIO();
    fastIO();
       // cout<<"Case "<<j+1<<": ";
        solve();
    return 0;
}