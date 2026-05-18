#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
// __int128 f(__int128 a,__int128 b,ll p)
// {
//     __int128 ans=1;
//     while(b>0)
//     {
//         if(b&1)ans=ans*a%p;
//         a=a*a%p;
//         b=b>>1;
//     }
//     ans%=p;
//     return ans;
// }
ll g(ll a,ll b,ll p)
{
    ll x=0;
    while(b>0)
    {
        if(b&1) x=(x+a)%p;
        a=(a+a)%p;
        b=b>>1;
    }
    x%=p;
    return x;
}
ll f(ll a,ll b,ll p)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1) ans=g(ans,a,p);
        a=g(a,a,p);
        b=b>>1;
    }
    ans%=p;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _;
    cin>>_;
    while(_--)
    {
        ll a,b,p;
        cin>>a>>b>>p;
        cout<<f(a,b,p)<<'\n';
    }
    return 0;
}

