#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    // k--;
    __int128 p=k;
    p++;
    // cout<<k<<'\n';
    for(ll i=n;i>=1;i--){
        // cout<<((k>>i)&1ll);
        // int t=((k>>i)&1ll);
        if(p>(1ll<<(i-1))){
            cout<<1;
            p-=(1ll<<(i-1));
            p=(1ll<<(i-1))-p+1;
        }
        else{
            cout<<0;
        }
        // ans.push_back((1ll<<i)&k);
    }
    return 0;
}