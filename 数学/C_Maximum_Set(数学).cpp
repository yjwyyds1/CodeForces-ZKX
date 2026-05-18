#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod =998244353;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        ll l,r;
        cin>>l>>r;
        // int ans=log2(r-l);
        ll x=l,ans=0;
        while(x<=r){
            x*=2;
            if(x>r){
                break;
            }
            ans++;
        }
        cout<<ans+1<<" ";
        ll cnt=0;
        // for(int i=l;i<=r;i++){
        //     if(i*pow(2,ans)<=r){
        //         cnt++;
        //         cnt%=mod;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // cnt+=r/pow(2,ans)-l+1;
        // cnt%=mod;
        // cnt+=(r/(pow(2,ans-1)*3)-l+1)*(ans);
        // cnt%=mod;
        ll k=1<<ans;
        cnt+=r/k-l+1;
        cnt%=mod;
        if(ans>0){
            if(r/(1<<(ans-1))/3-l+1>0){
                cnt+=(r/(1<<(ans-1))/3-l+1)*(ans);
                cnt%=mod;
            }
        }
        
        // for(int i=l;i<=r;i++){
        //     if(i*pow(2,ans-1)*3<=r){
        //         cnt+=ans;
        //         cnt%=mod;
        //     }
        //     else{
        //         break;
        //     }
        // }
        cout<<cnt<<'\n';
    }
    return 0;
}

// 4 8 16 32 64 
// 4 12 24 48 96
