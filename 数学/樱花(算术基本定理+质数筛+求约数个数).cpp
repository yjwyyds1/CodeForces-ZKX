#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const ll mod=1e9+7;
const int inf = 0x3f3f3f3f;
ll per[N],v[N],ct=1;
map<ll,ll>mp;
void fp(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!v[i]) per[ct++]=i;
        for(int j=1;j<ct;j++)
        {
            if(i*per[j]>n)break;
            v[per[j]*i]=1;
            if(i%per[j]==0) break;
        }
    }
}
void f(ll x)
{
    for(int j=1;per[j]*per[j]<=x;j++)
    {
        while(x%per[j]==0)
        {
            mp[per[j]]++;
            x/=per[j];
        }
    }
    if(x>1) mp[x]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll n;
    cin>>n;
    fp(n);
    for(ll i=1;i<=n;i++)f(i);
    ll ans=1;
    for(auto x:mp)
    {
        ans=ans*(2*x.second+1)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}