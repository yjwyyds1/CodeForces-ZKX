#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
const int mod=1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,p;
    cin>>n>>p;
    vector<ll> f(N,0);
    f[1]=1,f[2]=1;
    for(int i=3;i<=p+1;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    for(int i=1;i<=p+1;i++){
        f[i]=(f[i]+f[i-1])%mod;
    }
    vector<ll> a,b;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        int k=a[i];
        int ok=1;
        while(k){
            if(mp[k]){  
                ok=0;
                break;
            }
            if(k&1) k>>=1;
            else if(k&2){
                ok=1;
                break;
            }
            else k>>=2;
        }
        if(ok){
            mp[a[i]]=1;
            b.push_back(a[i]);
        }
    }
    ll ans=0;
    for(int i=0;i<b.size();i++){
        // cout<<b[i]<<" ";
        int idx=0;
        for(int j=31;j>=0;j--){
            if(b[i]>>j&1){
                idx=j+1;
                break;
            }
        }
        if(p+1>idx)ans=(ans+f[p-idx+1])%mod;
    }
    cout<<ans<<'\n';
    return 0;
}