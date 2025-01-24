/* problem link: https://codeforces.com/problemset/problem/1237/B
 * solved by: Raghad Islam
 * Date: 28-1-2024 
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
    queue<int>q;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        q.push(x);
    }
    vector<int>v(n,0);
    set<int>s;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        while(!q.empty() && s.count(q.front())) q.pop();
        if((x != q.front())) {
            s.insert(x);
        }
        else if(x == q.front()) q.pop();
    }
    cout<<s.size();

}

signed main(){
    fileIO();
    fastIO();
 // tests
     solve();
    return 0;
}

