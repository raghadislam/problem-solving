/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
 * solution by: Raghad Islam
 * date: 13-5-2025 
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

typedef long long ll;
#define int ll
#define tests int t; cin >> t; int k = -1; while(++k < t)

int mx = 0,c=0;
void dfs(int u, vector<bool>& visited,vector<int> adjList[] ){
    visited[u] = true;
    c++;
    for(int v : adjList[u]){
        if(!visited[v]){
            dfs(v,visited,adjList);
        }
    }
}

void solve() {
    int n,m,u,v,tmp;
    vector<bool> visited(30005,false);
    vector<int> adjList[30005]={{0}};
    mx =0,c=0;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        c =0;
        if(!visited[i]){
            dfs(i,visited,adjList);
        }
        mx = max(mx,c);
    }
    mx = max(mx,c);
    cout<<mx<<'\n';
}

signed main(){
    fileIO();
    fastIO();
    tests {
        // cout<<"Case "<<j+1<<": ";
        solve();
    }
    return 0;
}
