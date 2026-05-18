#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=min(dp[u][v],w);
        dp[v][u]=min(dp[v][u],w);
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}