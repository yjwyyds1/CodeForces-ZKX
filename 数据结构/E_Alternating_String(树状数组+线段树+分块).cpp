// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// const int N=5e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// int a[N],t[N];
// int n,q;
// int lowbit(int x){树状数组
//     return x&(-x);
// }
// void change(int x,int a){
//     while(x<=n){
//         t[x]+=a;
//         x+=lowbit(x);
//     }
//     return;
// }
// int query(int x){
//     int res=0;
//     while(x){
//         res+=t[x];
//         x-=lowbit(x);
//     }
//     return res;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>q;
//     string s;
//     cin>>s;
//     s='%'+s;
//     for(int i=1;i<n;i++){
//         a[i]=(s[i]!=s[i+1]);
//     }
//     for(int i=1;i<n;i++){
//         change(i,a[i]);
//     }
//     for(int i=1;i<=q;i++){
//         int op,L,R;
//         cin>>op>>L>>R;
//         if(op==1){
//             if(L>1){
//                 change(L-1,-a[L-1]);
//                 a[L-1]^=1;
//                 change(L-1,a[L-1]);
//             }
//             if(R<n){
//                 change(R,-a[R]);
//                 a[R]^=1;
//                 change(R,a[R]);
//             }
//         }
//         else{
//             if(L==R||query(R-1)-query(L-1)==R-L){
//                 cout<<"Yes"<<'\n';
//             }
//             else{
//                 cout<<"No"<<'\n';                
//             }
//         }
//     }
    
//     return 0;
// }
// int _;
// cin>>_;
// while (_--)
// {
    
// }
// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n,q;
//     cin>>n>>q;
//     string a;
//     cin>>a;
//     a='$'+a;
//     set<int> s;
//     for(int i=1;i<n;i++){
//         if(a[i]==a[i+1]){
//             s.insert(i);
//         }
//     }
//     for(int i=1;i<=q;i++){
//         int op,L,R;
//         cin>>op>>L>>R;
//         if(op==1){
//             if(s.find(L-1)==s.end())s.insert(L-1);
//             else{
//                 s.erase(L-1);
//             }
//             if(s.find(R)==s.end())s.insert(R);
//             else{
//                 s.erase(R);
//             }
//         }   
//         else{
//             auto x=s.lower_bound(L);
//             if(x==s.end()||*x>=R)cout<<"Yes"<<'\n';
//             else{
//                 cout<<"No"<<'\n';
//             }
//         }
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
        
    }
    
    
    return 0;
}