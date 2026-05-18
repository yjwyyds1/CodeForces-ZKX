// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// const int N=1e5+10;

// int main() {
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 1. 随机 n∈[2,100000], q∈[1,n]
//     uniform_int_distribution<int> N(1,20);
//     ll n = N(rng);
//     uniform_int_distribution<int> g(1,423143);
//     // ll q = dist_q(rng);
//     uniform_int_distribution<int> L(1,15);
//     ofstream fout("in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }
//     n=1000000;
//     fout<<n<<'\n';
//     uniform_int_distribution<int> ns(1,n);
//     for(int i=1;i<=n;i++){
//     	ll x=ns(rng);
//     	x+=ns(rng);
//     	if(x%2){
//     		fout<<96433469<<'\n';
//     	}
//     	else{
//     		fout<<x<<'\n';
//     	}
//     }
//     // fout<<10<<'\n';
//     // for(int i=1;i<=10;i++){
//     //     int k=L(rng);
//     //     uniform_int_distribution<int> ns(0,2<<k-1);
//     //     fout<<ns(rng)<<" "<<k<<'\n';
//     // }
    
//     // 2. 输出 n, q
//     // fout << n << " " << q << "\n";
//     // uniform_int_distribution<int> X(1, n);
//     // map<pair<int,int>,int> mp;
//     // for(int i=1;i<=q;i++){
//     //     int x=X(rng),y=X(rng);
//     //     if(x>y)swap(x,y);
//     //     while(mp[{x,y}]||x==1&&y==n){
//     //         x=X(rng),y=X(rng);
//     //         if(x>y)swap(x,y);
//     //     }
//     //     fout<<x<<" "<<y<<'\n';
//     //     mp[{x,y}]=1;
//     // }
//     // // 3. 每个节点的权值 ∈[-1e9,1e9]
//     // uniform_int_distribution<int> dist_val(0, 32100);
//     // for (int i = 1; i <= n; i++) {
//     //     fout << dist_val(rng) << (i < n ? ' ' : '\n');
//     //     fa[i] = i;  // 初始化并查集
//     // }

//     // // 4. 为节点编号创建 [1,n] 的分布
//     // uniform_int_distribution<int> dist_node(1, n);

//     // // 5. 随机生成一棵树的 n-1 条边
//     // while (cnt < n - 1) {
//     //     int u = dist_node(rng), v = dist_node(rng);
//     //     int pu = zhao(u), pv = zhao(v);
//     //     if (pu != pv) {
//     //         fa[pu] = pv;
//     //         cnt++;
//     //         fout << u << " " << v << "\n";
//     //         e[u].push_back(v);
//     //         e[v].push_back(u);
//     //     }
//     // }
//     // dfs(1,-1);
//     // // 6. q 条查询 (r,k)，1≤k≤20
//     // uniform_int_distribution<int> dist_k(1, 20);
//     // for (int i = 0; i < q; i++) {
//     //     int r = dist_node(rng);
//     //     int k = dist_k(rng);
//     //     fout << r << " " << min(k,s[r]) << "\n";
//     // }

//     // 7. 关闭文件
//     fout.close();
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// // 通过 Prüfer 序列（长度 n-2）解码生成的边
// vector<pair<int,int>> prufer_to_tree(const vector<int>& prufer) {
//     int m = prufer.size();
//     int n = m + 2;
//     vector<int> degree(n+1, 1);
//     for (int x : prufer) {
//         degree[x]++;
//     }
//     // 小根堆维护当前度为 1 的最小节点
//     priority_queue<int, vector<int>, greater<int>> leaf;
//     for (int i = 1; i <= n; i++) {
//         if (degree[i] == 1) leaf.push(i);
//     }

//     vector<pair<int,int>> edges;
//     edges.reserve(n-1);
//     for (int x : prufer) {
//         int u = leaf.top(); leaf.pop();
//         int v = x;
//         edges.emplace_back(min(u,v), max(u,v));
//         // “移除” u，更新 v 的度
//         degree[v]--;
//         if (degree[v] == 1) leaf.push(v);
//     }
//     // 最后剩下两棵叶子
//     int u = leaf.top(); leaf.pop();
//     int v = leaf.top(); leaf.pop();
//     edges.emplace_back(min(u,v), max(u,v));

//     return edges;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     const int MAX_T = 100;
//     const int MAX_N = 100;
//     const int MAX_K = (MAX_N - 1) / 2; // 4999

//     uniform_int_distribution<int> distT(1, MAX_T);
//     uniform_int_distribution<int> distK(1, MAX_K);

//     int T = distT(rng);

//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     fout << T << "\n";
//     for (int tc = 0; tc < T; tc++) {
//         // 保证奇数节点数
//         int k = distK(rng);
//         int n = 2*k + 1;
//         fout << n << "\n";

//         // 生成长度 n-2 的 Prüfer 序列
//         vector<int> prufer(n-2);
//         uniform_int_distribution<int> distNode(1, n);
//         for (int &x : prufer) {
//             x = distNode(rng);
//         }

//         // 解码
//         auto edges = prufer_to_tree(prufer);

//         // 为了多样性，再打乱输出顺序
//         shuffle(edges.begin(), edges.end(), rng);

//         // 写入
//         for (auto &e : edges) {
//             fout << e.first << " " << e.second << "\n";
//         }
//     }

//     fout.close();
//     cout << "生成完成！\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 随机数引擎（64 位保证大范围均匀）
//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 随机分布
//     uniform_int_distribution<int> distT(1, 10);
//     uniform_int_distribution<ll>  distA(1, 1210000LL);
//     uniform_int_distribution<ll>  distL(1, 1000LL);

//     int t = 10000;

//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     fout << t << "\n";
//     for (int i = 0; i < t; i++) {
//         ll l = distL(rng);
//         // 生成 r 时保证 r ≥ l
//         uniform_int_distribution<ll> distR(l, 1004500LL);
//         ll r = distR(rng);
//         ll a = distA(rng);
//         fout << l << " " << r << " " << a << "\n";
//     }

//     fout.close();
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // Random engine
//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // Distributions for parameters
//     uniform_int_distribution<int> distN(2, 10000);
//     uniform_int_distribution<int> distK(0, 10);
//     uniform_int_distribution<int> distCost(0, 1000);

//     int n = 1000;
//     // m in [n-1 .. min(5e4, n*(n-1)/2)]
//     int maxEdges = min(2000, n*(n-1)/2);
//     uniform_int_distribution<int> distM(n-1, maxEdges);
//     int m = distM(rng);

//     int k = distK(rng);
//     uniform_int_distribution<int> distNode(0, n-1);
//     int s = distNode(rng), t = distNode(rng);
//     while (t == s) t = distNode(rng);

//     // Prepare to generate edges
//     vector<pair<int,int>> edges;
//     edges.reserve(m);
//     // First generate a random spanning tree via shuffle of nodes
//     vector<int> perm(n);
//     iota(perm.begin(), perm.end(), 0);
//     shuffle(perm.begin(), perm.end(), rng);
//     for (int i = 1; i < n; i++) {
//         int u = perm[i];
//         uniform_int_distribution<int> distParent(0, i-1);
//         int p = perm[distParent(rng)];
//         edges.emplace_back(min(u,p), max(u,p));
//     }

//     // Add remaining edges uniformly at random without duplicates
//     unordered_set<ll> used;
//     auto encode = [&](int u, int v) {
//         return ll(u) << 32 | ll(v);
//     };
//     for (auto &e : edges) {
//         used.insert(encode(e.first, e.second));
//     }
//     while ((int)edges.size() < m) {
//         int u = distNode(rng), v = distNode(rng);
//         if (u == v) continue;
//         int a = min(u,v), b = max(u,v);
//         ll code = encode(a,b);
//         if (used.insert(code).second) {
//             edges.emplace_back(a,b);
//         }
//     }

//     // Shuffle the final edge list
//     shuffle(edges.begin(), edges.end(), rng);

//     // Output to file
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "Cannot open in.txt for writing\n";
//         return 1;
//     }
//     fout << n << " " << m << " " << k << "\n";
//     fout << s << " " << t << "\n";
//     for (auto &e : edges) {
//         int c = distCost(rng);
//         fout << e.first << " " << e.second << " " << c << "\n";
//     }
//     fout.close();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 随机数引擎，基于时钟
//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 测试用例数量 t 的范围
//     const int MIN_T = 1;
//     const int MAX_T = 10000;
//     // 木棍长度范围
//     const int MIN_L = 1;
//     const int MAX_L = 100000000;

//     // 分布
//     uniform_int_distribution<int> distT(MIN_T, MAX_T);
//     uniform_int_distribution<int> distL(MIN_L, MAX_L);

//     // 打开输出文件
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     // 生成随机 t
//     int t = 10000;
//     fout << t << "\n";

//     // 生成每个测试用例
//     for (int i = 0; i < t; i++) {
//         int l1 = distL(rng);
//         int l2 = distL(rng);
//         int l3 = distL(rng);
//         fout << l1 << " " << l2 << " " << l3;
//         if (i + 1 != t) fout << "\n";
//     }

//     fout.close();
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 随机数引擎
//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 生成 n
//     const int MINN = 100, MAXN = 3000;
//     uniform_int_distribution<int> distN(MINN, MAXN);
//     int n = distN(rng);

//     // 生成 1..n 的一个随机排列 a
//     vector<int> a(n);
//     iota(a.begin(), a.end(), 1);
//     shuffle(a.begin(), a.end(), rng);

//     // 生成查询序列 q（长度 n，每次询问 x ∈ [1,n]）
//     vector<int> q(n);
//     q=a;
//     shuffle(a.begin(), a.end(), rng);

//     ofstream fout("D:/CodeForces/duip/in.txt");
//     fout << n << "\n";
//     for(int i = 0; i < n; i++){
//         fout << a[i] << (i+1<n? ' ':'\n');
//     }
//     for(int i = 0; i < n; i++){
//         fout << q[i] << (i+1<n? ' ':'\n');
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 随机数引擎
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    // 参数范围
    const int MAXN = 200000;
    const int MAXQ = 200000;
    uniform_int_distribution<int> distN(1, MAXN);
    uniform_int_distribution<int> distQ(1, MAXQ);
    uniform_int_distribution<int> opType(1, 10000);
    
    // int n = 200000;
    // int q = 200000;

    // 打开输出文件
    ofstream fout("D:/CodeForces/duip/in.txt");
    if(!fout){
        cerr << "无法打开 in.txt\n";
        return 1;
    }
    // fout<<1<<'\n';
    fout<<300000<<'\n';
    for(int i=1;i<=300000;i++){
        fout<<i<<" ";
    }
    fout<<'\n';
     for(int i=1;i<=300000;i++){
        fout<<i<<" ";
    }
    fout<<'\n';
    // fout << n << " " << q << "\n";

    // uniform_int_distribution<int> distPos(1, n);
    // for(int i = 0; i < q; i++){
    //     int op = opType(rng)%10;
    //     if(op<=7){
    //         // 区间翻转
    //         int l = distPos(rng);
    //         int r = distPos(rng);
    //         if(l > r) swap(l, r);
    //         fout << "1 " << l << " " << r << "\n";
    //     } else {
    //         // 查询
    //         int x = distPos(rng);
    //         fout << "2 " << x << "\n";
    //     }
    // }

    fout.close();
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// // 最大 n 和最大 a_i
// const ll MAX_N = 1e4;
// const ll MAX_A = (ll)12771343;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//     uniform_int_distribution<int> distT(1, 100);        // t ∈ [1,100]
//     uniform_int_distribution<int> distN(1, MAX_N);     // n ∈ [1,3e5]
//     uniform_int_distribution<ll>  distA(1, MAX_A);     // a_i ∈ [1,1e12]

//     int T = 30;
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if(!fout){
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     fout << T << "\n";
//     for(int tc = 0; tc < T; tc++){
//         // 每组测试先随机选个 n
//         ll n = distN(rng);
//         // 对于前几个测试用例，我们输出一些 edge / 大答案模板：
//         // if(tc == 0){
//         //     // 极小 n=1
//         //     n = 1;
//         //     fout << n << "\n";
//         //     fout << MAX_A << "\n";
//         //     continue;
//         // }
//         // if(tc == 1){
//         //     // 极大 n，且 a_i 单调递增（让 a[i]+i 严格增大，方便得到大 ans）
//         //     n = MAX_N;
//         //     fout << n << "\n";
//         //     for(ll i = 0; i < n; i++){
//         //         // 令 a[i] = i * (MAX_A / n) 保证 a[i]+i 线性增长
//         //         ll x = (MAX_A / n) * i + 1;
//         //         fout << x << (i+1<n? ' ':'\n');
//         //     }
//         //     continue;
//         // }
//         // if(tc == 2){
//         //     // 所有 a_i 相等 = MAX_A/2，测试 dp 只靠索引 i 决定
//         //     n = MAX_N;
//         //     fout << n << "\n";
//         //     for(ll i = 0; i < n; i++){
//         //         fout << (MAX_A/2) << (i+1<n? ' ':'\n');
//         //     }
//         //     continue;
//         // }
//         // if(tc == 3){
//         //     // 极大 n，完全随机
//         //     fout << n << "\n";
//         //     for(ll i = 0; i < n; i++){
//         //         fout << distA(rng) << (i+1<n? ' ':'\n');
//         //     }
//         //     continue;
//         // }

//         // 其余测试，大小随机 + 部分前缀/后缀赋极值，模拟混合情况
//         fout << n << "\n";
//         if(tc%2){
//             for(int i = 0; i < n; i++){
//             // 输出时注意性能，采用 '\n' 和 ' ' 交替
//                 fout << (ll)(n - i) << (i+1<n? ' ':'\n');
//             }
//         }
//         else{
//             vector<ll> a(n);
//             // 先全随机
//             for(int i = 0; i < n; i++){
//                 a[i] = distA(rng);
//             }
//             for(int i = 0; i < n; i++){
//                 fout << a[i] << (i+1<n? ' ':'\n');
//             }
//         }
        
//     }

//     fout.close();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//     uniform_int_distribution<int> distT(1, 10000);
//     uniform_int_distribution<int> distL(1, 1000000);
//     uniform_int_distribution<int> distPattern(1, 100000000);

//     int t = 10000;
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in_yes.txt\n";
//         return 1;
//     }
//     fout << t << "\n";

//     for (int i = 0; i < t; i++) {
//         int p = distPattern(rng)%10;
//         ll a, b, c;

//         if (p == 1) {
//             // a + b == c
//             a = distL(rng);
//             b = distL(rng);
//             c = a + b;
//             // 如果超出范围，就截到最大
//             if (c > 100000000) c = 100000000;
//         }
//         else if (p == 2) {
//             // a 偶， b == c
//             b = distL(rng);
//             c = b;
//             // 随机生成一个偶数 a
//             ll x = distL(rng);
//             a = (x % 2 == 0 ? x : x + 1);
//             if (a > 100000000) a -= 1;
//         }
//         else if(p == 3){
//             // c 偶， a == b
//             a = distL(rng);
//             b = a;
//             ll x = distL(rng);
//             c = (x % 2 == 0 ? x : x + 1);
//             if (c > 100000000) c -= 1;
//         }
//         else{
//             a=distL(rng);
//             b=distL(rng);
//             c=distL(rng);
//         }

//         // 随机打乱顺序，保证无序输入
//         array<ll,3> L = {a,b,c};
//         shuffle(L.begin(), L.end(), rng);
//         fout << L[0] << " " << L[1] << " " << L[2] << "\n";
//     }

//     fout.close();
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 随机数引擎
//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 参数范围
//     const int MIN_N = 2;
//     const int MAX_N = 10000;
//     const int MAX_M = 50000;
//     const int MAX_COST = 1000;
//     const int MAX_K = 10;

//     // 随机分布
//     uniform_int_distribution<int> distN(2, MAX_N);
//     uniform_int_distribution<int> distK(0, MAX_K);
//     uniform_int_distribution<int> distCost(0, MAX_COST);

//     int n = distN(rng);
//     int k = distK(rng);

//     // m 至少 n-1，最多 min(5e4, n*(n-1)/2)
//     int maxEdges = min(MAX_M, n*(n-1)/2);
//     uniform_int_distribution<int> distM(n-1, maxEdges);
//     int m = distM(rng);

//     // 强制 s=0, t=n-1
//     int s = 0, t = n-1;

//     // 构造边集，先主链
//     vector<pair<int,int>> edges;
//     edges.reserve(m);
//     for (int i = 0; i < n-1; i++) {
//         edges.emplace_back(i, i+1);
//     }
//     // 记录已有边以去重
//     unordered_set<ll> used;
//     used.reserve(m*2);
//     auto code = [&](int u, int v){
//         return (ll)u<<32 | (unsigned long long)v;
//     };
//     for (auto &e : edges) {
//         used.insert(code(e.first, e.second));
//     }

//     // 补充随机边
//     uniform_int_distribution<int> distNode(0, n-1);
//     while ((int)edges.size() < m) {
//         int u = distNode(rng);
//         int v = distNode(rng);
//         if (u == v) continue;
//         if (u > v) swap(u,v);
//         ll key = code(u,v);
//         if (used.insert(key).second) {
//             edges.emplace_back(u, v);
//         }
//     }

//     // 最后打乱边的顺序
//     shuffle(edges.begin(), edges.end(), rng);

//     // 输出
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }
//     fout << n << " " << m << " " << k << "\n";
//     fout << s << " " << t << "\n";
//     for (auto &e : edges) {
//         int c = distCost(rng);
//         fout << e.first << " " << e.second << " " << c << "\n";
//     }
//     fout.close();
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//     const int MAX_T = 100;
//     const int MAX_N = 1000;
//     const ll MAX_V = 12320LL;

//     uniform_int_distribution<int> distT(1, MAX_T);
//     uniform_int_distribution<int> distN(1, MAX_N);
//     uniform_int_distribution<ll>  distM(1, MAX_V);

//     int t = 100;

//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if(!fout){
//         cerr<<"无法打开 in.txt\n";
//         return 1;
//     }

//     fout << t << "\n";
//     for(int tc = 0; tc < t; tc++){
//         int n = distN(rng);
//         ll m = max(1ll,distM(rng)/2);
//         uniform_int_distribution<int> distK(1, n);
//         int k = distK(rng);

//         fout << n << " " << m << " " << k << "\n";

//         // 随机生成 h_i ∈ [1, MAX_V]
//         for(int i = 0; i < n; i++){
//             ll h = uniform_int_distribution<ll>(1, MAX_V)(rng);
//             fout << h << (i + 1 < n ? ' ' : '\n');
//         }

//         // 从 [1 .. MAX_V] 中随机抽取 n 个不同的值，然后排序作 a_i
//         vector<ll> pool(MAX_V);
//         iota(pool.begin(), pool.end(), 1LL);
//         shuffle(pool.begin(), pool.end(), rng);
//         pool.resize(n);
//         sort(pool.begin(), pool.end());
//         for(int i = 0; i < n; i++){
//             fout << pool[i] << (i + 1 < n ? ' ' : '\n');
//         }
//     }

//     fout.close();
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// // 1. Prüfer 解码
// vector<pair<int,int>> prufer_to_tree(int n, mt19937 &rng) {
//     vector<int> prufer(n-2);
//     uniform_int_distribution<int> node(1, n);
//     for (int &x : prufer) x = node(rng);

//     vector<int> deg(n+1,1);
//     for (int x : prufer) deg[x]++;
//     priority_queue<int, vector<int>, greater<int>> leaves;
//     for (int i = 1; i <= n; i++) if (deg[i] == 1) leaves.push(i);

//     vector<pair<int,int>> edges;
//     edges.reserve(n-1);
//     for (int x : prufer) {
//         int u = leaves.top(); leaves.pop();
//         int v = x;
//         edges.emplace_back(min(u,v), max(u,v));
//         if (--deg[v] == 1) leaves.push(v);
//     }
//     int u = leaves.top(); leaves.pop();
//     int v = leaves.top(); leaves.pop();
//     edges.emplace_back(min(u,v), max(u,v));
//     return edges;
// }

// // 2. 随机递归树
// vector<pair<int,int>> recursive_tree(int n, mt19937 &rng) {
//     vector<pair<int,int>> edges;
//     edges.reserve(n-1);
//     uniform_int_distribution<int> pick;
//     for (int i = 2; i <= n; i++) {
//         pick = uniform_int_distribution<int>(1, i-1);
//         int p = pick(rng);
//         edges.emplace_back(min(p,i), max(p,i));
//     }
//     return edges;
// }

// // 3. 链状树
// vector<pair<int,int>> path_tree(int n) {
//     vector<pair<int,int>> edges;
//     edges.reserve(n-1);
//     for (int i = 1; i < n; i++)
//         edges.emplace_back(i, i+1);
//     return edges;
// }

// // 4. 星形树
// vector<pair<int,int>> star_tree(int n) {
//     vector<pair<int,int>> edges;
//     edges.reserve(n-1);
//     for (int i = 2; i <= n; i++)
//         edges.emplace_back(1, i);
//     return edges;
// }

// // 5. 完全二叉树（按编号为堆编号）
// vector<pair<int,int>> binary_tree(int n) {
//     vector<pair<int,int>> edges;
//     edges.reserve(n-1);
//     for (int i = 2; i <= n; i++) {
//         int p = i/2;
//         edges.emplace_back(min(p,i), max(p,i));
//     }
//     return edges;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//     uniform_int_distribution<int> distT(1,100), distMode(1,5), distK(1,4000);

//     int T = 100;
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     fout << T << "\n";
//     for (int tc = 0; tc < T; tc++) {
//         // 奇数 n
//         int k = distK(rng);
//         int n = 2*k + 1;
//         fout << n << "\n";

//         // 随机选一种模式
//         int mode = distMode(rng);
//         vector<pair<int,int>> edges;
//         switch(mode) {
//             case 1: edges = prufer_to_tree(n, rng);       break;
//             case 2: edges = recursive_tree(n, rng);       break;
//             case 3: edges = path_tree(n);                 break;
//             case 4: edges = star_tree(n);                 break;
//             default: edges = binary_tree(n);              break;
//         }
//         // 打乱顺序增加随机性
//         shuffle(edges.begin(), edges.end(), rng);
//         for (auto &e : edges)
//             fout << e.first << " " << e.second << "\n";
//     }
//     fout.close();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 随机数引擎
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 固定测试用例数
//     const int T = 100;
//     const int MAX_N = 7000;
//     const int MIN_K = -10000;
//     const int MAX_K =  1000000;
//     const int MIN_A = -1000000;
//     const int MAX_A =  10000;

//     // 分布
//     uniform_int_distribution<int> distN(1, MAX_N);
//     uniform_int_distribution<int> distK(MIN_K, MAX_K);
//     uniform_int_distribution<int> distA(MIN_A, MAX_A);

//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     fout << T << "\n";
//     for (int tc = 0; tc < T; tc++) {
//         int n = distN(rng);
//         int k = distK(rng);
//         fout << n << " " << k << "\n";

//         for (int i = 0; i < n; i++) {
//             int a = distA(rng);
//             fout << a << (i + 1 < n ? ' ' : '\n');
//         }
//     }

//     fout.close();
//     cout << "生成完成！\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 随机数引擎
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 参数上限
//     const int MAX_T = 1;        // 测试组上限
//     const int MAX_N = 1000000;    // 每组 n 的上限
//     const ll  MIN_A = -1000000000LL;
//     const ll  MAX_A =  1000000000LL;

//     // 分布
//     uniform_int_distribution<int> distT(1, MAX_T);
//     uniform_int_distribution<int> distN(1, MAX_N);
//     uniform_int_distribution<ll>  distA(MIN_A, MAX_A);

//     // 生成测试用例数 T
//     // int T = distT(rng);
//     int T=10;
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     fout << T << "\n";
//     for (int tc = 0; tc < T; tc++) {
//         // int n = distN(rng);
//         int n=100000;
//         fout << n << "\n";
//         for (int i = 0; i < n; i++) {
//             ll x = distA(rng);
//             fout << x << (i+1<n ? ' ' : '\n');
//         }
//     }

//     fout.close();
//     cout << "生成完成！\n";
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     const int MAX_T     = 100;
//     const int MAX_SUM_N = 1000000;

//     // 随机生成 T
//     uniform_int_distribution<int> dt(1, MAX_T);
//     // int T = dt(rng);
//     int T=100;

//     // 生成 T 个随机权重
//     vector<double> w(T);
//     double sum_w = 0;
//     for (int i = 0; i < T; i++) {
//         w[i] = uniform_real_distribution<double>(0.0, 1.0)(rng);
//         sum_w += w[i];
//     }

//     // 按比例初步分配 n_i，并确保至少为 1
//     vector<int> ns(T);
//     ll total = 0;
//     for (int i = 0; i < T; i++) {
//         ns[i] = max(1, int(floor(w[i] / sum_w * MAX_SUM_N)));
//         total += ns[i];
//     }

//     // 计算差值 diff = MAX_SUM_N - total
//     ll diff = MAX_SUM_N - total;
//     if (diff > 0) {
//         // 随机挑 diff 个位置，每个 +1
//         uniform_int_distribution<int> pos(0, T-1);
//         for (ll i = 0; i < diff; i++) {
//             ns[pos(rng)]++;
//         }
//     } else if (diff < 0) {
//         // 随机挑 -diff 个位置，每个 –1（至少保持为 1）
//         uniform_int_distribution<int> pos(0, T-1);
//         ll to_remove = -diff;
//         for (ll i = 0; i < to_remove; i++) {
//             int idx;
//             // 找一个当前还 >1 的组
//             do {
//                 idx = pos(rng);
//             } while (ns[idx] <= 1);
//             ns[idx]--;
//         }
//     }

//     // 准备写入文件
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     uniform_int_distribution<int> d01(0, 1);
//     fout << T << "\n";
//     for (int i = 0; i < T; i++) {
//         int n = ns[i];
//         fout << n << "\n";
//         // 随机生成长度为 n 的二进制串
//         string s;
//         s.reserve(n);
//         for (int j = 0; j < n; j++) {
//             s.push_back(char('0' + d01(rng)));
//         }
//         fout << s << "\n";
//     }

//     fout.close();
//     cout << "生成完成！\n";
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     // 随机数引擎
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     // 参数上限
//     const int MAX_T = 100;
//     const int MAX_N = 10000;
//     const ll MAX_V = 100000LL;

//     // 随机分布
//     uniform_int_distribution<int> dt(1, MAX_T);
//     uniform_int_distribution<int> dn(1, MAX_N);
//     uniform_int_distribution<ll> dk(0, MAX_V);
//     uniform_int_distribution<ll> da(1, MAX_V);

//     // 打开输出文件
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     int T = 100;
//     fout << T << "\n";

//     for (int tc = 0; tc < T; tc++) {
//         // int n = dn(rng);
//         int n=10000;
//         ll k = dk(rng);
//         fout << n << " " << k << "\n";

//         // 生成 A 数组
//         for (int i = 0; i < n; i++) {
//             fout << da(rng) << (i+1<n ? ' ' : '\n');
//         }
//     }

//     fout.close();
//     cout << "生成完成！\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     const int MAX_T = 100;       // 最多 100 组
//     const int MAX_N = 1000;    // 每棵树最多 10^5 个节点

//     uniform_int_distribution<int> dt(1, MAX_T);
//     uniform_int_distribution<int> dn(1, MAX_N);

//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     // int T = dt(rng);
//     int T=100;
//     fout << T << "\n";

//     for (int tc = 0; tc < T; tc++) {
//         int n = 1000;
//         fout << n << "\n";

//         bool bounded = dt(rng)%2;  // 随机决定是否度≤3
//         vector<pair<int,int>> edges;
//         edges.reserve(n-1);

//         if (!bounded) {
//             // 任意树：i -> [1, i-1]
//             for (int i = 2; i <= n; i++) {
//                 uniform_int_distribution<int> pd(1, i-1);
//                 edges.emplace_back(pd(rng), i);
//             }
//         } else {
//             // 度≤3 的树
//             vector<int> deg(n+1, 0);
//             vector<int> avail;
//             avail.reserve(n);
//             avail.push_back(1);
//             deg[1] = 0;

//             for (int i = 2; i <= n; i++) {
//                 // 从可用父节点中随机选
//                 uniform_int_distribution<int> ad(0, (int)avail.size()-1);
//                 int idx = ad(rng);
//                 int p = avail[idx];

//                 // 建边 p - i
//                 edges.emplace_back(p, i);
//                 // 更新父节点度
//                 if (++deg[p] == 3) {
//                     // 达到度上限，移出 avail
//                     avail.erase(avail.begin() + idx);
//                 }
//                 // 新节点 i 初始度 1 （和 p 相连）
//                 deg[i] = 1;
//                 // 如果 i 还可以再接子节点（度<3），则加入 avail
//                 if (deg[i] < 3) {
//                     avail.push_back(i);
//                 }
//             }
//         }

//         // 把边顺序打乱
//         shuffle(edges.begin(), edges.end(), rng);

//         for (auto &e : edges) {
//             fout << e.first << " " << e.second << "\n";
//         }
//     }

//     fout.close();
//     cout << "生成完成！\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     ll n = 10000;
//     uniform_int_distribution<int> ns(1, n);

//     //  明确文件路径
//     ofstream fout("D:/CodeForces/duip/in.txt");
//     if (!fout) {
//         cerr << "无法打开 in.txt\n";
//         return 1;
//     }

//     fout << n << '\n';

//     for (int i = 1; i <= n; i++) {
//         ll x = ns(rng) ;
//         string a;
//         for(int j=1;j<=4;j++){
//             a+=(ns(rng)%5)+'1';
//         }
//         if (x % 99==0) {
//             fout << 96433469 << '\n';
//         } else {
//             fout << a << '\n';
//         }
//     }

//     fout.close();
//     cout << "生成完成！\n"; //  确认程序执行
//     return 0;
// }
