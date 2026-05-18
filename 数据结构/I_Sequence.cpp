#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(n+1,1));
    vector<vector<int>> f(n+1,vector<int>(n+1,1));
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=0;
        f[x][y]=0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j])f[i][j]+=f[i-1][j];
            else{
                f[i][j]=0;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll S=0;
        stack<pair<ll,ll>> s;
        for(int j=1;j<=n;j++){
            ll len=1;
            while((!s.empty()&&s.top().first>=f[i][j])){
                len+=s.top().second;
                S-=(s.top().first*s.top().second);
                s.pop();
            }
            S+=f[i][j]*len;
            s.push({f[i][j],len});
            ans+=S;
        }
    }
    cout<<ans<<'\n';
    return 0;
}