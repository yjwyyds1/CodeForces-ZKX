#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
// int s=strlen(a);
int f[N];
struct vc
{
    int xl;
    int yl;
    int tl;
};
bool cmp(vc a,vc b)
{
    return a.tl<b.tl;
}
int Find(int x)
{
    if(x==f[x])return x;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vc a[N];
    for(int i=0;i<q;i++)
    {
        cin>>a[i].xl>>a[i].yl>>a[i].tl;
    }
    sort(a,a+q,cmp);
    
    for(int i=1;i<=n;i++) f[i]=i;

    for(int i=0;i<q;i++)
    {
        if(Find(a[i].xl)!=Find(a[i].yl))
        {
            // cout<<Find(a[i].xl)<<" "<<Find(a[i].yl)<<'\n';
            uion(a[i].xl,a[i].yl);
            n--;
        }
        if(n==1)
        {
            cout<<a[i].tl<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}


