#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
int dp[5000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n,k;
    cin>>n>>k;
    int v[n+1],w[n+1];
    for(int i=1;i<=n;i++)  cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=k;j++)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[k]<<'\n';
    return 0;
}