/* problem link: https://codeforces.com/problemset/problem/1669/B
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
    int n; cin>>n;
    int frq[200005]= {0};
    int x,f=0;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        frq[x]++;
        if(frq[x] >= 3 && !f) {
            cout<<x<<'\n';
            f = 1;
        }
    }
    if(!f)
    cout<<-1<<'\n';

}

signed main(){
    fileIO();
    fastIO();

     tests
    solve();

    return 0;
}