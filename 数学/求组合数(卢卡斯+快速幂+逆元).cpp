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

ll lucs(ll a,ll b,ll p)
{
    if(a<p&&b<p) return c(a,b,p);
    return c(a%p,b%p,p)*lucs(a/p,b/p,p)%p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll _;
    cin>>_;
    while(_--)
    {
        ll a,b,p;
        cin>>a>>b>>p;
        // cout<<a/p<<" "<<b/p<<" "<<p<<'\n';
        // cout<<c(a/p,b/p,p)<<" "<<c(a%p,b%p,p)<<'\n';
        cout<<lucs(a,b,p)<<'\n';
    }
    
    return 0;
}

