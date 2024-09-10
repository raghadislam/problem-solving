/* problem link: https://codeforces.com/gym/103643/problem/B
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

//float arr[100000001];

void solve() {
    int a,b; cin>>a>>b;
    int res=0;
    map<float,bool>arr;

    if(arr[((float)a+(float)b)] == 0) {
        res++;
        arr[((float)a+(float)b)] = 1;
    }


    if(arr[((float)a/(float)b)] == 0) {
        res++;
        arr[((float)a/(float)b)] = 1;
    }


    if(arr[((float)a-(float)b)] == 0) {
        res++;
        arr[((float)a-(float)b)] = 1;
    }


    if(arr[((float)a*(float)b)] == 0) {
        res++;
        arr[((float)a*(float)b)] = 1;
    }


    if(arr[((float)b-(float)a)] == 0) {
        res++;
        arr[((float)b-(float)a)] = 1;
    }

    if(arr[((float)b/(float)a)] == 0) {
        res++;
        arr[((float)b/(float)a)] = 1;
    }
    cout<<res<<'\n';
}

signed main(){
    fileIO();
    fastIO();
    tests
    solve();
    return 0;
}

