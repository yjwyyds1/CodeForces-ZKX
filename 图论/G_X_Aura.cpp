#include <bits/stdc++.h>
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


ll f(ll x,ll q){
    ll ans=1;
    for(int i=1;i<=q;i++){
        ans=x*ans;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> a(n+10,vector<ll>(m+10));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char p;
            cin>>p;
            a[i][j]=p-'0';
            // cout<<a[i][j]<<" ";
        }
    }
    int ok=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            ll S=f(a[i][j]-a[i][j+1],k)+f(a[i][j+1]-a[i+1][j+1],k)+f(a[i+1][j+1]-a[i+1][j],k)+f(a[i+1][j]-a[i][j],k);
            // cout<<f(a[i][j+1]-a[i][j],k)<<" "<<f(a[i+1][j+1]-a[i][j+1],k)<<" "<<f(a[i+1][j]-a[i+1][j+1],k)<<" "<<f(a[i+1][j]-a[i][j],k)<<'\n';
            if(S!=0){
                ok=0;
                break;
            }
        }
        if(ok==0)break;
    }
    vector<vector<ll>> d(n+10,vector<ll>(m+10,0));
    if(ok){
        for(int i=2;i<=n;i++){
            d[i][1]=d[i-1][1]+f(a[i-1][1]-a[i][1],k);
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=m;j++){
                d[i][j]=d[i][j-1]+f(a[i][j-1]-a[i][j],k);
            }
        }
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(ok==0){
            cout<<"INVALID"<<'\n';
        }
        else{
            cout<<d[x2][y2]-d[x1][y1]<<'\n';
        }
    }
    return 0;
}
