#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
void solve(){
	ll n,k;
    cin>>n>>k;
    if(k==1){
        cout<<n%mod<<'\n';
    }
    else{
        ll a1=1,a2=1;
        ll ans;
        for(int i=3;;i++){
            ll a3=(a1+a2)%k;
            if(a3==0){
                ans=i;
                break;
            }
            a1=a2,a2=a3;
        }
        cout<<((ans%mod)*(n%mod))%mod<<'\n';
    }

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
