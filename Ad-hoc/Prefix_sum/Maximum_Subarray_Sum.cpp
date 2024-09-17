/*
 * problem link: https://codeforces.com/gym/102961/problem/H
 * solved by: Raghad Islam
 * date: 28 - 3 - 2024
 * */
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
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i-1];
    }
    int mx = INT_MIN, mn = 0;;
    for(int i = 0; i < n; i++) {
        mx = max(mx, arr[i] - mn);
        mn = min (mn, arr[i]);
    }
    cout<<mx;

}

signed main(){
    fileIO();
    fastIO();
  //  tests
        solve();
    return 0;
}
