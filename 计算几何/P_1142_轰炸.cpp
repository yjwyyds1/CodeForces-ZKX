// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// #define ld long double 
// using namespace std;
// const int N=3e5+10;
// const int inf = 0x3f3f3f3f;
// // cout<<fixed<<setprecision(0)
// struct vc{
//     ll x,y;
// }a[N];
// struct line
// {
//     ll A,B,C;
//     bool operator < (const line& x)const{
//         if(A!=x.A){
//             return A<x.A;
//         }
//         else if(B!=x.B){
//             return B<x.B;
//         }
//         else if(C!=x.C){
//             return C<x.C;
//         }
//     }
// };
// tuple<int,int,int> f(ll x1,ll y1,ll x2,ll y2){
//     ll Ap=y1-y2;
//     ll Bp=x1-x2;
//     ll Cp=x2*y1-x1*y2;
//     ll d=__gcd(Ap,Bp);
//     d=__gcd(d,Cp);
//     Ap/=d;
//     Bp/=d;
//     Cp/=d;
//     tuple<int,int,int> res={Ap,Bp,Cp};
//     return res;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>a[i].x>>a[i].y;
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         int res=0;
//         map<tuple<int,int,int>,int> mp;
//         for(int j=1;j<=n;j++){
//             if(i==j)continue;
//             tuple<int,int,int> p=f(a[j].x,a[j].y,a[i].x,a[i].y);
//             // cout<<get<0>(p)<<" "<<get<1>(p)<<" "<<get<2>(p)<<'\n';
//             mp[p]++;
//             res=max(res,mp[p]);
//         }
//         ans=max(res,ans);
//     }
//     cout<<ans+1<<'\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double 
using namespace std;
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
// cout<<fixed<<setprecision(0)
struct vc{
    ll x,y;
}a[N];
struct line
{
    ll A,B,C;
    bool operator< (const line& x)const{
        if(A!=x.A){
            return A<x.A;
        }
        else if(B!=x.B){
            return B<x.B;
        }
        else if(C!=x.C){
            return C<x.C;
        }
        return false;
    }
};
line f(ll x1,ll y1,ll x2,ll y2){
    ll Ap=y1-y2;
    ll Bp=x1-x2;
    ll Cp=x2*y1-x1*y2;
    ll d=__gcd(Ap,Bp);
    d=__gcd(d,Cp);
    Ap/=d;
    Bp/=d;
    Cp/=d;
    line res={Ap,Bp,Cp};
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=0;
        map<line,int> mp;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            line p=f(a[j].x,a[j].y,a[i].x,a[i].y);
            // cout<<p.A<<" "<<p.B<<" "<<p.C<<'\n';
            mp[p]++;
            res=max(res,mp[p]);
        }
        ans=max(res,ans);
    }
    cout<<ans+1<<'\n';
    return 0;
}



