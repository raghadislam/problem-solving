
/* problem link: https://codeforces.com/problemset/problem/1133/C
 * solution by: Raghad Islam
 * date: 26-4-2023 
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
typedef unsigned long long ull;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<int, pi> p3i;
 
typedef pair<ll, ll> pll;
typedef pair<ll, pll> p3ll;
 
typedef pair<ll, ld> plld;
typedef pair<double, pi> pd2i;
 
typedef vector<int> vi;
typedef vector<pi> v2i;
typedef vector<p3i> v3i;
 
typedef vector<ll> vll;
typedef vector<pll> v2ll;
typedef vector<p3ll> v3ll;
 
typedef vector<string> vs;
typedef vector<bool> vb;
 
typedef vector<vll> vvl;
 
#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define f1(i,n)          for(int i = 1; i <= (n); ++i)
 
 
#define MP make_pair
#define PB push_back
#define EmB emplace_back
#define Em emplace
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define all_r(a)   a.rbegin(),a.rend()
#define clr(x, val)    memset((x), (val), sizeof(x))
#define maxEle max_element
#define minElemin_element
 
#define tests int t; cin >> t; int i = 0; while(i++ < t)
#define SetPre(n, x)  cout << fixed << setprecision(n) << x
 
#define endl '\n'
 
#define pow2(a) (1LL<<a)
 
#define kill return 0
 
struct object{
    int v;
    int w;
    double u;
};
 
bool preceed(object x, object y)
{
    return (x.u>=y.u);
}
 
vll get_divisors(ll num) {
 
    vll divisors;
 
    ll i;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) {
            divisors.push_back(i);
            divisors.push_back(num / i);
        }
    }
    if((i * i) == num) divisors.push_back(i);
 
    return divisors;
}
 
int main(void) {
    fileIO();
    fastIO();
    int n; cin>>n;
    vi v(n);
    loop(n) cin>>v[i];
    sort(all(v));
    int c=0;
    loop(n)
    {
        int x = upper_bound(all(v),v[i]+5) - v.begin();
        c = max(c,abs(x-i));
    }
    cout<<c;
    kill;
}