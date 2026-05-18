#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll _;
    cin>>_;
    map<ll,ll>mp;
    while(_--)
    {
        ll n;
        cin>>n;
        for(ll i=2;i<=n/i;i++)
        {
            while(n%i==0)
            {
                mp[i]++;
                n/=i;
            }
        }
        if(n>1)
        {
            mp[n]++;
        }
    }
    ll sum=1;
    for(auto x:mp)
    {
        ll a=x.first,b=x.second;
        ll ans=1;
        while(b--)
        {
            ans=(ans*a+1)%mod;
        }
        sum=sum*ans%mod;
    }
    cout<<sum<<'\n';
    return 0;
}

