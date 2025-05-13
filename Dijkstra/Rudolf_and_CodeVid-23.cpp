/* problem link: https://codeforces.com/problemset/problem/1846/G
 * solution by: Raghad Islam
 * date: 1-5-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
#define int ll
const int oo = 1e18;
int n, m;
struct node {
    int id;
    int days;
    int relieve;
    int cause;
};
vector<node> nodes(1005);
vector<node> adj[1005];
int days[(1 << 11)];
int turnToInt(string s) {
    int n = s.size();
    int num = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1') {
            num += (1 << (n-i-1));
        }
    }
    return num;
}

int turnToIntRev(string s) {
    int n = s.size();
    int num = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            num += (1 << (n-i-1));
        }
    }
    return num;
}

void dijkstra(int start) {
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    days[start] = 0;
    for (int i = 0; i < m; i++) {
        int symptoms = ((start & nodes[i].relieve) | nodes[i].cause);
        days[symptoms] = min(days[symptoms], nodes[i].days);
        pq.push({nodes[i].days, {symptoms, nodes[i].id}});
    }
    while (!pq.empty()) {
        int symptoms = pq.top().second.first;
        int d = pq.top().first;
        int id = pq.top().second.second;
        pq.pop();
        if (days[symptoms] < d) continue;
        if (symptoms == 0) return;
        for (auto v : adj[id]) {
            int newU = ((symptoms & v.relieve) | v.cause);
            if (days[newU] > d + v.days) {
                days[newU] = d + v.days;
                pq.push({days[newU], {newU, v.id}});
            }
        }
    }
}



void solve() {
    cin >> n >> m;
    string s; cin >> s;
    int start = turnToInt(s);
    for (int i = 0; i < m; i++) {
        int days; cin >> days;
        string relieve, cause; cin >> relieve >> cause;
        int relieveNum = turnToIntRev(relieve);
        int causeNum = turnToInt(cause);
        nodes[i].id = i;
        nodes[i].days = days;
        nodes[i].relieve = relieveNum;
        nodes[i].cause = causeNum;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j) {
                adj[i].push_back(nodes[j]);
                adj[j].push_back(nodes[i]);
            }
        }
    }
    fill(days, days+ (1 << (n+1)), oo);
    dijkstra(start);
    if (days[0] == oo) cout << -1 << "\n";
    else
        cout << days[0] << "\n";
    for (int i = 0; i < m; i++) {
        adj[i].clear();
    }
    nodes.clear();
}


signed main() {
    fileIO();
    fastIO();
    int t = 1;  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


