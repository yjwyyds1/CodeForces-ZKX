#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll  long long int
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
ll a[N<<2];
ll n,q;
ll lowbit(ll x)
{
    return x&(-x);
}
void add(ll x,ll k)
{
    for(;x<=n;x+=lowbit(x))
    {
        a[x]+=k;
    }
}
ll query(ll x)
{
    ll res=0;
    for(;x;x-=lowbit(x)) res+=a[x];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)  
    {
        ll d;
        cin>>d;
        add(i,d);
    }
    for(int i=1;i<=q;i++)
    {
        ll p;
        cin>>p;
        if(p==1)
        {
            ll x,k;
            cin>>x>>k;
            add(x,k);
        }
        else 
        {
            ll l,r;
            cin>>l>>r;
            cout<<query(r)-query(l-1)<<'\n';
        }
    }
    return 0;
}