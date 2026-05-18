#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
struct vc{
    ll to;
    ll c;
    ll d;
};

void solve(){
	int n,m;
    cin>>n>>m;
    vector<vector<vc>>e(n+1);
    for(int i=1;i<=m;i++){
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        e[u].push_back({v,c,d});
        e[v].push_back({u,c,d});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    vector<ll> dis(n+10,1e18);
    vector<ll> v(n+10,0);
    dis[1]=0;
    while(!q.empty()){
        ll x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(auto [to,c,d]:e[x]){
            vector<ll> p;
            p.push_back((int)(sqrt(d)-(dis[x]+1)));
            p.push_back((int)(sqrt(d)-(dis[x]+1))-1);
            p.push_back((int)(sqrt(d)-(dis[x]+1))+1);
            p.push_back((int)(sqrt(d)+(dis[x]+1)));
            p.push_back((int)(sqrt(d)+(dis[x]+1))-1);
            p.push_back((int)(sqrt(d)+(dis[x]+1))+1);
            ll T=dis[x]+c+d/(dis[x]+1);
            for(int i=0;i<6;i++){
                if(p[i]<0)continue;
                else{
                    T=min(dis[x]+p[i]+c+d/(dis[x]+p[i]+1),T);
                }
            }
            
            if(dis[to]>T){
                dis[to]=T;
                q.push({T,to});
            }
        }
    }
    if(dis[n]==1e18){
        cout<<-1<<'\n';
    }
    else{
        cout<<dis[n]<<'\n';
    }
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
