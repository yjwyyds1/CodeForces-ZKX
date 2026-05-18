#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
ll qmi(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b=b>>1;
    }
    ans%=mod;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if(k==-1&&abs(n-m)%2){
        cout<<0<<'\n';
    }
    else{
        cout<<qmi(qmi(2,n-1),m-1)<<'\n';
    }
    
    return 0;
}