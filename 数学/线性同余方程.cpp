#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) x=1,y=0;
	else
    {
		exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
}

int main() 
{
    int _;
    cin>>_;
    while(_--)
    {
        ll a,b,m;
        cin>>a>>b>>m;
        if(b%gcd(a,m)!=0) cout<<"impossible"<<'\n';
        else
        {
            ll x=0,y=0;
            exgcd(a,m,x,y);
            // cout<<b*x<<" "<<b*y<<'\n';
            // cout<<a<<" "<<b<<" "<<m<<'\n';
            b/=gcd(a,m);
            cout<<x*b%m<<'\n';
        }
    }
    
    return 0;
}
