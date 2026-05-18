#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll ans=0;//x^y<=x+y
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        ans^=x;
    }
    cout<<ans<<'\n';
    return 0;
}