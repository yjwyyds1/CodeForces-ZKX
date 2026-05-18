// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// const int N=1e6+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// int n,q;
// vector<int> a(n+10,0);
// struct vc{
//     int l,r,z,y,add;
// }tree[N<<2];

// void build(int x,int l,int r){
//     tree[x].l=l,tree[x].r=r;
//     if(l==r){
//         tree[x].z++;
//         return ;
//     }
//     int mid=l+r>>1;
//     build(x<<1,l,mid);
//     build(x<<1|1,mid+1,r);
//     tree[x].z=tree[x<<1].z+tree[x<<1|1].z;
// }
// void ld(int x){
//     if(!tree[x].add){
//         return;
//     }
//     swap(tree[x<<1].z,tree[x<<1].y);
//     swap(tree[x<<1|1].z,tree[x<<1|1].y);
//     tree[x<<1].add^=1;
//     tree[x<<1|1].add^=1;
//     tree[x].add=0;
// }
// void change(int x,int l,int r){
//     if(tree[x].l>=l&&tree[x].r<=r){
//         tree[x].add^=1;
//         swap(tree[x].z,tree[x].y);
//         return;
//     }
//     ld(x);
//     int mid=tree[x].l+tree[x].r>>1;
//     if(l<=mid)change(x<<1,l,r);
//     if(mid<r) change(x<<1|1,l,r); 
//     tree[x].z=tree[x<<1].z+tree[x<<1|1].z;
//     tree[x].y=tree[x<<1].y+tree[x<<1|1].y;
// }
// int ask(int x,int l,int r){
//     if(tree[x].l>=l&&tree[x].r<=r){
//         return tree[x].y;
//     }
//     ld(x);
//     int mid=tree[x].l+tree[x].r>>1,sum=0;
//     if(mid>=l){
//         sum+=ask(x<<1,l,r);
//     }
//     if(mid<r){
//         sum+=ask(x<<1|1,l,r);
//     }
//     return sum;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);    
//     cin>>n>>q;    
//     build(1,1,n);
//     for(int i=1;i<=q;i++){
//         int op,L,R;
//         cin>>op>>L>>R;
//         if(!op){
//             change(1,L,R);
//         }
//         else{
//             cout<<ask(1,L,R)<<'\n';
//         }
//     }
    
//     return 0;
// }


// int L[N],R[N],pos[N],d[N],add[N];
// void change(int a,int b){
//     int x=pos[a],y=pos[b];
//     if(x==y){
//         for(int i=a;i<=b;i++){
//             d[i]^=1;
//         }
//     }
//     else{
//         for(int i=x+1;i<=y-1;i++)add[i]++;
//         for(int i=a;i<=R[x];i++)d[i]^=1;
//         for(int i=L[y];i<=b;i++)d[i]^=1;
//     }
// }
// int Find(int L,int R){
//     int sum=0;
//     for(int i=L;i<=R;i++){
//         if((d[i]+add[pos[i]])%2){
//             sum++;
//         }
//     }   
//     return sum;
// }



// int n,q;
// cin>>n>>q;
// int x=sqrt(n);
// for(int i=1;i<=x;i++){
//     L[i]=(i-1)*x+1,R[i]=i*x;
// }
// if(R[x]<n){
//     x++;
//     L[x]=R[x-1]+1;
//     R[x]=n;
// }
// for(int i=1;i<=x;i++){
//     for(int j=L[i];j<=R[i];j++){
//         pos[j]=i;
//     }
// }
// for(int i=1;i<=q;i++){
//     int op,L,R;
//     cin>>op>>L>>R;
//     if(!op){
//         change(L,R);
//     }
//     else{
//         cout<<Find(L,R)<<'\n';
//     }
// }
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ld long double
#define ll long long int
const int N=430;
const int inf = 0x3f3f3f3f;
using namespace std;


ll a[N][N],d[N],sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    while(q--){
        int op,L,R;
        cin>>op>>L>>R;
        // if(L>R){
        //     swap(L,R);
        // }
        // L--;
        if(!op){
            for(int i=L;i<=R;){
                ll k=i/N;
                ll x=i%N;
                if(x||i+N>R){
                    a[k][x]^=1;
                    sum[k]+=a[k][x]?1:-1;
                    i++;
                }
                else{
                    d[k]^=1;
                    i+=N;
                }
            }
        }
        else{
            ll ans=0;
            for(int i=L;i<=R;){
                ll k=i/N;
                ll x=i%N;
                if(x||i+N>R){
                    ans+=a[k][x]^d[k];
                    i++;
                }
                else
                {
                    ans+=d[k]?N-sum[k]:sum[k];
                    i+=N;
                }
            }
            cout<<ans<<'\n';
        }
    }
    
    return 0;
}