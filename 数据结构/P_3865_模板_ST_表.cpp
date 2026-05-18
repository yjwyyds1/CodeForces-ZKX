#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;
const int N=1e6+10;
int a[N];
int lg2[N];
int f[N][32];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
    int n,q;
    n=read(),q=read();
    lg2[1]=0;
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    for(int i=1;i<=n;i++) f[i][0]=read();
    for(int k=1;k<=lg2[n];k++)
    {
        for(int i=1;i<=n-(1<<k)+1;i++)
        {
            f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
        }
    }
    while(q--)
    {
        int l,r;
        l=read(),r=read();
        int d=lg2[r-l+1];
        cout<<max(f[l][d],f[r-(1<<d)+1][d])<<'\n';
    }
    
    return 0;
}