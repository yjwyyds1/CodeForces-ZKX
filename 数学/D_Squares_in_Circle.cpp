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
    ld R;
    cin>>R;
    ll ans=4*(R-1)+1;
    ll ans1=0;
    ld b=R-1;
    for(ld a=1;a<R;a++){
        while((b+0.5l)*(b+0.5l)+(a+0.5l)*(a+0.5l)>R*R&&b>=0){
            b--;
        }
        ans1+=b;
    }
    cout<<ans+ans1*4<<'\n';
    return 0;
}