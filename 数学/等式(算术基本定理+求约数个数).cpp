#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _;
    cin>>_;
    while(_--)
    {
        ll n;
        cin>>n;
        n*=n;
        map<ll,ll>mp;
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
        int ans=1;
        for(auto x:mp)
        {
            // cout<<x.first<<" "<<x.second<<'\n';
            ans=ans*(x.second+1);
        }
        cout<<ans/2+1<<'\n';
    }
    
    
    return 0;
}

