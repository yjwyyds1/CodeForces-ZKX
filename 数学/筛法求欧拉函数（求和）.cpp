#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
ll p[N],v[N],per[N];
ll n,ct;
void init()
{
    p[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            per[ct++]=i;
            p[i]=i-1;
        }
        for(int j=0;per[j]<=n/i;j++)
        {
            v[per[j]*i]=1;
            if(i%per[j]==0)
            {
                p[i*per[j]]=p[i]*per[j];
                break;
            }
            p[i*per[j]]=p[i]*p[per[j]];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    init();
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=p[i];
    cout<<ans<<'\n';
    return 0;
}

