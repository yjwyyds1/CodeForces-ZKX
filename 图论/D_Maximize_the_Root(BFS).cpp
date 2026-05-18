// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// vector<ll> a(N),f(N);
// vector<vector<int>> e(N);
// ll ans;
// void dfs(int u,int f){
//     if(e[u].empty()){
//         f[u]=a[u];
//         return ;
//     }
//     ll mi=1e18;
//     for(auto v:e[u]){
//         if(v==f)continue;
//         dfs(v,u);
//         mi=min(mi,f[v]);
//     }
//     if(mi[u]==1e18)mi[u]=a[u];
//     if(mi[u]>a[u]&&u!=1)mi[u]=(mi[u]+a[u])/2;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int _;
//     cin>>_;
//     while (_--)
//     {
//         int n;
//         cin>>n;
//         for(int i=1;i<=n;i++){
//             e[i].clear();
//         }
//         for(int i=1;i<=n;i++){
//             cin>>a[i];
//         }
//         for(int i=2;i<=n;i++){
//             int x;
//             cin>>x;
//             e[x].push_back(i);
//         }
//         ans=0;
//         dfs(1,0);
//         cout<<ans+a[1]<<'\n';
        
//     }
    
    
//     return 0;
// }
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        vector<ll> a(n+10),d(n+10,0),mi(n+10,1e18),f(n+10,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            f[i]=x;
            d[x]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!d[i]){
                q.push(i);
                mi[i]=a[i];
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(t==1){
                break;
            }

            if(a[t]<mi[t]){
                a[t]=mi[t]+a[t]>>1;
            }
            else{
                a[t]=mi[t];
            }
            mi[f[t]]=min(mi[f[t]],a[t]);
            d[f[t]]--;
            if(!d[f[t]]){
                q.push(f[t]);
            }
        }
        cout<<a[1]+mi[1]<<'\n';
    }
    return 0;
}