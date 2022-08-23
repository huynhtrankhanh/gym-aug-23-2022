#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define se second
#define fi first
const int maxn= 1e6+5;
const int inf =1e15;



signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin>>s;
    int n= s.size();
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)   v[i]=s[i-1]-'0';
    vector<int>cnt(10,0);
    int need=0;
    for(int i=1;i<=9;i++) 
    {
        cin>>cnt[i];
        need+=cnt[i];
    }
    int pre[n+1][10]; // pre[i][j] la vi tri cua so j ve ben phai cua index i
    memset(pre, inf, sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        int num=v[i];
        for(int j=1;j<=9;j++)
        {
            for(int x=i;x<=n;x++)
            {
                if(v[x]==j)    
                {
                    pre[i][j]= x;
                    break;
                }
            }
        }
    }
    
}