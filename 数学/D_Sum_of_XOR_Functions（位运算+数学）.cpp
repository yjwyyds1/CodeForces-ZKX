#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mod=998244353;
    ll ans=0;
    for(int i=0;i<=30;i++){
        vector<int> s(n+10,0);
        for(int j=1;j<=n;j++){
            s[j+1]=s[j]^(a[j]>>i&1);
        }
        vector<ll> cnt(2,0),sum(2,0);
        for(int j=1;j<=n+1;j++){
            ans=(ans+cnt[s[j]^1]*j%mod*(1<<i))%mod;
            ans=(ans-sum[s[j]^1]*(1<<i)+mod)%mod;
            cnt[s[j]]++;
            sum[s[j]]=(sum[s[j]]+j)%mod;
        }
        ans%=mod;
    }
    cout<<ans<<'\n';
    // for(ll i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         ans=(ans+((i%mod)*(sum[j]^sum[j-i])%mod)%mod)%mod;
    //     }
    // }
    // cout<<ans<<'\n';
    return 0;
}