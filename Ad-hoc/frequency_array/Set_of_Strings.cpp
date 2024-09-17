/* problem link: https://codeforces.com/problemset/problem/544/A
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
    string s; cin>>s;
    vector<string> parts;
    map<char,int> frq;
    for (int i = 0; i < s.size(); ++i) {
        while (frq[s[i]] and i < s.size()) {
            parts[parts.size()-1] += s[i];
            i++;
        }
        if(i >= s.size()) break;
        frq[s[i]] = 1;
        string holder ;
        parts.push_back(holder+s[i]);
    }

    if(parts.size() < n) cout<<"NO";
    else {
        cout<<"YES\n";
        for (int i=0; i<n-1; i++) cout << parts[i]<<'\n';
        string last;
        for ( int i = n-1; i < parts.size();i++) {
            last += parts[i]; }
        cout<<last;
    }
}

signed main(){
    fileIO();
    fastIO();
    //tests
    solve();
    return 0;
}

