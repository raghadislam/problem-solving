/* problem link: https://codeforces.com/problemset/problem/268/A
 * solution by: Raghad Islam
 * date: 2-8-2024 
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

void solve() {
    int n,res=0; cin>>n;
    int home[105] = {0};
    int guest[105] = {0};
    for (int i = 0; i < n; ++i) {
        int h,g; cin>>h>>g;
        home[h]++;
        guest[g]++;
        if(guest[h]) res+=guest[h];
        if(home[g]) res+=home[g];
    }
    cout<<res;

}

signed main(){
    fileIO();
    fastIO();

   //  tests
    solve();

    return 0;
}