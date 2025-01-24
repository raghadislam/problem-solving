/*
 * problem link: https://codeforces.com/problemset/problem/381/A
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


void solve() {
    int n; cin>>n;
    deque<int>dq(n);
    for (int i = 0; i < n; ++i) {
        cin>>dq[i];
    }
    int A=0, B=0;
    bool turn = 1;
    while (!dq.empty()) {
        if(turn) {
            if(dq.front() > dq.back()) {
                A+= dq.front();
                dq.pop_front();
            }
            else {
                A+= dq.back();
                dq.pop_back();
            }
            turn = 1 - turn;
        }
        else {
            if(dq.front() > dq.back()) {
                B+= dq.front();
                dq.pop_front();
            }
            else {
                B+= dq.back();
                dq.pop_back();
            }
            turn = 1 - turn;
        }
    }
    cout<<A<<' '<< B;
}

signed main(){
    fileIO();
    fastIO();
    //tests
    solve();
    return 0;
}

