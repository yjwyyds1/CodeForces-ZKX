#include <bits/stdc++.h>
const int N=2e5+10;
const int mod=998244353;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


ll f(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    res%=p;
    return res;

}
ll c(ll a,ll b,ll p)
{
    if(b>a) return 0;
    ll res=1;
    for(int i=1,j=a;i<=b;i++,j--)
    {
        res=res*j%p;
        res=res*f(i,p-2,p)%p;
    }
    return res;
}
    



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        string k;
        cin>>k;
        int cnt11=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(k[i]=='0')cnt0++;
            else{
                if(i+1<n&&k[i+1]==k[i]){
                    cnt11++;
                    i++;
                }
            }
        }
        // cout<<cnt11<<" "<<cnt0<<'\n';
        cout<<c(cnt11+cnt0,cnt11,mod)<<'\n';
    }
    return 0;
}