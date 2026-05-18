#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> e(n+10);
    for(int i=1;i<=m;i++){
        int v,u,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,-w});
    }
    vector<int> vis(n+1,0);
    vector<ll> ans(n+1);
    function<void(int, ll)> dfs = [&](int v, ll k) -> void 
    {
        for(auto x:e[v]){
            int u=x.first;
            int w=x.second;
            if(!vis[u]){
                vis[u]=1;
                ans[u]=k+w;
                dfs(u,ans[u]);
            }
        }
        return ;
    };
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            ans[i]=0;
            dfs(i,ans[i]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}