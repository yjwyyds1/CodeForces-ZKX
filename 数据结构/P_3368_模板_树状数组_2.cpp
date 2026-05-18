#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll  long long int
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
ll a[N<<2],t[N<<2];
ll n,q;
ll lowbit(ll x)
{
    return x&(-x);
}
void add(ll x,ll k)
{
    for(;x<=n;x+=lowbit(x))
    {
        t[x]+=k;
    }
}
ll query(ll x)
{
    ll res=0;
    for(;x;x-=lowbit(x)) res+=t[x];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)    cin>>a[i];
    for(int i=1;i<=q;i++)
    {
        ll p;
        cin>>p;
        if(p==1)
        {
            ll l,r,k;
            cin>>l>>r>>k;
            add(l,k);
            add(r+1,-k);
        }
        else 
        {
            ll x;
            cin>>x;
            cout<<query(x)+a[x]<<'\n';
        }
    }
    return 0;
}
