#include <bits/stdc++.h>
const int N=3010;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
vector<vector<int>> e(N);
vector<int> dis1(N,1e9);
vector<int> dis2(N,1e9);
vector<int> dis3(N,1e9);
void dij1(int s){
    queue<int> q;
    dis1[s]=0;
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto y:e[t]){
            if(dis1[t]+1<dis1[y]){
                dis1[y]=dis1[t]+1;
                q.push(y);
            }
        }
    }
}
void dij2(int s){
    queue<int> q;
    dis2[s]=0;
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto y:e[t]){
            if(dis2[t]+1<dis2[y]){
                dis2[y]=dis2[t]+1;
                q.push(y);
            }
        }
    }
}
void dij3(int s){
    queue<int> q;
    dis3[s]=0;
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto y:e[t]){
            if(dis3[t]+1<dis3[y]){
                dis3[y]=dis3[t]+1;
                q.push(y);
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    int s1,t1,s2,t2;
    cin>>s1>>t1>>s2>>t2;
    dij1(1);
    if(dis1[s1]>t1||dis1[s2]>t2){
        cout<<-1;
    }
    else{
        dij2(s1);
        dij3(s2);
        int ans=1e9;
        for(int i=1;i<=n;i++){
            if(dis1[i]+dis2[i]<=t1&&dis1[i]+dis3[i]<=t2){
                ans=min(dis1[i]+dis2[i]+dis3[i],ans);
            }
        }
        cout<<m-ans;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
	// freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
