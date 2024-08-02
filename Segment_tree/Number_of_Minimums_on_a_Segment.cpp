/* problem link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
 * solution by: Raghad Islam
 * date: 12-4-2024 
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


struct Node
{
    int mn;
    int cnt;

    // neutral value
    Node()
    {
        mn = INT_MAX;               // ---------------------------> change according to the problem
        cnt =0;
    }

    Node(int x)
    {
        mn = x;
        cnt =1;
    }

    void change(int x)
    {
        mn = x;               // ---------------------------> change according to the problem
    }
};

struct SegTree
{
    int TreeSize;
    vector<Node> SegData;

    SegTree(int n)
    {
        TreeSize = 1;
        while (TreeSize < n) TreeSize *= 2;
        SegData.assign(2*TreeSize,Node());
    }

    // function to calculate the parent of two nodes
    Node merge(Node & lf, Node & ri)
    {
        Node ans = Node();
        ans.mn = min(lf.mn, ri.mn);               // ---------------------------> change according to the problem
        if(ans.mn == lf.mn) ans.cnt += lf.cnt;
        if(ans.mn == ri.mn) ans.cnt += ri.cnt;
        return ans;
    }

    void init(vector<int>& arr, int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < arr.size())
                SegData[ni] = Node(arr[lx]);
            return;
        }
        int mid = (lx + rx) / 2;

        init(arr, 2 * ni + 1,lx,mid);
        init(arr, 2 * ni + 2,mid,rx);

        SegData[ni] = merge(SegData[2 * ni + 1],SegData[2 * ni + 2]);
    }

    void init(vector<int> & arr)
    {
        init(arr,0,0,TreeSize);
    }

    void set(int idx, int val , int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            SegData[ni].change(val); // Update the leaf node directly
            return;
        }
        int mid = (lx + rx) / 2;
        if(idx < mid)
        {
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void set(int idx, int val)
    {
        set(idx,val,0,0,TreeSize);
    }

    Node get(int l, int r, int ni, int lx, int rx) // 0 indexed and r not included
    {
        if(lx >= l && rx <= r)
            return SegData[ni];
        if(rx <= l || lx >= r)
            return Node();

        int mid = (lx + rx)/2;

        Node lf = get(l,r,ni * 2 + 1,lx,mid);
        Node ri = get(l,r,ni * 2 + 2,mid,rx);

        return merge(lf,ri);
    }

    Node get(int l, int r)
    {
        return get(l,r,0,0,TreeSize);
    }
};






void solve() {
    int n,q; cin >> n >> q;
    vector<int> arr(n);
    SegTree st = SegTree(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    st.init(arr);
   // st.set(2,4);
    while (q--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int idx,val; cin>>idx>>val;
            st.set(idx,val);
        }
        else
        {
            int l,r; cin>>l>>r;
           // l--;
            Node ni = st.get(l,r);
            cout << ni.mn << " "<<ni.cnt<< '\n';
        }

    }
}

signed main(){
    fileIO();
    fastIO();
   // tests {
        // cout<<"Case "<<j+1<<": ";
        solve();
//    }
    return 0;
}
