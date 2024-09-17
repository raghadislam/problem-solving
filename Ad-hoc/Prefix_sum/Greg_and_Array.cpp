/* problem link: https://codeforces.com/contest/295/problem/A
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

typedef struct operation {
    int l;
    int r;
    int d;
}OP;

void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<int>v(n+9), tmp(n+9), p1(100009);
    vector<OP> op(m+9);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    for(int i = 1; i <= m; i++) {
        cin>>op[i].l>>op[i].r>>op[i].d;
    }
    for(int i = 1; i <= k; i++) {
        int x,y; cin>>x>>y;
        p1[x]++;
        p1[y+1]--;
    }

    for(int i = 1; i <= m; i++) {
        p1[i]+=p1[i-1];
    }

    for(int i = 1; i <= m; i++) {
        int val = op[i].d * p1[i];
        tmp[op[i].l] += val;
        tmp[op[i].r + 1] -= val;
    }

    for(int i = 1; i <= n; i++) {
        tmp[i] += tmp[i-1];
    }
    for(int i = 1; i <= n; i++) {
        cout<<v[i] + tmp[i] <<' ';
    }


}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
