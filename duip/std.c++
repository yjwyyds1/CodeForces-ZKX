// #include <bits/stdc++.h>
// using namespace std;
// const int N=2e5+10;
// const int mod = 1e9+7;
// using ll = long long int;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 打开文件流
//     ifstream fin("D:/CodeForces/duip/in.txt");
//     ofstream fout("D:/CodeForces/duip/out.txt");
//     if (!fin) {
//         cerr << "无法打开 in.txt 进行读取\n";
//         return 1;
//     }
//     if (!fout) {
//         cerr << "无法打开 out.txt 进行写入\n";
//         return 1;
//     }


//     // int n;
//     // fin>>n;
//     // vector<vector<int>> e(2*n+1);
//     // vector<int> d(2*n+1,0),f(2*n+1,0);
//     // queue<int>q;
//     // vector<int> vis(2*n+1,0);
//     // for(int i=1;i<=n;i++){
//     //     int x;
//     //     fin>>x;
//     //     e[i].push_back(x);
//     //     d[x]++;
//     // }
//     // for(int i=1;i<=2*n;i++){
//     //     if(d[i]==0){
//     //         q.push(i);
//     //     }
//     // }
//     // while(!q.empty()){
//     //     int t=q.front();
//     //     q.pop();
//     //     vis[t]=1;
//     //     for(auto y:e[t]){
//     //         f[y]=max(f[t],f[t]+1);
//     //         d[y]--;
//     //         if(!d[y]){
//     //             q.push(y);
//     //         }
//     //     }
//     // }
//     // ll ans=0;
//     // for(int i=1;i<=2*n;i++){
//     //     if(e[i].empty()){
//     //         ans+=f[i];
//     //     }
//     //     if(vis[i]==0){
//     //         ans++;
//     //     }
//     // }
//     // fout<<ans<<'\n';
//     int _;
//     fin>>_;
//     while(_--){
//         int n,k;
//         fin>>n>>k;
//         vector<vector<int>> f(2*N);
//         ll Z=1e6;
//         int a[n+1];
//         for(int i=1;i<=n;i++){
//             fin>>a[i];
//             f[a[i]+Z].push_back(i);
//         }
//         int ans=0;
//         vector<int>r;
//         for(int i=0;i<=2*Z;i++){
//             if(!f[i].empty()){
//                 ans=max(ans,(int)f[i].size());
//                 r.push_back(i);
//             }
//         }
//         if(k==0){
//             fout<<ans<<'\n';
//         }
//         else{
//             for(auto x:r){
//                 if((x-k>=0)&&(x-k<=2*Z)&&(!f[x-k].empty())){
//                     int res=0,Mi=0,A=0;
//                     int i=0,j=0;
//                     while(i<f[x].size()&&j<f[x-k].size()){
//                         if(f[x][i]<f[x-k][j]){
//                             i++;
//                             res--;
//                         }
//                         else{
//                             j++;
//                             res++;
//                         }
//                         A=max({res-Mi,A,res});
//                         Mi=min(Mi,res);
//                     }
//                     while(i<f[x].size()){
//                         i++;
//                         res--;
//                         A=max({res-Mi,A,res});
//                         Mi=min(Mi,res);
//                     }
//                     while(j<f[x-k].size()){
//                         j++;
//                         res++;
//                         A=max({res-Mi,A,res});
//                         Mi=min(Mi,res);
//                     }
//                     ans=max(ans,A+(int)f[x].size());
//                 }
//             }
//             fout<<ans<<'\n';
//         }
//     }

    

//     fin.close();
//     fout.close();
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using i64 = long long;
// const int MOD = 998244353;
// const int N=5e5+10;
// vector<int> g[N];
// i64 jc[N], inv[N];

// // 快速幂
// i64 ksm(i64 a, i64 b) {
//     i64 res = 1;
//     while (b) {
//         if (b & 1) res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }

// i64 ans;

// // DFS 返回子树「是否保留一个奇子树贡献」的标记
// bool dfs(int x, int f) {
//     int w = 0;
//     for (int y : g[x]) {
//         if (y == f) continue;
//         if (dfs(y, x)) w++;
//     }
//     // 对 w 个“奇子树”配对
//     for (int j = w; j >= 2; j -= 2) {
//         // 乘上 C(j,2) = j*(j-1)/2
//         ans = ans * ( (i64)j * (j - 1) / 2 % MOD ) % MOD;
//     }
//     // 除以 (w/2)!（因为我们配对了 w/2 对）
//     ans = ans * inv[w/2] % MOD;
//     // 如果原来是奇数个，最后还剩一个“未配对”，则返回 1；否则返回 0
//     return (w & 1);
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ifstream fin("D:/CodeForces/duip/in.txt");
//     ofstream fout("D:/CodeForces/duip/out.txt");
//     if (!fin) { cerr << "无法打开 in.txt\n"; return 1; }
//     if (!fout){ cerr << "无法打开 out.txt\n"; return 1; }

//     int T;
//     fin >> T;
//     while (T--) {

//         int n;
//         fin >> n;

//         // 清空上次留下的邻接
//         for (int i = 1; i <= n; i++) {
//             g[i].clear();
//         }

//         // 读入树的边
//         for (int i = 1; i < n; i++) {
//             int x, y;
//             fin >> x >> y;
//             g[x].push_back(y);
//             g[y].push_back(x);
//         }

//         // 预计算阶乘和逆阶
//         jc[0] = 1;
//         for (int i = 1; i <= n; i++) {
//             jc[i] = jc[i-1] * i % MOD;
//         }
//         inv[n] = ksm(jc[n], MOD-2);
//         for (int i = n; i >= 1; i--) {
//             inv[i-1] = inv[i] * i % MOD;
//         }

//         // 初始化答案
//         ans = 1;
//         // 从根 1 开始 DFS
//         dfs(1, 0);

//         fout << ans << '\n';
//     }

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// static const int maxn = 500000 + 10;   // 根据题目 n ≤ 1e4 可改小，这里保留足够冗余
// static const ll mod  = 998244353;

// vector<int> g[maxn];
// ll jc[maxn], invv[maxn];
// ll ans;

// // 快速幂
// ll ksm(ll a, ll b) {
//     ll r = 1;
//     while (b) {
//         if (b & 1) r = r * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return r;
// }

// // DFS 返回：当前子树是否“向上传递”一个未配对的奇子（true/false）
// bool dfs(int u, int fa) {
//     int w = 0;
//     // 先遍历子节点
//     for (int v : g[u]) {
//         if (v == fa) continue;
//         if (dfs(v, u)) 
//             w++;
//     }
//     // 如果 w 是奇数，则“多留一个”以凑成偶数
//     bool leaveOdd;
//     if (w & 1) {
//         // w 原本奇数，+1 后变偶数
//         w += 1;
//         leaveOdd = false;
//     } else {
//         // w 原本偶数
//         leaveOdd = true;
//     }
//     // 对 w 棵子树两两配对
//     // 配对方式数：∏_{j=w, w-2, …, 2} [ j*(j-1)/2 ]
//     for (int j = w; j >= 2; j -= 2) {
//         // j*(j-1)/2 一定是整数
//         ll ways = (ll)j * (j - 1) / 2 % mod;
//         ans = ans * ways % mod;
//     }
//     // 除以 (w/2)! ——乘以 invv[w/2]
//     ans = ans * invv[w/2] % mod;
//     return leaveOdd;
// }

// void solve() {
//     int n;
//     cin >> n;
//     // 清空上一组的数据
//     for (int i = 1; i <= n; i++) {
//         g[i].clear();
//     }
//     // 读入 n−1 条边
//     for (int i = 1; i < n; i++) {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     // 重置全局答案
//     ans = 1;
//     // 从 1 号节点开始 DFS
//     dfs(1, 0);
//     // 输出本组答案
//     cout << ans << "\n";
// }

// int main() {
//     freopen("D:/CodeForces/duip/in.txt","r",stdin);
//     freopen("D:/CodeForces/duip/out.txt","w",stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 一次性预计算阶乘 jc[] 和逆元 invv[]
//     jc[0] = 1;
//     for (int i = 1; i < maxn; i++) {
//         jc[i] = jc[i - 1] * i % mod;
//     }
//     invv[maxn - 1] = ksm(jc[maxn - 1], mod - 2);
//     for (int i = maxn - 2; i >= 0; i--) {
//         invv[i] = invv[i + 1] * (i + 1) % mod;
//     }

//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
// #include <bits/stdc++.h>

// using i64 = long long;

// void solve() {
//     int l, r, a;
//     std::cin >> l >> r >> a;
    
//     int ans = r / a + r % a;
//     int v = (r + 1) / a * a - 1;
//     if (v >= l) {
//         ans = std::max(ans, v / a + v % a);
//     }
    
//     std::cout << ans << "\n";
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     freopen("D:/CodeForces/duip/in.txt","r",stdin);
//     freopen("D:/CodeForces/duip/out.txt","w",stdout);
//     int t;
//     std::cin >> t;
    
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
// using ld = long double;
// using PII=pair<ll,ll>;
// const ld ESP = 1e-10;
// const ld PI = acosl(-1);
// const int N=1e6+10;
// const int M=2e5+10;
// const int inf = 0x3f3f3f3f;
// const int mod = 998244353;


// ll n,m,k;
// ll hp[M],x[M];
// bool ck(ll d){
//     vector<PII> r;
//     for(int i=1;i<=n;i++){
//         ll len=m-(hp[i]+d-1)/d;
//         if(len>=0){
//             r.push_back({x[i]-len,1});
//             r.push_back({x[i]+len+1,-1});
//         }
//     }
//     sort(r.begin(),r.end());
//     ll sum=0;
//     for(auto [l,w]:r){
//         sum+=w;
//         if(sum>=k)return 1;
//     }
//     return 0;
// }
// void solve(){
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;i++){
//         cin>>hp[i];
//     }
//     for(int i=1;i<=n;i++){
//         cin>>x[i];
//     }
//     ll L=1,R=1e14;
//     ll ans=-1;
//     while(L<=R){
//         ll mid=L+R>>1;
//         if(ck(mid)){
//             ans=mid;
//             R=mid-1;
//         }
//         else{
//             L=mid+1;
//         }
//     }
//     cout<<ans<<'\n';
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int _;
//     _=1;
//     cin>>_;
//     while(_--){
//         solve();
//     }
//     return 0;
// }


// #include <bits/stdc++.h>
// const int N=1e6+10;
// const int M=2e5+10;
// const int inf = 0x3f3f3f3f;
// const int mod = 1e9+7;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
// using ld = long double;
// using PII=pair<ll,ll>;

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     int s,t;
//     cin>>s>>t;
//     vector<vector<PII>> e((k+1)*n); 
//     for(int i=1;i<=m;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         e[u].push_back({w,v});
//         e[v].push_back({w,u});
//         for(int j=1;j<=k;j++){
//             e[u+j*n].push_back({w,v+j*n});
//             e[v+j*n].push_back({w,u+j*n});


//             e[v+(j-1)*n].push_back({0,u+j*n});
//             e[u+(j-1)*n].push_back({0,v+j*n});
//         }
//     }
//     vector<ll> d((k+1)*n,1e18);
//     d[s]=0;
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     q.push({0,s});
//     vector<int> v((k+1)*n,0);
//     while(!q.empty()){
//         int t=q.top().second;
//         q.pop();
//         if(v[t])continue;
//         v[t]=1;
//         for(auto [w,y]:e[t]){
//             if(d[y]>d[t]+w){
//                 d[y]=d[t]+w;
//                 q.push({d[y],y});
//             }
//         }
//     }
//     ll ans=1e18;
//     for(int i=0;i<=k;i++){
//         ans=min(ans,d[t+i*n]);
//     }
//     cout<<ans<<'\n';
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int _;
//     _=1;
//     // cin>>_;
//     while(_--){
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using i64 = long long;

// void solve() {
//     std::array<int, 3> l;
//     for (int i = 0; i < 3; i++) {
//         std::cin >> l[i];
//     }
    
//     std::sort(l.begin(), l.end());
    
//     if (l[0] + l[1] == l[2] || (l[0] % 2 == 0 && l[1] == l[2]) || (l[2] % 2 == 0 && l[0] == l[1])) {
//         std::cout << "YES\n";
//     } else {
//         std::cout << "NO\n";
//     }
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     freopen("D:/CodeForces/duip/in.txt","r",stdin);
//     freopen("D:/CodeForces/duip/out.txt","w",stdout);
//     int t;
//     std::cin >> t;
    
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }
// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
 
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int _;
//     cin>>_;
//     while (_--)
//     {
//         ll n;
//         cin>>n;
//         vector<pair<ll,ll>> a(n);
//         for(int i=0;i<n;i++){
//             cin>>a[i].second;
//             a[i].first=a[i].second+i;
//             a[i].second=i;
//         }
//         sort(a.begin(),a.end());
//         map<ll,ll> dp;
//         dp[n]=1;
//         ll ans=n;
//         for(int i=0;i<n;i++){
//             dp[a[i].first+a[i].second]|=dp[a[i].first];
//             if(dp[a[i].first+a[i].second]){
//                 ans=max(ans,a[i].first+a[i].second);
//             }
//         }
//         cout<<ans<<'\n';
//     }
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// struct BIT{
//     int n;
//     vector<int> t;
//     void init(int &_){
//         n=_;
//         t.assign(n+1,0);
//     }
//     void add(int x){
//         for(int i=x;i<=n;i+=i&-i){
//             t[i]^=1;
//         }
//     }
//     int query(int x){
//         int res=0;
//         for(int i=x;i;i-=i&-i){
//             res^=t[i];
//         }
//         return res;
//     }
// };
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     freopen("D:/CodeForces/duip/in.txt","r",stdin);
//     freopen("D:/CodeForces/duip/out.txt","w",stdout);
//     int n,q;
//     cin>>n>>q;
//     BIT a;
//     a.init(n);
//     for(int i=1;i<=q;i++){
//         int op;
//         cin>>op;
//         if(op==1){
//             int l,r;
//             cin>>l>>r;
//             a.add(l),a.add(r+1);
//         }
//         else{
//             int x;
//             cin>>x;
//             cout<<a.query(x)<<'\n';
//         }
//     }
// }
// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     freopen("D:/CodeForces/duip/in.txt","r",stdin);
//     freopen("D:/CodeForces/duip/out.txt","w",stdout);
//     int _;
//     cin>>_;
//     while (_--)
//     {
//         ll n;
//         cin>>n;
//         vector<pair<ll,ll>> a(n);
//         for(int i=0;i<n;i++){
//             cin>>a[i].second;
//             a[i].first=a[i].second+i;
//             a[i].second=i;
//         }
//         sort(a.begin(),a.end());
//         map<ll,ll> dp;
//         dp[n]=1;
//         ll ans=n;
//         for(int i=0;i<n;i++){
//             dp[a[i].first+a[i].second]|=dp[a[i].first];
//             if(dp[a[i].first+a[i].second]){
//                 ans=max(ans,a[i].first+a[i].second);
//             }
//         }
//         cout<<ans<<'\n';
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// // 最大 n
// static const int MAXN = 300010;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n;
//     cin >> n;
//     vector<ll> a(n+1);
//     vector<int> pos(n+1), q(n);
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> q[i];
//     }
//     // 记录每个值 x 在 a 中的位置
//     for(int i = 1; i <= n; i++){
//         pos[a[i]] = i;
//     }

//     // 笛卡尔树结构
//     vector<int> leftc(n+1, 0), rightc(n+1, 0), stk;
//     stk.reserve(n);

//     // 构建最小堆笛卡尔树
//     for(int i = 1; i <= n; i++){
//         int last = 0;
//         // 弹出直到找到 a[stk.top()] < a[i]
//         while(!stk.empty() && a[stk.back()] > a[i]){
//             last = stk.back();
//             stk.pop_back();
//         }
//         // 把 last 成为 i 的左孩子
//         leftc[i] = last;
//         // i 成为栈顶的新右孩子
//         if(!stk.empty()){
//             rightc[stk.back()] = i;
//         }
//         stk.push_back(i);
//     }
//     // 栈底即为根
//     int root = stk.front();

//     // DFS 计算每个子树的最左/最右下标
//     vector<int> L(n+1), R(n+1);
//     function<void(int)> dfs = [&](int u){
//         if(u == 0) return;
//         L[u] = R[u] = u;
//         if(leftc[u]){
//             dfs(leftc[u]);
//             L[u] = min(L[u], L[leftc[u]]);
//             R[u] = max(R[u], R[leftc[u]]);
//         }
//         if(rightc[u]){
//             dfs(rightc[u]);
//             L[u] = min(L[u], L[rightc[u]]);
//             R[u] = max(R[u], R[rightc[u]]);
//         }
//     };
//     dfs(root);

//     // 离线输出，按查询顺序
//     // 对于每个 x = q[i]，其位置为 pos[x]，答案就是 [L[pos[x]], R[pos[x]]]
//     for(int x : q){
//         int i = pos[x];
//         cout << L[i] << " " << R[i] << "\n";
//     }

//     return 0;
// }
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=1e5+10;
const int MAXN=3e5+10;
typedef pair<int,int>PII;
int dxy[8][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
template <class... Args>
void _(Args... args)
{
    auto _ = [&](auto x)
    { cout << x << " "; };
    cout << "--->";
    int arr[] = {(_(args), 0)...};
    cout << "\n";
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
    return x/gcd(x,y)*y;
}
int mod;
int qmi(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
   }
   return res;
}
int fz(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return i;
        }
    }
    return 0;
}
int a[MAXN],pos[MAXN];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    vector<int>l(n+1,-1);
    stack<int>st;
    for(int i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]>=a[i]) {
            st.pop();
        }
        l[i]=st.empty()?0:st.top();
        st.push(i);
    }
    vector<int>r(n+1,0);
    stack<int>st1;
    for (int i=n;i>=1;i--){
        while(!st1.empty()&&a[st1.top()]>=a[i]) {
            st1.pop();
        }
        r[i]=st1.empty()?n+1:st1.top();
        st1.push(i);
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        int p=pos[x];
        int l1=l[p]+1;
        int r1=r[p]-1;
        cout<<l1<<" "<<r1<< "\n";
    }

}
signed main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    freopen("D:/CodeForces/duip/in.txt","r",stdin);
    freopen("D:/CodeForces/duip/out.txt","w",stdout);
    int T;
    // cin>>T;
    T=1;
    while(T--){
        solve();
    }
    // qwq;
}
// #include <bits/stdc++.h>

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;

// void solve() {
//     int n;
//     std::cin >> n;
    
//     std::vector<std::array<i64, 2>> e;
//     for (int i = 0; i < n; i++) {
//         i64 a;
//         std::cin >> a;
        
//         if (a + i >= n && i > 0) {
//             e.push_back({a + i, a + i + i});
//         }
//     }
//     std::sort(e.begin(), e.end(), std::greater());
//     std::map<i64, i64> dp;
//     dp[n] = n;
//     for (auto [x, y] : e) {
//         if (!dp.contains(x)) {
//             dp[x] = x;
//         }
//         i64 &res = dp[x];
//         dp[x] = std::max(dp[x], dp.contains(y) ? dp[y] : y);
//     }
//     std::cout << dp[n] << "\n";
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
    
//     int t;
//     std::cin >> t;
    
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }