#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(m,vector<int>(n));
        vector<vector<int>>e(n+1);
        vector<int>d(n+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(j>=2){
                    e[a[i][j-1]].push_back(a[i][j]);
                    d[a[i][j]]++;
                }
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++)if(!d[i])q.push(i);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int t=q.front();
            q.pop();
            for(auto v:e[t]){
                d[v]--;
                if(!d[v]){
                    q.push(v);
                }
            }
        }
        cout<<(cnt==n?"YES":"NO")<<'\n';
    }
    return 0;
}




// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
// using ld = long double;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int _;
//     cin>>_;
//     while(_--){
//         int n,m;
//         cin>>n>>m;
//         vector<vector<int>> a(m,vector<int>(n));
//         map<int,int>mp,f;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cin>>a[i][j];
//                 if(j==0)f[a[i][j]]=i;
//                 if(j==1){
//                     mp[a[i][j]]++;
//                 }
//             }
//         }
//         if(m==1){
//             cout<<"YES"<<'\n';
//         }
//         else if(m==2){
//             int x=a[0][0],y=a[1][0];
//             vector<vector<int>> k(2,vector<int>(n));
//             for(int i=0;i<m;i++){
//                 for(int j=0;j<n;j++){
//                     if(a[i][j]==x||a[i][j]==y)continue;
//                     else{
//                         k[i].push_back(a[i][j]);
//                     }
//                 }
//             }
//             cout<<(k[1]==k[0]?"YES":"NO")<<'\n';
//         }
//         else{
//             vector<int> ans;
//             for(int i=1;i<=n;i++){
//                 if(mp[i]==m-1){
//                     ans=a[f[i]];
//                     break;
//                 }
//             }
//             // if(ans.empty()){
//             //     cout<<"NO"<<'\n';
//             // }
//             else{
//                 int ok=1;
//                 for(int i=0;i<m;i++){
//                     vector<int> p;
//                     p.push_back(a[i][0]);
//                     for(int j=0;j<n;j++){
//                         if(ans[j]==a[i][0])continue;
//                         else{
//                             p.push_back(ans[j]);
//                         }
//                     }
//                     if(p!=a[i]){
//                         ok=0;
//                     }
//                 }
//                 cout<<(ok?"YES":"NO")<<'\n';
//             }
//         }
//     }
//     return 0;
// }