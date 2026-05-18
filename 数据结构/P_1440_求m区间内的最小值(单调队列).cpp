#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    a[0]=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty()&&a[q.back()]>=a[i])q.pop_back();
        q.push_back(i);
        if(q.front()<i-m+1)q.pop_front();
        if(i>0)cout<<a[q.front()]<<'\n';
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}


// #include <bits/stdc++.h>
// const int N=2e6+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
// struct vc{
//     ll l;
//     ll r;
//     ll k;
// }tree[N<<2];
// vector<int> a(N,INT_MAX);
// void pushup(int p){
//     tree[p].k=min(tree[p<<1].k,tree[p<<1|1].k);
// }
// void build(ll p,ll l,ll r){
//     tree[p].l=l,tree[p].r=r;
//     if(l==r){
//         tree[p].k=a[l];
//         return ;
//     }
//     ll mid=l+r>>1;
//     build(p<<1,l,mid),build(p<<1|1,mid+1,r); 
//     pushup(p);
// }
// ll ask(ll p,ll l,ll r){
//     if(tree[p].l>=l&&tree[p].r<=r){
//         return tree[p].k;
//     }
//     ll mid=tree[p].l+tree[p].r>>1;
//     ll ans=INT_MAX;
//     if(l<=mid){
//         ans=min(ans,ask(p<<1,l,r));
//     }
//     if(r>mid){
//         ans=min(ans,ask(p<<1|1,l,r));
//     }
//     return ans;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }
//     build(1,1,n);
//     for(int i=1;i<=n;i++){
//         if(i>1){
//             cout<<ask(1,max(i-m,1),i-1)<<'\n';
//         }
//         else{
//             cout<<0<<'\n';
//         }
//     }
//     return 0;
// }

