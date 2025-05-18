/* problem link: https://codeforces.com/problemset/problem/500/B
 * solution by: Raghad Islam
 * date: 18-5-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
#define int ll
const int N = 300+5;
vector<int> adj[N];
// const int M = 1e5+5;
int roots[N];
vector<int> Sort[N];
int n, m;
int arr[N];
void init() {
    for (int i = 0; i <= n; i++) {
        roots[i] = i;
    }
}
int getRoot(int u) {
    if (u == roots[u])
        return u;
    return roots[u] = getRoot(roots[u]);
}

void merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u == v)
        return;
    roots[u] = v;
}

bool isSameSet(int u, int v) {
    return getRoot(u) == getRoot(v);
}


void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++)
            if (s[j-1] == '1') merge(i,j);
    }

    for (int i = 1; i <= n; i++) {
        int r = getRoot(i);
        Sort[r].push_back(arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(Sort[i].begin(), Sort[i].end());
    }
    int idx[305] = {0};
    for (int i = 1; i <= n; i++) {
        int r = getRoot(i);
        cout << Sort[r][idx[r]++] << ' ';
    }
    cout << endl;
}

signed main() {
    fileIO();
    fastIO();

    int t = 1;  //cin>>t;
    while (t--)
        solve();

    return 0;
}
