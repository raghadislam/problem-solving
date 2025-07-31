/* problem link: https://www.spoj.com/problems/DQUERY/en/
 * solution by: Raghad Islam
 * date: 21-7-2025 
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
const int MAXN = 3e4 + 5;
int BLOCK_SIZE;

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int block_a = l / BLOCK_SIZE;
        int block_b = other.l / BLOCK_SIZE;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

int a[MAXN];
int ans[200005];
int freq[MAXN * 100];

int currAnswer = 0;
void add(int idx) {

    int val = a[idx];
    freq[val]++;
    if (freq[val] == 1) currAnswer++;
}

void remove(int idx) {
    int val = a[idx];
    freq[val]--;
    if (freq[val] == 0) currAnswer--;
}

    void solve() {
    int n; cin >> n;
    BLOCK_SIZE = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q; cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
        queries[i].l--;
        queries[i].r--;
    }
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    for (auto& query : queries) {
        while (l > query.l) add(--l);
        while (r < query.r) add(++r);
        while (l < query.l) remove(l++);
        while (r > query.r) remove(r--);
        ans[query.idx] = currAnswer;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

}

signed main(){
    fileIO();
    fastIO();
    int t = 1;// cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}


