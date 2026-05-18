#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

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
ll c[N],inc[N];
void in()
{
    c[0]=1,inc[0]=1;
    for(int i=1;i<N;i++)
    {
        c[i]=c[i-1]*i%mod;
        inc[i]=inc[i-1]*f(i,mod-2,mod)%mod;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    in();
    ll _;
    cin>>_;
    while(_--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<c[a]*inc[b]%mod*inc[a-b]%mod<<'\n';
    }
    
    return 0;
}

