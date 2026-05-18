#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,p,ans=0;
    cin>>n>>m;
    int per[m];
    for(int i=0;i<m;i++)cin>>per[i];
    for(int i=1;i<(1<<m);i++)//二进制每一位表示一种状态——状压
    {
        k=n,p=0;
        for(int j=0;j<m;j++)
        {
            if((i>>j)&1)//查询每一位的状态
            {
                p++;
                k/=per[j];
            }
        }
        if(p&1) ans+=k;//容斥定理
        else  ans-=k;//奇加偶减
    }
    cout<<ans<<'\n';
    return 0;
}