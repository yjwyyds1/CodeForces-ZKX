#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    { 
        ll x,y;
        cin>>x>>y;
        ll ans=x+y;
        for(ll i=1;i<=100000;i++){
            ans=min(ans,(x+i-1)/i+(y+i-1)/i+(i-1));
        }
        cout<<ans<<'\n';
    }
    return 0;
}