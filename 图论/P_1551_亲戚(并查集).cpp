#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
// int s=strlen(a);
int f[N];
int Find(int x) {
    return x == f[x] ? x : f[x] = Find(f[x]);
}
void uion(int x,int y)
{
    f[Find(x)]=Find(y);//先查询x y 的各自最远祖先 再合并
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        uion(x,y);
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(Find(l)!=Find(r))cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';
    }
    return 0;
}