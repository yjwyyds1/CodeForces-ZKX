// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// vector<ll> w(N),f(N,1e18);
// vector<ll> s[N];

// ll dfs(int x){
//     if(f[x]<1e18) return f[x];
//     f[x]=w[x];
//     ll sum=0;
//     for(auto y:s[x]){
//         sum+=dfs(y);
//     }
//     if(s[x].empty()) sum=1e18;
//     f[x]=min(sum,f[x]);
//     return f[x];
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int _;
//     cin>>_;
//     while (_--)
//     {
//         int n,m;
//         cin>>n>>m;
//         for(int i=1;i<=n;i++){
//             cin>>w[i];
//             s[i].clear();
//             f[i]=1e18;
//         }
//         for(int i=1;i<=m;i++){
//             int x;
//             cin>>x;
//             f[x]=0;
//         }
//         for(int i=1;i<=n;i++){
//             int t;
//             cin>>t;
//             for(int j=1;j<=t;j++){
//                 int p;
//                 cin>>p;
//                 s[i].push_back(p);
//             }
//         }
//         for(int i=1;i<=n;i++){
//             cout<<dfs(i)<<" ";
//         }
//         cout<<'\n';
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
        int n,m;
        cin>>n>>m;
        ll a[n+1];
        vector<vector<int>> e(n+1);
        vector<int> d(n+1,0);
        vector<ll> f(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            a[x]=0;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            int p;
            cin>>p;
            for(int j=1;j<=p;j++){
                int v;
                cin>>v;
                e[v].push_back(i);
                d[i]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(!d[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(auto k:e[t]){
                d[k]--;
                f[k]+=a[t];
                if(!d[k]){
                    a[k]=min(a[k],f[k]);
                    q.push(k);
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}