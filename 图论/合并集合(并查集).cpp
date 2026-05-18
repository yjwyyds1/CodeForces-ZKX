#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e6+10;
int f[N];
int Find(int x)
{
    if(f[x]==x)return x;
    else 
    {
        f[x]=Find(f[x]);
        return f[x];
    }
}
void uion(int x,int y)
{
    f[Find(x)]=Find(y);
}
int main() 
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=q;i++)
    {
        char a;
        int b,c;
        cin>>a>>b>>c;
        if(a=='M')
        {
            uion(b,c);
        }
        if(a=='Q')
        {
            if(Find(b)==Find(c)) cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
    }
    return 0;
}