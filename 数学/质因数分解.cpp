#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll n;
    cin>>n;
    ll a,b;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                a=i;
                n/=i;
            }
        }
    }
    if(n>1)
    {
        b=n;
    }
    cout<<max(b,a)<<'\n';
    return 0;
}