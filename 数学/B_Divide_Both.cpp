#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
std::vector<ll> minp, primes, phi, f;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    f.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
            f[i]=f[i-1]+1;
        }
        else{
            f[i]=f[i-1];
        }
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}
void solve(){
	ll L,R;
    cin>>L>>R;
    vector<ll> f(N,0);
    ll ans=0;
    for(ll i=R;i>=2;i--){
        ll w=R/i-(L-1)/i;
        f[i]=w*w;
        for(int j=2*i;j<=R;j+=i){
            f[i]-=f[j];
        }
        ans+=f[i];
    }
    // cout<<ans<<'\n';
    for(int i=L;i<=R;i++){
        if(i==1)continue;
        ans-=(R/i)*2-1;
    }
    cout<<ans<<'\n';
    // sieve(N);
    // // for(int i=1;i<=R;i++){
    // //     cout<<f[i]<<" ";
    // // }
    // // cout<<'\n';
    // ll ans=(f[R]-f[L-1])*(R-L+1)+((R-L+1)-(f[R]-f[L-1]))*(f[R]-f[L-1]);
    // // cout<<ans<<'\n';

    // for(int i=L;i<=R;i++){
    //     if(phi[i]==i-1){
    //         continue;
    //     }
    //     else{
    //         if(R/i==1){
    //             ans++;
    //         }
    //         else{
    //             ans+=(R/i-1)*2+1;
    //         }
    //     }
    // }
    // int cnt=0;
    // for(int x=L;x<=R;x++){
    //     for(int y=L;y<=R;y++){
    //         int g=gcd(x,y);
    //         if(g==1||g==x||g==y){
    //             cout<<x<<" "<<y<<'\n';
    //             cnt++;
    //         }
    //     }
    // }
    // cout<<cnt<<'\n';
    // cout<<(R-L+1)*(R-L+1)-ans<<'\n';
    // cout<<ans<<'\n';
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