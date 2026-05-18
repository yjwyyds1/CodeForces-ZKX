#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using ll =long long int;
using ld =long double;
using namespace std;
// 叉乘
struct P{
    ll x,y;
};
ll cross(P a, P b)
{
    return a.x * b.y - a.y * b.x;
}

// 点积
ll mul(P a, P b)
{
    return a.x * b.x + a.y * b.y;
}

// 点平方和
ll mul(P a)
{
    return a.x * a.x + a.y * a.y;
}

// 计算矢量
P del(P a, P b)
{
    return {a.x - b.x, a.y - b.y};
}
bool f(ll a,ll b,ll c){
    __int128 a1=a;
    __int128 b1=b;
    __int128 c1=c;
    return a1*a1<b1*c1*c1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n;
        ll OR;
        cin>>n;
        P O;
        cin>>O.x>>O.y>>OR;
        // cout<<R<<'\n';
        vector<P> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y;
        }
        ll ans=0;
        ll s=0;
        for(int L=0,R=L+1;L<n;L++){
            while(1){
                int r=(R+1)%n;
                ll c=cross(del(a[r],a[L]),del(O,a[L]));
                // cout<<'\n';
                // cout<<L<<" "<<R<<" "<<r<<'\n';
                // cout<<"dian:"<<'\n';
                // cout<<del(a[r],a[L]).x<<" "<<del(a[r],a[L]).y<<'\n';
                // cout<<del(O,a[L]).x<<" "<<del(O,a[L]).y<<'\n';
                // cout<<'\n';

                // cout<<L<<" "<<R<<" "<<r<<" "<<"S:"<<c<<'\n';
                if(c<=0){
                    break;
                }
                // cout<<c*c<<" "<<mul(del(a[r],a[L]))<<" "<<OR*OR<<'\n';
                if(f(c,mul(del(a[r],a[L])),OR)){
                    break;
                }
                s+=cross(del(a[R],a[L]),del(a[r],a[L]));
                // cout<<'\n';
                // cout<<L<<" "<<R<<" "<<r<<" "<<s<<'\n';
                R=r;
            }
            ans=max(ans,s);
            int l=(L+1)%n;
            s-=cross(del(a[R],a[L]),del(a[R],a[l]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}