#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 1e5 + 7;
ll qmi(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b=b>>1;
    }
    return ans%mod;
}
ll C(ll n,ll m){
    ll res=1;
    for(ll i=1;i<=m;i++) res=(res%mod*qmi(i,mod-2)%mod)%mod;
    for(ll i=n;i>=n-m+1;i--) res=(res%mod*i%mod)%mod;
    return res%mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(a[i+n]-a[i])%mod;
    }   
    cout<<(ans%mod*C(2*n,n)%mod)%mod<<'\n';
    return 0;
}
