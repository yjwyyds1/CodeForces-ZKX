#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e6+10;
// int s=strlen(a);
int f[N],siz[N];
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
    if(Find(x)==Find(y))
    {
        return ;
    }
    else
    {
        siz[Find(y)]+=siz[Find(x)];
        f[Find(x)]=Find(y);//把x加到y上面去
    }
    
}
int main() 
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
    for(int i=1;i<=q;i++)
    {
        string a;
        cin>>a;
        if(a=="C")
        {
            int b,c;
            cin>>b>>c;
            uion(b,c);
        }
        if(a=="Q1")
        {
            int b,c;
            cin>>b>>c;
            if(Find(b)==Find(c)) cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
        if(a=="Q2")
        {
            int b;
            cin>>b;
            cout<<siz[Find(b)]<<'\n';
        }
    }
    return 0;
}