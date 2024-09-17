/* problem link: https://codeforces.com/problemset/problem/1690/D
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
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int White[n] = {0};
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'W') White[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            White[i] += White[i-1];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n - k; ++i) {
            ans = min(ans, White[i+k-1] - (i==0 ? 0 : White[i-1]));
        }
        cout<<ans<<'\n';
    }

    signed main(){
        fileIO();
        fastIO();
       tests
            solve();
        return 0;
    }

