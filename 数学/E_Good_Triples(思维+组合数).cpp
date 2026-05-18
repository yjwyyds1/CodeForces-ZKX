#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    vector<ll> f(20,0);
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(i+j+k<10){
                    f[i+j+k]++;
                }
            }
        }
    }
    while (_--)
    {
        ll n;
        cin>>n;
        ll ans=1;
        while(n){
            ll t=n%10;
            // ans*=(t+2)*(t+1)>>1;
            ans*=f[t];
            n/=10;
        }
        cout<<ans<<'\n';
    }
    
    
    return 0;
}