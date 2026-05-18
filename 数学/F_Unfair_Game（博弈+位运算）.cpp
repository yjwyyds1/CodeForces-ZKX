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
    int _;
    cin>>_;
    while(_--){
        int a,b,c,d;
        int ans=0;
        cin>>a>>b>>c>>d;//去掉3个不如去掉两个
        cout<<a/2+b/2+c/2+d/2+(a%2&&b%2&&c%2)<<'\n';
        // int c123=min({a,b,c});
        // // ans+=c123;
        // if(c123<2){
        //     ans+=(a-c123)/2;
        //     ans+=(b-c123)/2;
        //     ans+=(c-c123)/2;
        //     ans+=c123;
        //     ans+=d/2;
        // }
        // else{
        //     ans+=(a-c123)/2;
        //     ans+=(b-c123)/2;
        //     ans+=(c-c123)/2;
        //     ans+=c123+1;
        //     ans+=d/2;
        // }
        // cout<<ans<<'\n';
    }
    return 0;
}