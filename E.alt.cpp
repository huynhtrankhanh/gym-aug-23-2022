#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define se second
#define fi first
const int maxn= 1e6+5;




signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)   cin>>a[i];
    int pos=-1;
    int nn=*min_element(a.begin()+1, a.end());
    for(int i=1;i<=n;i++)
    {
        if(a[i] == nn)
        {
            pos=i;
            break;
        }
    }
    vector<int>ls(n+1,0), rs(n+1,0);
    int temp= pos;
    int cnt=2*n;
    while(cnt--)
    {
        int l=temp-1;
        if(l<1) l=n;
        if(a[l] > a[temp] && a[temp] !=0)   rs[l]= 1+rs[temp];
        temp--;
        if(temp<1)  temp=n;
    }
    cnt=2*n;
    temp= pos;
    while(cnt--)
    {
        int r= temp+1;
        if(r>n) r=1;
        if(a[r] > a[temp] && a[temp] !=0)   ls[r]= ls[temp] +1;
        temp++;
        if(temp >n) temp=1;  
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i] ==0)    cout<<0;
        else cout<<(max(ls[i], rs[i])+1)*k;
        cout<<" ";
    }
}