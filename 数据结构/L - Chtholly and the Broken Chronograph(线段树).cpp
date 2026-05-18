#include<iostream>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
struct xds
{
    int l,r;
    int cnt;//记录启用个数
    ll sum,lazy;
}tr[N*4];

int n,q,a[N],s[N];    
inline void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}
inline void pushdown(int u)
{
    tr[u<<1].sum+=(1ll*tr[u<<1].cnt*tr[u].lazy);
    tr[u<<1|1].sum+=(1ll*tr[u<<1|1].cnt*tr[u].lazy);
    tr[u<<1].lazy+=tr[u].lazy;
	tr[u<<1|1].lazy+=tr[u].lazy;
    tr[u].lazy=0;
}
inline void build(int u,int l,int r)
{
    if(l==r)
    {
        tr[u]={l,r,s[r],a[r],0};
    }
    else 
    {
        tr[u]={l,r,0,0,0};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
inline ll query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    {
    	return tr[u].sum;
	}
    else
    {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        ll sum=0;
        if(l<=mid) sum+=query(u<<1,l,r);
        if(r>mid)  sum+=query(u<<1|1,l,r);
        return sum;
    }
}
inline void modify1(int u,int l,int r,ll v){
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        tr[u].sum+=(tr[u].cnt*v);    
        tr[u].lazy+=v;
    }
    else 
    {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)modify1(u<<1,l,r,v);
        if(r>mid)modify1(u<<1|1,l,r,v);
        pushup(u);
    }
} 
inline void modify2(int u,int x,int v){
    if(tr[u].l==x&&x==tr[u].r)
    {
        tr[u].cnt=v;
        s[x]=v;
    }
    else 
    {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid) modify2(u<<1,x,v);
        else modify2(u<<1|1,x,v);
        pushup(u);
    }
}
int main()
{
    cin>>n>>q;
    for(int i(1);i<=n;i++)scanf("%d",&a[i]);
    for(int i(1);i<=n;i++)scanf("%d",&s[i]);
    build(1,1,n);
    while(q--)
    {
        int l,r,cz;
        ll x;
        scanf("%d",&cz);
        if(cz==1)
        {
            scanf("%d",&x);
             if(s[x]==1)   modify2(1,x,0);
        }
        else if(cz==2)
        {
            scanf("%d",&x);
            if(s[x]==0)  modify2(1,x,1);
        }
        else if(cz==3)
        {
            scanf("%d%d%lld",&l,&r,&x);
            modify1(1,l,r,x);
        }
        else 
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,l,r));
        }
    } 
}