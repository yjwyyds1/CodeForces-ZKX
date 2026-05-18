// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// const int mod = 998244353;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
// using ld = long double;
// vector<vector<pair<int,int>>> e(410);
// vector<vector<ll>> dis(410,vector<ll>(410,1e18));
// vector<vector<ll>> f(410,vector<ll>(410,-1));
// void dij(int x){
//     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
//     q.push({0,x});
//     vector<int>v(410,0);
//     dis[x][x]=0;
//     while(!q.empty()){
//         ll t=q.top().second;
//         // cout<<q.top().first<<" "<<q.top().second<<'\n';
//         // cout<<dis[x][t]<<" "<<x<<" "<<t<<'\n';
//         q.pop();
//         if(v[t])continue;
//         v[t]=1;
//         for(auto [L,y]:e[t]){
//             if(dis[x][y]>dis[x][t]+L){
//                 if(f[x][t]==-1){
//                     f[x][y]=0;
//                 }
//                 else{
//                     f[x][y]=max(f[x][t],t);
//                 }
//                 dis[x][y]=dis[x][t]+L;
//                 q.push({dis[x][y],y});
//             }
//         }

//     }
// }
// void solve(){
// 	int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=m;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         e[a].push_back({c,b});
//     }
//     for(int i=1;i<=n;i++){
//         dij(i);
//     }
//     ll ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             // cout<<dis[i][j]<<" ";
//             // cout<<f[i][j]<<" ";
//             if(dis[i][j]!=1e18){
//                 if(f[i][j]<=0){
//                     ans+=dis[i][j]*n;
//                 }
//                 else{
//                     ans+=dis[i][j]*(n-f[i][j]+1);
//                 }
//             }
//             // -1 0 5 0 0 
//             // 0 -1 0 0 0 
//             // 0 0 -1 0 1 
//             // 0 3 0 -1 1 
//             // 0 0 0 0 -1
            
//             // 0 6 7 4 1 
//             // 5 0 9 8 6 
//             // 5 1 0 7 6 
//             // 4 5 4 0 5 
//             // 2 5 6 5 0 

//             // 0 6 7 4 1 
//             // 5 0 9 8 6 
//             // 5 1 0 7 6 
//             // 4 5 4 0 5 
//             // 2 5 6 5 0 
//         }
//         cout<<'\n';
//     }
//     cout<<ans;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// 	//  freopen("zkx.in","r",stdin);
// 	//  freopen("zkx.out","w",stdout);
//     int _;
//     _=1;
//     // cin>>_;
//     while(_--){
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
// const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
const int N = 410;
ll  n, m, d[N][N];
ll ans=0;
void floyd() {
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if(d[i][j]<inf)ans+=d[i][j];
            }
                
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = inf;
    while (m --) {
        ll x, y, w; cin >> x >> y >> w;
        d[x][y] = min(d[x][y], w);
    }
    floyd();
    cout<<ans;
    // for (int i = 1; i <= n; ++ i) {
    //     for (int j = 1; j <= n; ++ j) {
    //         if (d[i][j] > inf / 2) cout << "N" << endl;
    //         else cout << d[i][j] << endl;
    //     }
    // }
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
