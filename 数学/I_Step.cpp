#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n+10);
    ll LCM=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        LCM=lcm(a[i],LCM);
    }
    LCM=2*LCM;
    vector<ll> p;
    map<ll,ll> f;
    for(ll i=2;i<=LCM/i;i++){
        if(LCM%i==0){
            p.push_back(i);
            int cnt=0;
            while(LCM%i==0){
                LCM/=i;
                cnt++;
            }
            f[i]=cnt;
        }
    }
    if(LCM>1){
        p.push_back(LCM);
        f[LCM]=1;
    }
    int d=p.size();
    ll ans=LLONG_MAX;
    for(ll i=0;i<(1<<d);i++){
        ll A=1,B=1;
        for(ll j=0;j<d;j++){
            if(i>>j&1)A*=qmi(p[j],f[p[j]]);
            else{
                B*=qmi(p[j],f[p[j]]);
            }
        }
        ll x=0,y=0;
        exgcd(A,B,x,y);
        x=-x;
		if(x<=0)x+=B;
        ans=min(ans,A*x);
    }
    cout<<ans<<'\n';
    return 0;
}