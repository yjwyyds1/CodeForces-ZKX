#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
struct vc{
    ll minx,miny;
    ll maxx,maxy;
    ll l,r;
    ll aX,aY;
}tree[N<<2];
ll a[N],b[N];
void pushup(int p){
    tree[p].maxx=max(tree[p<<1].maxx,tree[p<<1|1].maxx);
    tree[p].minx=min(tree[p<<1].minx,tree[p<<1|1].minx);
    tree[p].maxy=max(tree[p<<1].maxy,tree[p<<1|1].maxy);
    tree[p].miny=min(tree[p<<1].miny,tree[p<<1|1].miny);

    tree[p].aX=max({tree[p<<1].aX,tree[p<<1|1].aX,tree[p<<1].maxx-tree[p<<1|1].minx});
    //最大值在左边 就是用(a[l]+l)-(a[r]+r)
    tree[p].aY=max({tree[p<<1].aY,tree[p<<1|1].aY,tree[p<<1|1].maxy-tree[p<<1].miny});
    //最大值在右边 就是用(a[r]-r)-(a[l]-l)

}
void build(ll p,ll l,ll r){
    tree[p].l=l,tree[p].r=r;
    if(l==r){
        tree[p].maxx=tree[p].minx=b[l];   
        tree[p].maxy=tree[p].miny=a[l];
        tree[p].aX=0,tree[p].aY=0;
        return ;
    }
    ll mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}


void update(ll p,ll L,ll R,ll c){
    if(tree[p].l==tree[p].r){
        tree[p].minx=tree[p].maxx=b[L];
        tree[p].miny=tree[p].maxy=a[L];
        return;
    }
    
    ll mid=(tree[p].l+tree[p].r)>>1;
    if(L<=mid){
        update(p<<1,L,R,c);
    }
    if(R>mid){
        update(p<<1|1,L,R,c);
    }
    pushup(p);
}
ll query(){
    return max(tree[1].aX,tree[1].aY);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        ll n,q;
        cin>>n>>q;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i]+i;
            a[i]-=i;
        }
        build(1,1,n);
        cout<<query()<<'\n';
        for(ll i=1;i<=q;i++){
            int p,x;
            cin>>p>>x;
            b[p]=x+p;
            a[p]=x-p;
            update(1,p,p,x);
            cout<<query()<<'\n';
        }
    }
    
    return 0;
}