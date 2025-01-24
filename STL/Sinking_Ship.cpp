/*
 * problem link: https://codeforces.com/problemset/problem/63/A
 * solved by: Raghad Islam
 * Date: 1-7-2024
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

bool fun(pair<int,string>p1, pair<int,string>p2) {
    return p1.first <= p2.first;
}

void solve() {
    int n; cin>>n;
    vector<pair<pair<int,int>,string>>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].second;
        v[i].first.second = i;
        string s; cin>>s;
        if(s == "captain") {
            v[i].first.first = 3;
        }
        else if(s == "woman" || s == "child") {
            v[i].first.first= 1;
        }
        else if(s == "man") v[i].first.first = 2;
        else {
            v[i].first.first = 0;
        }
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        cout<<v[i].second<<'\n';
    }
}

signed main(){
    fileIO();
    fastIO();
 //tests
     solve();
    return 0;
}

