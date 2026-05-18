// #include <iostream>
// typedef long long LL;
// LL n, a[100005], d[270000], b[270000];

// void build(LL l, LL r, LL p)
// { 
//   if (l == r) {
//     d[p] = a[l];
//     return;
//   }
//   LL m = l + ((r - l) >> 1);
//   build(l, m, p << 1), build(m + 1, r, (p << 1) | 1);  // 分别建立子树
//   d[p] = d[p << 1] + d[(p << 1) | 1];
// }

// void update(LL l, LL r, LL c, LL s, LL t, LL p) 
// {
//   if (l <= s && t <= r) {
//     d[p] += (t - s + 1) * c, b[p] += c;  // 如果区间被包含了，直接得出答案
//     return;
//   }
//   LL m = s + ((t - s) >> 1);
//   if (b[p])
//       d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
//       b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
//   b[p] = 0;
//   if (l <= m)
//     update(l, r, c, s, m, p << 1);  // 本行和下面的一行用来更新p*2和p*2+1的节点
//   if (r > m) update(l, r, c, m + 1, t, (p << 1) | 1);
//   d[p] = d[p << 1] + d[(p << 1) | 1];  // 计算该节点区间和
// }

// LL getsum(LL l, LL r, LL s, LL t, LL p) {
//   if (l <= s && t <= r) return d[p];
//   LL m = s + ((t - s) >> 1);
//   if (b[p])
//     d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
//         b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
//   b[p] = 0;
//   LL sum = 0;
//   if (l <= m)
//     sum =
//         getsum(l, r, s, m, p << 1);  // 本行和下面的一行用来更新p*2和p*2+1的答案
//   if (r > m) sum += getsum(l, r, m + 1, t, (p << 1) | 1);
//   return sum;
// }

// int main() {
//   std::ios::sync_with_stdio(0);
//   LL q, i1, i2, i3, i4;
//   std::cin >> n >> q;
//   for (LL i = 1; i <= n; i++) std::cin >> a[i];
//   build(1, n, 1);
//   while (q--) {
//     std::cin >> i1 >> i2 >> i3;
//     if (i1 == 2)
//       std::cout << getsum(i2, i3, 1, n, 1) << std::endl;  // 直接调用操作函数
//     else
//       std::cin >> i4, update(i2, i3, i4, 1, n, 1);
//   }
//   return 0;
// }
#include <bits/stdc++.h>
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
struct vc{
    ll x;
    ll l,r;
    ll lazy;
}tree[N<<2];
ll a[N];
void pushdown(ll p){
    tree[p<<1].x+=tree[p].lazy*(tree[p<<1].r-tree[p<<1].l+1);
    tree[p<<1|1].x+=tree[p].lazy*(tree[p<<1|1].r-tree[p<<1|1].l+1);
    tree[p<<1].lazy+=tree[p].lazy;
    tree[p<<1|1].lazy+=tree[p].lazy;
    tree[p].lazy=0;
}
void build(ll p,ll l,ll r){
    tree[p].l=l,tree[p].r=r,tree[p].lazy=0;
    if(l==r){
        tree[p].x=a[l];
        return ;
    }
    ll mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p].x=tree[p<<1].x+tree[p<<1|1].x;
}
void add(ll p,ll L,ll R,ll c){
    if(L<=tree[p].l&&tree[p].r<=R){
        tree[p].x+=(tree[p].r-tree[p].l+1)*c;
        tree[p].lazy+=c;    
        return;
    }
    pushdown(p);
    ll mid=(tree[p].l+tree[p].r)>>1;
    if(L<=mid){
        add(p<<1,L,R,c);
    }
    if(R>mid){
        add(p<<1|1,L,R,c);
    }
    tree[p].x=tree[p<<1].x+tree[p<<1|1].x;
}
ll query(ll p,ll L,ll R){
    if(L<=tree[p].l&&tree[p].r<=R){
        return tree[p].x;
    }
    pushdown(p);
    ll mid=(tree[p].l+tree[p].r)>>1;
    ll sum=0;
    if(L<=mid){
        sum+=query(p<<1,L,R);
    }
    if(R>mid){
        sum+=query(p<<1|1,L,R);
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(ll i=1;i<=q;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll L,R,c;
            cin>>L>>R>>c;
            add(1,L,R,c);
        }
        else{
            ll L,R;
            cin>>L>>R;
            cout<<query(1,L,R)<<'\n';
        }
    }
    return 0;
}