
/* problem link: https://atcoder.jp/contests/dp/tasks/dp_f?lang=en
 * solution by: Raghad Islam
 * date: 30-3-2024
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
int dp[3009][3009];
int vis[3009][3009];
int n;
string s1,s2;

int fun(int i, int j)
{
    if(i>= s1.size() or j>=s2.size()) return 0;
    int&ret = dp[i][j];
    if(vis[i][j]) return ret;
    vis[i][j] = 1;
    int ch1=0,ch2=0,ch3=0;
    if(s1[i] == s2[j]) ch1 = fun(i+1,j+1) + 1;
    else {
        ch2 = fun(i+1,j);
        ch3 = fun(i,j+1);
    }
    return ret = max({ch1,ch2,ch3});
}

int x;
int c=0;
void build(int i, int j)
{
    if(c==x) return;
    if(i>= s1.size() or j>=s2.size()) return;
    int sol = fun(i,j);
    int ch1=0,ch2=0,ch3=0;
    if(s1[i] == s2[j]) ch1 = fun(i+1,j+1) + 1;
    else {
        ch2 = fun(i+1,j);
        ch3 = fun(i,j+1);
    }
    if(sol == ch1)
    {
        cout<<s1[i];
        c++;
        build(i+1,j+1);
    }
    if(sol == ch2)
    {
        build(i+1,j);
    }
    if(sol == ch3)
    {
        build(i,j+1);
    }
}


void solve() {
    cin>>s1>>s2;
     x = fun(0,0);
    build(0,0);
}

signed main(){
    fileIO();
    fastIO();
  //  tests {
        solve();
  //  }
    return 0;
}
