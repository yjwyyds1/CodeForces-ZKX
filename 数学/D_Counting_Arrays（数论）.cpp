#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll mul=1,cnt=1,mn=1;
    ll mod=998244353;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(mul<=m&&__gcd(mul,i)==1){
            mul*=i;
        }
        mn=m%mod*mn%mod;
        cnt=(m/mul)%mod*cnt%mod;
        ans=(ans+mn-cnt+mod)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}