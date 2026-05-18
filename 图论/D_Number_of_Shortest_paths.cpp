#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
vector<vector<pair<ll,ll>>> e(N);
vector<ll> dis(N,1e18),dp(N,0),Dis(N,1e18);
void dij(){
    using PII=pair<ll,ll>;
    vector<ll> v(N,0);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    dis[1]=0;
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [L,y]:e[t]){
            if(dis[y]>dis[t]+L){
                dis[y]=dis[t]+L;
                q.push({dis[y],y});
            }
        }
    }
}
void Dij(){
    using PII=pair<ll,ll>;
    vector<ll> v(N,0);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    dp[1]=1;
    Dis[1]=0;
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [L,y]:e[t]){
            if(Dis[y]>=Dis[t]+L){
                Dis[y]=Dis[t]+L;
                if(Dis[y]==dis[y]){
                    dp[y]=(dp[y]+dp[t])%mod;
                }
                q.push({Dis[y],y});
            }
        }
    }
}
void solve(){
	int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>u>>v;
        e[u].push_back({1,v});
        e[v].push_back({1,u});
    }
    dij();
    // for(int i=1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<'\n';
    Dij();
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<'\n';
    cout<<dp[n]%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
