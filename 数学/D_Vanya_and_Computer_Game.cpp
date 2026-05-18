// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     ll n,x,y;
//     cin>>n>>x>>y;
//     ll d=gcd(x,y);
//     x/=d;
//     y/=d;
//     vector<pair<ll,ll>> ans(x+y+10);
//     for(ll i=1;i<=x;i++){
//         ans[i]={i*y,1};
//     }
//     for(ll i=1;i<=y;i++){
//         ans[i+x]={i*x,2};
//     }
//     sort(ans.begin()+1,ans.begin()+x+y+1);
//     vector<string> f(ans.size());
//     for(int i=1;i<=x+y-2;i++){
//         if(ans[i].second==1) f[i]="Vanya";
// 		else f[i]="Vova";                                                                                                           
//     }
//     f[x+y-1]=f[0]="Both";
//     for(int i=1;i<=n;i++){
//         int m;
//         cin>>m;
//         cout<<f[m%(x+y)]<<'\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        ll L=1,R=2e16;
        while(L<R){
            ll mid=L+R>>1;
            if(mid/x+mid/y>=t)R=mid;
            else{
                L=mid+1;
            }
        }
        if(L%x==0&&L%y==0)cout<<"Both"<<'\n';
        else if(L%x==0)cout<<"Vova"<<'\n';
        else cout<<"Vanya"<<'\n';
    }
    return 0;
}