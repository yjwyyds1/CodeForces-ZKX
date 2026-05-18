#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
int c[5000][5000];
void in()
{
    for(int i=0;i<3000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j)c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    in();
    ll _;
    cin>>_;
    while(_--)
    {
        int a,b;
        cin>>a>>b;
        cout<<c[a][b]<<'\n';
    }
    
    return 0;
}

