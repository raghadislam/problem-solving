

/* problem link: https://codeforces.com/problemset/gymProblem/101028/I
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
#define loop_r(n)          for(int i = n; i > (0); i--)

#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)

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


#define kill return 0
const long long mx = 1ll << 32;
bool preceed(int x, int y)
{
    return x > y;
}

int Binary_search(int arr[], int key, int imin, int imax)
{
    if (imax < imin) return -1;
    else {
        while (imin < imax) {
            int imid = ((imin + imax) / 2);
            if (arr[imid] < key) imin = imid + 1;
            else imax = imid;
        }
        if ((imin == imax) and arr[imin] == key)
            return imin;
        else
            return -1;
    }
}

int BSFindFirst(int start, int end, int val, int const arr[])
{
    while (start < end)
    {
        int mid = start + (end - start) / 2; // or start + (end - start +1 )/2 if infinite loop happened
        if (arr[mid] < val) start = mid + 1;
        else if (arr[mid] > val) end = mid - 1;
        else end = mid;
    }
    return start;
}

int BSFindLast(int start, int end, int val, int const arr[])
{
    while (start < end)
    {
        int mid = start + (end - start + 1) / 2; // or start + (end - start )/2 if infinite loop happened
        if (arr[mid] < val) start = mid + 1;
        else if (arr[mid] > val) end = mid - 1;
        else start = mid;
    }
    return start;
}

//bool can(ll cookiesNum) {
//    ll magic = 0;
//    for(int i = 0; i < n; i++) {
//        ll need = (ll) a[i] * cookiesNum;
//        if(need > b[i]) {
//            magic += need - b[i];
//            if(magic > k) return false;
//        }
//    }
//    return true;
//}

//ll n,s;
//ll cost;
//vll v,c;
//
//bool can(ll NumOfSouv)
//{
//    cost =0;
//    loop(n)
//    {
//        c[i]= (ll) v[i]+(i+1)*NumOfSouv;
//    }
//    sort(all(c));
//    loop(NumOfSouv)
//    {
//        cost+=c[i];
//    }
//    cout<<cost<<" ";
//    if(cost>s) return false;
//    else return true;
//}
ll h, n, k, timee;
vll v(n);

bool can(ll num)
{
    ll c = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if ((v[j] - v[i] + 1) <= num) continue;
            else {
                c++;
                i = j;
            }
        }
    }
    if (c <= k) return true;
    else return false;
}


int main(void) {
    fileIO();
    fastIO();
    tests{
        cin >> n >> k;
        v.resize(n);
        loop(n) cin >> v[i];
        ll start = 1, end = v[n - 1];
        while (start < end) {
            ll mid = start + (end - start) / 2;
            if (can(mid)) {
                end = mid;
            }
 else start = mid + 1;
}
cout << end << '\n';
    }
    kill;
}