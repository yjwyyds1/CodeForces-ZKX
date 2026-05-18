#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
struct vc{
    ll l;
    ll r;
    ll xor0;
    ll xor1;
    ll tag;
}tree[N<<2];
int a[N];
string b;
void pushup(int p){
    tree[p].xor1=tree[p<<1].xor1^tree[p<<1|1].xor1;
    tree[p].xor0=tree[p<<1].xor0^tree[p<<1|1].xor0;
}
void pushdown(int p){
    swap(tree[p<<1].xor0,tree[p<<1].xor1);
    tree[p<<1].tag^=1;
    swap(tree[p<<1|1].xor0,tree[p<<1|1].xor1);
    tree[p<<1|1].tag^=1;
    tree[p].tag=0;
}
void build(ll p,ll l,ll r){
    tree[p].l=l,tree[p].r=r,tree[p].tag=0;
    if(l==r){
        if(b[l]=='0'){
            tree[p].xor0=a[l],tree[p].xor1=0;
        }
        else{
            tree[p].xor1=a[l],tree[p].xor0=0;
        }
        return ;
    }
    ll mid=l+r>>1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r); 
    pushup(p);
}
void update(ll p,ll l,ll r){
    if(tree[p].l>=l&&tree[p].r<=r){
        swap(tree[p].xor0,tree[p].xor1);
        tree[p].tag^=1;
        return ;
    }
    if(tree[p].tag){
        pushdown(p);
    }
    ll mid=tree[p].l+tree[p].r>>1;
    if(mid>=l){
        update(p<<1,l,r);
    }
    if(mid<r){
        update(p<<1|1,l,r);
    }
    pushup(p);
}
ll ask(ll p,ll l,ll r,ll k){
    if(tree[p].l>=l&&tree[p].r<=r){
        if(k==1){
            return tree[p].xor1;
        }
        else{
            return tree[p].xor0;
        }
    }
    if(tree[p].tag){
        pushdown(p);
    }
    ll mid=tree[p].l+tree[p].r>>1;
    ll ans=0;
    if(mid>=l){
        ans=ask(p<<1,l,r,k);
    }
    if(mid>r){
        ans=ans^ask(p<<1|1,l,r,k);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>b;
        b='$'+b;
        build(1,1,n);
        int m;
        cin>>m;
        while(m--){
            int op;
            cin>>op;
            if(op==1){
                int l,r;
                cin>>l>>r;
                update(1,l,r);
            }
            else if(op==2){
                int k;
                cin>>k;
                cout<<ask(1,1,n,k)<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}


// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int _;
//     cin>>_;
//     while (_--)
//     {
//         int n;
//         cin>>n;
//         int a[n+1];
//         int sum[n+1];
//         string b;
//         sum[0]=0;
//         for(int i=1;i<=n;i++){
//             cin>>a[i];
//             sum[i]=sum[i-1]^a[i];
//         }
//         cin>>b;
//         b='%'+b;
//         int ans=0;
//         for(int i=1;i<=n;i++){
//             if(b[i]=='1'){
//                 ans^=a[i];
//             }
//         }
//         int q;
//         cin>>q;
//         while(q--){
//             int op;
//             cin>>op;
//             if(op==1){
//                 int L,R;
//                 cin>>L>>R;
//                 ans=ans^sum[R]^sum[L-1];
//             }
//             else if(op==2){
//                 int g;
//                 cin>>g;
//                 if(g==1){
//                     cout<<ans<<" ";
//                 }
//                 else{
//                     cout<<(sum[n]^ans)<<" ";
//                 }
//             }
//         }
//         cout<<'\n';
//     }
//     return 0;
// }
