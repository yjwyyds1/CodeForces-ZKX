#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
vector<vector<int>> e(N),c(N);
int in[N],out[N],dep[N];
int t=0;
void dfs(int x){
    in[x]=t++;
    c[dep[x]].push_back(in[x]);
    for(auto y:e[x]){
        dep[y]=dep[x]+1;
        dfs(y);
    }
    out[x]=t++;
}
void solve(){
	int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        e[p].push_back(i);
    }
    dfs(1);
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;i++){
        int u,d;
        cin>>u>>d;
        int L=lower_bound(c[d].begin(),c[d].end(),in[u])-c[d].begin();
        int R=lower_bound(c[d].begin(),c[d].end(),out[u])-c[d].begin();
        cout<<R-L<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
