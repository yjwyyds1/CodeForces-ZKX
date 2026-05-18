#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;

int tree[N<<2],a[N];
void build(int x,int l,int r){
    if(l==r){
        tree[x]=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    tree[x]=tree[x<<1]&tree[x<<1|1];
}
int  query(int l,int r,int x,int L,int R){
    if(r<L||l>R)return INT_MAX;
    if(L<=l&&r<=R){
        return tree[x];
    }
    int mid=l+r>>1;
    return query(l,mid,x<<1,L,R)&query(mid+1,r,x<<1|1,L,R);
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
        build(1,1,n);
        int m;
        cin>>m;
        while(m--){
            int L,k;
            cin>>L>>k;
            if(a[L]<k){
                cout<<-1<<" ";
            }
            else{
                int l=L,r=n;
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(query(1,n,1,L,mid)>=k){
                        l=mid;
                    }
                    else{
                        r=mid-1;
                    }
                }
                cout<<l<<" ";
            }
        }
        cout<<'\n';
    }
    
    
    return 0;
}

// vector<vector<int>> Ans(N,vector<int>(33,0));
// bool ck(int L,int R,int k){
//     int res=0;
//     for(int i=0;i<=32;i++){
//         if(Ans[R][i]-Ans[L-1][i]==R-L+1){
//             res+=(1ll<<i);
//         }
//     }
//     return res>=k;
// }
// ll a[n+1];
// for(int i=0;i<=32;i++)Ans[0][i]=0;
// for(int i=1;i<=n;i++){
//     cin>>a[i];
//     Ans[i]=Ans[i-1];
//     for(int j=0;j<=32;j++){
//         if(a[i]&(1ll<<j)){
//             Ans[i][j]++;
//         }
//     }
// }
// int m;
// cin>>m;
// while(m--){
//     int L,k;
//     cin>>L>>k;
//     if(a[L]<k){
//         cout<<-1<<" ";
//     }
//     else{
//         int l=L,r=n;
//         while(l<r){
//             int mid=(l+r+1)>>1;
//             if(ck(L,mid,k)){
//                 l=mid;
//             }
//             else{
//                 r=mid-1;
//             }
//         }
//         cout<<l<<" ";
//     }
// }
// cout<<'\n';