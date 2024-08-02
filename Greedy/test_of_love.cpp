/* problem link: https://codeforces.com/contest/1992/problem/D
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

typedef long long ll;
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)


int fun(int cnt, int a, int b, int c)
{
    if(cnt == 5) return (a*b*c);
    int ch1 = fun(cnt + 1, a+1, b, c);
    int ch2 = fun(cnt + 1, a, b+1, c);
    int ch3 = fun(cnt + 1, a, b, c+1);
    return max({ch1,ch2,ch3});
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s; cin>>s;
    s = 'L' + s + 'L';
    for (int i = 0; i < s.size() - 1; ) {
        if(s[i] == 'C' or k < 0)
        {
            cout<<"NO\n";
            return;
        }
        if(s[i] == 'L')
        {
            int idx = find(s.begin() + i + 1,s.end(),'L') - s.begin();
            if((idx - i) <= m)
            {
                i = idx;
            }
            else
            {
               // k -= (idx - i - 1);
                i = i + m;
            }
            if(s[i] == 'C' or k < 0)
            {
                cout<<"NO\n";
                return;
            }
        }
        else
        {
            i++;
            k--;
            if(s[i] == 'C' or k < 0)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

signed main(){
    fileIO();
    fastIO();

    tests
    solve();

    return 0;
}