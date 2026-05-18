#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
// int s=strlen(a);
int a[N];
int ct;
void down(int x)
{
    int t=x;
    if(x*2<=ct&&a[x*2]<a[t]) t=x*2;//先换左儿子
    if(x*2+1<=ct&&a[x*2+1]<a[t]) t=x*2+1;//如果右儿子比左儿子小，就直接换右儿子
    //换的一定是两个儿子中最小的那个
    if(t!=x)
    {
        swap(a[x],a[t]);
        down(t);
    }
}
int main() 
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    ct=n;
    for(int i=n/2;i>=1;i--)down(i);
    while(m--)
    {
        cout<<a[1]<<" ";
        a[1]=a[ct];
        ct--;
        down(1);
    }
    return 0;
}







