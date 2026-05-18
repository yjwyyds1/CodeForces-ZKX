#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=2e6+10;
const int inf = 0x3f3f3f3f;

ll n,m,idx;
ll a[N],b[N],root[N*40];
ll lp[N*20],rp[N*20],sum[N*40];

int build(int begin,int end)
{
    int x=++idx;
    sum[x]=0;
    if(begin==end)return x;
    int mid=(begin+end)>>1;
    lp[x]=build(begin,mid);
    rp[x]=build(mid+1,end);
    return x;
}
int update(int last,int begin,int end,int k,int v)
{
    int x=++idx;
    sum[x]=sum[last];lp[x]=lp[last];rp[x]=rp[last];
    if(begin==end)
    {
        sum[x]+=v;
        return x;
    }
    int mid=(begin+end)>>1;
    if(k<=mid)
    {
        lp[x]=update(lp[last],begin,mid,k,v);
    }
    else{
        rp[x]=update(rp[last],mid+1,end,k,v);
    }
    sum[x]=sum[lp[x]]+sum[rp[x]];
    return x;
}
int query(int lx,int rx,int begin,int end,int k){
    if(begin==end)
    {
        return begin;
    }
    int mid=(begin+end)>>1;    
    int lct=sum[lp[lx]]-sum[lp[rx]];
    if(k<=lct){
        return query(lp[lx],lp[rx],begin,mid,k);
    }
    else{
        return query(rp[lx],rp[rx],mid+1,end,k-lct);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int t=unique(b+1,b+n+1)-(b+1);
    root[0]=build(1,t);
    for(int i=1;i<=n;i++){
        int x=lower_bound(b+1,b+1+t,a[i])-b;
        root[i]=update(root[i-1],1,t,x,1);
    }
    for(int i=1;i<=m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<b[query(root[r],root[l-1],1,t,k)]<<'\n';
    }
    return 0;
}