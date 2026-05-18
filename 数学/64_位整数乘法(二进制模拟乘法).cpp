#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
ll g(ll a,ll b,ll p)
{
    ll x=0;
    while(b>0)
    {
        if(b&1)x=(a+x)%p;
        a=(a+a)%p;
        b=b>>1;
    }
    x%=p;
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<g(a,b,p)<<'\n';
    return 0;
}