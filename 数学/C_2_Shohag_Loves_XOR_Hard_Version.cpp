#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
void solve(){
    ll x,m;
    cin>>x>>m;
    ll ans=0;
    for(int y=1;y<=min(x-1,m);y++){
        if((y^x)%y==0){
            ans++;
        }
    }
    // x-y<=x^y<=x+y
    // x|(x^y) ----> i*x==x^y ----> y=(i*x)^x 
    // (i-1)*x <= y <= (i+1)*x
    // 1 <= y <= m  
    // j=(m/x) i+1<=j  一定可以 i<=j-1
    // i属于[0，j-1]
    // i==1 的时候 y=0 不符合要求
    ans+=m/x;//[0,j-1]一共j个
    if(m/x-1>=1)ans--;//[0,j-1]不能等于1，就要去掉1
    for(ll i=m/x;i<=m/x+1;i++){//判断j和j+1
        ll y=((x*i)^x);
        if(y<=m&&y>=1)ans++;
    }
    cout<<ans<<'\n';



    // ll res=0;
	// for(int y=1;y<=m;y++){
    //     if((x^y)%x==0||(x^y)%y==0){
    //         res++;
    //         if((x^y)%x==0&&(x^y)%y!=0){
    //             cout<<"X:"<<'\n';
    //             cout<<x<<" "<<y<<" "<<(x^y)<<'\n';
    //         }
    //         if((x^y)%x!=0&&(x^y)%y==0){
    //             cout<<"Y:"<<'\n';
    //             cout<<x<<" "<<y<<" "<<(x^y)<<'\n';
    //         }
    //         if((x^y)%x==0&&(x^y)%y==0){
    //             cout<<"X && Y"<<'\n';
    //             cout<<x<<" "<<y<<" "<<(x^y)<<'\n';
    //         }
    //     }
    // }
    // cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
