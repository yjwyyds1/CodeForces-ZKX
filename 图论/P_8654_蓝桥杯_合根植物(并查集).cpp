#include <bits/stdc++.h>
const int N=1e6+10;
#define ll long long int
const int N=1e6+10;
using namespace std;

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
    int n,m,q;
    cin>>n>>m;
    cin>>q;
    n=n*m;
    set<int> s;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=q;i++)
    {
        int b,c;
        cin>>b>>c;
        uion(b,c);
    }
    for(int i=1;i<=n;i++)
    {
        s.insert(Find(i));
    }
    cout<<s.size()<<'\n';
    return 0;
}