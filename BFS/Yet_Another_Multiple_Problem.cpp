/* problem link: https://www.spoj.com/problems/MULTII/
 * solution by: Raghad Islam
 * date: 22-4-2025
 */

#include <bits/stdc++.h>
using namespace std;
void fileIO(void)
{

#ifndef ONLINE_JUDGE // DLRU

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
// #define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
int n,m,k;
char grid[1005][1005];
int dist1[1005][1005];
int dist2[1005][1005];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};
pair<int,int> A;
vector<pair<int,int>>mons;
vector<pair<int,int>>ext;
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}


string BFS(int N, const unordered_set<int>& forbidden) {
    vector<bool> visited(N, false);
    queue<pair<string, int>> q; // {current number, remainder}

    for (int d = 1; d <= 9; d++) {
        if (forbidden.count(d) == 0) {
            int rem = d % N;
            if (rem == 0) return to_string(d);
            if (!visited[rem]) {
                visited[rem] = true;
                q.push({to_string(d), rem});
            }
        }
    }

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        string num = current.first;
        int rem = current.second;

        for (int d = 0; d <= 9; d++) {
            if (forbidden.count(d) == 0) {
                int new_rem = (rem * 10 + d) % N;
                string new_num = num + to_string(d);

                if (new_rem == 0) return new_num;
                if (!visited[new_rem]) {
                    visited[new_rem] = true;
                    q.push({new_num, new_rem});
                }
            }
        }
    }

    return "-1";
}


void solve() {

    int N, m, digit;
    int case_num = 1;

    while (cin >> N >> m) {
        unordered_set<int> forbidden;
        for (int i = 0; i < m; i++) {
            cin >> digit;
            forbidden.insert(digit);
        }

        string result = BFS(N, forbidden);
        cout << "Case " << case_num++ << ": " << result << "\n";
    }

}



signed main(){
    fileIO();
    fastIO();
  // tests
    solve();
    return 0;
}
