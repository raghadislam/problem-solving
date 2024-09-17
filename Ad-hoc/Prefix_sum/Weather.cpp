/* problem link: https://codeforces.com/problemset/problem/234/C
 * solution by: Raghad Islam
 * date: 6-8-2024 
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
    int arr[n];
    int neg[n] = {0}, pos[n] = {0}, z = 0;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        if(arr[i] > 0) pos[i] = 1;
        else if(arr[i] < 0) neg[i] = 1;
        else z++;
    }
    for(int i = 1; i < n; i++) {
        pos[i] += pos[i-1];
        neg[i] += neg[i-1];
    }
    int mn = INT_MAX;

    for (int i = 0; i < n-1; ++i) {
        int res = z;
        res += pos[i];
        res += neg[n-1] - neg[i];
        mn = min(mn,res);
    }
    cout<<mn;

}

signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fastIO();
    solve();
    return 0;
}
