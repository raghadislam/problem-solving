/* problem link: https://codeforces.com/contest/400/submission/280657840
 * solution by: Raghad Islam
 * date: 2-4-2024 
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

void solve() {
    int n,m; cin>>n>>m;
    string arr[1001];
    int S[1002];
    int G[1002];
    set<int>res;
    for (int i = 0; i < n; ++i) {
            cin>>arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(arr[i][j] == 'G') G[i] = j;
            else if(arr[i][j] == 'S') S[i] = j;
        }
        if(G[i] > S[i]) {
            cout<<-1;
            return;
        }
        else res.insert(S[i] - G[i]);
    }
    cout<<res.size();
}

signed main(){
    fileIO();
    fastIO();
    //tests
    solve();
    return 0;
}
