#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod=1000000007;
// ll g(ll a,ll b,ll p)
// {
//     ll x=0;
//     while(b>0)
//     {
//         if(b&1) x=(x+a)%p;
//         a=(a+a)%p;
//         b=b>>1;
//     }
//     x%=p;
//     return x;
// }
ll gcd(ll x,ll y)
{
    return y>0?gcd(y,x%y):x;
}
ll f(ll a,ll b,ll p)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1) ans=ans*a%p;
        a=a*a%p;
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
        ll a,p;
        cin>>a>>p;
        // cout<<gcd(a,p);
        if(gcd(a,p)!=1)cout<<"impossible"<<'\n';
        else 
        {
            cout<<f(a,p-2,p)<<'\n';
        }
    }
    return 0;
}