/* problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925
 * solution by: Raghad Islam
 * date: 21-1-2025 
 */

#include<bits/stdc++.h>
using namespace std;

const int maxn=17;
int dp[1<<maxn];
int p[maxn],covers[1<<maxn];
int n,m,x;

int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    while(cin>>n,n)
    {
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
        memset(covers,0,sizeof(covers));
        for(int i=0;i<n;i++)
        {
            p[i]=(1<<i);
            cin>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>x;
                p[i]|=(1<<x);
            }
        }
        for(int S=0;S<(1<<n);S++)
        {
            covers[S]=0;
            for(int i=0;i<n;i++)
            {
                if(S&(1<<i))
                    covers[S]|=p[i];
            }
        }
        dp[0]=0;
        int full=(1<<n)-1;
        for(int S=1;S<(1<<n);S++)
        {
            dp[S]=0;
            for(int ss=S;ss;ss=(ss-1)&S)
            {
                if(covers[ss]==full)
                    dp[S]=max(dp[S],dp[S^ss]+1);
            }
        }
        cout<<"Case "<<t++<<": "<<dp[full]<<endl;
    }
    return 0;
}

