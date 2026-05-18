#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ll n;
    // cin>>n;
    // vector<ll> a(n+10);
    // for(int i=1;i<=n;i++){
    //     cin>>a[i];
    // }
    // ll ans=0;
    // for(ll i=30;i>=0;i--){
    //     ll s=0,m=0;
    //     for(int j=1;j<=n;j++){
    //         if(a[j]>>i&1){
    //             s=j-s;
    //         }
    //         m+=s;
    //     }
    //     ans+=m*(1ll<<i);
    // }
    // cout<<ans<<'\n';
    int n;
    cin>>n;
    vector<ll> a(N,0);
    vector<ll> cnt0(N,1),cnt1(N,0);
    ll ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
        for(int j=30;j>=0;j--){
            if(a[i]>>j&1){
                ans+=cnt0[j]*(1ll<<j),cnt1[j]++;
            }
            else{
                ans+=cnt1[j]*(1ll<<j),cnt0[j]++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}