#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout<<100<<'\n';
    // for(int i=1;i<=100;i++)cout<<i<<'\n';
    vector<ll> f(N);
    for(ll i=1;i<=1e5;i++){
        f[i]=i*(i-1)/2;
    }
    int _;
    cin>>_;
    while(_--){
        ll n;
        cin>>n;
        ll x=1;
        while(f[x+1]<=n){
            x++;
        }
        for(int i=x;i>=2;i--){
            while(f[i]<=n){
                n-=f[i];
                cout<<1;
            }
            cout<<3;
        }
        cout<<37<<'\n';
    }
    return 0;
}