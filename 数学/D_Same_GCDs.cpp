#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


ll gcd(ll x,ll y){
    return (y?gcd(y,x%y):x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        ll a,m;
        cin>>a>>m;
        ll d=gcd(a,m);
        ll n=m/d;
        ll ans=m/d;
        set<ll> s;
        for(ll i=2;i*i<=n;i++){
            while(n%i==0){
                n/=i;
                s.insert(i);
            }
        }
        if(n>1)s.insert(n);
        for(auto x:s){
            ans=ans/x*(x-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}