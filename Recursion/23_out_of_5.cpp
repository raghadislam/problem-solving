/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1285
 * solution by: Raghad Islam
 * date: 3-11-2023 
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

vector<int>v;

bool f =0;
int arr[5];
void rec (int i, int res)
{
    if(i==5) {
        if(res == 23) f=1;
        return;
    }
    rec(i+1,res*arr[i]);
    rec(i+1,res+arr[i]);
    rec(i+1,res-arr[i]);
}

void solve() {

    while (1)
    {
        for (int i = 0; i < 5; ++i) {
            cin>>arr[i];
        }
        if(!arr[0] and !arr[1] and !arr[2] and !arr[3] and !arr[4]) break;
        sort(arr,arr+5);
        do {
            rec(1, arr[0]);
        } while (next_permutation(arr,arr+5));
        if(f) cout<<"Possible\n";
        else cout<<"Impossible\n";
        f=0;
    }
}

signed main(){
    fileIO();
    fastIO();
    //tests {
        // cout<<"Case "<<j+1<<": ";
        solve();
   // }
    return 0;
}