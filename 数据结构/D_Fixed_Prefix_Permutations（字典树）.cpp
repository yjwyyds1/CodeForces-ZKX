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
        
    }
    return 0;
}
// #include <bits/stdc++.h>
// const int N=1e5+10;
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
//         bitset<N> ds[11][11],res;
//         vector<vector<int>> a(n+1,vector<int>(m+1));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 cin>>a[i][j];
//                 ds[j][a[i][j]].set(i);
//             }
//         }
//         for(int i=1;i<=n;i++){
//             int ans=0;
//             res.set();
//             for(int j=1;j<=m;j++){
//                 res&=ds[a[i][j]][j];
//                 if(res.any()){
//                     ans=j;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             cout<<ans<<" ";
//         }
//         cout<<'\n';
        
//     }
//     return 0;
// }
// int a[N][20];
// int p[20];
// set<vector<int>> s[20];
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=m;j++){
//         cin>>a[i][j];
//         p[a[i][j]]=j;
//     }
//     for(int j=1;j<=m;j++){
//         s[j].emplace(p + 1 , p + j + 1);
//     }
// }
// for(int i=1;i<=n;i++){
//     int k=0;
//     for(int j=m;j;j--){
//         if(s[j].contains(vector<int>(a[i]+1,a[i]+1+j))){
//             k=j;
//             break;
//         }
//     }
//     cout<<k<<" ";
// }
// cout<<'\n';