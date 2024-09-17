/* problem link: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/D
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
#define ll long long
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)


void solve() {
    int n; cin>>n;

    vector<int>v(n+1);
    int yasser = 0;
    for(int i = 0; i < n; ++i) {
        cin>>v[i];
	    }
    for(int i = 0; i < n; ++i) {
        yasser += v[i];
        if(yasser <= 0) {
            cout<<"NO\n";
            return;
        }
    }
    yasser = 0;
    for(int i = n-1; i >=0; --i) {
        yasser += v[i];
        if(yasser <= 0) {
            cout<<"NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main(){
    fileIO();
    fastIO();
    tests
    {
        solve();
    }
    return 0;
}

