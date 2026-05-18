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
    ll k;
    cin>>k;
    vector<ll> a(k+1,0),sum(k+1,0);
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    ll n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=k;i++){
        a[i]%=m;
        sum[i]=sum[i-1]+a[i];
    }
    ll t=n/k;
    ll p=n%k;
    ll bn=x%m+t*sum[k]+sum[p];
    cout<<n-(bn/m)<<'\n';
    return 0;
}
