#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
struct vc{
    int v;
    int w;
    bool operator <( const vc &x )const
    {
        return x.w < w;
    }
};
int d[N],vis[N];
int n,m,s;
vector<vector<vc>> e(N);

void dijkstra(int x){
    priority_queue<vc> q;//小根堆优化 O(nlog(n))
    for(int i=0;i<=n;i++) d[i]=INT_MAX;
    d[x]=0;
    q.push({x,0});
    while(!q.empty())
    {
        int xv=q.top().v;
        q.pop();
        if(vis[xv]){
            continue;
        }
        vis[xv]=1;
        for(auto k:e[xv]){
            if(d[k.v]>d[xv]+k.w){
                d[k.v]=d[xv]+k.w;
                if(!vis[k.v]){
                    q.push({k.v,d[k.v]});
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){//O(n^2) 
    //     int u=0;
    //     for(int j=1;j<=n;j++){
    //         if(!vis[j]&&d[j]<d[u])u=j;
    //     }
    //     vis[u]=1;
    //     for(auto k:e[u]){
    //         if(d[k.v]>d[u]+k.w){
    //             d[k.v]=d[u]+k.w;
    //         }
    //     }
    // }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    cout<<'\n';
    return 0;
}