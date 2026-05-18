#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define ll long long int
int main() 
{
    int n;
    cin>>n;
    int a[n+1];
    priority_queue<ll,vector<ll>,greater<ll> >q;
    for(int i=1;i<=n;i++)cin>>a[i],q.push(a[i]);
    ll ans=0;
    while(q.size()>1)
    {
        ll a=q.top();
        q.pop();
        ll b=q.top();
        q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    cout<<ans<<'\n';
    return 0;
}