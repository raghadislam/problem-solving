/* problem link: https://codeforces.com/problemset/problem/835/C
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
int arr[109][109][13];

void solve() {
    int n,q,c; cin>>n>>q>>c;
    for (int i = 0; i < n; ++i) {
        int x,y,t; cin>>x>>y>>t;
        arr[x][y][t]++;
    }

    for (int i = 1; i < 109; ++i) {
        for (int j = 1; j < 109; ++j) {
            for (int k = 0; k <= c; ++k) {
                arr[i][j][k] += arr[i][j - 1][k] + arr[i - 1][j][k] - arr[i - 1][j - 1][k];
            }
        }
    }

      while (q--) {
          int ti, x1, y1, x2, y2;
          cin >> ti >> x1 >> y1 >> x2 >> y2;
          ti = ti % (c + 1);
          int ans = 0;
          for (int i = 0; i <= c; ++i) {
              int a = arr[x2][y2][i] - arr[x1 - 1][y2][i] - arr[x2][y1 - 1][i] + arr[x1 - 1][y1 - 1][i];
              ans += (((ti + i) % (c + 1)) * (a));
          }
          cout << ans << '\n';
      }

}

signed main(){
    fastIO();

    solve();

    return 0;
}