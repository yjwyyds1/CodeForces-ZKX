#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const ll inf=9223372036854775807;
// int s=strlen(a);

ll n,k;
ll a[N];
stack<ll> b;

void sovle()
{
    char c[N];
    cin>>c;
    int s=strlen(c);
    ll now=0;
    for(int i=0;i<s;i++)
    {
        if(c[i]=='*')
        {
            i++;
            ll x1=b.top();
            b.pop();
            now=0;
            while(c[i]>='0'&&c[i]<='9'&&i<s)
            {
                now*=10,now+=(c[i]-'0');
                i++;
            }
            i--;
            ll x2=now;
            now=0;
            b.push((x1%10000)*(x2%10000));
            
        }
        else if(c[i]>='0'&&c[i]<='9')
        {
            now=0;
            while(c[i]>='0'&&c[i]<='9'&&i<s) 
            {
                now*=10,now+=(c[i]-'0');
                i++;
            }
            b.push(now);
            now=0;
            i--;
        }
    }
    ll ans=0;
    while(!b.empty())
    {
        ll x3=b.top();
//         cout<<b.top()<<'\n';
        b.pop();
        ans=ans+x3%10000;
        ans%=10000;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sovle();
    return 0;
}
