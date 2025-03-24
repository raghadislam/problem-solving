/* problem link: https://codeforces.com/contest/1873/problem/E
 * solution by: Raghad Islam
 * date: 24-3-2024
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

#define loop(n)          for(int i = 0; i < (n); ++i)
#define loop_r(n)          for(int i = (n); i >= 0; --i)

#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define f1(i,n)          for(ll i = 1; i <= (n); ++i)


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

#define ceil_i(a, b) ((a+b-1)/b)
#define floor_i(a, b) (a/b)
#define round_i(a, b) ((a+(b/2))/b)

#define tests int t; cin >> t; int i = -1; while(++i < t)
#define SetPre(n, x)  cout << fixed << setprecision(n) << x

#define endl '\n'

#define pow2(a) (1LL<<a)


template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define kill return 0
//int res = INT_MAX;
ll n,x,ans=0;
vll v;
bool can(ll mid)
{
    ll sum = 0;
    loop(n)
    {
        if (v[i] > mid)
            continue;
        sum += (mid - v[i]);
        if(sum>x) return false;
    }
    return sum <= x;
}
void solve() {
    cin>>n>>x;
    v.resize(n);
    loop(n) cin>>v[i];
    ll l=0,r=1e10,h=0;
    while (l<=r)
    {
        ll mid = (r+l)/2;
        if(can(mid))
        {
            l = mid+1;
            h=mid;
        } else
        {
            r = mid-1;
        }
    }
    cout<<h<<'\n';
}


signed main(){
    fileIO();
    fastIO();
    tests {
    solve();
    }
    kill;
}
