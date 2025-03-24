/* problem link: https://codeforces.com/contest/1883/problem/D
 * solved by: Raghad Islam
 * Date: 24-3-2025 
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


void solve()
{
    int q;
    cin >> q;

    multiset<pair<int, int>> segments;
    multiset<int> left_ends, right_ends;

    for (int i = 0; i < q; ++i) {
        char op;
        int l, r;
        cin >> op >> l >> r;

        if (op == '+') {
            segments.emplace(l, r);
            left_ends.insert(l);
            right_ends.insert(r);
        } else {
            segments.erase(segments.find({l, r}));
            left_ends.erase(left_ends.find(l));
            right_ends.erase(right_ends.find(r));
        }

        if (segments.size() <= 1) {
            cout << "NO" << endl;
        } else {
            int max_left = *left_ends.rbegin();
            int min_right = *right_ends.begin();

           // cout<<max_left<<' '<< min_right<<' ';
            if (max_left > min_right) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }


}

signed main(){
    fileIO();
    fastIO();
 // tests {
        solve();
  //}
    return 0;
}
