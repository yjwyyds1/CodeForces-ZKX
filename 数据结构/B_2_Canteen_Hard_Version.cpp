#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll n,k;
ll a[2*N],b[2*N];
ll A[2*N],B[2*N];
ll ck(int x){
    for(int i=1;i<=2*n;i++){
        A[i]=a[i];
        B[i]=b[i];
    }
    stack<int> s;
    ll ans=0;
    for(int i=1;i<=2*n;i++){
        if(A[i]){
            s.push(i);
        }
        while(!s.empty()&&B[i]){
            int t=s.top();
            if(i-t+1>x){
                ans+=A[t];
                A[t]=0;
                if(t<=n){
                    A[t+n]=0;
                }
                s.pop();
            }
            else{
                ll Mi=min(A[t],B[i]);
                A[t]-=Mi;
                B[i]-=Mi;
                if(i<=n){
                    B[i+n]-=Mi;
                    A[t+n]-=Mi;
                }
                if(A[t]==0){
                    s.pop();
                }
            }
        }
    }
    return ans;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[i+n]=b[i];
    }
    stack<int> s;
    int ans=0;
    for(int i=1;i<=2*n;i++){
        if(a[i]){
            s.push(i);
        }
        while(!s.empty()&&b[i]){
            int t=s.top();
            ans=max(ans,i-t+1);
            int Mi=min(a[t],b[i]);
            a[t]-=Mi;
            b[i]-=Mi;
            if(i<=n){
                a[t+n]-=Mi;
                b[i+n]-=Mi;
            }
            if(a[t]==0){
                s.pop();
            }
        }
    }
    cout<<ans<<'\n';
    // int L=0,R=n;
    // while(L<R){
    //     int mid=L+R>>1;
    //     // cout<<L<<" "<<R<<" "<<mid<<" "<<ck(mid)<<'\n';
    //     if(ck(mid)>k){
    //         L=mid+1;
    //     }
    //     else{
    //         R=mid;
    //     }
    // }
    // cout<<L<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
	// freopen("zkx.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}