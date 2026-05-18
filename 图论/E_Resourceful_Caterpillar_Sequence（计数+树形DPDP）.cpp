#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        vector<vector<int>> e(n+1);
        vector<ll> d(n+1,0),f(n+1,0),dep(n+1,1),cnt(n+1);
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
            d[x]++,d[y]++;
        }
        ll ans=0,g=0;
        for(int i=1;i<=n;i++){
            g+=(d[i]==1);
        }
        ans+=(n-g)*g;
        for(int i=1;i<=n;i++){
            for(auto x:e[i]){
                if(d[x]==1){
                    f[i]=1;
                    break;
                }
            }
        }
        function<void(int, int)> dfs = [&](int x, int fa){
            cnt[x]=(d[x]>1&&!f[x]);
            for(auto y:e[x]){
                if(y==fa)continue;
                dep[y]+=dep[x]+1;
                dfs(y,x);
                cnt[x]+=cnt[y];
            }
        };
        dfs(1,0);
        for(int i=1;i<=n;i++){
            if(d[i]>1){
                for(auto j:e[i]){
                    if(f[j]){
                        ans+=(dep[j]>dep[i]?cnt[j]:cnt[1]-cnt[i]);
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
