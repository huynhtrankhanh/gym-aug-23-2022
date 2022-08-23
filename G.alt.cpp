#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define se second
#define fi first
const int maxn= 1e5+5;

vector<int>seg(maxn*4,0);
vector<int>val(maxn);
vector<pair<int,int>>pos(maxn);

void update(int l, int r,int pos, int id)
{
    if(id > r || id < l)    return ;
    if(l==r)
    {
        seg.at(pos)= val.at(id);
    }
    else{
        int mid= (l+r)/2;
        update(l,mid,pos*2,id);
        update(mid+1,r,pos*2+1,id);
        seg.at(pos)= max(seg.at(pos*2), seg.at(pos*2+1));
    }
}

int query(int q1, int q2, int l, int r, int pos)
{
    if(q1 > r || q2 < l)    return 0;
    else if(q1<=l && r<=q2) return seg.at(pos);
    else{
        int mid= (l+r)/2;
        return max(query(q1,q2,l,mid,pos*2), query(q1,q2,mid+1,r,pos*2+1));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>val.at(i);
        update(1,n,i,1);
        cin>>pos.at(i).fi>>pos.at(i).se;
    }
    int ans=val[n];
    for(int i=n-1;i>=1;i--)
    {
        int l= i+pos.at(i).fi;
        int r= i+pos.at(i).se;
        if(l>n) continue;
        r=min(r,n);
        val.at(i)=val.at(i) + query(l,r,1,n,1);
        update(1,n,1,i);
    }
    for(int i=1;i<=n;i++)   ans=max(ans, val[i]);
    cout<<ans;
}