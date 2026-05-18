#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
int  k[N],x[N],y[N],a[N],sum[N],low[N],vis[N],dfn[N];
vector<vector<int>> v(N);
stack<int> s;
int t=0,num=0;
void tarjan(int x){
    dfn[x]=low[x]=++t;
    s.push(x);
    vis[x]=1;
    for(auto y:v[x])
    {
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(dfn[y]){
            low[x]=min(low[x],low[y]);
        }
    }
    if(low[x]==dfn[x]){
        num++;
        while(s.top()!=x){
            a[s.top()]=num;
            sum[num]+=k[s.top()];
            vis[s.top()]=0;
            s.pop();
        }
        a[x]=num;
        sum[num]+=k[x];
        vis[x]=0;
        s.pop();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        v[x[i]].push_back(y[i]);    
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    return 0;
}