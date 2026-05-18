#include <bits/stdc++.h>
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;

vector<vector<ll>> f(N,vector<ll>(60,0));
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            for(int i=1;i<=50;i++){
                f[v][i]=(f[parent[v]][i]+qmi(dep[v],i))%mod;
            }
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    // void DFS(int u,int p){
    //     for(auto v:adj[u]){
    //         f[v][p]=(f[u][p]+qmi(dep[v],p))%mod;
    //         DFS(v,p);
    //     }
    // }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    // freopen("zkx.in","r",stdin);
	// freopen("zkx.out","w",stdout);
    int n;
    cin>>n;
    HLD a(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        a.addEdge(u,v);
    }
    a.work(1);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y,k;
        cin>>x>>y>>k;
        // cout<<((f[x][k]+f[y][k])%mod-(f[a.lca(x,y)][k]+f[a.parent[a.lca(x,y)]][k])%mod+mod)%mod<<'\n';
        if(a.lca(x,y)==1){
            cout<<((f[x][k]+f[y][k])%mod-(2*f[a.lca(x,y)][k])%mod+mod)%mod<<'\n';
        }
        else{
            cout<<((f[x][k]+f[y][k])%mod-(f[a.lca(x,y)][k]+f[a.parent[a.lca(x,y)]][k])%mod+mod)%mod<<'\n';
        }
    }
    
    return 0;
}
