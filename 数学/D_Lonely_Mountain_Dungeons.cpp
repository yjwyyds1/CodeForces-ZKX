#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


ll C(ll x){
    return x*(x-1)/2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        ll n,b,x;
        cin>>n>>b>>x;
        vector<ll> c(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        sort(c.begin(),c.end());
        ll sum=0,ans=0,idx=1;
        for(ll i=1;i<=c[n];i++){
            while(idx<=n&&c[idx]<=i){
                sum+=C(c[idx]),idx++;
            }
            ll res=sum;
            for(int j=idx;j<=n;j++){
                res+=C(c[j])-(C(c[j]/i)*i)-(c[j]/i)*(c[j]%i);
            }
            ans=max(ans,res*b-(i-1)*x);
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
