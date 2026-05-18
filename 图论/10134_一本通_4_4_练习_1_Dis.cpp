#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq , c;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<pair<int,int>>> L;
    int cur,d;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        c.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        d = 0;
        adj.assign(n, {});
        L.assign(n,{});
    }
    void addEdge(int u, int v, int k) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        L[u].push_back({v,k});
        L[v].push_back({u,k});
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
        dfs3(root,0);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
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
    void dfs3(int u,int fa) {
        for(auto v:L[u]){
            if(v.first==fa){
                continue;
            }
            d+=v.second;
            c[v.first]=d;
            dfs3(v.first,u);
            d-=v.second;
        }
    }
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
    int n,m;
    cin>>n>>m;
    HLD a(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,k;
        cin>>u>>v>>k;
        a.addEdge(u,v,k);
    }
    a.work(1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        cout<<a.c[x]+a.c[y]-2*a.c[a.lca(x,y)]<<'\n';
    }

    
    return 0;
}
