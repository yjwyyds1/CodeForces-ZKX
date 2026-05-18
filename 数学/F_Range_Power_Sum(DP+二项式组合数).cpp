#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
int a[N];
ll dp[N][15];
ll C[15][15];
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
void solve(){
    int n,Ks;
    cin>>n>>Ks;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=Ks;j++){
            dp[i][j]=0;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=Ks;j++){
            dp[i][j]=qmi(a[i],j);
            ll sum=0;
            for(int k=0;k<=j;k++){
                sum=(sum+((qmi(a[i],j-k)*C[j][k])%mod*dp[i-1][k]%mod))%mod;
            }
            dp[i][j]=(dp[i][j]+sum)%mod;
        }
        ans=(ans+dp[i][Ks])%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
	// freopen("zkx.out","w",stdout);
    for(int i=0;i<=10;i++){
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    // for(int i=0;i<=10;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<C[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
