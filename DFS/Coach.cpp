/* problem link: https://codeforces.com/problemset/problem/300/B
 * solution by: Raghad Islam
 * date: 2-12-2023 
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

int dx_all[8] = { 1, 0, -1, 0, 1, 1, -1, -1 },
        dy_all[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dx[4] = { 1, 0, -1, 0 },
        dy[4] = { 0, 1, 0, -1 };

typedef long long ll;
#define int ll
#define all(x) x.begin(),x.end()

int n, m;
vector<vector<int>>adj;
vector<int>vis;

int dfs(int u){

    vis[u] = 1;
    int ret = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            ret += dfs(v);
        }
    }
    return ret;
}

void init(int cnt,map<int, vector<int>>&tmp){
    for (int j = 1; j <= n; ++j){
        if(vis[j] == 1){
            tmp[cnt].push_back(j);
            vis[j] = 2;
        }
    }
}

void solve(int t) {
    cin >> n >> m;
    adj.resize(n + 1), vis.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int , vector<int>>three, two;
    vector<int>one;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(!vis[i]){
            cnt++;
            int sz = dfs(i);
            if(sz == 3){
                init(cnt, three);
            }
            else  if(sz == 2){
                init(cnt, two);
            }
            else if(sz == 1){
                for (int j = 1; j <= n; ++j){
                    if(vis[j] == 1){
                        one.push_back(j);
                        vis[j] = 2;
                    }
                }
            }
            else{
                cout << -1 << '\n';
                return;
            }
        }
    }
    if(two.size() > one.size() || (one.size() - two.size()) % 3 != 0){
        cout << -1 << '\n';
        return;
    }
    for(auto it : three){
        for(auto i : it.second){
            cout << i << ' ';
        }
        cout << '\n';
    }
    for(auto it : two){
        for(auto i : it.second){
            cout << i << ' ';
        }
        cout << one.back() << ' ';
        if(!one.empty()) one.pop_back();
        cout << '\n';
    }
    int idx = 0;
    for(auto i : one){
        idx++;
        cout << i << ' ';
        if(idx%3 == 0) cout << '\n';
    }
}

signed main() {
    fastIO();
    fileIO();
    int test = 1, t = 1; //cin>>test;
    while(test--) {
        solve(t);

        t++;

    }
    return 0;
}