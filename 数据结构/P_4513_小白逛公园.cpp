#include <bits/stdc++.h>
#define ull unsigned long long int
#define ld long double
#define ll long long int
const int N=21e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
struct vc{
    int l,r;
    int s,lz;
}tree[N<<2];
vector<int> a(N);
void build(int x,int l,int r){
    tree[x].l=l,tree[x].r=r;
    if(l==r){
        tree[x].s=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    tree[x].s=max(tree[x<<1].s,tree[x<<1|1].s);
}
void change(int x,int l,int r,int p,int k){
    
}
int query(int x,int l,int r,int L,int R){

}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int L,R;
            cin>>L>>R;
            cout<<qurey(1,1,n,L,R)<<'\n';
        }
        else{
            int id,x;
            cin>>id>>x;
            change(1,1,n,id,x);
        }
    }
    return 0;
}