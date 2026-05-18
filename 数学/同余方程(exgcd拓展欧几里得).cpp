#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return ;
    }
    else 
    {
        exgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
}

int main() 
{
    ll a,b;
    cin>>a>>b;
    ll x=0,y=0;
    exgcd(a,b,x,y);
    cout<<(x%b+b)%b<<'\n';
    return 0;
}