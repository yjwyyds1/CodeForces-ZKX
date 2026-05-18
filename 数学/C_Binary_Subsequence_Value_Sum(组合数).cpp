#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inv(ll a){
    return qmi(a,mod-2);
}
ll f(ll a,ll b,ll n){
    return (inv(4)*(qmi(2,n-2)*(((qmi(abs(a-b),2)+a)%mod+b)%mod-2+mod)%mod)%mod)%mod;
}
void solve(){
    int n,q;
    cin>>n>>q;
    // char s[n+10];
    string s;
    cin>>s;
    s='>'+s;
    ll cnt1=0,cnt0=0;
    for(int i=1;i<=n;i++){
        cnt1+=s[i]=='1';
        cnt0+=s[i]=='0';
    }
    if(n>=2){
        for(int i=1;i<=q;i++){
            int x;
            cin>>x;
            if(s[x]=='1'){
                s[x]='0';
                cnt1--;
                cnt0++;
            }
            else{
                s[x]='1';
                cnt1++;
                cnt0--;
            }
            cout<<f(cnt1,cnt0,n)<<'\n';
        }
    }
    else{
        for(int i=1;i<=q;i++){
            int x;
            cin>>x;
            cout<<0<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
	// freopen("zkx.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
