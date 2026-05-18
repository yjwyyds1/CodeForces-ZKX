#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll _;
    cin>>_;
    while(_--)
    {
        ll n;
        cin>>n;
        ll ans=n;
        set<int> s;
        for(ll i=2;i<=n/i;i++)
        {
            while(n%i==0)
            {
                n/=i;
                s.insert(i);
            }
        }
        if(n>1) s.insert(n);
        for(auto x:s)
        {
            ans=ans/x*(x-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}

