#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll XOR(ll x){
    if(x%4==0) return x;
    if(x%4==1) return 1;
    if(x%4==2) return x+1;
    return 0;
}
ll get(ll x,ll pos, ll k){
    if(x==0)return 0;
    ll t=(x>>pos);
    if(x%(1<<pos)>=k){
        t++;
    }
    return XOR(x)^(XOR(t-1)<<pos)^((t&1)*k);
}
void solve(){
    ll L,R,I,k;
    cin>>L>>R>>I>>k;
    cout<<(get(R,I,k)^get(L-1,I,k))<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
