#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
struct HLD
{
	int n;
	std::vector<int> siz, top, dep, fa, L, R, id;
	std::vector<std::vector<int>> adj;
	int cur;
 
	HLD() {}
	HLD(int n)
	{
		init(n);
	}
 
	void init(int n)
	{
		this->n = n;
		siz.resize(n);
		top.resize(n);
		dep.resize(n);
		fa.resize(n);
		L.resize(n);
		R.resize(n);
		id.resize(n);
 
		cur = 0;
		adj.assign(n, {});
	}
 
	void add(int u, int v)
	{
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
 
	void work(int root = 0)
	{
		top[root] = root;
		dep[root] = 0;
		fa[root] = -1;
		dfs1(root);
		dfs2(root);
	}
 
	void dfs1(int x)
	{	
		if(fa[x] != -1)
			adj[x].erase(std::find(adj[x].begin(), adj[x].end(), fa[x]));
 
		siz[x] = 1;
		for(auto &y : adj[x])
		{
			fa[y] = x;
			dep[y] = dep[x] + 1;
			dfs1(y);
 
			siz[x] += siz[y];
			if(siz[y] > siz[adj[x][0]]) std::swap(y, adj[x][0]);
		}
	}
 
	void dfs2(int x)
	{
		L[x] = cur++;
		id[L[x]] = x;
 
		for(auto y : adj[x])
		{
			top[y] = (y == adj[x][0] ? top[x] : y);
			dfs2(y);
		}
		R[x] = cur;
	}
 
	int lca(int x, int y)
	{
		while(top[x] != top[y])
		{
			if(dep[top[x]] > dep[top[y]]) x = fa[top[x]];
			else y = fa[top[y]];
		}
 
		return dep[x] < dep[y] ? x : y;
	}
 
	int dist(int x, int y)
	{
		return dep[x] + dep[y] - 2 * dep[lca(x, y)];
	}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        
        int n,q;
        cin>>n>>q;
        HLD tr(n);

        vector<int> a(n);
        for(int i=1;i<n;i++){
            cin>>a[i];
            a[i]--;
            tr.add(a[i],i);
        }

        tr.work();
        vector<int> good(n);
        vector<int> p(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
            p[i]--;
        }

        int cnt=0;
        auto ck = [&](int x) -> void
        {
            cnt -= good[x];
            good[x] = (tr.fa[p[x + 1]] == tr.lca(p[x], p[x + 1]));
            cnt += good[x];
        };
        for(int i=0;i+1<n;i++){
            ck(i);
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            swap(p[x],p[y]);
            if(x+1<n) ck(x);
            if(x) ck(x-1);
            if(y+1<n) ck(y);
            if(y) ck(y-1);
            if(cnt==n-1){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }  
    }
    
    
    return 0;
}

// struct HLD {
//     int n;
//     std::vector<int> siz, top, dep, parent, in, out, seq;
//     std::vector<std::vector<int>> adj;
//     int cur;
    
//     HLD() {}
//     HLD(int n) {
//         init(n);
//     }
//     void init(int n) {
//         this->n = n;// n：树的节点数
//         siz.resize(n);// siz：每个节点子树的大小
//         top.resize(n);// top：每个节点所属链的顶部节点
//         dep.resize(n);// dep：每个节点的深度
//         parent.resize(n);// parent：每个节点的父节点
//         in.resize(n);// in 和 out：每个节点在链中的开始和结束时间戳
//         out.resize(n);
//         seq.resize(n);// seq：链上的节点序列。
//         cur = 0;// cur：时间戳计数器，用于在 dfs2 中分配 in 值
//         adj.assign(n, {});// adj：邻接表，用于存储树的结构
//     }
//     void addEdge(int u, int v) {
//         adj[u].push_back(v);// addEdge(int u, int v)：在节点 u 和 v 之间添加一条无向边
//         adj[v].push_back(u);
//     }
//     void work(int root = 0) {
//         top[root] = root;
//         dep[root] = 0;
//         parent[root] = -1;
//         dfs1(root);//work(int root = 0):从 root 节点开始执行 HLD初始化节点的 top、dep 和 parent 信息,
//         dfs2(root);//然后调用 dfs1 和 dfs2 进行深度优先搜索，完成 HLD 剖分
//     }
//     void dfs1(int u) {//dfs1(int u):计算每个节点的子树大小 siz,确定重链（子树最大）的重儿子,并调整 adj 以去掉父节点的影响
//         if (parent[u] != -1) {
//             adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
//         }
//         siz[u] = 1;
//         for (auto &v : adj[u]) {
//             parent[v] = u;
//             dep[v] = dep[u] + 1;
//             dfs1(v);
//             siz[u] += siz[v];
//             if (siz[v] > siz[adj[u][0]]) {
//                 std::swap(v, adj[u][0]);
//             }
//         }
//     }
//     void dfs2(int u) {//dfs2(int u):为每个节点分配 in 和 out 时间戳,并记录节点在链中的序列 seq,更新每个节点的 top 和链的结束时间 out
//         in[u] = cur++;
//         seq[in[u]] = u;
//         for (auto v : adj[u]) {
//             top[v] = v == adj[u][0] ? top[u] : v;
//             dfs2(v);
//         }
//         out[u] = cur;
//     }
//     int lca(int u, int v) {//lca(int u, int v):计算节点 u 和 v 的最近公共祖先（LCA）沿着链向上移动,直到 u 和 v 在同一链上
//         while (top[u] != top[v]) {
//             if (dep[top[u]] > dep[top[v]]) {
//                 u = parent[top[u]];
//             } else {
//                 v = parent[top[v]];
//             }
//         }
//         return dep[u] < dep[v] ? u : v;
//     }
    
//     int dist(int u, int v) {//dist(int u, int v):计算 u 和 v 之间的距离,利用 LCA 和节点深度计算距离
//         return dep[u] + dep[v] - 2 * dep[lca(u, v)];
//     }
    
//     int jump(int u, int k) {//jump(int u, int k)从节点 u 向上跳跃 k 步,利用 dep 和 top 确定跳跃的路径,并返回跳跃后的节点
//         if (dep[u] < k) {
//             return -1;
//         }
        
//         int d = dep[u] - k;
        
//         while (dep[top[u]] > d) {
//             u = parent[top[u]];
//         }
        
//         return seq[in[u] - dep[u] + d];
//     }
    
//     bool isAncester(int u, int v) {//isAncester(int u, int v):判断节点 u 是否是节点 v 的祖先,通过比较 in 和 out 时间戳来确定
//         return in[u] <= in[v] && in[v] < out[u];
//     }
    
//     int rootedParent(int u, int v) {//rootedParent(int u, int v):计算根节点 u 到 v 的根节点,如果 u 是 v 的祖先,返回 v 的父节点,否则在邻接表中查找 u 的合适父节点
//         std::swap(u, v);
//         if (u == v) {
//             return u;
//         }
//         if (!isAncester(u, v)) {
//             return parent[u];
//         }
//         auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
//             return in[x] < in[y];
//         }) - 1;
//         return *it;
//     }
    
//     int rootedSize(int u, int v) {//rootedSize(int u, int v):计算以 u 为根的子树大小,其中 v 可能是 u 的子树,如果 u 是 v 的祖先,则返回 v 的子树大小的补集
//         if (u == v) {
//             return n;
//         }
//         if (!isAncester(v, u)) {
//             return siz[v];
//         }
//         return n - siz[rootedParent(u, v)];
//     }
    
//     int rootedLca(int a, int b, int c) {//rootedSize(int u, int v):计算以 u 为根的子树大小,其中 v 可能是 u 的子树,如果 u 是 v 的祖先,则返回 v 的子树大小的补集
//         return lca(a, b) ^ lca(b, c) ^ lca(c, a);
//     }
// //这个 HLD 类通过重链剖分将树分解成链，以便高效地处理树上节点的各种查询和操作。它包括：
// // 链分配：使用深度优先搜索（DFS）来计算子树大小、链顶节点、节点在链中的序列。
// // LCA 查询：高效地计算两个节点的最近公共祖先。
// // 节点跳跃：在链上从节点跳跃一定的步数。
// // 祖先判断：判断一个节点是否是另一个节点的祖先。
// // 子树计算：计算从一个节点到另一个节点的子树大小。
// // 该类适合用于处理大规模树形结构的各种查询和操作，尤其是在竞赛和复杂的树上问题中。
// };