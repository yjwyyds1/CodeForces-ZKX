#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
const int mod=998244353;
vector<ll> fact(1e6+10), infact(1e6+10);
ll qmi(ll a,ll b){a=a%mod;ll t=1;while(b){if(b&1){t=t*a%mod;}a=a*a%mod;b=b>>1;}return t;}
void init(){fact[0]=infact[0]=1;for(int i=1;i<=1E6;i ++){fact[i]=fact[i-1]*i%mod;infact[i]=infact[i-1]*qmi(i,mod-2)%mod;}}
ll C(ll a, ll b){if(b<0||b>a)return 0;return fact[a] * infact[b] % mod * infact[a - b] % mod;}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    n--;
    vector<ll> dp(n+10,0),g(n+10,0);
    dp[0]=2,g[0]=2;
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(i-k>=0){
            dp[i]=(g[i-1]-g[i-k]+mod)%mod;
        }
        else{
            dp[i]=g[i-1];
        }
        g[i]=(g[i-1]+dp[i])%mod;
        ans=(ans+(dp[i]*C(n,i))%mod)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}