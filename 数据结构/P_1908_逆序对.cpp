#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
struct vc
{
    int x,id;
}a[N];
int n;
int t[N];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        t[i]+=k;
    }
}
ll query(int x){
    ll sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=t[i];
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+n+1,[](const vc& p,vc& b){
        if(p.x!=b.x){
            return p.x>b.x;
        }
        else{
            return p.id>b.id;
        }
    });
    ll ans=0;
    for(int i=1;i<=n;i++){
        add(a[i].id,1);
        ans+=query(a[i].id-1);
    }
    cout<<ans<<'\n';
    return 0;
}
