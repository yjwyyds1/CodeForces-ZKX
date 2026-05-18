#include <bits/stdc++.h>
const int N=2e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll f[N];
ll qmi(ll a ,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inv(ll x){
    return qmi(x,mod-2)%mod;
}
ll C(ll a, ll b){
    if(a<b){
        return 0;
    }
    return (f[a]%mod*inv(f[b])%mod*inv(f[a-b])%mod)%mod;
}
void solve(){
	ll n,m,k;
    cin>>n>>m>>k;
    if(m+k<n){
        cout<<0<<'\n';
    }
    else{
        ll L=2000000;
        f[0]=1;
        for(ll i=1;i<=L;i++){
            f[i]=f[i-1]%mod*i%mod;
        }
        // cout<<C(n+m,m+k+1)<<'\n';
        // cout<<C(n+m,m)<<'\n';
        cout<<(C(n+m,m)-C(n+m,m+k+1)+mod)%mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
