<p align="center"><font size="10">By HGNU zkx</font></p>


## [ABC209D](https://atcoder.jp/contests/abc209/tasks/abc209_d)
### 问题陈述

高桥王国由 $N$ 个城镇和 $N-1$ 条道路组成，其中城镇编号为 $1$ 到 $N$。第 $i$ 条道路 $(1 \leq i \leq N-1)$ 连接着城镇 $a_i$ 和城镇 $b_i$，因此可以通过一些道路从每个城镇到达每个城镇。所有道路的长度相同。

将获得 $Q$ 个查询。在第 $i$ 个查询 $(1 \leq i \leq Q)$ 中，给定整数 $c_i$ 和 $d_i$，求解下面的问题：

- 高桥现在在城镇 $c_i$，青木现在在城镇 $d_i$。他们将同时离开城镇，并以相同的速度开始旅行：
  - 高桥前往城镇 $d_i$
  - 青木前往城镇 $c_i$
  
确定他们是在城镇还是在半路上相遇。假设：
1. 两人都沿着最短的路径行进
2. 经过城镇的时间可以忽略不计

- $2 \leq N \leq 10^5$
- $1 \leq Q \leq 10^5$
- $1 \leq a_i < b_i \leq N$ $(1 \leq i \leq N-1)$
- $1 \leq c_i < d_i \leq N$ $(1 \leq i \leq Q)$
- 所有输入值均为整数
- 通过一些道路可以从每个城镇到达每个城镇（即图是连通的）
___
### 思路
查询树上两点的简单路径的长度，树的边权为$1$，用树链剖分直接求$LCA(最近公共祖先)$，然后减一下$L_{u,v}=L_{1,u}+L_{1,v}-2*L{1,LCA(u,v)}$，判断奇数偶数即可;
### 代码
```c++
#include <bits/stdc++.h>
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
struct HLD {
    int n, idx;
    vector<vector<int>> ver;
    vector<int> siz, dep;
    vector<int> top, son, parent;
    
    HLD(int n) {
        this->n = n;
        ver.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        
        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
    }
    void add(int x, int y) { // 建立双向边
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfs1(int x) {
        siz[x] = 1;
        dep[x] = dep[parent[x]] + 1;
        for (auto y : ver[x]) {
            if (y == parent[x]) continue;
            parent[y] = x;
            dfs1(y);
            siz[x] += siz[y];
            if (siz[y] > siz[son[x]]) {
                son[x] = y;
            }
        }
    }
    void dfs2(int x, int up) {
        top[x] = up;
        if (son[x]) dfs2(son[x], up);
        for (auto y : ver[x]) {
            if (y == parent[x] || y == son[x]) continue;
            dfs2(y, y);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) {
                x = parent[top[x]];
            } else {
                y = parent[top[y]];
            }
        }
        return dep[x] < dep[y] ? x : y;
    }
    int clac(int x, int y) { // 查询两点间距离
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
    void work(int root = 1) { // 在此初始化
        dfs1(root);
        dfs2(root, root);
    }
};

void solve(){
	int n,q;
    cin>>n>>q;
    HLD S(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        S.add(u,v);
    }
    S.work();
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<(S.clac(x,y)%2?"Road":"Town")<<'\n';
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

```

## [ABC207D](https://atcoder.jp/contests/abc207/tasks/abc207_d)
### 问题陈述

给你两个集合 $ S = \{(a_1, b_1), (a_2, b_2), \ldots, (a_N, b_N)\} $ 和 $ T = \{(c_1, d_1), (c_2, d_2), \ldots, (c_N, d_N)\} $，每个集合在二维平面上有 $ N $ 个点。

请判断是否有可能对 $ S $ 按任意顺序进行任意次数（可能为零）的下列运算，从而使 $ S $ 与 $ T $ 相匹配。

- 选择一个实数 $ p $ $ (0 < p < 360) $，将 $ S $ 中的每一点绕原点顺时针旋转 $ p $ 度。
- 选择实数 $ q $ 和 $ r $，将 $ S $ 中的每一点沿 $ x $ 轴方向移动 $ q $ 个单位，沿 $ y $ 轴方向移动 $ r $ 个单位。这里，$ q $ 和 $ r $ 可以是任何实数，无论是正数、负数还是零。

- $ 1 \leq N \leq 100 $
- $ -10 \leq a_i, b_i, c_i, d_i \leq 10 $
- $ (a_i, b_i) \neq (a_j, b_j) $ 如果 $ i \neq j $。
- $ (c_i, d_i) \neq (c_j, d_j) $ 如果 $ i \neq j $。
- 输入值均为整数。

___
### 思路

实际上，解决这个问题总共需要 $O(N \log N)$ 个时间，其中除了排序之外的所有过程都需要 $O(N)$ 个时间。  
首先，将所有坐标乘以 $N$ ，使 $N$ 个点的重心成为整数。  
然后，将 $N$ 个矢量 ${\bf u}$ 相对于重心（即 ${\bf u_i}=(X_i-gx,Y_i-gy)$ ，其中 $(gx, gy)$ 是重心）的集合按角度坐标排序。这里去掉了长度为 $0$ 的（最多一个）矢量。让 ${\bf v}$ 成为排序后的数组。根据它们的长度打破平局。

然后，将排序向量 ${\bf v}$ 的数据转换成以下序列的数据：（ $|{\bf v_1}|,{\bf v_1} \cdot {\bf v_2},{\bf v_1} \times {\bf v_2},|{\bf v_2}|,{\bf v_2} \cdot {\bf v_3},{\bf v_2} \times {\bf v_3}, \dots ,|{\bf v_N}|,{\bf v_N} \cdot {\bf v_1},{\bf v_N} \times {\bf v_1}$ ）、
其中 $\cdot$ 表示向量的内积， $\times$ 表示向量的外积（此处 ${\bf A} \times {\bf B} =A_x \times B_y - A_y \times B_x$ 表示 ${\bf A}=(A_x,A_y) , {\bf B}=(B_x,B_y)$ ）。  
为了保持整数性，我们可以用 $|{\bf v_i}|^2$ 代替 $|{\bf v_i}|$ 。

要解决这个问题，可以通过将元素循环移动三个元素的倍数，检查得到的两个序列是否一一对应；不过时间复杂度可以用 Z 算法改进，最快也要 $O(N)$ 时间。


- 将所有横纵坐标都扩大N倍，避免中心的坐标是小数
- 将零向量去掉，不进行比较？
- 极角排序要先按角度从小到，再按离原点的距离从小到大
- 比较两个点集的时候有三个因素都要对应相同
1. 每一个点到中心点的距离，向量的长度
2. 在任意角度旋转之后与相邻点的夹角的$\sin \theta$
3. 在任意角度旋转之后与相邻点的夹角的$\cos \theta$
### 代码
```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
struct point{
    ld x;
    ld y;
    point operator-(const point &a)const{
        return {x-a.x,y-a.y};
    }
    bool operator==(const point &a)const{
        return x==a.x&&y==a.y;
    }
    bool operator<(const point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};
struct G{
    ld m;
    ld Dot;
    ld Crs;
    bool operator==(const G &a)const{
        return (m==a.m)&&(Dot==a.Dot)&&(Crs==a.Crs);
    }
};
ld dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
ld crs(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
ld df(const point &a){
    return dot(a,a);
}
bool comp(const point &l,const point &r){
	double atl=atan2(l.y,l.x);
	double atr=atan2(r.y,r.x);
	return (atl!=atr)?(atl<atr):(df(l)<df(r));
}
void solve(){
	int n;
    cin>>n;
    if(n==1)cout<<"Yes"<<'\n';
    else{
        vector<point> a(n+1),b(n+1);
        vector<point> s,t;
        vector<G> Sv,Tv;
        ld Sx=0,Sy=0,Tx=0,Ty=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y;
            a[i].x*=n;
            a[i].y*=n;
            Sx+=a[i].x;
            Sy+=a[i].y;
        }
        point S={Sx/n,Sy/n};
        for(int i=1;i<=n;i++){
            point Z={0,0};
            if(a[i]-S==Z){
                continue;
            }
            else{
                s.push_back(a[i]-S);
            }
        }
        for(int i=1;i<=n;i++){
            cin>>b[i].x>>b[i].y;
            b[i].x*=n;
            b[i].y*=n;
            Tx+=b[i].x;
            Ty+=b[i].y;
        }
        point T={Tx/n,Ty/n};
        for(int i=1;i<=n;i++){
            point Z={0,0};
            if(b[i]-T==Z){
                continue;
            }
            else{
                t.push_back(b[i]-T);
            }
        }
        if(s.size()!=t.size())cout<<"No"<<'\n';
        else{
            sort(s.begin(),s.end(),comp);
            sort(t.begin(),t.end(),comp);
            int sn=s.size();
            int tn=t.size();
            s.push_back(s[0]);
            t.push_back(t[0]);
            for(int i=0;i<sn;i++){
                Sv.push_back({df(s[i]),dot(s[i],s[i+1]),crs(s[i],s[i+1])});
            }
            for(int i=0;i<tn;i++){
                Tv.push_back({df(t[i]),dot(t[i],t[i+1]),crs(t[i],t[i+1])});
            }
            int r=Tv.size();
            for(int i=0;i<r;i++){
                Tv.push_back(Tv[i]);
            }
            int ok=0;
            for(int i=0;i<r;i++){
                int res=0;
                for(int j=0;j<r;j++){
                    if(Sv[j]==Tv[j+i]){
                        res++;
                    }
                }
                if(res==r){
                    ok=1;
                }
            }
            cout<<(ok?"Yes":"No")<<'\n';
        }
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

```

## [第十三届山东ICPC省级大学生程序设计大赛 M. Computational Geometry](https://codeforces.com/gym/104417/problem/M)
### 问题陈述
给定一个有 $n$ 个顶点的凸多边形 $P$ ，需要选择 $P$ 的三个顶点，按逆时针方向依次表示为 $a$ 、 $b$ 和 $c$ 。从 $b$ 到 $c$ 必须正好有 $k$ 条按逆时针顺序排列的边（也就是说， $a$ 不是这些 $k$ 边的端点）。

考虑用线段 $ab$ 和 $ac$ 切过 $P$ 。设 $Q$ 是由 $ab$ 、 $ac$ 和 $b$ 与 $c$ 之间的 $k$ 条边组成的多边形。不难看出，这个多边形有 $(k + 2)$ 条边。

求 $Q$ 的最大可能面积。注意 $ab$ 和 $ac$ 可能与 $P$ 的边重叠。

有多个测试用例。输入的第一行包含一个整数 $T$ ，表示测试用例的数量。对于每个测试用例：

第一行包含两个整数 $n$ 和 $k$ ( $3 \le n \le 10^5$ ， $1 \le k \le n-2$ )，表示凸多边形 $P$ 的顶点数，以及按逆时针顺序从 $b$ 到 $c$ 的边数。

对于下面的 $n$ 行， $i$ 行包含两个整数 $x_i$ 和 $y_i$ ( $ -10^9 \le x_i, y_i \le 10^9$ )，表示凸多边形 $P$ 的第 $i$ 个顶点的 $x$ 和 $y$ 坐标。顶点按逆时针顺序给出。保证凸多边形的面积为正，且没有两个顶点的坐标相同。可能有三个顶点位于同一条直线上。

保证所有测试用例的 $n$ 之和不超过 $10^5$ 。

对每个测试用例输出一行，其中包含一个实数，表示 $Q$ 的最大可能面积。如果相对误差或绝对误差小于 $10^{-9}$ ，则认为答案正确。

### 思路
类似旋转卡壳的思路，旋转$b$和$c$双指针同步同向移动$a$，算$bc$所围成多边形面积
拆成若干个三角形面积用向量叉积计算，每一个三角形面积用叉积算的时候，保证后一个向量在相对前一个向量的左边，就算的是正的面积
然后每次用叉积计算$S_{abc}=\vec{bc}\times\vec{ba}$和$S_{a^{'}bc}=\vec{bc}\times\vec{ba^{'}}$，比较大小，移动$a$的位置,最后面积就是$bc$多边形面积加$abc$三角形面积去$max$即可，最后答案输出除以$2$，叉积是两倍面积

### 代码
```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
struct point{
    ll x,y;
    point operator-(const point &a)const{
        return {x-a.x,y-a.y};
    }
};
ll dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
ll crs(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
void solve(){
	int n,k;
    cin>>n>>k;
    vector<point> a(2*n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i+n]=a[i];
    }
    ll S=0;
    for(int i=2;i<=k;i++){
        S+=crs(a[i]-a[1],a[i+1]-a[1]);//后面一个向量相对前面一个向量在左边就是正+
        // cout<<(a[i]-a[1]).x<<" "<<(a[i]-a[1]).y<<'\n';
        // cout<<(a[i+1]-a[1]).x<<" "<<(a[i+1]-a[1]).y<<'\n';
        // cout<<S<<'\n';
    }
    ll ans=0;
    for(int B=1,A=k+1;B<=n;B++){
        int C=B+k;
        while(1){
            ll s1=crs(a[C]-a[B],a[A]-a[B]);//向量减法：末减初
            ll s2=crs(a[C]-a[B],a[A+1]-a[B]);
            if(s2>s1)A++;
            else{
                break;
            }
        }
        ans=max(ans,S+crs(a[C]-a[B],a[A]-a[B]));
        S+=crs(a[B+1]-a[C],a[B+1]-a[C+1])-crs(a[B+1]-a[B],a[C]-a[B]);
        if(A==C)A++;//A点不能和C点重合因为可能A和A+1和C在同一条直线上
        //如果不保持A在相对C的右边，之后A就会到C和B中间去了就WA了
    }
    ld p=2;
    cout<<ans/p<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        cout<<fixed<<setprecision(12);
        solve();
    }
    return 0;
}
```


## [Codeforces Round 1004 (Div. 2) E. White Magic](https://codeforces.com/contest/2067/problem/E)
### 题意
求出最长的子序列长度 $n$ 满足对于 $\forall 1 \le i \le n - 1$，使得


$$
\min \left\{ a_{1}, a_{2}, \dots, a_{i} \right\} \le \text{mex} \left\{ a_{i+1}, a_{i+2}, \dots, a_{n} \right\}
$$
### 思路
先考虑子序列里面没有$0$的情况，那么一定成立，因为任何子序列前缀最小值都大于等于$0$
如果子序列存在两个以上的$0$，那么对于从左到右的第一个零的位置一定不满足，因为从$i+1$位置到$n$的后缀$mex$至少为$1$，所以答案只能是$n-cnt_{0}$或者$n-cnt_{0}+1$，简单判断一下是否有一个$0$的位置左边的前缀都是合法的即可
### 代码
```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
void solve(){
	int n;
    cin>>n;
    int a[n+10],dp[n+10],Mi[n+10];
    Mi[0]=2e9,dp[n+1]=0;
    int c0=0;
    map<int,int>f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        Mi[i]=min(Mi[i-1],a[i]);
        dp[i]=0;
    }
    for(int i=n;i>=1;i--){
        f[a[i]]=1;
        int idx=dp[i+1];
        while(f[idx]){
            idx++;
        }
        dp[i]=idx;
    }
    int ok=0;
    int C0=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(i-1-C0==sum)ok=1;
            C0++;
        }
        if(Mi[i]>=dp[i+1])sum++;
    }
    cout<<n-C0+ok<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
    // freopen("zkx.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [AtCoder Beginner Contest 217 D - Cutting Woods](https://atcoder.jp/contests/abc217/tasks/abc217_d) 
### 问题陈述

我们有一根长 $L$ 米的长木料。  
在距木料左端 $x$ 米处，每隔 $x = 1, 2, \dots, L - 1$ 米有一个称为 $x$ 的标记。

你得到了 $Q$ 个询问，其中的 $i$ 个是一对数字 $(c_{i}, x_{i})$ 。  
按照下面所述，以 $i$ 的升序处理这些查询。

- 如果 $c_{i}= 1$ ：将标记 $x _{i}$ 处的标记一分为二。
- 如果 $c_{i}= 2$ ：选择标记 $x _{i}$ 的标记并打印其长度。

在这里，对于 $c_{i}= 1, 2$ 这两种查询，可以保证在处理查询时，在标记 $x _{i}$ 处没有切割。


### 思路
用$set$维护，每次一分为二就插入$x_{i}$，查询就用set自带的二分函数查找大于$x_{i}$的右端点，然后左端点就是前面一个，包含$x_{i}$的就是$R-L$，如果用`set<piar<int,int>>`不好在`set`中查找
### 代码
```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
void solve(){
	int n,q;
    cin>>n>>q;
    set<int> s;
    s.insert(0),s.insert(n);
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            s.insert(x);
        }
        else{
            int x;
            cin>>x;
            auto it=s.lower_bound(x);
            cout<<*it-*prev(it)<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
    // freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [第十三届山东省ICPC省级大学生程序设计大赛 E. Math Problem](https://codeforces.com/gym/104417/problem/E)

### 问题陈述
给定两个正整数 $n$ 和 $k$ ，你可以执行以下两种类型的运算任意多次（包括零次）：
选择一个满足 $0 \leq x < k$ 的整数 $x$ ，将 $n$ 变为 $k\cdot n+x$ 。执行一次这个操作需要花费 $a$ 枚金币。您每次选择的整数 $x$ 可以是不同的。

将 $n$ 变为 $\lfloor \frac{n}{k} \rfloor$ 。执行一次这个操作需要花费 $b$ 枚金币。请注意， $\lfloor \frac{n}{k} \rfloor$ 是小于或等于 $\frac{n}{k}$ 的最大整数。
给定正整数 $m$ ，计算将 $n$ 变为 $m$ 的倍数所需的最少硬币数。请注意， $0$ 是任何正整数的倍数。
有多个测试用例。输入的第一行包含一个整数 $T$ ( $1\leq T\leq 10^5$ )，表示测试用例的数量。对于每个测试用例
第一行包含五个整数 $n$ 、 $k$ 、 $m$ 、 $a$ 、 $b$ （ $1\leq n\leq 10^{18}$ 、 $1\leq k, m, a, b\leq 10^9$ ）。
对每个测试用例输出一行，其中包含一个整数，表示将 $n$ 变为 $m$ 的倍数所需的最少硬币数。如果无法实现，则输出 $-1$ 。
### 思路
考虑两个操作的性质，相当于把$n$转成$k$进制，操作一就是$n$在$k$进制下左移一位然后末尾加一个$x$，操作二就是$n$在$k$进制下右移一位
于是我们在左移$p$次之后$n$的范围是$[k^{p} \times n,k^{p} \times (n+1) - 1]$
我们就直接枚举使用操作二，就是枚举$n$在$k$进制下的前缀，然后枚举操作一如果在范围里面存在$m$的倍数就记录代价，最后所有情况取$min$
### 代码

```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
void solve(){
    ll n,k,m,a,b;
    cin>>n>>k>>m>>a>>b;
    if(k==1){//k为1特判一下
        if(n%m==0){
            cout<<0<<'\n';
            return ;
        }
        else{
            cout<<-1<<'\n';
            return ;
        }
    }
    ll ans=2e18;
    for(ll i=0;;i++,n/=k){
        if(n==0){//0是任意数的倍数，n/k为0直接break
            ans=min(ans,i*b);
            break;
        }
        __int128_t l=n,r=n;//区间范围
        ll res=i*b;
        while(l/m==r/m&&l%m)//{考虑r和l中的m的倍数个数还要特判l端点
            r=r*k+k-1;
            l=l*k;
            res+=a;
        }
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
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
```

##
## [AtCoder Beginner Contest 212 E - Safety Journey](https://atcoder.jp/contests/abc212/tasks/abc212_e) 

### 问题陈述

AtCoder 共和国有 $N$ 座城市，分别叫做城市 $1$ 、城市 $2$ 、城市 $\ldots$ 城市 $N$ 。起初，每对不同的城市之间都有一条双向道路，但随着时间的推移，其中 $M$ 条道路因老化而无法使用。更具体地说，在每个 $1\leq i \leq M$ 城市中，连接城市 $U_i$ 和城市 $V_i$ 的道路已经无法使用。

高桥将进行 $K$ 天的旅行，起点和终点都是城市 $1$ 。从形式上来说，以城市 $1$ 为起点和终点的 $K$ 天的旅行是 $K+1$ 个城市 $(A_0, A_1, \ldots, A_K)$ 的序列，使得 $A_0=A_K=1$ 成立，并且对于每个 $0\leq i\leq K-1$ ， $A_i$ 和 $A_{i+1}$ 都不同，并且仍然有一条可用的道路连接城市 $A_i$ 和城市 $A_{i+1}$ 。

输出以城市 $1$ 为起点和终点 的$K$天不同行程的次数，求模 $998244353$ 。这里，当存在 $i$ 使得 $A_i\neq B_i$ 不同时，两个 $K$ 天的旅行 $(A_0, A_1, \ldots, A_K)$ 和 $(B_0, B_1, \ldots, B_K)$ 被认为是不同的。

- $2 \leq N \leq 5000$
- $0 \leq M \leq \min\left( \frac{N(N-1)}{2},5000 \right)$
- $2 \leq K \leq 5000$
- $1 \leq U_i<V_i \leq N$
- 所有 $(U_i, V_i)$ 对都是成对不同的。
- 输入的所有值都是整数。

### 思路



### 代码

```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll vis[5050][5050],dp[5050][5050];
vector<vector<int>> e(5050);
int n,m,k;

void solve(){
	
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dp[1][0]=1;
    for(int i=1;i<=k;i++){
        ll sum=0;
        for(int j=1;j<=n;j++){
            sum=(sum+dp[j][i-1])%mod;
        }
        for(int j=1;j<=n;j++){
            dp[j][i]=(sum-dp[j][i-1]+mod)%mod;
        }
        for(int u=1;u<=n;u++){
            for(auto v:e[u]){
                dp[u][i]=(dp[u][i]-dp[v][i-1]+mod)%mod;
            }
        }
    }
    cout<<dp[1][k];
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
```

## [AtCoder Beginner Contest 207 E - Mod i](https://atcoder.jp/contests/abc207/tasks/abc207_e)

### 问题陈述

给定的是由 $N$ 个数字组成的序列 $A$ 。求把 $A$ 分成若干个非空连续子序列 $B _{1}, B _{2}, \ldots, B _{k}$ 从而满足下列条件的方法数：

- 对于每一个 $i\\ (1 \leq i \leq k)$ ， $B _{i}$ 中的元素之和都能被 $i$ 整除。

由于计数可能非常大，因此打印它的模数 $(10^9+7)$ 

- $1 \leq N \leq 3000$
- $1 \leq A _{i} \leq 10^{15}$
- 所有输入值均为整数。
### 思路
$N$范围较小考虑动态规划，那么令$dp_{i,x}$为前$i$个元素划分成$x$段的方案数
$$
dp_{i,x}=dp_{i,x}+dp_{j,x-1}[(sum[i]-sum[j])\%x=0]
$$
时间复杂度为$O(N^{3})$，考虑优化，因为每次转移
$$
dp_{i,x}=\sum_{j=1}^{i-1}dp[j][x-1][(sum[i]-sum[j])\%x=0]
$$
那么考虑对取模做前缀和记录，因为约束为$[(sum[i]-sum[j])\%x=0]$，那么$sum[i]\%x=
sum[j]\%x$，所以需要记录$i$前面所有模$x$为$sum[i]\%x$的$dp$和$f_{x,sum[i]\%x}$
$$
f_{x,sum[i]\%x}=\sum_{j=1}^{i-1}dp[j][x-1][(sum[j]\%x)=(sum[i]\%x)]
$$
那么时间复杂度就降为$O(N^2)$
### 代码
```c++
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
ll dp[3050][3050],f[3050][3050];
ll sum[3050],a[3050];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    f[1][0]=1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=1;x<=n;x++){
            dp[i][x]=(dp[i][x]+f[x][sum[i]%x])%mod;
            f[x][sum[i]%x]=(f[x][sum[i]%x]+dp[i][x-1])%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zkx.in","r",stdin);
    // freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Codeforces Round 1027 (Div. 3) F. Small Operations](https://codeforces.com/contest/2114/problem/F)
### 问题描述

给定一个整数 $x$ 和一个整数 $k$。在一次操作中，可以执行以下两种操作之一：

- 选择一个整数 $1 \le a \le k$ 并将 $x$ 赋值为 $x \cdot a$；
- 选择一个整数 $1 \le a \le k$ 并将 $x$ 赋值为 $\frac{x}{a}$，其中 $\frac{x}{a}$ 必须是整数。

找到使 $x$ 等于 $y$ 所需的最少操作次数，或者确定这是不可能的。

**输入**

输入的第一行包含一个整数 $t$ ($1 \le t \le 10^4$)，表示测试用例的数量。

每个测试用例的唯一一行包含三个整数 $x$，$y$ 和 $k$ ($1 \le x, y, k \le 10^6$)。

保证所有测试用例的 $x$ 之和以及所有测试用例的 $y$ 之和均不超过 $10^8$。

**输出**

对于每个测试用例，如果无法通过给定操作使 $x$ 等于 $y$，则输出 $-1$，否则输出所需的最少操作次数。


### 思路

考虑$x,y$的唯一分解形式
- $x=\prod p_{1}^{\alpha_{1}}p_{2}^{\alpha_{2}}...p_{k}^{\alpha_{k}}$
- $y=\prod q_{1}^{\alpha_{1}}q_{2}^{\alpha_{2}}...q_{n}^{\alpha_{n}}$

我们每次操作类似将$x$的某一些质因子的一些幂次减去或者加上，考虑让操作次数最少并且让$x=y$，所以把$x$比$y$多的部分去掉，再加上$x$比$y$少的部分

那么就变成了先让$x \to gcd(x,y)$ ，再$gcd(x,y) \to y$，就相当于先让$x$除以$\frac{x}{gcd(x,y)}$，然后再乘以$\frac{y}{gcd(x,y)}$

所以现在就变成了对于$k$而且，我们最少操作几次可以凑出$\frac{x}{gcd(x,y)}$和$\frac{y}{gcd(x,y)}$，所以就枚举一下倍数然后用调和级数预处理一下，

对每一个$i$枚举一下倍数$j$，就有 $dp_{j}=min(dp[j/i]+1,dp[j])$

对于每一个测试样例中的$k$从小到大计算答案就可以了

### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
ll x[N],y[N],k[N],ans[N];
vector<ll> r[N];
vector<ll> dp(N,0);
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>k[i];
        r[k[i]].push_back(i);
    }
    for(int i=2;i<N;i++){
        dp[i]=1e18;
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            dp[j]=min(dp[j/i]+1,dp[j]);
        }
        for(auto j:r[i]){
            ans[j]=dp[x[j]/gcd(x[j],y[j])]+dp[y[j]/gcd(x[j],y[j])];
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]>N)cout<<-1<<'\n';
        else{
            cout<<ans[i]<<'\n';
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [#88. [R15D]二维异或和](https://bs.daimayuan.top/p/88)
### 问题描述

给定一个长度为 $ n $ 的整数数组 $ A $。

定义区间 $[L, R]$ 的二维异或和为 $\sum_{i=L}^{R}\sum_{j=L}^{R} A_i \oplus A_j$，这里的 $\oplus$ 表示按位异或运算。

有 $ q $ 个询问，第 $ i $ 个询问求区间 $[L_i, R_i]$ 的二维异或和。


第一行包含两个整数 $ n, q $，分别表示数组 $ A $ 的长度和询问的数量。

第二行包含 $ n $ 个整数 $ A_i $。

接下来 $ q $ 行每行两个整数 $ L_i, R_i $，表示第 $ i $ 个询问。


输出 $ q $ 个整数，第 $ i $ 个整数表示第 $ i $ 个询问的答案。

### 思路

枚举二进制位的个数计算贡献，二进制第$ k $位在$ L $到$ R $中零的个数乘一的个数再乘以$2$再乘$ 2^{k} $，因为相当于 $[L,R]$ 任意选两个算一次，考虑顺序不同也算不同贡献

### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;


void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<ll>> a(n+1,vector<ll>(20,0)); 
    vector<vector<ll>> sum(n+1,vector<ll>(20,0)); 
    int c[n+1];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        for(int j=0;j<20;j++){
            a[i][j]+=(c[i]>>j)&1;
            sum[i][j]=(a[i][j]+sum[i-1][j]);
        }
    }
    for(int i=1;i<=q;i++){
        ll L,R;
        cin>>L>>R;
        ll ans=0;
        for(ll k=0;k<20;k++){
            ll c1=sum[R][k]-sum[L-1][k];
            ll c0=R-L+1-c1;
            if(c1==0||c0==0){
                continue;
            }
            ans+=2ll*c1*c0*(1ll<<k);
        }
        cout<<ans<<" ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [Codeforces Round 1029 (Div. 3)G	Omg Graph](https://codeforces.com/contest/2117/problem/G)
### 问题描述

给定一个无向连通加权图。定义路径的长度为 $k$ 的成本如下：
- 假设路径上各边的权重依次为 $w_1, w_2, \ldots, w_k$。
- 路径的成本为 $(\min_{i = 1}^{k}{w_i}) + (\max_{i=1}^{k}{w_i})$，即最大边权重与最小边权重之和。

在所有从顶点 $1$ 到顶点 $n$ 的路径中，找出成本最小的路径。注意路径不一定是简单路径。

**输入**

第一行包含一个整数 $t$ ($1 \le t \le 10^4$)，表示测试用例的个数。

每个测试用例的第一行包含两个整数 $n$ 和 $m$ ($2 \le n \le 2 \cdot 10^5, n - 1 \le m \le \min(2 \cdot 10^5, \frac{n(n - 1)}{2})$)。

接下来的 $m$ 行中，每行包含三个整数 $u, v, w$ ($1 \le u, v \le n, 1 \le w \le 10^9$)，表示顶点 $u$ 到顶点 $v$ 的一条边，权重为 $w$。保证图中不存在自环或多重边，且图是连通的。

保证所有测试用例的 $n$ 之和不超过 $2 \cdot 10^5$，所有测试用例的 $m$ 之和不超过 $2 \cdot 10^5$。

**输出**

对于每个测试用例，输出一个整数，表示从顶点 $1$ 到顶点 $n$ 的最小成本路径。
### 思路

类似最小生成树的思路，按边权从小到大依次使用并查集维护当前每一个连通块的最小值，如果在某一次连边合并之后$1$和$n$处于同一个连通块中了，那么考虑枚举以当前边作为最大的边一直取$min$就可以了，因为我们先将所有变按边权排序了，所以每次枚举的边权一定是逐渐增大的，如果在先前1和n就已经是同一个并查集里面了，那么之后的值肯定劣于之前取的$min$


### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
struct DSU {
    std::vector<ll> f, siz ,Mi;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        Mi.assign(n,1e18);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y,ll w) {
        x = find(x);
        y = find(y);
        if (x == y) {
            Mi[x]=min({Mi[y],Mi[x],w});
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        Mi[x]=min({Mi[y],Mi[x],w});
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,PII>> a;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a.push_back({w,{u,v}});
    }
    sort(a.begin(),a.end());
    DSU T(n+10);
    ll ans=1e18;
    for(int i=0;i<m;i++){
        T.merge(a[i].second.first,a[i].second.second,a[i].first);
        if(T.same(1,n)){
            ans=min(ans,T.Mi[T.find(1)]+a[i].first);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```




## [2025 年江苏省大学生节目制作大赛、2025 年广东省大学生节目制作大赛 J. Puzzle Competition](https://codeforces.com/gym/105945/problem/J)

### 问题描述

年度 CCPC（密码与代码渗透竞赛）即将开始，今年的竞赛采用了独特的问题发布方式。本次竞赛共有 $n$ 个问题，编号从 $1$ 到 $n$。与往年不同，今年的问题并非在竞赛开始时全部解锁，而是逐步解锁。组委会根据问题之间的关系构建了一个有向图，图中有 $n$ 个节点，每个节点代表一个问题。初始时，每个问题的能量值为 $0$，每个问题有一个参数 $a_i$，表示当该问题的能量值大于或等于 $a_i$ 时，该问题将立即解锁。一旦解锁，该节点的所有出边将同时向目标问题传递 $1$ 点能量，传递过程需要 $w_i$ 秒。

然而，组委会发现有些问题可能永远不会被解锁，这需要避免。因此，他们设计了 $k$ 个强制刷新器来帮助参赛者。每个强制刷新器控制若干个问题，并在激活时（时间 $t_i$ 秒）立即将其控制的问题的 $a_i$ 参数修改为 $0$。

现在，对于每个问题，需要确定其最早解锁时间，或者判断它是否永远无法解锁。

**输入**

第一行包含三个整数 $n,m,k$ ($3 \le n \le 10^5,0 \le m \le 10^6,0\le k \le 10^5$)，分别表示问题数量、有向边数量和强制刷新器数量。

第二行包含 $n$ 个整数 $a_i$ ($0 \le a_i \le 10^5$)，表示每个问题的参数。保证至少存在一个 $i$ 使得 $a_i=0$。

接下来的 $k$ 行中，第 $j$ 行包含两个整数 $t_j,sc_j$ ($0\le t_j \le 10^9,1\le sc_j\le n$)，表示第 $j$ 个强制刷新器在 $t_j$ 秒激活，控制 $sc_j$ 个问题，后面跟着 $sc_j$ 个整数 $id_1,\ldots,id_{sc_j}$ ($1\le id_l\le n$)，表示该强制刷新器控制的问题编号。保证一个强制刷新器控制的问题互不相同。

接下来的 $m$ 行中，每行包含三个整数 $u,v,w$ ($1\le u,v\le n,0\le w\le 10^9,u\neq v$)，表示从问题 $u$ 到问题 $v$ 的一条有向边，传递 $1$ 点能量需要 $w$ 秒。

保证 $\sum sc_i \le 10^6$。

**输出**

输出一行，包含 $n$ 个整数，表示每个问题的最早解锁时间。如果某个问题永远无法解锁，输出 $-1$。

### 思路

用小根堆把每一个要开启的点跟时间存进去，每次让时间最小的出队，然后先它所连接的边发送能量，然后每一个点$y$有一个大根堆，维护前$a[y]$小的能量到达时间，如果当前的点$y$满足`g[y].size()==a[y]`，那么就先把这个`g[y].top()`入堆,就是$y$点当前的第$a[y]$小的时间，如果之后这个点又有更早的可能性那么又会重新将新的更早的时间再入队，因为我们每次只取一个点最早的时候，而且如果一个点已经激活了那么之后就可以不用管了，这个时候的时间已经没有之前的优了

### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    ll a[n+1];
    priority_queue<PII,vector<PII>,greater<PII>> q;
    vector<vector<PII>>e(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            q.push({0,i});
        }
    }
    for(int i=1;i<=k;i++){
        int t,cnt;
        cin>>t>>cnt;
        for(int j=1;j<=cnt;j++){
            int x;
            cin>>x;
            q.push({t,x});
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    priority_queue<ll> g[n+1];
    vector<ll> ans(n+1,-1); 
    while(!q.empty()){
        auto [t,j]=q.top();
        q.pop();
        if(ans[j]!=-1)continue;
        ans[j]=t;
        for(auto [y,w]:e[j]){
            g[y].push(w+t);
            while(g[y].size()>a[y])g[y].pop();
            if(g[y].size()==a[y]&&ans[y]==-1){
                q.push({g[y].top(),y});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [2025 年江苏省大学生节目制作大赛、2025 年广东省大学生节目制作大赛 H. Loose Subsequences](https://codeforces.com/gym/105945/problem/H)

### 问题描述

给定一个长度为 $n$ 的仅由小写字母组成的字符串 $S$，建立以下约定：

- 子序列：从 $S$ 中提取若干元素（不一定是连续的）且不改变其相对位置形成的序列称为 $S$ 的子序列。
- $k$ 松散子序列：如果 $S$ 的一个子序列中任意两个相邻字符在原字符串中的位置至少相隔 $k$ 个位置，则该子序列称为 $S$ 的一个 $k$ 松散子序列。具体来说，对于 $S$ 的一个长度为 $m$ 的子序列 $T = \overline{S_{pos_{1}}S_{pos_{2}}\cdots S_{pos_{m}}}$，当且仅当对于所有 $i \in [1, m - 1]$，满足 $pos_{i + 1} - pos_{i} > k$ 时，$T$ 是 $S$ 的一个 $k$ 松散子序列。

现在，给定一个非负整数 $k$，需要计算 $S$ 的不同非空 $k$ 松散子序列的数量，并输出结果对 998244353 取模后的值。

两个子序列 $A$ 和 $B$ 被认为是不同的当且仅当它们的长度不同，或者存在一个索引 $i$ 使得 $A_i \neq B_i$。

**输入**

第一行包含一个整数 $T$ ($1 \le T \le 10^6$)，表示测试用例的数量。

对于每个测试用例，第一行包含两个整数 $n, k$ ($1 \le n \le 10^6, 0 \le k \le n$)，如问题描述中所述。

第二行包含一个长度为 $n$ 的字符串 $S$，保证仅由小写字母组成。

保证所有测试用例的 $\sum n$ 不超过 $10^6$。

**输出**

对于每个测试用例，输出一个整数，表示 $S$ 的不同非空 $k$ 松散子序列的数量对 $998244353$ 取模后的结果。


### 思路


1. **状态定义**  
   令 `dp[i]` 表示“所有以位置 $i$ 字符结尾的、满足 $k$-loose 且本质不同的子序列数量”。  
   最终答案即为：  
   $$\displaystyle \sum_{i=1}^n dp[i]\pmod{998244353}.$$

2. **前缀和优化**  s
   维护前缀和 `g[i] = dp[1] + dp[2] + … + dp[i]`，这样可以 $O(1)$ 求任意区间和。

3. **上次出现位置**  
   对于每个字符 `c`，用数组 `last[c]` 记录其在当前索引之前的**最近一次**出现位置。

4. **状态转移**

   - **可接入的前缀**  
     若要在位置 $i$ 选字符 $S[i]$ 作为新子序列末尾，则前一个字符必须来自下标 $\le i-k-1$。  
     因此，所有合法前缀的贡献数为  

     $$
       \sum_{j=0}^{i-k-1} dp[j]\;+\;1
       =(\;g[i-k-1]\;+\;1\;),
     $$

     其中 $\!+1$ 对应“只选 $S[i]$ 单字符”这一情况。

   - **去重**  
     如果字符 $S[i]$ 之前最后一次出现在位置 $last[c]$，那么“在 $last[c]$ 处末尾再接 $S[i]$”的部分，会与“在 $i$ 处直接接”的一些序列重复，需要减去：  

     $$
       \sum_{j=0}^{\,last[c]-k-1}dp[j]\;+\;1
       =(\;g[last[c]-k-1]\;+\;1\;)
     $$

   - **最终公式**  
 
     $$
       dp[i]
       =\Bigl(g[i-k-1]+1\Bigr)
       -\Bigl(g[last[c]-k-1]+1\Bigr)
       \quad(\bmod\,998244353)
     $$


     其中若下标越界则对应项视为 $0$ 或者只保留“$+1$”部分。


### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    map<char,int> last;
    for(char i='a';i<='z';i++){
        last[i]=-1;
    }
    vector<ll> dp(n+10,0);
    vector<ll> g(n+10,0);
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i-k-1>=0)dp[i]=(g[i-k-1]+1)%mod;
        else{
            dp[i]=1;
        }
        if(last[a[i]]!=-1){
            if(last[a[i]]-k-1>=0){
                dp[i]=(dp[i]-(g[last[a[i]]-k-1]+1)%mod+mod)%mod;
            }
            else{
                dp[i]=(dp[i]-1+mod)%mod;
            }
        }
        if(i>=1){
            g[i]=(g[i-1]+dp[i])%mod;
        }
        else{
            g[i]=dp[i];
        }
        ans=(ans+dp[i])%mod;
        last[a[i]]=i;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [P6242 【模板】线段树 3（区间最值操作、区间历史最值）](https://www.luogu.com.cn/problem/P6242)

### 问题描述

本题是线段树维护区间最值操作与区间历史最值的模板。

给出一个长度为 $n$ 的数列 $A$，同时定义一个辅助数组 $B$，$B$ 开始与 $A$ 完全相同。接下来进行了 $m$ 次操作，操作有五种类型，按以下格式给出：

- `1 l r k`：对于所有的 $i\in[l,r]$，将 $A_i$ 加上 $k$（$k$ 可以为负数）。
- `2 l r v`：对于所有的 $i\in[l,r]$，将 $A_i$ 变成 $\min(A_i,v)$。
- `3 l r`：求 $\sum_{i=l}^{r}A_i$。
- `4 l r`：对于所有的 $i\in[l,r]$，求 $A_i$ 的最大值。
- `5 l r`：对于所有的 $i\in[l,r]$，求 $B_i$ 的最大值。

在每一次操作后，我们都进行一次更新，让 $B_i\gets\max(B_i,A_i)$。

**输入格式**

第一行包含两个正整数 $n,m$，分别表示数列 $A$ 的长度和操作次数。

第二行包含 $n$ 个整数 $A_1,A_2,\cdots,A_n$，表示数列 $A$。

接下来 $m$ 行，每行行首有一个整数 $op$，表示操作类型；接下来两个或三个整数表示操作参数，格式见【题目描述】。

**输出格式**

对于 $op\in\{3,4,5\}$ 的操作，输出一行包含一个整数，表示这个询问的答案。

### 思路



### 代码
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 10;
const ll INF = 1e18;

struct Node {
    int l, r;
    ll sum;          // 区间和
    ll max1;         // 区间当前最大值
    ll se;           // 区间严格次大值
    ll his_max;      // 区间历史最大值
    int cnt;         // 最大值个数
    ll add1;         // 最大值的加法懒标记
    ll add2;         // 非最大值的加法懒标记
    ll add3;         // 最大值加法标记的历史最大值
    ll add4;         // 非最大值加法标记的历史最大值
} tree[MAXN * 4];

int n, m;
ll a[MAXN];

void push_up(int p) {
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
    tree[p].max1 = max(tree[p<<1].max1, tree[p<<1|1].max1);
    tree[p].his_max = max(tree[p<<1].his_max, tree[p<<1|1].his_max);

    if (tree[p<<1].max1 == tree[p<<1|1].max1) {
        tree[p].se = max(tree[p<<1].se, tree[p<<1|1].se);
        tree[p].cnt = tree[p<<1].cnt + tree[p<<1|1].cnt;
    } else if (tree[p<<1].max1 > tree[p<<1|1].max1) {
        tree[p].se = max(tree[p<<1].se, tree[p<<1|1].max1);
        tree[p].cnt = tree[p<<1].cnt;
    } else {
        tree[p].se = max(tree[p<<1].max1, tree[p<<1|1].se);
        tree[p].cnt = tree[p<<1|1].cnt;
    }
}

void update(int p, ll k1, ll k2, ll k3, ll k4) {
    // 更新区间和
    tree[p].sum += k1 * tree[p].cnt + k2 * (tree[p].r - tree[p].l + 1 - tree[p].cnt);
    // 更新历史最大值
    tree[p].his_max = max(tree[p].his_max, tree[p].max1 + k3);
    // 更新当前最大值
    tree[p].max1 += k1;
    // 更新次大值（如果存在）
    if (tree[p].se != -INF) tree[p].se += k2;
    // 更新懒标记
    tree[p].add3 = max(tree[p].add3, tree[p].add1 + k3);
    tree[p].add4 = max(tree[p].add4, tree[p].add2 + k4);
    tree[p].add1 += k1;
    tree[p].add2 += k2;
}

void push_down(int p) {
    // 找到左右子树的最大值，用于判断下传的标记类型
    ll max_val = max(tree[p<<1].max1, tree[p<<1|1].max1);
    // 处理左子树
    if (tree[p<<1].max1 == max_val) {
        update(p<<1, tree[p].add1, tree[p].add2, tree[p].add3, tree[p].add4);
    } else {
        update(p<<1, tree[p].add2, tree[p].add2, tree[p].add4, tree[p].add4);
    }
    // 处理右子树
    if (tree[p<<1|1].max1 == max_val) {
        update(p<<1|1, tree[p].add1, tree[p].add2, tree[p].add3, tree[p].add4);
    } else {
        update(p<<1|1, tree[p].add2, tree[p].add2, tree[p].add4, tree[p].add4);
    }
    // 重置父节点的懒标记
    tree[p].add1 = tree[p].add2 = tree[p].add3 = tree[p].add4 = 0;
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add1 = tree[p].add2 = tree[p].add3 = tree[p].add4 = 0;
    if (l == r) {
        tree[p].sum = a[l];
        tree[p].max1 = a[l];
        tree[p].his_max = a[l];
        tree[p].se = -INF;
        tree[p].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    push_up(p);
}

void update_add(int p, int l, int r, ll k) {
    if (l <= tree[p].l && tree[p].r <= r) {
        update(p, k, k, k, k);
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) update_add(p<<1, l, r, k);
    if (r > mid) update_add(p<<1|1, l, r, k);
    push_up(p);
}

void update_min(int p, int l, int r, ll v) {
    if (v >= tree[p].max1) return;
    if (l <= tree[p].l && tree[p].r <= r && v > tree[p].se) {
        update(p, v - tree[p].max1, 0, v - tree[p].max1, 0);
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) update_min(p<<1, l, r, v);
    if (r > mid) update_min(p<<1|1, l, r, v);
    push_up(p);
}

ll query_sum(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    ll res = 0;
    if (l <= mid) res += query_sum(p<<1, l, r);
    if (r > mid) res += query_sum(p<<1|1, l, r);
    return res;
}

ll query_max(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].max1;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    ll res = -INF;
    if (l <= mid) res = max(res, query_max(p<<1, l, r));
    if (r > mid) res = max(res, query_max(p<<1|1, l, r));
    return res;
}

ll query_his_max(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].his_max;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    ll res = -INF;
    if (l <= mid) res = max(res, query_his_max(p<<1, l, r));
    if (r > mid) res = max(res, query_his_max(p<<1|1, l, r));
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    while (m--) {
        int op, l, r;
        ll k, v;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%lld", &l, &r, &k);
            update_add(1, l, r, k);
        } else if (op == 2) {
            scanf("%d%d%lld", &l, &r, &v);
            update_min(1, l, r, v);
        } else if (op == 3) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query_sum(1, l, r));
        } else if (op == 4) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query_max(1, l, r));
        } else if (op == 5) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query_his_max(1, l, r));
        }
    }
    return 0;
}
```


## [AtCoder Beginner Contest 210 E - Ring MST ](https://atcoder.jp/contests/abc210/tasks/abc210_e)

### 题目描述

- 给定一张 $n$ 个点的图，顶点的编号为 $[0, n - 1]$，同时给出两个长度为 $m$ 的数组 $a_1, a_2, \cdots, a_m$ 和 $b_1, b_2, \cdots, b_m$。

- 初始时图中并没有任何边，你可以按照以下操作加边：选择一个 $1 \le i \le m$ 和一个 $0 \le x < n$，并在顶点 $x$ 和顶点 $(x + a_i) \bmod n$ 中添加一条长度为 $b_i$ 的边。

- 你现在想要知道，你添加的边的长度总和至少为多少，才能使得整个图连通?如果无论如何都不能使整个图连通，输出 `-1`。

**输入格式**

- 第一行包含两个整数 $n, m$，分别表示图的顶点个数和数组的数组的长度。

- 接下来 $m$ 行，第 $i$ 行包含两个整数 $a_i, b_i\space(1 \le a_i \le n - 1)$。

**输出格式**

- 输出一个数，表示答案。

### 思路

首先我们可以想到把 $(x, (x + a_i) \mod n)$ 看成一条边，然后答案就是最小生成树，使用Kruskal，时间复杂度是 $O(nm \log nm)$。

模拟Kruskal的算法过程。把 $(a_i, b_i)$ 按照 $b_i$ 升序排序，然后考虑尽可能的用较前的 $(a_i, b_i)$ 来建边。假设只加了 $(a_1, b_1)$ 的边，那么有一个结论：令 $g = \gcd(a_1, n)$，则所有模 $g$ 相同的节点均可以连到同一个连通块，并且会有 $g$ 个这样的连通块。

以此类推，如果用了前 $i$ 种边，则令 $g = \gcd(a_1, a_2, \cdots, a_i, n)$，上述结论仍然成立。当 $g = 1$ 时，图就联通了。令 $g_i$ 表示加入前 $i$ 种边之后的 $g$ 值，边权之和只要用 $\sum_{i=1}^m (g_{i−1} − g_i) \times b_i$ 计算即可。时间复杂度 $O(m \log n)$。


**数论上的可达性条件**

直接用数论分析从 $x$ 到 $y$ 的可达性。

* 从 $x$ 经过若干步长 $\pm a$ 到达 $y$，当且仅当存在整数 $k$ 使得

  $$
    x + k\,a \equiv y \pmod{n}
    \quad\Longleftrightarrow\quad
    k\,a \equiv y - x \pmod{n}.
  $$
* 方程 $k\,a \equiv d\pmod{n}$ 有解的充要条件是
  $\gcd(a,n)\mid d$。记 $g=\gcd(a,n)$，则等价于

  $$
    g \mid (y - x)
    \quad\Longleftrightarrow\quad
    y\equiv x\pmod{g}.
  $$
* 因此，恰当且仅当 $x$ 与 $y$ 同属一个模 $g$ 的同余类时，二者在图中连通。


综上，无论从群论还是从线性同余方程的角度，都可以得出：

> **只加入步长为 $a$ 的边时，图分成 $\gcd(a,n)$ 个连通块；每个连通块恰是一个模 $\gcd(a,n)$ 的同余类。**

考虑推广到多条边的情况，下面给出纯粹数论（线性同余与裴蜀恒等式）意义下的严格证明，说明当我们同时允许步长 $a_1,\dots,a_i$ 时，恰有

$$
g_i \;=\;\gcd(a_1,a_2,\dots,a_i,n)
$$

个连通块，每个连通块对应一个模 $g_i$ 的同余类。

---


在图中，从顶点 $x$ 出发，经过若干条步长属于 $\{a_1,\dots,a_i\}$ 的边（可向前“加”或向后“减”），到达顶点 $y$ 的条件等价于：存在整数系数 $k_1,\dots,k_i$ 使得

$$
  x + \sum_{j=1}^i k_j\,a_j \;\equiv\; y \pmod{n}.
$$

两边移项可写为

$$
  \sum_{j=1}^i k_j\,a_j \;\equiv\; y - x \pmod{n}.
$$

也即

$$
  \sum_{j=1}^i k_j\,a_j \;-\;(y - x) \;=\; t\,n
  \quad(t\in\mathbb Z).
$$

这是一条**线性丢番图方程**。

---

**解的存在性与 gcd 的约束**

经典数论告诉我们：方程

$$
  u_1\,a_1 + u_2\,a_2 + \cdots + u_i\,a_i + v\,n = d
$$

在整数 $(u_1,\dots,u_i,v)$ 中有解，**当且仅当**

$$
  d \;\text{是}\;\gcd(a_1,\dots,a_i,n)\text{的倍数}.
$$

令

$$
  g_i = \gcd(a_1,\dots,a_i,n),
  \quad d = y - x.
$$

则可达性（上式有解）等价于

$$
  g_i \;\bigm|\;(y - x)
  \quad\Longleftrightarrow\quad
  y \equiv x\pmod{g_i}.
$$

---

**连通块划分**

* 当且仅当两点 $x,y$ 满足 $y - x\equiv 0\pmod{g_i}$，它们之间才存在一条（或多条）合法路径。
* 于是顶点集合被分成若干个互不连通的“等差”子集

  $$
    \{\,x\,:\,x\equiv r\pmod{g_i}\},
    \quad r=0,1,\dots,g_i-1.
  $$
* 这样的同余类一共有 $g_i$ 个，且每个同余类内部任意两点都可互达。

---

**结论**

1. **连通块数**：$g_i$。
2. **每个连通块**：即对应一个模 $g_i$ 的同余类。
3. **完全连通**（单个连通块）发生当且仅当 $g_i=1$。

这就是利用数论中“线性丢番图方程有解当且仅当其右端是系数的 $gcd$ 的倍数的结论，推出来的混用多种步长时连通块结构。



### 代码


```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>a(m+1);
    int d=n;
    for(int i=1;i<=m;i++){
        cin>>a[i].second>>a[i].first;
        d=gcd(d,a[i].second);
    }
    if(d!=1){
        cout<<-1<<'\n';
    }
    else{
        sort(a.begin()+1,a.end());
        ll ans=0;
        ll g[m+1];
        g[0]=n;
        for(int i=1;i<=m;i++){
            if(i==1){
                g[i]=gcd(a[i].second,n);
            }
            else{
                g[i]=gcd(g[i-1],a[i].second);
            }
            ans+=(g[i-1]-g[i])*a[i].first;
        }
        cout<<ans<<'\n';   
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Codeforces Round 974 (Div. 3)E.Rendez-vous de Marian et Robin](https://codeforces.com/contest/2014/problem/E)

### 题目描述

在相会的那一刻，快乐如花蕾绽放。

离别让思念愈发深切。Marian 在集市卖完了最后一件货物的瞬间，Robin 刚好在 Major Oak （橡树下）完成了训练。他们迫不及待地想见到对方，于是立即出发。

旅行网络由 $n$ 个顶点（编号 $1$ 到 $n$）和 $m$ 条边组成。第 $i$ 条边连接顶点 $u_i$ 和 $v_i$，通行需要 $w_i$ 秒（所有 $w_i$ 均为偶数）。Marian 从顶点 $1$（集市）出发，Robin 从顶点 $n$（橡树下）出发。

此外，在这 $n$ 个顶点中，有 $h$ 个顶点各自配备了一匹马上。Marian 和 Robin 都会骑马，上马和下马都不耗时（即耗时为 $0$ 秒）。骑马后，旅行时间将减半，且下马后马匹随即消失（也即一旦上马，就可在剩余全程都以骑马速度行进）。两人只能在顶点上会面（不能在边上相遇），他们也可以在任意顶点等待。

请你计算他们最早可以在第几秒见面。如果顶点 $1$ 与顶点 $n$ 不连通，则输出 $-1$。

---

**输入格式**

* 第一行包含一个整数 $t$（$1 \le t \le 10^4$）——测试用例数量。
* 每个测试用例第一行包含三个整数 $n, m, h$（$2 \le n \le 2\cdot10^5$, $1 \le m \le 2\cdot10^5$, $1 \le h \le n$）——顶点数、边数，以及有马的顶点数量。
* 第二行包含 $h$ 个互不相同的整数 $a_1,a_2,\dots,a_h$（$1 \le a_i \le n$），表示哪些顶点各有一匹马。
* 接下来 $m$ 行，每行三个整数 $u_i,v_i,w_i$（$1\le u_i,v_i\le n$, $2\le w_i\le 10^6$），表示在顶点 $u_i$ 和 $v_i$ 之间有一条权值为 $w_i$ 秒的无向边。保证所有 $w_i$ 均为偶数，且无自环或重边。
* 保证所有测试用例中 $n$ 与 $m$ 的总和均不超过 $2\cdot10^5$。

**输出格式**

对于每个测试用例，输出一个整数——他们最早可以在第几秒见面；如果不可能相遇，则输出 $-1$。
### 思路
 
分层图，一个是原图，一个是上马之后的边权都减半的图，考虑将有马的点跟$ \frac{w}{2}  $的图层连边相连，那么就是$i \to i+n $, 那么接下来就是跑两次最短路，一个求$ 1 $到所有点的最短路，再求终点$ n $到所有点的最短路，那么答案是一个点$ 1 $到某一个点的时间和$ n $到这个点的时间的$ max $，那么到这个点可以骑马也可以不骑马，所以要取$ min $ ，枚举一下$ 1 $到 $ n $ 取$ min $就可以了

那么如果出现有某个有马的点又被$ 1 $经过又被$ n $经过，但是这个点只有一个马，会不会求的有问题呢?想一想就会发现并不会，因为如果这个点在$ 1 $和$ n $的某一个路径中都被经过，那么肯定到这个点会更早，并且先到的会等另外一个人


### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<PII>> e(2*n+10);
    for(int i=1;i<=h;i++){
        int x;
        cin>>x;
        e[x].push_back({0,x+n});
        e[x+n].push_back({0,x});
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({w,v});
        e[v].push_back({w,u});
        e[u+n].push_back({w/2,v+n});
        e[v+n].push_back({w/2,u+n});
    }
    vector<ll>d1(2*n+10,1e18);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    d1[1]=0;
    vector<int> v(2*n+10,0);
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [w,y]:e[t]){
            if(d1[y]>w+d1[t]){
                d1[y]=w+d1[t];
                q.push({d1[y],y});
            }
        }
    }
    vector<ll>d2(2*n+10,1e18);
    q.push({0,n});
    d2[n]=0;
    for(int i=1;i<=2*n;i++){
        v[i]=0;
    }
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [w,y]:e[t]){
            if(d2[y]>w+d2[t]){
                d2[y]=w+d2[t];
                q.push({d2[y],y});
            }
        }
    }   
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        ans=min(ans,max(min(d1[i],d1[i+n]),min(d2[i],d2[i+n])));
    }
    if(ans==1e18){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans<<'\n';
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [P4568 [JLOI2011] 飞行路线](https://www.luogu.com.cn/problem/P4568)

### 题目描述

Alice 和 Bob 现在要乘飞机旅行，他们选择了一家相对便宜的航空公司。该航空公司一共在 $n$ 个城市设有业务，设这些城市分别标记为 $0$ 到 $n-1$，一共有 $m$ 种航线，每种航线连接两个城市，并且航线有一定的价格。

Alice 和 Bob 现在要从一个城市沿着航线到达另一个城市，途中可以进行转机。航空公司对他们这次旅行也推出优惠，他们可以免费在最多 $k$ 种航线上搭乘飞机。那么 Alice 和 Bob 这次出行最少花费多少？

**输入格式**

第一行三个整数 $n,m,k$，分别表示城市数，航线数和免费乘坐次数。

接下来一行两个整数 $s,t$，分别表示他们出行的起点城市编号和终点城市编号。

接下来 $m$ 行，每行三个整数 $a,b,c$，表示存在一种航线，能从城市 $a$ 到达城市 $b$，或从城市 $b$ 到达城市 $a$，价格为 $c$。

**输出格式**

输出一行一个整数，为最少花费。
### 思路 

分成$k+1$层图 每一层图相同 但是本层内每有一条边，就要向下一层的对应点连一个边权为$0$的边，因为考虑这一层跑最短路那么就是走了$0$次跨层，那么如果要跨层那么次数就增加一次，因为最多$k$次所以有$0$到$k$层，那什么时候可以到下一层去呢?就是最初的图中有边的两个点就可以在不同层建边，注意这个层之间的边只能从小的到大的，这样就可以保证每走一次就会到下一层，不会反复到同一层去，最后对所有层的终点取$min$就可以了

### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int s,t;
    cin>>s>>t;
    vector<vector<PII>> e((k+1)*n); 
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({w,v});
        e[v].push_back({w,u});
        for(int j=1;j<=k;j++){
            e[u+j*n].push_back({w,v+j*n});
            e[v+j*n].push_back({w,u+j*n});


            e[v+(j-1)*n].push_back({0,u+j*n});
            e[u+(j-1)*n].push_back({0,v+j*n});
        }
    }
    vector<ll> d((k+1)*n,1e18);
    d[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});
    vector<int> v((k+1)*n,0);
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [w,y]:e[t]){
            if(d[y]>d[t]+w){
                d[y]=d[t]+w;
                q.push({d[y],y});
            }
        }
    }
    ll ans=1e18;
    for(int i=0;i<=k;i++){
        ans=min(ans,d[t+i*n]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Codeforces Round 1033 (Div. 2) and CodeNite 2025 D. Matrix game](https://codeforces.com/contest/2120/problem/D)

### 题目描述

Aryan 和 Harshith 玩一个游戏。两人最初共有三个整数 $a$、$b$ 和 $k$。游戏流程如下：

1. Aryan 先给 Harshith 两个整数 $n$ 和 $m$。
2. 然后 Harshith 构造一个大小为 $n$ 行、$m$ 列的矩阵 $X$，矩阵中每个元素都是从 $1$ 到 $k$ 之间的整数（包含端点）。
3. 如果 Aryan 能从 $X$ 中找到一个大小为 $a\times b$ 的子矩阵 $Y$，使得 $Y$ 中所有元素都相等，则 Aryan 获胜。

> **子矩阵**：可以通过从原矩阵中删除若干行和／或若干列得到。

Aryan 给出 $a$、$b$、$k$ 这三个参数，要求你计算一个**字典序最小**的 $(n,m)$ 对，使得对于任意 Harshith 构造的矩阵 $X$，Aryan 都能找到满足条件的子矩阵。假设 Harshith 总是最优地（也就是说，尽可能让 Aryan 失败）构造矩阵。由于 $n$ 和 $m$ 可能很大，答案需对 $10^9+7$ 取模。

所谓字典序最小，是指：$(n_1,m_1)$ 比 $(n_2,m_2)$ 字典序更小，当且仅当

* $n_1 < n_2$，或者
* $n_1 = n_2$ 且 $m_1 < m_2$。

**输入格式**

第一行一个整数 $t$（$1\le t\le 10^4$），表示测试用例数。
接下来 $t$ 行，每行三个整数 $a,b,k$（$1\le a,b,k\le 10^5$），保证所有测试用例中 $\max(a,b,k)$ 的总和不超过 $10^5$。

**输出格式**

对每个测试用例，输出一行，包含两个整数 $n$ 和 $m$，表示答案。$n$ 和 $m$ 都需对 $10^9+7$ 取模。

### 思路

这个解法核心上就是在“行”上和“列”上各用一次鸽巢原理（Pigeonhole Principle），保证无论 Harshith 怎么填，Aryan 都能找到一个全相同元素的 $a\times b$ 子矩阵。下面分两步来讲：

---

1. 确定最小的 $n$（行数）

* **目标**：保证每一列中，一定能找到 $a$ 个相同的元素。
* 如果列高为 $n=k(a-1)+1$，把 $n$ 个元素分成 $k$ 种可能的取值，鸽巢原理告诉我们：

  $$
    n = k(a-1) + 1
    \quad\Longrightarrow\quad
    \text{某个值 }v\in[1,k]\text{，在这一列中至少出现 }a\text{ 次。}
  $$
* 所以取

  $$
    n = k\,(a-1) + 1.
  $$

---

2. 确定最小的 $m$（列数）

* 在每一列，我们都能挑出一组大小为 $a$ 的“行号集合”$\{p_1<p_2<\cdots<p_a\}$，以及那 $a$ 个位置上共同出现的值 $v$。

* 把每列看成一个“类型”——用一个元组来表示：

  $$
    \bigl(v,\;p_1,p_2,\dots,p_a\bigr).
  $$

* 这个元组一共有多少种可能？

  1. $v$ 有 $k$ 种选法；
  2. $\{p_1,\dots,p_a\}$ 是从 $n$ 行中选 $a$ 行出来的组合，种数是 $\displaystyle\binom{n}{a}$。

  因此总共

  $$
    T = k\times \binom{n}{a}
  $$

  种不同的“列类型” 。

* **要把这些列类型凑出 $b$ 列“同类型”**，再用一次鸽巢原理：
  如果你有 $m$ 列，鸽巢数量是 $T$，要保证至少有一个类型出现 $b$ 次，就需要

  $$
    m \;=\; (b-1)\,T\;+\;1.
  $$

  这样无论 Harshith 怎么布置，只要 $m$ 列，你就能凑出 $b$ 列相同类型，和那每列中选出的 $a$ 行，合起来就是一个 $a\times b$ 全相同的子矩阵。

---

### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=a*res%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inv(ll x){
    return qmi(x,mod-2);
}
void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    ll n=k*(a-1)+1ll;
    ll m=k*(b-1)%mod;
    for(ll i=n,j=1;i>=n-a+1;i--,j++){
        m=(m*(i%mod))%mod;
        m=m*inv(j)%mod;
    }
    cout<<n%mod<<" "<<(m+1ll)%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Codeforces Round 1032 (Div. 3) F. Yamakasi](https://codeforces.com/contest/2121/problem/F)

### 题目描述

给定一个整数数组 $ a_1, a_2, \ldots, a_n $ 和两个整数 $ s $ 和 $ x $ 。统计满足以下条件的子段的数量：

- 子段内元素的和等于 $ s $。
- 子段内元素的最大值等于 $ x $。

更正式地说，统计满足以下条件的数对 $ 1 \leq l \leq r \leq n $ 的数量：

- $ a_l + a_{l + 1} + \ldots + a_r = s $。
- $ \max(a_l, a_{l + 1}, \ldots, a_r) = x $。

**输入格式**

测试包含多个测试用例。第一行包含一个整数 $ t $（$ 1 \leq t \leq 10^4 $），表示测试用例的数量。接下来是测试用例的描述。

每个测试用例的第一行包含三个整数 $ n $、$ s $ 和 $ x $（$ 1 \leq n \leq 2 \times 10^5 $，$ -2 \times 10^{14} \leq s \leq 2 \times 10^{14} $，$ -10^9 \leq x \leq 10^9 $）。

每个测试用例的第二行包含 $ n $ 个整数 $ a_1, a_2, \ldots, a_n $（$ -10^9 \leq a_i \leq 10^9 $）。

保证所有测试用例的 $ n $ 之和不超过 $ 2 \times 10^5 $。

**输出格式**

对于每个测试用例，输出满足条件的子段数量。

### 思路

考虑只有第一个条件是怎么算的，只用顺着求一遍前缀和然后记录一下`f[sum[i]]`出现的次数，然后对于第$i$个位置的贡献就是`f[s-sum[i]]`，但是现在多了一个要求，要区间$max$为$x$，那么先算出`<=x-1`的情况，再算出`<=x`，再相减就可以了，每一次遇见大于$x$或者$x-1$的时候就把`f`清空，这样就相当于有贡献的段累加的都是满足条件的了


### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    ll n,s,x;
    cin>>n>>s>>x;
    ll a[n+10];
    vector<ll> sum(n+10,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    map<ll,ll> f;
    ll r1=0,r2=0;
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]>x){
            f.clear();
        }
        else{
            if(f[sum[i]-s]){
                r1+=f[sum[i]-s];
            }
        }
        f[sum[i]]++;
    }
    f.clear();
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]>x-1){
            f.clear();
        }
        else{
            if(f[sum[i]-s]){
                r2+=f[sum[i]-s];
            }
        }
        f[sum[i]]++;
    }
    cout<<r1-r2<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [Codeforces Round 1034 (Div. 3) G. Modular Sorting](https://codeforces.com/contest/2123/problem/G)

### 题目描述
给定一个整数 $ m $（$ 2 \leq m \leq 5 \cdot 10^5 $）和一个由小于 $ m $ 的非负整数组成的数组 $ a $。

需要回答以下形式的查询：

- 1 $ i $ $ x $：将 $ a_i $ 赋值为 $ x $
- 2 $ k $：在一次操作中，你可以选择一个元素 $ a_i $ 并将其赋值为 $ a_i := (a_i + k) \mod m $ — 确定是否存在一系列（可能为零）操作使得 $ a $ 非递减。

注意查询2的实例是独立的；也就是说，实际上没有进行任何操作。查询1的实例是持久的。

* $ a \mod m $ 被定义为满足 $ 0 \leq b < m $ 且 $ a - b $ 是 $ m $ 的整数倍的唯一整数 $ b $。
* 如果对于所有 $ 1 \leq i < n $，都有 $ a_i \leq a_{i+1} $，则称大小为 $ n $ 的数组 $ a $ 是非递减的。

**输入**

第一行包含一个整数 $ t $（$ 1 \leq t \leq 10^4 $） — 测试用例的数量。

每个测试用例的第一行包含三个整数 $ n $，$ m $ 和 $ q $（$ 2 \leq n \leq 10^5 $，$ 2 \leq m \leq 5 \cdot 10^5 $，$ 1 \leq q \leq 10^5 $） — 数组 $ a $ 的大小，整数 $ m $，以及查询的数量。

每个测试用例的第二行包含 $ n $ 个整数 $ a_1, a_2, \ldots, a_n $（$ 0 \leq a_i < m $）。

接下来是 $ q $ 行。每行是以下形式之一：

- 1 $ i $ $ x $（$ 1 \leq i \leq n $，$ 0 \leq x < m $）
- 2 $ k $（$ 1 \leq k < m $）

保证所有测试用例中 $ n $ 和 $ q $ 的总和不超过 $ 10^5 $。

**输出**

对于每个查询$2$的实例，如果存在一系列（可能为零）操作使得 $ a $ 非递减，则输出一行 "YES"，否则输出 "NO"。

你可以以任何大小写形式输出答案（大写或小写）。例如，字符串 "yEs"，"yes"，"Yes" 和 "YES" 都将被视为肯定的响应。



### 思路
**Step 1：贪心模拟（O(n²) 版本）**

最直观的想法是「贪心」：我们想最终让数组排好序，就一格一格地「放最小」。也就是说：

1. 从左到右依次处理位置 $1,2,\dots,n$
2. 对于位置 $i$，枚举所有能够从原来 $a_i$ 通过若干次操作到达的合法值，选其中最小的放到第 $i$ 位；
3. 如果在某一步找不到合法值，就输出 NO；否则一直做到最后输出 YES。

这个方法要做 $n$ 次查找，每次要枚举所有可达值，最坏 $O(m)$，于是是 $O(nm)$，对于大 $m$ 会超时。

---

**Step 2：可达性分析 —— 同余类划分**

关键就在于：**对同一个位置 $i$，所有你能到达的值恰好是**

$$
\bigl\{\,x\in[0,m)\;\big|\;x\equiv a_i\pmod{g}\bigr\},
$$

这里 $g=\gcd(k,m)$。

* **为什么？**

  * 只加 $k$ 相当于在模 $m$ 的环上跳步长为 $k$。
  * 最终你能到达的值就是从 $a_i$ 出发，一直加 $g$（因为 $k$ 在模 $m$ 环中产生的子群生成元的阶是 $\tfrac m g$，所以跳跃只能落在同一个模 $g$ 的同余类里），一共恰好能扫遍那个同余类的所有元素。
  * 由于 $\gcd(k,m)$ 在加法下不变（每一步都加的是 $k$，$\gcd(k,m)$ 始终不变），因此不同同余类之间不会互相“通行”。

于是我们可以把所有数按照它们对 $g$ 的余数分成 $g$ 个桶（同余类），在每个桶里独立地做「取最小」操作；最终能否排好序，取决于在每个同余类里取出的序列能否拼起来整体非降。

---

**Step 3：高效维护「每个同余类当前最小值」**


> **只维护每个同余类里「剩余值」的差分数组**
>
> 设同余类 $r$ 里剩下的值按增序排列是
>
> $$
> x_1 < x_2 < \cdots < x_t,
> $$
>
> 定义它们的「差分」
>
> $$
> d_1 = x_1,\quad
> d_2 = x_2 - x_1,\quad
> \dots,\quad
> d_t = x_t - x_{t-1}.
> $$
>
> 那么
>
> 1. 取走最小值就是把 $x_1$ 删掉，只影响两个差分 $d_1,d_2$（把它们合并成一个新差分）；
> 2. 差分之和恰好是「最大值」减「前面那个值」的累积，或者说是下次要比较的关键指标；
> 3. $\gcd(k,m)$ 依然是差分的公因子，所以不同同余类完全独立。

因为每次删除只要更新常数个差分，就能得出下一个桶的最小值，整个过程让每次查询／删除都变成 $O(1)$ 或 $O(\text{\#约数}(m))$（维护 gcd 约数列表的开销）。这样一来，模拟 $n$ 次取最小值，总共 $O(n\cdot d(m))$，$d(m)$ 是 $m$ 的约数数目，通常很小，足够快。

---
* **核心洞察**：加 $k$ 取模 $m$ 的操作，只能在同一个「$\bmod\;\gcd(k,m)$ 同余类」中来回跳，整个可达集合是完整的一整类。
* **贪心策略**：把排序看成「每次取下一个最小的可达值」。
* **高效实现**：把每个同余类的剩余值按差分维护，删除最小值只要更新常数个差分指标，就能得到下一个最小值，无需整桶重建。

这样我们就能在 $O(n\,d(m))$ 的时间里判断能不能把数组通过这种操作排成非降序。


### 代码
```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;  
    vector<int> a(n+10,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,ll> ans;
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            ans[i]=0;
            ans[m/i]=0;
        }
    }
    for(auto &[x,d]:ans){
        for(int i=1;i<=n;i++){
            d+=(a[i]%x-a[i-1]%x+x)%x;
        }
    }
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int idx,s;
            cin>>idx>>s;
            for(auto &[x,d]:ans){
                if(idx==n){
                    d+=(s%x-a[n-1]%x+x)%x;
                    d-=(a[n]%x-a[n-1]%x+x)%x;
                }
                else{
                    d+=(s%x-a[idx-1]%x+x)%x;
                    d-=(a[idx]%x-a[idx-1]%x+x)%x;

                    d+=(a[idx+1]%x-s%x+x)%x;
                    d-=(a[idx+1]%x-a[idx]%x+x)%x;
                }
            }
            a[idx]=s;
        }
        else{
            int k;
            cin>>k;
            cout<<(ans[gcd(m,k)]<m?"YES":"NO")<<'\n';
        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [2021 Hubei Provincial Collegiate Programming Contest H. Information Transmission](https://codeforces.com/gym/103104/problem/H)

### 题目描述

秋叶原有 SERN 的 $ N $ 个站点（编号 $1$ 到 $N$ ）。现需将 Rintaro 的时间机器信息从站点 1 传输到其他站点。每个站点的广播能力不同，信号可能需要多次中继。站点构成有向图：边 $ X \to Y $ 表示站点 $ X $ 可向 $ Y $ 传输信号。

每次传输会发生信号衰减（信息丢失）。但若一个站点发出的信息经过**最多三次衰减后**回到自身（即经过长度不超过 $3$ 的环），则认为该环具有自修正能力，环上所有路径的传输**不会产生衰减**。

求从站点 $1$ 到每个站点所需的最小衰减次数。

**输入**
- 第一行：$ N $（站点数）和 $ M $（传输关系数），满足 $ 1 \leq N \leq 300 $，$ 0 \leq M \leq 10000 $
- 接下来 $ M $ 行：每行两个整数 $ X $ 和 $ Y $，表示 $ X \to Y $ 的边
- **保证无重边和自环**

**输出**
- 一行 $ N $ 个整数：第 $ i $ 个数表示站点 $1$ 到站点 $ i $ 的最小衰减次数。若不可达，输出 $-1$


### 思路

1. 构建初始邻接矩阵 `dis[i][j]`

```cpp
vector<vector<int>> dis(310, vector<int>(310, 1e6));
for(int i = 1; i <= n; i++) dis[i][i] = 0;
for(int i = 1; i <= m; i++){
    int v, u;
    cin >> v >> u;
    dis[v][u] = 1;
}
```

* **含义**：`dis[i][j]` 存的是从站点 `i` 到 `j` 的一条直接传输的“衰减次数”：

  * 如果存在边 `i→j`，初始就设为 1；
  * 不存在就设成一个大数（这里取 1e6 代表无穷）；
  * 自身 `i→i` 衰减为 0。

---

2. 「零化」所有能自修正（环长 ≤3）的环上边

```cpp
for(int i = 1; i <= n; i++){
  for(int j = 1; j <= n; j++){
    if(i != j && dis[i][j] + dis[j][i] <= 3){
      dis[i][j] = dis[j][i] = 0;
    }
    for(int k = 1; k <= n; k++){
      if(i!=j && i!=k && j!=k && dis[i][j] + dis[j][k] + dis[k][i] <= 3){
        // 把三角环上所有 6 条方向边都置 0
        dis[i][j] = dis[j][k] = dis[k][i] = 0;
        dis[j][i] = dis[k][j] = dis[i][k] = 0;
      }
    }
  }
}
```

* **长度 2 的“互逆”环**：若 `i→j` + `j→i` 的代价 ≤3（也就是两条普通边各 1），就把 `i→j` 和 `j→i` 都“自修正”地置为 0。
* **长度 3 的三角环**：枚举三元组 `(i,j,k)`，若 `i→j→k→i` 三边之和 ≤3，就把这三条和它们的反向边一共 6 条全都置为 0。

这样一来，所有能在衰减次数不超过 3 内回到起点的有向环上的边，都被正确标记为“权 0”。

---

3. 建图并跑 Dijkstra 求最短衰减

```cpp
vector<vector<PII>> e(330);
for(int i = 1; i <= n; i++){
  for(int j = 1; j <= n; j++){
    if(dis[i][j] != 1e6){
      e[i].push_back({dis[i][j], j});
    }
  }
}

// Dijkstra 从 1 出发
priority_queue<PII, vector<PII>, greater<PII>> pq;
vector<int> vis(n+1, 0), d(n+1, 1e6);
d[1] = 0;
pq.push({0, 1});
while(!pq.empty()){
  auto [dist_u, u] = pq.top(); pq.pop();
  if(vis[u]) continue;
  vis[u] = 1;
  for(auto [w, v] : e[u]){
    if(d[v] > dist_u + w){
      d[v] = dist_u + w;
      pq.push({d[v], v});
    }
  }
}
```

* **建邻接表** `e[u]`：遍历 `dis[u][v]`，只要不是无穷，就把 `(weight=dis[u][v], to=v)` 加到 `e[u]`。
* **Dijkstra**：使用小顶堆，`d[v]` 记录从 1 到 `v` 的最小衰减次数。这里边权要么是 0（自修正环边），要么是 1（普通边），Dijkstra 完全可以正确处理。

---

4. 输出结果

```cpp
for(int i = 1; i <= n; i++){
  if(d[i] == 1e6) cout << -1 << " ";
  else            cout << d[i]  << " ";
}
cout << "\n";
```

如果 `d[i]` 仍是无穷，就输出 `-1`（不可达）；否则输出它的最小衰减次数。

* **初始化矩阵**：$O(n^2)$。
* **零化环**：两层 $i,j$ 再一层 $k$，$O(n^3)$。
* **建图和 Dijkstra**：建图 $O(n^2)$，Dijkstra $O(n^2\log n)$（但实际上边数 $≤n^2$ 且 $n≤300$）。

总计仍然是 $O(n^3 + n^2\log n)$，在 $n\le300$、$m\le10^4$ 的约束下可以稳妥通过 2 秒。


### 代码

```c++
#include <bits/stdc++.h>
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dis(310,vector<int>(310,1e6));
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        dis[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&dis[i][j]+dis[j][i]<=3){
                dis[i][j]=dis[j][i]=0;
            }
            for(int k=1;k<=n;k++){
                if(i!=j&&k!=i&&k!=j&&dis[i][j]+dis[j][k]+dis[k][i]<=3){
                    dis[i][j]=dis[j][k]=dis[k][i]=0;
                    dis[j][i]=dis[k][j]=dis[i][k]=0;
                }
            }
        }
    }
    vector<vector<PII>> e(330);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]!=1e6){
                e[i].push_back({dis[i][j],j});
            }
        }
    }
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    vector<int> v(330,0);
    vector<int> d(330,1e6);
    d[1]=0;
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [w,y]:e[t]){
            if(d[y]>w+d[t]){
                d[y]=w+d[t];
                q.push({d[y],y});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]==1e6)cout<<-1<<" ";
        else{
            cout<<d[i]<<" ";
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [2021 Hubei Provincial Collegiate Programming Contest](https://codeforces.com/gym/103104)

### 题目描述

对于平面上给定的 $ n $ 个点 $(x_i, y_i)$，尝试在其中某个点 $ i $ 的周围以固定距离（这里是 2）放置一个新点，使得：

1. 它与任何已有点都不重叠（相距至少 2）；
2. 它依然落在半径为 $ r $ 的“大圆”内部。

要判断是否存在这样的放置位置，对每个点 $ i $ 都做了一次“极角扫描”。

### 思路

平面几何中的点放置问题：极角扫描与空间哈希优化

1. 预处理：邻居查找加速

- 把所有点都映射到一个足够大的二维整型网格 `who[rx][ry]` 中（这里偏移量为 $ Z = 1010 $）。这样，对于任意一个点 $ i $，只需要检查它周围固定格子范围（$\pm5$）内的格子，就能找到所有可能在距离 4 单位（因为若两点距离 $\ge 4$，那么它们间距 $\ge 2 + 2$，不会相交）内的点。
- 通过这种方式，复杂度从 $ O(n^2) $ 降到 $ O(n) $ 量级。

1. 对每个点 $ i $ 构造“禁入角度”区间

- 邻居造成的禁区

- 对于每个在距 $ i $ 小于 4 的点 $ j $，计算两点向量方向的极角 $\alpha = \arctan (y_j - y_i, x_j - x_i)$，以及因为“新点与 $ j $ 不得重叠”所需的半开口角度

  $$
  \delta = \arccos\left(\frac{\text{dist}(i, j)}{4}\right), \quad \text{其中 } \text{dist}(i, j) = \sqrt{(x_i - x_j)^2 + (y_i - y_j)^2}.
  $$

- 那么方向 $\alpha \pm \delta$ 之间的扇形就是不允许放新点的区域。

- 大圆边界造成的禁区

- 还得保证新点落在以原点为中心、半径 $ r $ 的大圆内部。令当前点到原点的距离为 $ d $。若 $ d + 2 > r $，就有角度区间会使得新点超出大圆。
- 这个区间可以用极角 $\beta = \arctan(y_i, x_i)$ 和开口角度

  $$
  \Delta = \arccos\left(\frac{-(d^2 + 2^2 - r^2)}{4d}\right)
  $$

  计算得到，需要排除的方向也是 $\beta \pm \Delta$。

- 所有这些“禁入”扇形都被统一映射到 $[0, 2\pi)$ 上的若干区间，然后通过“线性化”（拆成若干增删事件）：

  ```cpp
  ev.emplace_back(L + eps, +1);
  ev.emplace_back(R - eps, -1);
  if (L >= R) ev.emplace_back(0, +1); // 跨越 0 的区间
  ```

- 对这些事件按角度排序后，一次扫描累加“禁区平衡” `balance`。当 `balance == 0` 时，说明该方向既不被任何邻居打扰，也不越界，就可以放置新点。

---

3. 找到可行方向就立即输出

- 一旦找到第一个 `balance` 从正变零（或一开始就 `ev` 为空），就取该角度 $\theta$，令

  $$
  x_{\text{new}} = x_i + 2\cos\theta, \quad y_{\text{new}} = y_i + 2\sin\theta,
  $$

  输出 “Yes” 以及新点坐标，程序结束。

- 如果遍历所有点都找不到空余角度，则输出 “No”。

---

1. **空间哈希**（固定网格） → 快速寻找“冲突”点
2. **极角区间禁入** → 把几何可行性判断化为“在 $[0, 2\pi)$ 上找一个未被覆盖的角度”
3. **扫描线** → 高效地合并多个可能相交的角度区间并查找空隙

这种“对于每个基点做一次极角扫描来找空余方向”的方法，在平面几何中处理“放圆”、“视野可见性”以及“避障”问题时非常常见。

---

- 更通俗的解释

1. 目标是什么？

给你 $ n $ 个点 $(x_i, y_i)$ 和一个半径为 $ r $ 的大圆，目标是在这些点周围“放”一个小圆（半径固定为 2），使得：

- 小圆不与任何已有点重叠（即中心到每个已有点距离 $\ge 4$）；
- 小圆的整个范围都在大圆内部。

2. 为什么要按“极角”来做？

对于某一个已有点 $ P = (x_i, y_i) $，如果我们想把小圆的中心放在距离它恰好 2 的某个方向上，就相当于在点 $ P $ 上画一个半径为 2 的“小圆”，我们只要在这个小圆的周长上选一个点即可。把周长上的点用“极角” $\theta \in [0, 2\pi)$ 来表示，就是：

$$
\bigl(x_i + 2\cos\theta, \; y_i + 2\sin\theta\bigr)
$$

3. 哪些方向不能选？（“禁入区间”）

- 被其他已有点挡住的方向

- 如果另一个点 $ Q $ 离 $ P $ 太近（小于 4），那么沿着从 $ P $ 指向 $ Q $ 的方向，有一段扇形会被挡住——因为如果你把小圆中心放在这段扇形里，小圆就会碰到点 $ Q $。
- 代码里算出这个扇形的中心角和张角 $\delta$，标记为不能选的角度区间 $[\alpha - \delta, \alpha + \delta]$。

- 超出大圆边界的方向

- 如果从原点到 $ P $ 的距离是 $ d $，而 $ d + 2 > r $，那么靠近外圈的某些方向会让小圆跑出大圆。
- 它也对应一个角度区间，同样要排除。

4. 怎么高效合并这些“禁区”并找空隙？

- 把每个被挡住的角度区间拆成“开始”（+1）和“结束”（−1）两个事件，按角度排序。
- 从 $\theta = 0$ 开始扫过去，用一个累加器 `balance` 来表示当前有几个区间在“覆盖”这个角度。
- 当 `balance == 0` 时，就说明此时没有任何禁区，角度 $\theta$ 是可行的。

5. 一旦找到可行角度就输出答案

- 算到某个 $\theta$ 时 `balance` 变为 0，就立即算出小圆心的新坐标

  $$
  x_{\text{new}} = x_i + 2\cos\theta, \quad y_{\text{new}} = y_i + 2\sin\theta
  $$

  然后输出 “Yes” 和这对坐标，程序结束。

6. 为什么用网格（`who[rx][ry]`）？

- 如果每次都对所有 $ n $ 个点两两比较，会是 $ O(n^2) $，非常慢。
- 网格哈希法把点先放到一个足够大的整型格子里，只要检查离当前点 $\pm5$ 个格子范围内的点，就能找到所有可能“冲突”的点，把复杂度降到接近 $ O(n) $。

---

**总结**

- **思路核心**：把几何上的“找一个合适位置”问题转化为“在 $[0, 2\pi)$ 上找一个不被任何区间覆盖的角度”。
- **实现方式**：
  1. 先用格子找出所有可能挡住你的点；
  2. 对每个点，列出所有“被挡住的角度区间”；
  3. 排序 + 扫描线（`balance` 累加） → 找到第一个 `balance == 0` 的角度 → 输出结果。



**使用数学函数**
- **`acos` 和 `acosl`**
  - **功能**：计算反余弦值。`acos`用于`double`类型，`acosl`用于`long double`类型。返回值范围为`[0, π]`。
  - **使用场景**：在代码中用于计算角度，例如`acosl(-1)`用于计算π的值。

- **`atan2` 和 `atan2l`**
  - **功能**：计算反正切值。`atan2(y, x)`返回`y/x`的反正切值，结果范围为`(-π, π]`。`atan2l`是`long double`版本。
  - **使用场景**：用于计算两点之间的角度，例如`atan2l(y[j] - y[i], x[j] - x[i])`。

- **`hypot` 和 `hypotl`**
  - **功能**：计算直角三角形的斜边长度，即`sqrt(x*x + y*y)`。`hypotl`是`long double`版本。
  - **使用场景**：在代码中用于计算点到原点的距离，例如`hypotl(x[i], y[i])`。

- **`sqrt` 和 `sqrtl`**
  - **功能**：计算平方根。`sqrt`用于`double`类型，`sqrtl`用于`long double`类型。
  - **使用场景**：用于计算距离或其他需要平方根的场景。

- **`sin` 和 `sinl`**
  - **功能**：计算正弦值。`sin`用于`double`类型，`sinl`用于`long double`类型。
  - **使用场景**：在代码中用于计算点的坐标，例如`sinl(th)`。

- **`cos` 和 `cosl`**
  - **功能**：计算余弦值。`cos`用于`double`类型，`cosl`用于`long double`类型。
  - **使用场景**：在代码中用于计算点的坐标，例如`cosl(th)`。

- **`clamp`**
  - **功能**：将值限制在指定范围内。`clamp(value, low, high)`返回`value`，如果`value`在`[low, high]`范围内；否则返回`low`或`high`。
  - **使用场景**：在代码中用于防止计算结果超出有效范围，例如`clamp((ld)(-(d0*d0 + 4 - r*r) / (4*d0)), (ld)-1, (ld)1)`。

- **`llround`**
  - **功能**：将浮点数四舍五入到最接近的整数，并返回`long long`类型。
  - **使用场景**：在代码中用于将浮点坐标转换为整数坐标，例如`llround(x[i])`。

- **`fixed` 和 `setprecision`**
  - **功能**：用于设置输出的小数精度。`fixed`将输出格式设置为固定小数点表示法，`setprecision(n)`设置小数点后保留的位数。
  - **使用场景**：在代码中用于精确输出浮点数，例如`fixed << setprecision(20)`。


- 总结
这段代码主要涉及输入输出优化、数学计算（角度、距离、三角函数等）以及一些辅助功能（如四舍五入、精度控制等）。这些函数在处理几何问题和数值计算时非常常用，尤其是在竞赛编程中。


### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld PI = acosl(-1);
const ld EPS = 1e-10;
const int Z = 1010;

ld fix(ld a) {
    if (a < 0) a += 2*PI;
    if (a >= 2*PI) a -= 2*PI;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ZKX.in","r",stdin);
    freopen("ZKX.out","w",stdout);  
    int n;
    ld r;
    cin >> n >> r;

    vector<ld> x(n), y(n);
    vector<vector<int>> who(2*Z, vector<int>(2*Z, -1));
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        int xi = llround(x[i]) + Z, yi = llround(y[i]) + Z;
        who[xi][yi] = i;
    }

    auto ban = [&](vector<pair<ld,int>>& ev, ld ang, ld d) {
        if (d <= EPS) return;
        if (d > PI) {
            ev.emplace_back(0, +1);
            return;
        }
        ld L = fix(ang - d), R = fix(ang + d);
        ev.emplace_back(L + EPS, +1);
        ev.emplace_back(R - EPS, -1);
        if (L >= R) ev.emplace_back(0, +1);
    };

    for (int i = 0; i < n; i++) {
        int xi = llround(x[i]) + Z, yi = llround(y[i]) + Z;
        vector<pair<ld,int>> ev;

        for (int dx = -5; dx <= 5; dx++) for (int dy = -5; dy <= 5; dy++) {
            int j = who[xi+dx][yi+dy];
            if (j < 0 || j == i) continue;
            ld dxl = x[j]-x[i], dyl = y[j]-y[i];
            ld dist2 = dxl*dxl + dyl*dyl;
            if (dist2 >= 16) continue;
            ld ang = atan2l(dyl, dxl);
            ld d   = acosl(sqrtl(dist2)/4);
            ban(ev, ang, d);
        }

        ld d0 = hypotl(x[i], y[i]);
        if (d0 + r < 2) {
            cout << "No\n"; 
            return 0;
        }
        if (d0 + 2 > r) {
            ld cs = clamp((ld)(-(d0*d0 + 4 - r*r) / (4*d0)), (ld)-1, (ld)1);
            ban(ev, atan2l(y[i], x[i]), acosl(cs));
        }

        sort(ev.begin(), ev.end());
        auto output = [&](ld th) {
            cout << "Yes\n"
                 << fixed << setprecision(20)
                 << x[i] + 2*cosl(th) << " "
                 << y[i] + 2*sinl(th) << "\n";
            exit(0);
        };
        if (ev.empty() || ev[0].first > 0) output(0);

        int bal = 0;
        for (auto& [ang, d] : ev) {
            bal += d;
            if (bal == 0) output(ang);
        }
    }

    cout << "No\n";
    return 0;
}
```










## [Codeforces Round 826 (Div. 3) F. Multi-Colored Segments](https://codeforces.com/contest/1741/problem/F)

### 题目描述

给定 $n$ 条带有颜色标记的线段，第 $i$ 条线段的左端点为 $l_i$，右端点为 $r_i$，颜色为 $c_i$。对于每一条线段，我们要计算一个非负整数 $d_i$，使得将该线段左右两端各延申 $d_i$ 后，它与至少一条颜色不同的线段有交集。求每条线段的最小满足条件的 $d_i$。

换句话说，如果当前线段已经与某条异色线段有重叠，则答案为 0；否则，需要将它向左或向右延伸，直到“碰到”某条异色线段，求最小的延伸距离。


### 思路
* **暴力思路**：对每条线段，遍历所有异色线段，计算最小的距离，但这样是 $O(n^2)$，在 $n$ 高达 $2\times10^5$ 时显然不可行。

* **优化方向**：

  1. **快速判断是否存在重叠**：需要一个能维护「所有（或除去某种颜色外的）线段覆盖情况」的数据结构，支持区间加一、点查询。
  2. **快速找到最近的异色线段**：在一维线上，要么找开始点在自己右侧最近的线段，要么找结束点在自己左侧最近的线段。可以用两个有序集合（multiset）来维护所有线段的开始集合和结束集合。

基于此，我们给出两种主流做法：

---

**解法一：离散化 + BIT + 分颜色维护**


1. **离散化端点**：因为端点范围可能很大，先把所有 $l_i, r_i$ 收集起来排序去重，映射到 $[1,2n]$ 范围内。
2. **全局区间覆盖**：使用一个「差分型」Fenwick 树（BIT），对所有线段的离散化区间 $[L_i, R_i]$ 进行区间加 1，支持：

   * `add(L, R, +1)`：表示在 $[L,R]$ 上覆盖数 +1
   * `ask(x)`：查询位置 $x$ 上的覆盖数
3. **分颜色「去除」**：对于每一种颜色 $c$，我们要临时把它所有的线段从 BIT 中去掉，再对该颜色下的每个线段单独判断：

   * 如果 `ask(位置)` > 0，则说明此时它与至少一条异色线段有重叠，答案为 0。
   * 否则，在除去当前颜色后，所有异色线段的开始点和结束点分别存在两个 multiset `S_L`, `S_R` 中：

     * 在 `S_L` 中查找第一个 $\ge l_i$ 的开始点，记作 $l^*$，那么向右延伸所需距离至少为 $\max(0,\,l^* - r_i)$。
     * 在 `S_R` 中查找最后一个 $\le r_i$ 的结束点，记作 $r^*$，那么向左延伸所需距离至少为 $\max(0,\,l_i - r^*)$。
   * 取这两者的最小值即为该线段的答案。
4. **恢复 BIT**：判断完一个颜色后，再把它所有线段加回 BIT 和两个 multiset 中，继续处理下一种颜色。

**时间复杂度**

* 离散化：$O(n\log n)$
* 对每种颜色 $c$：

  * 删除其所有线段：共做 $O(\sum_c k_c\log n)=O(n\log n)$
  * 在该颜色内做 $k_c$ 次查询：每次 $O(\log n)$
  * 恢复操作同删除
* 总计 $O(n\log n)$，能轻松应对 $n\le2\times10^5$。

---

**解法二：一次扫描 + 记录「最长」与「次长」区间**


**预处理**：将所有线段按左端点从小到大排序，若左端点相同则按右端点升序。
在一次从左到右的扫描中，维护：

   * 全局最大的右端点 `max1` 及其对应颜色 `col1`
   * 第二大的右端点 `max2`（颜色必与 `col1` 不同）
设当前扫描到的线段为 $(l_i, r_i, c_i)$，我们要判断它与之前所有线段（即左边的线段）中有没有异色重叠，或最近的异色段距它多远：

   * **重叠检测**：如果 `r_i ≤ max1` 且 `c_i ≠ col1`，说明已有一条右端点达到 `max1` 且颜色不同的线段与它重叠，此时答案为 0。
   * **若 `c_i == col1`**，则它只能与 `max2` 这条次大右端点的异色线段重叠；若 `r_i ≤ max2`，答案同样为 0。
   * **无重叠时的距离计算**：

     * 向左看：取合适的 `max`（若 `c_i==col1` 则用 `max2`，否则用 `max1`），计算 $\max(0,\,l_i - \text{that\_max})$。
     * 向右看：看下一个不同颜色线段的左端点。由于已经排序，可以在当前位置向右找第一个颜色不同的线段，记其左端点为 `nextL`，则右侧距离为 $\max(0,\,nextL - r_i)$。
   * 取两者最小值。
**更新状态**：将当前线段 $(r_i,c_i)$ 插入到全局的「最大」/「次大」维护结构中：

   * 如果 `r_i > max1`：

     * 若 `c_i == col1`，直接更新 `max1 = r_i`；否则：

       * 将原 `(max1,col1)` 降为 `(max2,col2) = (max1,col1)`
       * `max1 = r_i`, `col1 = c_i`
   * 否则若 `r_i > max2` 且 `c_i ≠ col1`，更新 `max2 = r_i`。

**时间复杂度**

* 排序 $\;O(n\log n)$
* 一次扫描 $\;O(n)$
* 整体 $\;O(n\log n)$

---

两种解法思路侧重不同：

* **解法一** 借助数据结构，逻辑清晰，擅长处理需要频繁「去除自己颜色」的情况；
* **解法二** 则更为精简，一次排序+扫描即可完成，用贪心维护「最优候选」，代码量更少，常数也更小。

根据实际情况选用即可。若颜色种类较少或线段分布高密集，解法一更为稳健；若只需单次扫描，解法二则更加优雅高效。

### 解法1代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
struct vc{
    int l,r,id;
    int k1,k2;
};
struct BIT {
    int n;
    vector<int> w;
 
    BIT() {}
    BIT(int n) {
        this->n = n; // 这里必须写 n ，否则会RE
        // w.resize(n + 1);
        w.assign(n+1,0);
    }
    void add(int x, int k) {
        for (; x <= n; x += x & -x) {
            w[x] += k;
        }
    }
    void add(int x, int y, int k) {
        add(x, k), add(y, -k);
    }
    int ask(int x) {
        int ans = 0;
        for (; x; x -= x & -x) {
            ans += w[x];
        }
        return ans;
    }
    int ask(int x, int y) {
        return ask(y) - ask(x - 1);
    }
};
void solve(){
	int n;
    cin>>n;
    vector<vc> a[n+1];
    vector<int> d;
    for(int i=1;i<=n;i++){
        int l,r,c;
        cin>>l>>r>>c;
        a[c].push_back({l,r,i});
        d.push_back(l);
        d.push_back(r);
    }
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    BIT T(d.size()+10);
    multiset<int> ls,rs;
    for(int c=1;c<=n;c++){
        for(auto &seg:a[c]){
            seg.k1=lower_bound(d.begin(),d.end(),seg.l)-d.begin()+1;
            seg.k2=lower_bound(d.begin(),d.end(),seg.r)-d.begin()+1;
            T.add(seg.k1,1);
            T.add(seg.k2+1,-1);
            ls.insert(seg.l);
            rs.insert(seg.r);
        }
    }
    vector<int> ans(n+10,inf);
    for(int c=1;c<=n;c++){
        for(auto &seg:a[c]){
            T.add(seg.k1,-1);
            T.add(seg.k2+1,+1);
            ls.erase(ls.find(seg.l));
            rs.erase(rs.find(seg.r));
        }
        for(auto &seg:a[c]){
            if(T.ask(seg.k1)>0){
                ans[seg.id]=0;
            }
            else{
                int res=inf;
                auto lx=ls.lower_bound(seg.l);
                if(lx!=ls.end()){
                    res=min(res,max(0,*lx-seg.r));
                }
                auto rx=rs.upper_bound(seg.r);
                if(rx!=rs.begin()){
                    --rx;
                    res=min(res,max(0,seg.l-*rx));
                }
                ans[seg.id]=res;
            }
        }
        for(auto &seg:a[c]){
            T.add(seg.k1,+1);
            T.add(seg.k2+1,-1);
            ls.insert(seg.l);
            rs.insert(seg.r);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


### 解法2代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
struct vc{
    ll l,r,c,id;
};
bool cmp(vc a, vc b){
    if(a.l!=b.l){
        return a.l<b.l;
    }
    else{
        return a.r<b.r;
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vc>a={{-2000000000,-2000000000,0,0},{2000000000,2000000000,0,n+1}};
    for(int i=1;i<=n;i++){
        ll l,r,c;
        cin>>l>>r>>c;
        a.push_back({l,r,c,i});
    }
    sort(a.begin(),a.end(),cmp);
    int r;
    ll Mx=-2000000000,Mc=0,Ms=-2000000000;
    vector<ll> ans(n+1,2000000000);
    for(int i=1;i<=n;i++){
        if(a[i].c!=a[i-1].c){
            r=i+1;
            while(a[r].c==a[i].c){
                r++;
            }
        }
        if(a[i].r>Mx){
            if(a[i].c!=Mc){
                Ms=Mx;
                Mc=a[i].c;
            }
            Mx=a[i].r;
        }else if(a[i].r>Ms&&a[i].c!=Mc){
            Ms=a[i].r;
        }
        ans[a[i].id]=min({ans[a[i].id],max(0ll,a[i].c==Mc?a[i].l-Ms:a[i].l-Mx),max(0ll,a[r].l-a[i].r)});
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [Codeforces Round 683 (Div. 1, by Meet IT) D1. Frequency Problem (Easy Version)&&D2. Frequency Problem (Hard Version)](https://codeforces.com/contest/1446/problem/D1)


### 题目描述

给定长度为 $n$ 的数组 $\{a_i\}$。

* **D1 (Easy)**：元素值 $1\le a_i\le\min(n,100)$。
* **D2 (Hard)**：元素值 $1\le a_i\le n$。

要求找到最长的子数组，使得该子数组中出现次数最多的那个值**不唯一**，即如果该子数组的最多出现次数为 $f$，则至少有两种不同的值都恰好出现了 $f$ 次。若不存在，输出 0。

子数组定义为原数组去掉若干前缀和若干后缀后得到的连续段。

---

### 思路

1. **全局众数 $G$**
   先统计全数组出现次数，令 $G$ 为出现次数最多的元素（若并列任选其一）。

2. **重-轻分治**
   令阈值 $B\approx\sqrt n$。

   * **“重数”**：出现次数 $>B$ 的值。它们的个数 $\le n/B=O(\sqrt n)$。
   * **“轻数”**：出现次数 $\le B$ 的值。

3. **处理重数**
   对每个重数 $x\neq G$：

   * 将 $G$ 看作 “+1”，$x$ 看作 “–1”，其余元素忽略；
   * 构造前缀和数组 `pref[i] = (#G up to i) – (#x up to i)`，加一个大偏移防止负下标；
   * 同值前缀和之间区间即为 $\#G=\#x$ 的最长子数组。
     复杂度每个 $O(n)$，共 $O(n\sqrt n)$。

4. **处理轻数**
   枚举“最频繁次数” $c$ 从 1 到 $B$：

   * 用双指针维护一个滑动窗口 $[L,R]$，并维护窗口内每种值的出现次数 `cnt[v]`；
   * 维护一个计数器 `T =` “有多少种值恰好出现了 $c$ 次”；
   * 当将 $R$ 向右扩时，`cnt[a[R]]++`，若恰好 `cnt[a[R]]==c` 则 `T++`；
   * 若 `cnt[a[R]]>c` 时，就移动 $L$ 收缩窗口，直到窗口内所有值都 $\le c$ 次，并相应更新 `T`；
   * 每次 `T>=2` 时，说明窗口内有至少两种值恰好出现 $c$ 次，合法，更新答案 `ans = max(ans, R-L+1)`。
     枚举 $c$ 共 $B$ 次，每次双指针 $O(n)$，合计仍是 $O(n\sqrt n)$。

5. **答案**
   将重数和轻数两部分的结果取最大即为最终答案。如果始终没有任何合法窗口，输出 0。

---

### 复杂度分析

* **重数部分**：最多 $O(n / B)$ 个 heavy，每个 $O(n)$ 扫描 → $O(n\sqrt n)$。
* **轻数部分**：枚举 $c=1\ldots B$，每次双指针 $O(n)$ → $O(n\sqrt n)$。
* 总体 $O(n\sqrt n)$，对于 $n\le 2\!\times10^5$ 足够高效。


### 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int B=447;
int a[M];
int ans=0;
int n;
int g;
void ck(int x){
    vector<int> v((n+10)<<1,-1);
    v[n]=0;
    int now=n;
    for(int i=1;i<=n;i++){
        if(a[i]==g)now++;
        if(a[i]==x)now--;
        if(v[now]==-1)v[now]=i;
        else{
            ans=max(ans,i-v[now]);
        }
    }
}
void solve(){
    ans=0;
    cin>>n;
    vector<int>f(M,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cnt<f[a[i]]){
            cnt=f[a[i]];
            g=a[i];
        }
    }   
    set<int>z;
    for(int i=1;i<=n;i++){
        if(f[a[i]]>B&&a[i]!=g){
            z.insert(a[i]);
        }
    }
    for(auto x:z){
        ck(x);
    }
    for(int c=1;c<=B;c++){
        vector<int> p(n+10,0);
        int L=1,T=0;
        for(int i=1;i<=n;i++){
            p[a[i]]++;
            if(p[a[i]]==c)T++;
            while(L<=i&&p[a[i]]>c){
                if(p[a[L]]==c)T--;
                p[a[L]]--;
                L++;
            }
            if(T>=2)ans=max(ans,i-L+1);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Codeforces Round 1036, Div. 1 + Div. 2 C. Subset Multiplication](https://codeforces.com/contest/2124/problem/C)



### 题目描述

1. 我们有原数组 $a$ 满足

   $$
   a_1\mid a_2\mid\cdots\mid a_n.
   $$
2. Bob 选了一个正整数 $x$，对某些位置 $i$ 做

   $$
     b_i = a_i \times x,
     \quad
     b_j = a_j \quad(j\notin S).
   $$
3. 只看得到结果 $b$，要找出一个可能的 $x$。

### 思路

关键在于考察每对相邻下标 $(i,i+1)$：

* 如果 $b_i\mid b_{i+1}$，那么无论是“都不乘”、“都乘”、“只乘左边”还是“只乘右边”，都能在反推时找到合法的 $a_i\mid a_{i+1}$，对 $x$ 没要求。
* 唯一需要“补 $x$”的情形，是 **$b_i\nmid b_{i+1}$**。这时：

  * 不乘，显然 $a_i\mid a_{i+1}$ 不可能；
  * 都乘，会保持 $b_i x \nmid b_{i+1} x$；
  * 只乘右边，$\,b_{i+1}x$ 只会更大，仍旧无法被左侧 $b_i$ 整除；
  * **唯一可行** 的是 “只乘左边”：

    $$
      b_i = a_i\,x,\quad b_{i+1}=a_{i+1}, 
      \quad\text{并且}\quad a_i\mid a_{i+1}.
    $$

  由此推出

  $$
    \frac{b_i}{x} \;\bigm|\; b_{i+1}
    \quad\Longleftrightarrow\quad
    b_{i+1}\text{ 是 }\frac{b_i}{x}\text{ 的整数倍.}
  $$

  等价地（令 $d=\gcd(b_i,b_{i+1})$），

  $$
    x\;\Bigm|\;\frac{b_i}{d}.
  $$

4. 因此，对每个 $i$（使得 $b_i\nmid b_{i+1}$）都得到一个“$x$ 必须整除 $\tau_i=b_i/\gcd(b_i,b_{i+1})$”的约束。要同时满足所有相邻对，**只需取**

   $$
     x = \mathrm{lcm}\bigl(\tau_i : b_i\nmid b_{i+1}\bigr).
   $$
5. 特别地，如果对于所有 $i$ 都有 $b_i\mid b_{i+1}$，那么没有任何约束，此时任意 $x\ge1$ 都合法，我们可以输出 $x=1$。

这样既满足“所有需要补 $x$ 的相邻对”，又不会多余。

---

**严格数学证明**

我们需证明：给定条件 $b_i = a_i \cdot x$，$b_{i+1} = a_{i+1}$，且原始数组满足 $a_i \mid a_{i+1}$，则关系 $a_i \mid a_{i+1}$ 成立当且仅当：
\[
x \mid b_i \quad \text{且} \quad \frac{b_i}{\gcd(b_i, b_{i+1})} \mid x.
\]

其中：
- $x \mid b_i$ 确保 $a_i = \frac{b_i}{x}$ 是整数。
- $\frac{b_i}{\gcd(b_i, b_{i+1})} \mid x$ 确保整除关系 $a_i \mid a_{i+1}$ 成立。

---


**步骤 1：建立等价条件**
由 $a_i = \frac{b_i}{x}$ 和 $a_{i+1} = b_{i+1}$，条件 $a_i \mid a_{i+1}$ 等价于：
\[
\frac{b_i}{x} \mid b_{i+1}.
\]
此条件成立当且仅当存在整数 $k$ 使得：
\[
b_{i+1} = k \cdot \frac{b_i}{x}.
\]
等价于：
\[
x \cdot b_{i+1} = k \cdot b_i.
\]
因此，$\frac{b_i}{x}$ 整除 $b_{i+1}$ 当且仅当 $b_{i+1}$ 是 $\frac{b_i}{x}$ 的整数倍。

---

**步骤 2：引入最大公约数**
设 $d = \gcd(b_i, b_{i+1})$。由最大公约数的性质，可表示为：
\[
b_i = d \cdot m, \quad b_{i+1} = d \cdot n, \quad \gcd(m, n) = 1.
\]
其中 $m, n$ 为互质整数。代入原条件：
\[
\frac{b_i}{x} \mid b_{i+1} \implies \frac{d \cdot m}{x} \mid d \cdot n.
\]
两边除以 $d$（因 $d > 0$)：
\[
\frac{m}{x} \mid n.
\]
因此，存在整数 $t$ 使得：
\[
n = t \cdot \frac{m}{x}.
\]
即：
\[
x = t \cdot \frac{m}{n}.
\]

---

**步骤 3：分析互质条件**
由 $\gcd(m, n) = 1$ 和 $n = t \cdot \frac{m}{x}$，有：
\[
x = t \cdot \frac{m}{n}.
\]
由于 $x$ 为整数，$\frac{m}{n}$ 必须是整数（因 $t$ 为整数）。设 $\frac{m}{n} = c$（$c \in \mathbb{Z}^+$)，则：
\[
x = t \cdot c.
\]
但由 $\gcd(m, n) = 1$ 和 $m = c \cdot n$，代入得：
\[
\gcd(c \cdot n, n) = n \cdot \gcd(c, 1) = n \cdot 1 = n = 1.
\]
（因 $\gcd(m, n) = 1$）。故 $n = 1$，进而 $m = c$. 于是：
\[
x = t \cdot m.
\]

---

**步骤 4：关联回原始变量**
由 $b_i = d \cdot m$ 和 $b_{i+1} = d \cdot n = d \cdot 1 = d$，代入得：
\[
m = \frac{b_i}{d} = \frac{b_i}{\gcd(b_i, b_{i+1})}.
\]
而 $x = t \cdot m$，故：
\[
x = t \cdot \frac{b_i}{\gcd(b_i, b_{i+1})}.
\]
因此：
\[
\frac{b_i}{\gcd(b_i, b_{i+1})} \mid x.
\]
同时，由 $x \mid b_i$（因 $b_i = d \cdot m$ 且 $x = t \cdot m$，需 $t \mid d$ 确保整数性，但已隐含在 $x$ 的构造中）。

---

**步骤 5：验证充分性**
若 $x \mid b_i$ 且 $\frac{b_i}{\gcd(b_i, b_{i+1})} \mid x$，设：
\[
d = \gcd(b_i, b_{i+1}), \quad \tau_i = \frac{b_i}{d}.
\]
由 $\tau_i \mid x$，令 $x = k \cdot \tau_i$ ($k \in \mathbb{Z}^+$)则：
\[
a_i = \frac{b_i}{x} = \frac{d \cdot \tau_i}{k \cdot \tau_i} = \frac{d}{k}.
\]
由 $x \mid b_i$，有 $k \mid d$（因 $b_i = d \cdot \tau_i$ 且 $x = k \cdot \tau_i \mid d \cdot \tau_i$）。故 $a_i = \frac{d}{k}$ 为整数。同时：
\[
a_{i+1} = b_{i+1} = d \cdot n \quad (\text{由 } b_{i+1} = d \cdot n).
\]
因 $d \mid b_{i+1}$，且 $a_i = \frac{d}{k}$，有：
\[
a_{i+1} = d \cdot n = a_i \cdot (k \cdot n).
\]
故 $a_i \mid a_{i+1}$.

---

### 结论
为保证关系 $a_i \mid a_{i+1}$ 成立，必须满足：
\[
\boxed{x \mid b_i \quad \text{且} \quad \dfrac{b_i}{\gcd(b_i,\ b_{i+1})} \mid x}
\]

### 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
void solve(){
    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll x=1;
    for(int i=2;i<=n;i++){
        ll d=a[i-1]/gcd(a[i],a[i-1]);
        x=lcm(x,d);
    }
    cout<<x<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [Codeforces Round 1032 (Div. 3) G. Gangsta](https://codeforces.com/contest/2121/problem/G)


### 题目描述

给定一个长度为 $n$ 的二进制字符串 $s_1s_2 \ldots s_n$。仅由 0 和 1 组成的字符串称为二进制字符串。

对于字符串 $p$，定义函数 $f(p)$ 为字符串 $p$ 中任一字符的最大出现次数。例如，$f(00110) = 3$，$f(01) = 1$。

你需要找到所有满足 $1 \leq l \leq r \leq n$ 的对 $(l, r)$ 的 $f(s_ls_{l+1} \ldots s_r)$ 的和。

**输入格式**

每个测试包含多组测试用例。第一行包含一个整数 $t$ ($1 \le t \le 10^4$) — 测试用例的数量。接下来是它们的描述。

每个测试用例的第一行包含一个整数 $n$ ($1 \le n \le 2 \cdot 10^5$) — 二进制字符串的长度。

每个测试用例的第二行包含一个长度为 $n$ 的字符串，由 0 和 1 组成 — 二进制字符串 $s$。

保证所有测试用例的 $n$ 的总和不超过 $2 \cdot 10^5$。

**输出格式**

对于每个测试用例，输出所有满足 $1 \leq l \leq r \leq n$ 的对 $(l, r)$ 的 $f(s_ls_{l+1} \ldots s_r)$ 的和。





### 方法一：树状数组（Fenwick）在线计数 + 求和

这里的树状数组（Fenwick Tree）思路，核心是把原题中对每个子串求

$$
f(s_l\cdots s_r)=\max(\#0,\#1)
$$

的工作，转化为对“前缀和差”的绝对值之和的统计。下面分步说明：

---

### 1. 函数变换

令

$$
\text{len}=r-l+1,\quad x=\#1-\#0\quad\text{（在子串 }s_l\cdots s_r\text{ 中）}.
$$

那么

$$
\max(\#0,\#1)
=\frac{\#0+\#1+|\#1-\#0|}{2}
=\frac{\text{len}+|x|}{2}.
$$

因此，题目要求的答案

$$
\sum_{1\le l\le r\le n} \max(\#0,\#1)
\;=\;\sum_{l\le r}\frac{(r-l+1)+|\,\text{pre}[r]-\text{pre}[l-1]\,|}{2},
$$

其中 $\text{pre}[i]=\sum_{k=1}^i(\;s_k=='1'?+1:-1)$ 是“1 减 0”的前缀和。

将上式拆成两部分：

1. **长度之和**
   $\displaystyle\sum_{l\le r}(r-l+1)$ 可以用组合数学直接算出：

   $$
   \sum_{i=1}^n i\,(n-i+1).
   $$

2. **绝对前缀差之和**
   $\displaystyle\sum_{1\le l\le r\le n}\bigl|\text{pre}[r]-\text{pre}[l-1]\bigr|$。

---

### 2. 如何高效算 $\sum|\,\text{pre}[r]-\text{pre}[j]|$

枚举右端点 $r$，把它看作当前的“新值” $P=\text{pre}[r]$，需要快速算出：

$$
\sum_{j=0}^{r-1} |\,P - \text{pre}[j]\,|.
$$

我们把对所有之前的前缀和 $\text{pre}[j]$ 分成两类：

* $\text{pre}[j]\le P$ 的部分，
* $\text{pre}[j]> P$ 的部分。

对于第一类：

$$
\sum_{\text{pre}[j]\le P} (P - \text{pre}[j])
= P\cdot\bigl(\#\{\text{pre}[j]\le P\}\bigr)
  \;-\;\sum_{\text{pre}[j]\le P}\text{pre}[j].
$$

同理，对于第二类：

$$
\sum_{\text{pre}[j]> P} (\text{pre}[j] - P)
= \sum_{\text{pre}[j]> P}\text{pre}[j]
  \;-\;P\cdot\bigl(\#\{\text{pre}[j]> P\}\bigr).
$$

于是只要维护两棵树状数组：

1. `cnt`：记录到目前为止每个前缀和出现的次数；
2. `sum`：记录到目前为止每个前缀和的累计和。

下标为了避免负数，通常把实际的前缀和值偏移 $+n+1$ 再当作树状数组的下标。

每次处理 $r$ 时：

```cpp
int idx = pre[r] + (n+1);
long long c_le = cnt.query(1, idx);         // ≤ P 的个数
long long s_le = sum.query(1, idx);         // ≤ P 的前缀和之和
long long c_gt = cnt.query(idx+1, N);       // > P 的个数
long long s_gt = sum.query(idx+1, N);       // > P 的前缀和之和

// 累加 |差| 部分：
ans += P * c_le - s_le
     + s_gt - P * c_gt;

// 然后把当前 pre[r] 加入 Fenwick
cnt.modify(idx, 1);
sum.modify(idx, P);
```

在遍历结束后，`ans` 就包含了所有 $\sum|\,\text{pre}[r]-\text{pre}[l-1]|$，再加上长度之和并除以 2，就得到最终答案。

**复杂度**：

* 预处理前缀和 $O(n)$。
* 每个 $j$ 做两次 `sum` + 两次 `add`，每次 $O(\log n)$。
* 总 $O(n\log n)$，在 $n\le10^6$ 也能跑得很快。

---

### 方法二：排序 + 前缀和

这个思路更简洁，也是经典做法：

1. 先把所有 前缀和 $\{\mathit{per}[0],\mathit{per}[1],\dots,\mathit{per}[n]\}$ 放入一个数组 `P`，长度 $n+1$。

2. 对 `P` **排序** 为 `Q`。记原来的第 $i$ 小位置在排序后是 `Q[i]`。

3. 要算
   $\sum_{0\le p<q\le n} |P[p] - P[q]|$，分解成：

   $$
     \sum_{i=0}^{n}\sum_{j=0}^{n}|P[i]-P[j]|
     = \sum_{k=0}^{n}Q[k]\cdot (2k - n).
   $$

   公式来源：对一个已排序序列 $Q$，它第 $k$ 小对所有左边的 $k$ 个元素做 $(Q[k]-Q[i])$，对右边的 $(n-k)$ 个做 $(Q[j]-Q[k])$，合并后系数就是 $(2k-n)$。

4. 最后除以 $2$（因为上面算的是 $ i \ne j $ 的全和，要得到 $ i < j $ 的一半），或者把公式变成只累加 $k$ 到一半。

```cpp
vector<ll> P(n+1);
P[0] = 0;
for (int i = 1; i <= n; i++)
    P[i] = P[i-1] + (a[i]=='1'?+1:-1);

// 排序
sort(P.begin(), P.end());

// 累加
ll ans = 0;
for (int k = 0; k <= n; k++) {
    ans += P[k] * ( (ll)2*k - n );
}
// 由于上面算的是 sum_{i,j} |P[i]-P[j]|，需除 2
ans /= 2;

cout << ans << "\n";
```

**复杂度**：

* 计算前缀和 $O(n)$。
* 排序 $O(n\log n)$。
* 一次 $O(n)$ 累加。
* 总 $O(n\log n)$，常数比 Fenwick 解法略小。

---

### 解法1(BIT)
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};
void solve(){
    ll n;
    cin>>n;
    string a;
    cin>>a;
    a='+'+a;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+i*(n-i+1);
    }
    Fenwick<ll> S(2*n+10),C(2*n+10);
    int per=0;
    S.add(per+n,0);
    C.add(per+n,1);
    for(int i=1;i<=n;i++){
        per+=a[i]=='1'?1:-1;
        ans+=C.rangeSum(1,per+n)*per-S.rangeSum(1,per+n);//比per小的个数乘以per再减去它们的和
        ans+=S.rangeSum(per+n+1,2*n)-C.rangeSum(per+n+1,2*n)*per;//比per大的个数乘以per再减去它们的和
        S.add(per+n,per),C.add(per+n,1);//当前点更新
    }
    cout<<ans/2<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}

```
### 解法2(排序)

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

void solve(){
    ll n;
    cin>>n;
    string a;
    cin>>a;
    a='+'+a;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+i*(n-i+1);
    }
    vector<ll> per(n+1,0);
    for(int i=1;i<=n;i++){
        per[i]+=per[i-1];
        per[i]+=(a[i]=='1'?1:-1);
    }
    sort(per.begin(),per.end());
    for(int i=0;i<=n;i++){
        ans=ans+per[i]*(2*i-n);
    }
    cout<<ans/2<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [Codeforces Round 1016 (Div. 3) G. Shorten the Array](https://codeforces.com/contest/2093/problem/G)

### 题目描述

给定长度为 $n$ 的整数数组 $\,a_1,a_2,\dots,a_n$, 和一个整数 $k$。定义任意子数组 $b=a_\ell,\dots,a_r$ 的「美观度」

$$
f(b)=\max_{\,\ell\le i\le j\le r}\bigl(a_i\oplus a_j\bigr).
$$

如果 $f(b)\ge k$，则称该子数组是美观的。求数组 $a$ 中最短的美观子数组长度，如果不存在则输出 $-1$。

约束：

* 多组测试，$\sum n\le 2\times10^5$。
* $0\le a_i,k\le10^9$。

---

### 思路

1. **滑动窗口＋前缀最优异或**

   * 我们想在 $L$ 到 $R$ 的窗口里判断是否存在一对 $(i,j)$ 使得 $a_i\oplus a_j\ge k$。
   * 维护一个动态集合 $S$（窗口内的所有值），以及支持插入、删除和“给定 $x$，查询 $\max_{y\in S}(x\oplus y)$” 的数据结构。

2. **用二叉字典树（01-Trie）维护集合**

   * 字典树每个节点有两个孩子 `tr[p][0]`、`tr[p][1]`，表示当前位为 0/1。
   * 每个节点保存一个计数 `cnt[p]`：有多少个数的路径经过该节点。这样就能在删除时将对应路径上的计数减 1。

3. **查询操作**

   * 对给定 $x$，从最高位 29 到 0 贪心地走分支：优先选择与 $x$ 当前位相反（能凑出 1）的那条子树，只要它的 `cnt>0`；否则只能退而走同位子树。
   * 最终累加构造出的“与 $x$ 异或后最大”的值，再与 $x$ 异或，得到真正的最大异或结果。

4. **双指针滑动窗口**

   * 左指针 $L=1$，右指针 $R$ 从 1 跑到 $n$。
   * 每一步先把 $a_R$ 插入 Trie；然后只要当前窗口能满足条件，即 `query(a[R]) >= k`，就尝试用 $L$ 缩小窗口：

     * 更新答案 $\min(ans, R-L+1)$；
     * 从 Trie 中删除 $a_L$，并让 $L++$。
   * 最终若 $ans$ 未被更新，则输出 $-1$。

5. **复杂度**

   * 每个元素最多入窗一次、出窗一次，字典树操作为 $O(\log C)$ （$C\approx2^{30}$），总体 $O(n\log C)$，足够 $n\le2\times10^5$。

---

### 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int trie[M*31][2], cnt[M*31], tot;

int newNode() {
    int x = ++tot;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}

void add(int x, int t=1) {
    int p = 1;
    cnt[p] += t;
    for (int i = 29; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (!trie[p][u]) trie[p][u] = newNode();
        p = trie[p][u];
        cnt[p] += t;
    }
}

int query(int x) {
    int p = 1;
    if (!cnt[p]) return 0;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int u = (x >> i) & 1;
        // 优先走能让当前位异或出 1 的分支，且该分支非空
        if (trie[p][u^1] && cnt[trie[p][u^1]] > 0) {
            ans |= (1 << i);
            p = trie[p][u^1];
        } else {
            p = trie[p][u];
        }
    }
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    tot = 0;
    newNode();  // 创建根节点 = 1
    int L=1;
    int ans=1e9;
    for(int R=1;R<=n;R++){
        add(a[R],1);
        while(L<=R&&query(a[R])>=k){
            ans=min(ans,R-L+1);
            add(a[L],-1);
            L++;
        }
    }
    if(ans==1e9){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Codeforces Round 988 (Div. 3) F - Ardent Flames](https://codeforces.com/contest/2037/problem/F)


### 问题重述

* 有 $n$ 个敌人，分别位于一维坐标系上的位置 $x_i$，生命值为 $h_i$。
* 角色西洛嫩（Xilonen）的“地裂”技能：预先选择一个固定位置 $p$（整数），每次攻击对位置 $x$ 处的敌人造成的伤害是

  $$
    \max\bigl(0,\;m - |p - x|\bigr)
  $$
* 攻击会重复执行，且位置 $p$ 一旦选定就不可更改。
* 目标是在最少次数的攻击下，让至少 $k$ 个敌人的生命降到 $0$ 以下。若无论如何也无法同时歼灭 $k$ 个敌人，输出 $-1$。

---

### 思路 

### 二分答案

* **攻击次数** 显然是一个单调量：攻击次数越多，能歼灭的敌人越多。
* 设我们猜测用 $d$ 次攻击是否可行：若可行，则更大的次数也一定可行；若不可行，则更小的次数也一定不可行。
* 因此可对答案 $d$ 进行二分搜索。

### 对于固定的 $d$，如何判定能否歼灭 ≥$k$ 个敌人？

* **单个敌人的“可被歼灭区间”**

  * 对敌人 $i$，每次攻击在它身上造成的伤害是 $\max(0,\,m - |p - x_i|)$。
  * 如果选在位置 $p$，在 $d$ 次攻击中对它累计造成的伤害：

    $$
      \sum_{t=1}^d \bigl(m - |p - x_i|\bigr)
      = d\cdot m \;-\; d\cdot |p - x_i|.
    $$
  * 要使其生命值 $h_i$ 降至 0，需要

    $$
      d\,m - d\,|p - x_i| \;\ge\; h_i
      \quad\Longrightarrow\quad
      m - |p - x_i| \;\ge\; \Bigl\lceil \frac{h_i}{d}\Bigr\rceil.
    $$
  * 令

    $$
      t_i = \Bigl\lceil \frac{h_i}{d}\Bigr\rceil,
      \quad
      L_i = m - t_i.
    $$

    若 $L_i < 0$，那么无论如何选 $p$，每次攻击对该敌人造成的最大伤害都不超过 $m$，$d$ 次累计也一定达不到 $h_i$，该敌人 **不可能** 在 $d$ 次内被歼灭——可以直接跳过。
    否则，只有当 $|p - x_i| \le L_i$ 时，才满足上式，即

    $$
      x_i - L_i \;\le\; p \;\le\; x_i + L_i.
    $$

    这就是敌人 $i$ 的“可被歼灭区间” $[\,x_i - L_i,\;x_i + L_i\,]$。

* **汇总所有敌人的区间，寻找能同时覆盖 ≥$k$ 条区间的点**

  * 我们把每个区间的左端点记为 +1 事件、右端点的下一个位置记为 −1 事件，扫描所有事件并累加权值，就能得到每一个可能的 $p$，被多少个区间覆盖。
  * 如果存在某个 $p$ 使得覆盖数 ≥ $k$，说明可以在 $d$ 次攻击内歼灭至少 $k$ 个敌人。

---

### 实现细节

1. **预处理与跳过**

   * 对每个敌人 $i$，计算

     $$
       t_i = \Bigl\lceil h_i / d \Bigr\rceil,\quad
       L_i = m - t_i.
     $$
   * 若 $L_i < 0$，则不产生任何区间；否则在事件数组中添加

     $$
       (x_i - L_i,\; +1),\quad (x_i + L_i + 1,\; -1).
     $$

2. **事件排序与扫描**

   * 将所有事件按位置从小到大排序；相同位置按 +1 先于 −1（通常排序即可）。
   * 线性扫描，维护一个当前覆盖数 `sum`，每遇到 +1 则 `sum++`，遇到 −1 则 `sum--`。
   * 若扫描过程中 `sum >= k`，即可判定 $d$ 次攻击可行。

3. **二分搜索上下界**

   * 最少为 $1$ 次攻击，最多可取一个很大的数，比如 $10^{14}$（题目中 $h_i$ 最多到 $10^9$，$m$ 最多到 $10^9$，在最坏情况下差值需很大）。
   * 二分到 $[L,R]$ 收敛，输出最小可行的 $d$，否则输出 −1。

* **关键函数 `ck(d)`**：把能被 $d$ 次攻击覆盖（即歼灭）的敌人区间做成“加一减一”事件，扫描求最大重叠数。
* **二分框架**：在 $[1,\,10^{14}]$ 里搜索最小的可行攻击次数。
* **至多 $\approx50$ 次二分，每次 $O(n\log n)$**，总复杂度可接受。

---

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


ll n,m,k;
ll hp[M],x[M];
bool ck(ll d){
    vector<PII> r;
    for(int i=1;i<=n;i++){
        ll len=m-(hp[i]+d-1)/d;
        if(len>=0){//差分
            r.push_back({x[i]-len,1});
            r.push_back({x[i]+len+1,-1});
        }
    }
    sort(r.begin(),r.end());
    ll sum=0;
    for(auto [l,w]:r){//前缀和
        sum+=w;
        if(sum>=k)return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>hp[i];
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    ll L=1,R=1e14;
    ll ans=-1;
    while(L<=R){//二分
        ll mid=L+R>>1;
        if(ck(mid)){
            ans=mid;
            R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```





## [P3811 【模板】模意义下的乘法逆元](https://www.luogu.com.cn/problem/P3811)

### 题目描述

给定 $n,p$ 求 $1\sim n$ 中所有整数在模 $p$ 意义下的乘法逆元。

这里 $a$ 模 $p$ 的乘法逆元定义为 $ax\equiv1\pmod p$ 的解。

## 输入格式

一行两个正整数 $n,p$。

## 输出格式

输出 $n$ 行，第 $i$ 行表示 $i$ 在模 $p$ 下的乘法逆元

### 思路

### 方法一：扩展欧几里得算法

对每个 $i$ 单独调用扩展欧几里得，求解 $i x + p y = 1$：

1. 写出递归式：

   ```cpp
   ll exgcd(ll a, ll b, ll &x, ll &y) {
       if (b == 0) { x = 1; y = 0; return a; }
       ll d = exgcd(b, a % b, x, y);
       ll tx = x, ty = y;
       x = ty;
       y = tx - (a / b) * ty;
       return d;
   }
   ```
2. 对每个 $ i=1\ldots n $：

   * 调用 `exgcd(i, p, x, y)`；
   * 逆元即 $ (x \bmod p + p) \bmod p $。

**复杂度**
单次扩展欧几里得为 $ O(\log p) $，总计 $ O(n\log p) $，当 $n,p\le10^6 $ 时通常可过。

---

### 方法二：线性递推法（更优 $O(n)$）

当 $p$ 为质数时，有著名的递推公式：

$$
\mathrm{inv}[1] = 1, 
\quad
\mathrm{inv}[i] = \bigl(p - \lfloor p / i\rfloor\bigr)\times \mathrm{inv}[p \bmod i]\bmod p.
$$


用于求一个数对于一个模$p$ 的逆元($p$ 为素数)。

只要运用这种方法，就能在 $O(n)$ 时间内求出所有 $1…p–1$ 的逆元。

首先，我们有

$$
1 \cdot 1^{-1} \equiv 1 \pmod p.
$$

假设

$$
p = k \cdot i + r,\quad (1 < r < i < p)
$$

由整除 $p/i$ 可得商 $k$ 和余数 $r$。

将上式两边取 mod p 得：

$$
k\,i + r \equiv 0 \pmod p.
$$

两边同时乘以 $i^{-1}\,r^{-1}$ 后：

$$
k\,i\,i^{-1} + r\,i^{-1} \equiv 0 \pmod p
\quad\Longrightarrow\quad
i^{-1} \equiv -\,k\,r^{-1} \pmod p.
$$

又因为 $k = \lfloor p/i\rfloor$ 且 $r = p \bmod i$，所以

$$
i^{-1} \;\equiv\; -\,\bigl\lfloor p/i\bigr\rfloor \;\cdot\;(p \bmod i)^{-1}
\;\pmod p.
$$

由此便可从最基本的 $1^{-1}$ 开始，递推求出所有 $i^{-1}$。


### 扩展欧几里得
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

ll exgcd(int a,int b,int &x,int &y)
{
    if(!b){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int nx=x;
    int ny=y;
    x=ny;
    y=nx-(a/b)*ny;
    return d;
}
void solve(){
    int n,p; 
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        int x,y;
        exgcd(i,p,x,y);
        cout<<(x+p)%p<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

### 线性逆元
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

void solve(){
    ll n,p;
    cin>>n>>p;
    ll inv[n+1];
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=((p-p/i)*inv[p%i])%p;
    }
    for(int i=1;i<=n;i++){
        cout<<inv[i]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [2025牛客暑期多校训练营1 L.Numb Numbers](https://ac.nowcoder.com/acm/contest/108298/L)

### 题目描述

给定一个大小为 $n$ 的数组 $a[1..n]$。每天，每个数都会和其它 $n-1$ 个数各自比一次大小——如果它比某个数小，则算作一次“失败”。如果一个数在一次“比赛”中失败 $\ge\bigl\lceil\frac{n-1}2\bigr\rceil$ 次，就会“numb”（郁闷）。
此外，一共有 $q$ 天，每天给定一个更新：挑选下标 $p$ 的数，加上一个正整数 $v$。更新后，再计算一次“numb”的数的个数，输出结果。

* $3 \le n \le 2\times10^5$，$1\le q\le2\times10^5$；
* 初始和所有更新后值都在 $[1,10^9]$；
* 所有测试用例的 $n$ 和 $q$ 总和 $\le5\times10^5$。

### 思路

1. **等价转换**
   一个数如果在比赛中失败 $\ge\lceil\frac{n-1}2\rceil$ 次，则它在数组中“比它大的元素”数量 $\ge \lceil\frac{n-1}2\rceil$。等价地，它“排在最小的前” $\lfloor\frac{n+1}2\rfloor$ 个位置中。

2. **维护“前 $t$ 小”元素的个数**
   设阈值 $\displaystyle t = \bigl\lfloor\frac{n+1}2\bigr\rfloor$。此时，“numb”的数量就是“当前数组中排在最前 $t$ 小的元素的实际个数”。

3. **在线更新：树状数组 + 离散化**

   * **离散化**：把所有初始值和每次更新后可能出现的新值 收集、排序去重，映射到 $[1..M]$，其中 $M\le n+q$。
   * **树状数组（Fenwick Tree）**：用大小 $M$ 的数组 `bit`，维护“每个离散化值上有多少个元素”。

     * 插入和删除：`bit.add(id, +1)` 或 `bit.add(id, -1)`；
     * 查询前缀和：`bit.sum(x)` 得 $\sum_{i=1}^x \text{freq}_i$。
   * **查询“numb”数量**：在 $[1..M]$ 区间二分，找最大的 `pos` 使得 `bit.sum(pos) ≤ t`，然后答案就是 `bit.sum(pos)`。

4. **时间复杂度**

   * 离散化：$O((n+q)\log(n+q))$
   * 每次更新 + 二分查前缀：各 $O(\log(n+q))$，共 $O((n+q)\log(n+q))$。

* **离散化**：把所有可能出现的值先收集、排序去重，再映射到紧凑区间 $[1..M]$。
* **树状数组**：支持单点更新与前缀和查询，更新 $\log M$，查询 $\log M$。
* **二分前缀和**：在 $[1..M]$ 上找最大的下界，使得前缀和 $\le t$，从而得到“numb”的个数。
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
struct BIT{//树状数组
    int n;
    vector<int> t;
    void init(int _){//初始化大小
        n=_;
        t.resize(n+1,0);
    }
    void add(int x,int v){//单点修改，下标必须从1开始
        for(int i=x;i<=n;i+=(i&-i)){
            t[i]+=v;
        }
    }
    ll query(int x){//查询前x位置的和
        ll res=0;
        for(int i=x;i>=1;i-=(i&-i)){
            res+=t[i];
        }
        return res;
    }
};  
int f(ll x,vector<ll>& k){//二分查询这个值在k的位置
    int L=0,R=k.size()-1,idx=0;
    while(L<=R){
        int mid=L+R>>1;
        if(k[mid]<=x){
            idx=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    idx++;//树状数组下标必须从1开始，k是从0开始
    return idx;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> k;
    ll a[n+10],b[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        k.push_back(a[i]);
    }
    vector<pair<ll,ll>> t;
    for(int i=1;i<=q;i++){
        ll p,v;
        cin>>p>>v;
        t.push_back({p,v});
        b[p]+=v;
        k.push_back(b[p]);//离线所有的值到k中
    }
    sort(k.begin(),k.end());
    k.erase(unique(k.begin(),k.end()),k.end());//然后离散化
    BIT r;
    r.init(k.size());
    for(int i=1;i<=n;i++){
        r.add(f(a[i],k),+1);//先初始化树状数组
    }
    for(int i=0;i<q;i++){
        auto [p,x]=t[i];
        r.add(f(a[p],k),-1);//原来的位置删掉
        a[p]+=x;
        r.add(f(a[p],k),+1);//新的位置加上
        int L=1,R=k.size();//在所有的值上二分
        int ans=0;
        while(L<=R){
            int mid=L+R>>1;
            if(r.query(mid)<=(n+1)/2){//如果这个前缀的个数小于等于(n+1)/2就可以
                ans=r.query(mid);
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        cout<<ans<<'\n';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [2025牛客暑期多校训练营1 K.Museum Acceptance](https://ac.nowcoder.com/acm/contest/108298/K)

### 题目描述

有一个连通的博物馆，共 $n$ 个房间，每个房间最多有 3 扇门，每扇门通向不同的邻居房间。门两端是双向的走廊。给定每个房间的门按标签（读入顺序）列出的连接信息，游客按如下规则无穷漫游：

1. **初始** 在房间 $u$，先走标签为 1 的门；
2. **之后**，如果是从该房间的第 $i$ 号门进来的，下次就从第 $(i+1)$ 号门出去，到达下一个房间；
3. 如果 $i$ 已是该房间的最大标签，则下次回到标签 1。

要求对每个起始房间 $i$，无穷走下去能经过多少条**不同**（去重）走廊？输出 $n$ 行，对应每个房间的答案。

---

### 思路

将“房间 $x$ 、下次从第 $p$ 号门出去”视作一个**状态** $(x,p)$。

* 对应的**后继状态** $(y,q)$ 唯一确定：

  1. 先走走廊 $(x,p)$→房间 $y$。
  2. 在房间 $y$ 找到通回 $x$ 的门号 $r$（在 $y$ 的列表里线性扫描），这是“从 $y$ 的门 $r$ 进来”。
  3. 按规则“进来 $r$ 号，下次走 $(r+1)\bmod d_y$”得到 $q$。

于是我们在所有状态上构造一条指向其唯一后继的**函数图**。从任何起点迭代下去，必先走一段“尾”，再落入一个**环**。我们要统计沿途经过的不同走廊数，即在这条轨迹上每条有向通道第一次出现时 +1。

用 **DFS + 记忆化 + 回溯**，复杂度 $O(\sum d_u)=O(n)$：

1. **状态数** $\sum_u d_u \le 3n$。
2. 维护全局计数器 `cnt`，以及两张表

   * `vis[x][p]`：当前这条 DFS 路径上，“状态 $(x,p)$” 是否已经访问过（用于**去重计数**和检测环）；
   * `ans[x][p]`：记忆化表，存储“从 $(x,p)$ 开始”最终能走过多少条不同走廊，一旦写入就不再重复 DFS。
3. **调用**：对每个房间 $i$，如果 `ans[i][0]` 还未计算，就令 `cnt=0; dfs(i,0);`，然后输出 `ans[i][0]`。

这样每个状态 $(x,p)$ 最多进入一次 `dfs`，每次内部扫描度数至多 3，故总复杂度线性。

---

### 关键细节：DFS 记忆化的位置

* **`if (vis[x][p]) return;`**

  * 检测到当前路径内曾访问过该状态（环或重复），直接返回，不再深入。

* **`vis[x][p] = true;`**

  * 标记该状态入栈，用于保证“一条路径里”对同一通道只 `cnt++` 一次。

* **`if (!vis[y][r]) cnt++;`**

  * 这是「新通道计数」的唯一位置：当且仅当“走到的下一个通道 $(y,r)$”在当前 DFS 路径上**尚未**被访问过，才 `cnt++`。

* **递归后 `vis[y][q] = false;`**

  * 回溯：撤销对后继状态的标记，使它对「从别的起点启动」的 DFS 仍然可统计为“新通道”。

* **`ans[x][p] = cnt;`**

  * 在离开当前 `dfs(x,p)` 之前，将累计的 `cnt` 写进 `ans[x][p]`。这样，下次再遇到状态 $(x,p)$ 就直接跳过，不用重复 DFS。

* **线性复杂度**：状态数 $\sum d_i \le 3n$，每个状态只进 `dfs` 一次，内部操作 $O(1)$。
* **记忆化与回溯**：确保了“每条通道第一次出现时才计数”，并避免重复计算。

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
vector<vector<int>> e(M),ans(M),v(M);
int cnt;
void dfs(int x,int p){
    if(v[x][p])return ;// 环或已入栈，结束
    v[x][p]=1;
    int to=e[x][p];
    int rd;
    for(int i=0;i<e[to].size();i++){
        if(e[to][i]==x){
            rd=i;
        }
    }
    if(!v[to][rd])cnt++;// 第一次踩到这条通道
    int cd=(rd+1)%e[to].size();// 下次从(to,cd) 出发
    dfs(to,cd);
    v[to][cd]=0;// 回溯：释放后继状态
    ans[x][p]=cnt;// 记忆化：保存结果
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        e[i].resize(d);
        ans[i].resize(d,0);
        v[i].resize(d,0);
        for(int j=0;j<d;j++){
            cin>>e[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(!ans[i][0]){
            cnt=0;
            dfs(i,0); // 从房间 i 的第 0 号门（原题的 1 号门）跑
        }
        cout<<ans[i][0]<<'\n';
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [Educational Codeforces Round 153 (Rated for Div. 2)](https://codeforces.com/contest/1860/problem/D)

### 问题描述

给定长度为 $n$ 的二元串 $s$，定义：

* $\#01$ 为所有满足 $i<j$ 且 $(s_i,s_j)=(0,1)$ 的对数；
* $\#10$ 为所有满足 $i<j$ 且 $(s_i,s_j)=(1,0)$ 的对数。

如果 $\#01=\#10$，则称该串**平衡**。保证对给定的 $s$，存在若干次「任意两字符交换」操作后可达平衡态，问最少需要多少次交换。

---
### 思路

### 核心观察

1. **差值**
   定义当前串的“平衡差值”

   $$
     D = \#01 \;-\;\#10.
   $$

   目标是使最终重排后 $D=0$。

2. **交换与不匹配**
   将原串 $s$ 重建为某个平衡串 $t$（通过若干次交换），可以证明：

   * 只要知道重建过程中有多少下标 $i$ 满足 $s_i\neq t_i$（记作不匹配数 $M$），
   * 每次交换最多修复两个不匹配位置，

   则最小交换次数就是

   $$
     \bigl\lceil M/2 \bigr\rceil = \frac{M}{2}
     \quad(\text{因 }M\text{必为偶数}).
   $$

所以，问题等价于：**构造一个平衡串 $t$，并最小化它与 $s$ 的不匹配数**。

---

### 动态规划方案

**1. 状态定义**

记原串中“0”的总数为

$$
  Z = \#\{i: s_i=0\},\quad
  O = n-Z.
$$

我们按位置从左向右重建目标串 $t$，用三维 DP 表示：

$$
  \mathrm{dp}[i][j][d]
  = \min\bigl(\text{已重建前缀长度 }i,\;
       \text{其中放了 }j\text{ 个 ‘0’，且当前差值 }D=d\text{ 时的“不匹配数”}\bigr).
$$

* $i\in[0,n]$：已处理的字符数；
* $j\in[0,Z]$：前 $i$ 位中已经放的 ‘0’ 数，故放了 $i-j$ 个 ‘1’；
* 差值 $D$ 取值范围 $[-Z\cdot O,\,+Z\cdot O]$，我们在线性化下标时加上常数
  $\mathrm{OFFSET}=Z\times O$，即用

  $$
    d = D + \mathrm{OFFSET}\;\in\;[0,\,2\,Z\,O].
  $$

初始状态

$$
  \mathrm{dp}[0][0][\mathrm{OFFSET}] = 0,
$$

其余均初始化为 +∞（或一个足够大的常数）。

---

**2. 差值更新**

当我们在第 $i+1$ 位选放一个字符时：

* 若放 **‘0’**，它会与前面所有已放的 ‘1’ 形成新的 “10” 对：

  $$
    D \;\gets\; D \;-\;(\#\text{已放 ‘1’}) \;=\; D - (\,i-j\,).
  $$
* 若放 **‘1’**，它会与前面所有已放的 ‘0’ 形成新的 “01” 对：

  $$
    D \;\gets\; D \;+\;(\#\text{已放 ‘0’}) \;=\; D + j.
  $$

---

**3. 状态转移**

记原串第 $i+1$ 个字符为 $s_i$。从状态 $\bigl(i,j,d\bigr)$（差值真实为 $D=d-\mathrm{OFFSET}$）可转：

1. **放 ‘0’** （条件：$j<Z$）

   * 新差值下标

     $$
       d' = d - (\,i-j\,),
     $$

     需保证 $0\le d'\le 2ZO$；
   * 不匹配增量

     $$
       \delta = [\,s_i\neq '0'\,] \quad(\text{若原串该位也是 ‘0’ 则 $\delta=0$，否则 $\delta=1$}).
     $$
   * 转移：

     $$
       \mathrm{dp}[i+1][\,j+1\,][\,d'\,]
         = \min\bigl(\mathrm{dp}[i+1][j+1][d'],\;
                    \mathrm{dp}[i][j][d] + \delta\bigr).
     $$

2. **放 ‘1’** （条件：$(i-j)<O$）

   * 新差值下标

     $$
       d' = d + j,
     $$

     需保证 $0\le d'\le 2ZO$；
   * 不匹配增量

     $$
       \delta = [\,s_i\neq '1'\,].
     $$
   * 转移同理：

     $$
       \mathrm{dp}[i+1][\,j\,][\,d'\,]
         = \min\bigl(\mathrm{dp}[i+1][j][d'],\;
                    \mathrm{dp}[i][j][d] + \delta\bigr).
     $$

---

**4. 答案读取**

完成所有 $i=0,\dots,n-1$ 的转移后，最终我们关心：

$$
  M = \mathrm{dp}[n][\,Z\,][\,\mathrm{OFFSET}\,],
$$

即放完所有 $n$ 位、用了所有 $Z$ 个 ‘0’、且差值 $D=0$（对应偏移后下标 $\mathrm{OFFSET}$）时的最小不匹配数。交换次数即

$$
  \text{ans} \;=\; \frac{M}{2}.
$$


### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


void solve(){
    string a;
    cin>>a;
    int cnt0=0,cnt1=0;
    for(int i=0;i<a.size();i++){
        cnt0+=(a[i]=='0');
        cnt1+=(a[i]=='1');
    }
    int R=cnt0*cnt1;
    //[-R,R]->[0,2*R];
    vector<vector<int>> dp(cnt0+10,vector<int>(2*R+10,1e9));
    dp[0][R]=0;
    for(int i=0;i<a.size();i++){
        vector<vector<int>> f(cnt0+10,vector<int>(2*R+10,1e9));
        for(int j=0;j<=cnt0;j++){
            int q1=i-j;
            if(q1>=0&&q1<=cnt1){
                for(int d=0;d<=2*R;d++){
                    if(dp[j][d]!=1e9){
                        if(j<cnt0){//这一位放0
                            int nd=d-q1;
                            if(nd>=0){
                                f[j+1][nd]=min(f[j+1][nd],dp[j][d]+(a[i]!='0'));
                            }
                        }
                        if(q1<cnt1){//这一位放1
                            int nd=d+j;
                            if(nd<=2*R){
                                f[j][nd]=min(f[j][nd],dp[j][d]+(a[i]!='1'));
                            }
                        }
                    }
                }
            }
        }
        dp=f;
    }
    cout<<dp[cnt0][R]/2<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [Codeforces Round 1037 (Div. 3) G2. Big Wins! (hard version)](https://codeforces.com/contest/2126/problem/G2)

---

### 题目重述

给定长度为 $n$ 的数组 $a[1…n]$，元素均在 $[1,n]$ 范围内。定义任意子数组 $a[l…r]$ 的值为

$$
\operatorname{med}(a[l…r]) \;-\;\min(a[l…r])\!,
$$

其中 $\min$ 取最小值，$\operatorname{med}$ 取排序后第 $\lceil(k+1)/2\rceil$ 个数（$k=r-l+1$ 的子数组长度）。求能够使上式最大化的 $l,r$。

---

### 核心思路

1. **将“$med - min$ 最大化”转换为“最大化中位数与最小值之差”**

   * 记子数组最小值为 $m$，我们想最大化“能够取到的中位数 $\ge m+d$”的最大 $d$。
   * 等价对每个可能 $m$（数组中出现过的值）单独计算，找出最小值固定为 $m$ 时能“抬高”到的最大中位数减去 $m$。

2. **双指针 + 线段树维护“是否 $\ge$ 阈值”**

   * 枚举子数组最小值 $mn$（从小到大）。
   * 维护一个当前“尝试的中位数阈值” `med`，初始 `med = mn`。
   * 线段树上将 `a[i] ≥ med` 的位置记作 +1，否则 −1。
   * 对于所有值恰好等于 `mn` 的下标，先将它们标成 −1（消费掉这些最小值）。
   * 然后遍历所有等于 `mn` 的位置 `x`，尝试能否把 `med → med+1`：

     * 计算以 `x` 为最小值的扩展区间 $[L[x],,R[x]]$ 中，除去 `x` 自身左右两段的“最优后缀/前缀和”之和，再加上 `x` 自身对新阈值的贡献（+1 或 −1），看是否 $\ge0$。
     * 若满足，则表示可以把中位数阈值成功提升到 `med+1`，于是先 `med++`，然后把所有原来等于新 `med` 的位置也翻成 −1（继续消费）。重复直到不可提升。
   * 每轮枚举 `mn` 后，答案候选为 `med - mn`，取最大。

3. **区间 $[L[i],R[i]]$ 的预处理**

   * 用单调栈一遍求出每个位置作为“最小值”时能扩到的左右边界 $L[i],R[i]$，保证区间内所有值 $\ge a[i]$。

4. **时间复杂度**

   * 单调栈求 $L,R$： $O(n)$
   * 枚举 `mn` （最多 $n$）+ 对应的双指针提升 `med`（每次提升会对每个值消费一次）：整体 $O(n\log n)$
   * 线段树查询/更新： $\log n$

合计 $O(n\log n)$，$n$ 总和 $\le2·10^5$，足够通过。

---

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200000;
struct Node {
    int sum, lmx, rmx;
} tr[4*MAXN+5];
int a[MAXN+5], Lb[MAXN+5], Rb[MAXN+5];
vector<int> pos[MAXN+5];

// 合并两个子区间
inline Node merge(const Node &A, const Node &B) {
    Node C;
    C.sum = A.sum + B.sum;
    C.lmx = max(A.lmx, A.sum + B.lmx);
    C.rmx = max(B.rmx, B.sum + A.rmx);
    return C;
}

// 建树：所有点初始 +1
inline void build(int p, int l, int r) {
    if (l == r) {
        tr[p] = {1, 1, 1};
        return;
    }
    int m = (l + r) >> 1;
    build(p<<1, l, m);
    build(p<<1|1, m+1, r);
    tr[p] = merge(tr[p<<1], tr[p<<1|1]);
}

// 点更新：把 x 位置设为 k(+1 or -1)
inline void update(int p, int l, int r, int x, int k) {
    if (l == r) {
        tr[p].sum = k;
        tr[p].lmx = tr[p].rmx = max(k, 0);
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) update(p<<1, l, m, x, k);
    else         update(p<<1|1, m+1, r, x, k);
    tr[p] = merge(tr[p<<1], tr[p<<1|1]);
}

// 区间查询
inline Node query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {0,0,0};
    if (ql <= l && r <= qr) return tr[p];
    int m = (l + r) >> 1;
    if (qr <= m) return query(p<<1, l, m, ql, qr);
    if (ql >  m) return query(p<<1|1, m+1, r, ql, qr);
    Node L = query(p<<1, l, m, ql, qr);
    Node R = query(p<<1|1, m+1, r, ql, qr);
    return merge(L, R);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        // 清理
        for (int i = 1; i <= n; i++) pos[i].clear();

        // 读入并记录每个值出现的位置
        int Mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
            Mx = max(Mx, a[i]);
        }

        // 单调栈求 Lb, Rb
        {
            static int stk[MAXN+5], top = 0;
            top = 0;
            for (int i = 1; i <= n; i++) {
                while (top && a[stk[top]] >= a[i]) top--;
                Lb[i] = top ? stk[top]+1 : 1;
                stk[++top] = i;
            }
            top = 0;
            for (int i = n; i >= 1; i--) {
                while (top && a[stk[top]] >= a[i]) top--;
                Rb[i] = top ? stk[top]-1 : n;
                stk[++top] = i;
            }
        }

        // 初始化线段树，所有点置 +1
        build(1,1,n);

        // 初始消费掉所有等于 1 的点（即把它们设 -1），并将 med=1→2
        int med = 1;
        for (int idx : pos[1])
            update(1,1,n, idx, -1);
        med++;

        int ans = 0;
        // 枚举最小值 mn
        for (int mn = 1; mn <= Mx; mn++) {
            // 对所有位置值 == mn
            for (int x : pos[mn]) {
                // 尝试不断把 med 推高
                while (med <= Mx) {
                    // 左侧后缀、右侧前缀
                    int left  = query(1,1,n, Lb[x], x-1).rmx;
                    int right = query(1,1,n, x+1, Rb[x]).lmx;
                    // x 自身对新阈值的贡献
                    int self = (a[x] >= med ? +1 : -1);
                    if (left + right + self >= 0) {
                        // 可以提升
                        for (int posi : pos[med])
                            update(1,1,n, posi, -1);
                        med++;
                    } else break;
                }
            }
            ans = max(ans, med - 1 - mn);
        }

        cout << ans << "\n";
    }
    return 0;
}
```

---























## [Codeforces Round 1037 (Div. 3) F. 1-1-1, Free Tree!](https://codeforces.com/contest/2126/problem/F)

### 题目描述
给定一棵有 $n$ 个节点的树，节点编号 $1$ 到 $n$。每个节点 $i$ 有初始颜色 $a_i$。树上每条边 $(u,v)$ 有一个权值参数 $c$。如果连接的两个端点颜色相同，则该边的代价为 0，否则为 $c$。

接下来有 $q$ 次操作，每次操作将某个节点 $v$ 的颜色改为 $x$，颜色变化保留到后续操作。每次操作后，要求输出整棵树上所有边的总代价之和。

* $1 \le t \le 10^4$（测试组数）
* 对所有测试组，$\sum n \le 2\cdot10^5$，$\sum q \le 2\cdot10^5$。
* 每个节点的颜色范围 $1 \le a_i \le n$，每条边权值 $1 \le c \le 10^9$。
* 每次重染操作：$1 \le v,x \le n$。

---

### 思路

要在每次单点染色修改后，**高效**地更新所有边的总代价，显然不能每次重算整棵树（那是 $O(n)$ 每次，最坏 $O(nq)$ 不可行）。我们需要支持：

1. **查询当前总代价**
2. **修改一个节点颜色**
3. **高效地更新因该节点周围若干边带来的总代价变化**

> 观察：一条边 $(u,v)$ 的贡献只和它两端点的颜色是否相同有关。改动节点 $v$ 只会影响和它相连的那些边。所以我们需要快速维护，某节点与其所有邻居按颜色分组的“跨色权值之和”。

 **1. 预处理：初始 DFS 构建**

任选一点（比如 1）作为根，做一次 DFS，记录：

* `fa[v]`：节点 $v$ 的父节点；
* `fc[v]`：边 $(fa[v],v)$ 的权值；
* 对每个节点 $u$，维护一个哈希表（或 `map<int64,int64>`）`s[u]`，记录它的子节点中**不同颜色**的累积“跨色权值”：

  $$
    s[u][color] = \sum_{\substack{v\text{ 是 }u\text{ 的子} \\ a[v]=color}} c(u,v).
  $$
* 全局变量 `ans`：初始时计算所有边的代价之和。

在 DFS 过程中，对每条边 $(u,v)$：

* 如果 $a[u] \neq a[v]$，就把 $c$ 加到 `ans`；
* 同时在 `s[u][a[v]]` 中累加 $c$。

DFS 复杂度 $O(n\log n)$（若用 `map` 插入）。

 **2. 单次颜色修改的处理**

设要把节点 $v$ 的颜色从旧色 $\alpha$ 改成新色 $\beta$：

* **它所有子边的影响**
  每条子边 $(v, w)$ 对总代价的影响已体现在当时 `ans`。但整体可以总结为：

  * 它和子节点间“跨色”的权值总和 =
    $\sum_{w\in\text{children}(v)} [a[w]\neq a[v]]\cdot c(v,w)$.
    而这个值正好是 `s[v][*]` 中，所有键 $\neq a[v]$ 的条目之和；但我们不想遍历所有子节点。
    更妙的是，我们只需要两项：

  1. 它原来与颜色 $\beta$ 的子节点之间的“本来相同后变不同”权值：`s[v][β]`，这部分在染色前是“颜色不同”还是“相同”？

     * 原来：若 $\beta \neq \alpha$，子节点颜色 $\beta$ 被当成“跨色”计入了 `ans`；改完色后它们反而同色，应**减去**这部分 `s[v][β]`。
  2. 它原来与颜色 $\alpha$ 的子节点之间的“本来相同后变不同”权值：`s[v][α]`；因为原来它们是同色，不贡献；改色后变跨色，要**加上**这部分。

* **它与父边的影响**
  如果 $v$ 不是根，还要额外处理和父节点 $u=fa[v]$ 之间的那条边：

  * 原来若 $a[u]\neq\alpha$，这条边在 `ans` 中已含一次 $c$；若相同则没含。改色后要**重新计算**是否跨色：

    * 若 $a[u]\neq\beta$，则要在 `ans` 中包含 $+c$；否则要移除这条 $c$。
  * 等价地，也可用同样的“先减去旧状态，再加上新状态”方法。

* **维护 `s` 结构**
  最后要维护父节点 `u` 的 `s[u]` 中关于 $v$ 这条边的归属颜色：

  ```cpp
  s[fa[v]][old_color] -= c(fa[v],v);
  s[fa[v]][new_color] += c(fa[v],v);
  ```

  （若 $v$ 是根则跳过）

整合上面四步，就可以 $O(\log n)$（map 的查找与修改）完成一次染色操作及 `ans` 更新。


* **预处理 DFS**：$O(n\log n)$（每条边在 `map` 上插入一次）
* **每次染色操作**：$O(\log n)$（修改和查询两三个 `map` 条目）
* 总体对于一组 $n,q$：$O\bigl((n+q)\log n\bigr)$
* 因为所有测试组 $\sum n,\sum q \le 2\times10^5$，总时间约 $O\bigl((N+Q)\log N\bigr)$ 可在 1 秒内通过。

---

**小结**

* 由“节点改色只影响其相邻的边”，我们局部维护每个节点与相邻子节点 **按颜色分桶的权值和**，以及父边的单独处理。
* 这样单次改色更新可做到 $O(\log n)$，整体满足题目规模要求。

### 代码
``` c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;

vector<PII> e[M];
ll a[M],fa[M],fc[M];
map<ll,ll> s[M];
ll ans;
void dfs(int x,int f){
    fa[x]=f;
    for(auto [y,c]:e[x]){
        if(y==f)continue;
        s[x][a[y]]+=c;
        fc[y]=c;
        ans+=(a[x]==a[y])?0:c;
        dfs(y,x);
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        e[u].push_back({v,c});
        e[v].push_back({u,c});
    }
    ans=0;
    dfs(1,0);
    for(int i=1;i<=q;i++){
        int v,x;
        cin>>v>>x;
        if(a[v]!=x){
            ans-=s[v][x];
            if(fa[v]){
                ans-=(a[fa[v]]==x)*fc[v];
            }
            ans+=s[v][a[v]];
            if(fa[v]){
                ans+=(a[fa[v]]==a[v])*fc[v];
            }
            if(fa[v]){
                s[fa[v]][a[v]]-=fc[v];
                s[fa[v]][x]+=fc[v];
            }
            a[v]=x;
        }
        cout<<ans<<'\n';
    }
    for(int i=1;i<=n;i++){
        e[i].clear();
        fa[i]=fc[i]=0;
        s[i].clear();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```


## [2025牛客暑期多校训练营1  I.Iron Bars Cutting](https://ac.nowcoder.com/acm/contest/108298/I)

### 题目描述

* 有 $n$ 根长度分别为 $a_1,a_2,\dots,a_n$ 的铁棒，按顺序焊接成一根长铁棒。
* 需要通过恰好 $n-1$ 次切割，将其恢复成 $n$ 根独立铁棒。
* **每次切割规则**：在某个焊点处把一根铁棒分成长度分别为 $l_1$ 和 $l_2$ 的两段。

  * **不平衡度**：$\Delta=|l_1-l_2|$。
  * **切割代价**：$\min(l_1,l_2)\times\bigl\lceil\log_2(l_1+l_2)\bigr\rceil$。
* **额外限制**：所选的 $n-1$ 次切割，其不平衡度必须呈**非增**序列。
* 对于每个可能的“**首次切割位置**”（即在第 $i$ 和 $i+1$ 根之间），求满足上述限制的**最小总代价**，若无解则输出无解标记。

---

### 思路

1. **分段递归切割**
   将区间 $[l,r]$ 上的焊点按顺序切分，递归地切完左右两边，合并子问题的最优解。

2. **状态扩展：带“不平衡度”**
   为了满足“切割不平衡度非增”的全局约束，需要在每个子区间切割后记录“当前这次切割的不平衡度”以及“切完整个子区间的累积最小代价”。

3. **排序 + 前缀最小值 + 二分**
   对每个子区间 $[l,r]$，将所有可能切在焊点 $m$ 处、且能切完的合法解 $(\Delta,\;C)$ 对按 $\Delta$ 升序排序，并做一次前缀最小值处理。这样上层在合并时，只需根据父割的“不平衡度上限”二分查找即可得到最优子解。


**状态定义**

令

$$
dp[l][r] = \text{一个有序列表}\;\{(\Delta_k,\,C_k)\}\quad(\Delta_1<\Delta_2<\cdots)
$$

表示将区间 $[l,r]$（按原序号拼接的若干根铁棒）**完全切割**成单根铁棒，且最后一次切割的不平衡度恰为 $\Delta_k$ 时的最小总代价为 $C_k$。

* 当 $l=r$ 时，无需切割，唯一状态为 $(\Delta=0,\;C=0)$。


**状态转移**

考虑区间 $[l,r]$ 的一次“顶层”切割，切点在 $d$（即把 $[l,r]$ 切为 $[l,d-1]$ + $[d,r]$）；设

$$
L_1 = \sum_{i=l}^{d-1} a_i,\quad L_2 = \sum_{i=d}^{r} a_i,
$$

则本次切割的不平衡度

$$
\Delta = |L_1 - L_2|,
$$

本次切割代价

$$
Cost = \min(L_1,L_2)\;\times\;\bigl\lceil\log_2(L_1+L_2)\bigr\rceil.
$$

若要使 $[l,r]$ 区间的总切割最后一次不平衡度为 $\Delta$，则左右子区间的**各自**最后一次不平衡度都不能超过 $\Delta$，且两边都要有效可切。

* 在 `dp[l][d-1]` 中二分查找最大的下标 $x$ 使得 $\Delta_x\le\Delta$，取其最小累积代价为 $C_{\text{left}}$；
* 在 `dp[d][r]` 中同理查得 $C_{\text{right}}$。
  则合并得到一个候选解 $(\Delta,\;C_{\text{left}}+C_{\text{right}}+Cost)$，插入 `dp[l][r]`。


**转移优化**

* **枚举复杂度**：三层区间 $[l,r]$ 枚举切点 $d$ 共 $O(n^3)$，每次合并左右需二分查找各 $O(\log n)$，总体 $O(n^3\log n)$。
* **前缀最小值**：在每次 `dp[l][r]` 聚合完所有 $(\Delta,C)$ 对后，先按 $\Delta$ 升序排序，然后将 $C$ 做一次前缀最小化：

  $$
    C_i \leftarrow \min_{j\le i} C_j.
  $$

  这样上层二分查询只需取到某个 $\Delta$ 的最小代价。


**初始化与答案输出**

* 对每个测试用例，先读入 $n$、数组 $a$，并预处理前缀和 $S[i]=\sum_{k=1}^i a_k$。
* 枚举所有区间长度，依次填 `dp[l][r]`。
* 最后，对“**首次切割在第 $i$ 和 $i+1$ 根之间**”对应的区间 $[1,n]$，实际上就是在顶层枚举切点时，当 $d=i+1$ 时产生的候选值，直接输出其最小值；若没有任何可行合并，输出“$-1$”或“Impossible”。


**复杂度与可行性**

* 时间复杂度：$O(n^3\log n)$。当 $\sum n\le 420$ 时，约 $420^3\log 420\approx 3\times10^8$ 次基本操作，配合常数优化（剪枝、紧凑存储）可在 1–2 秒内通过。
* 空间复杂度：维护 $O(n^2)$ 个区间状态，每个区间存储至多 $O(n)$ 个 $(\Delta,C)$ 对，总体 $O(n^3)$。在 $n\le420$ 下可接受
* 

### 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;


vector<PII> dp[450][450];
int ck(vector<PII> &a,ll x){
    int L=0,R=a.size()-1;
    int idx=-1;
    while(L<=R){
        int mid=L+R>>1;
        if(a[mid].first<=x){
            idx=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    return idx;
}
ll f(ll x){
    int ans;
    for(ll i=0;i<=40;i++){
        if((1ll<<i)>=x){
            ans=i;
            break;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)dp[i][j].clear();
    }
    ll s[n+10],a[n+10]; s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int len=1;len<=n;len++){
        for(int L=1;L+len-1<=n;L++){
            int R=L+len-1;
            if(L==R){
                dp[L][R].push_back({0ll,0ll});
            }
            for(int d=L+1;d<=R;d++){
                ll L1=s[d-1]-s[L-1];
                ll L2=s[R]-s[d-1];
                ll p=abs(L1-L2);
                ll res=min(L1,L2)*f(L1+L2);
                int lx=ck(dp[L][d-1],p);
                int rx=ck(dp[d][R],p);
                if(lx!=-1&&rx!=-1){
                    res=res+dp[L][d-1][lx].second;
                    res=res+dp[d][R][rx].second;
                    dp[L][R].push_back({p,res});
                }
                else{
                    res=-1;
                }
                if(L==1&&R==n){
                    cout<<res<<" ";
                }
            }
            sort(dp[L][R].begin(),dp[L][R].end());
            for(int i=0;i<dp[L][R].size();i++){
                if(i-1>=0)dp[L][R][i].second=min(dp[L][R][i].second,dp[L][R][i-1].second);
            }
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```


## [Educational Codeforces Round 181 (Rated for Div. 2) D. Segments Covering](https://codeforces.com/problemset/problem/2125/D)

### 题目描述

给定长度为 $ m $ 的格子带（格子编号 $ 1 \ldots m $），有 $ n $ 条线段，第 $ i $ 条线段覆盖区间 $[l_i, r_i]$，并且**以独立概率** $ \frac{p_i}{q_i} $ “存在”（否则不出现）。求每个格子**恰好**被**一条**线段覆盖的概率（对全带最后是同一个值，因为所有格子独立同分布），并对 $ 998244353 $ 取模输出。


### 思路
我们其实要求的是：在整个带上，某个固定格子（比如第 $ m $ 格）恰好被一条线段覆盖的概率。由于所有格子同分布，这个答案就是题目要求的值。

记事件 $ E $ 为“第 $ m $ 格被恰好一条线段覆盖”。那么

\[
\Pr[E] = \sum_{i=1}^n \Pr[\text{第 } m \text{ 格被第 } i \text{ 条线段覆盖且不被其它任何线段覆盖}]。
\]

对于第 $ i $ 条线段，若 $ r_i \neq m $，它根本不会覆盖第 $ m $ 格，直接贡献 0。只需考虑所有满足 $ r_i = m $ 的线段。

再来看一个满足 $ r_i = m $ 的线段 $ i $：

- 它“出现” 的概率是 $ \frac{p_i}{q_i} $；
- 同时，所有**覆盖区间含 $ m $ 但不是第 $ i $ 条**线段，或者所有不覆盖 $ m $ 的线段，都**不出现**。
  - 对于一条覆盖 $ m $ 的线段 $ j \neq i $，它不出现的概率是 $ 1 - \frac{p_j}{q_j} = \frac{q_j - p_j}{q_j} $；
  - 对于一条不覆盖 $ m $ 的线段（即 $ r_j < m $ 或 $ l_j > m $），无论出现与否，都不会影响第 $ m $ 格是否恰被一条线段覆盖，于答案无关。

但是直接把所有段分为“覆盖 $ m $”和“不覆盖 $ m $”来枚举，难以高效处理。我们可以用**动态规划 + 预处理**来加速：

**1. 预处理初始“不覆盖任何已结束段”概率**

对于所有段 $ i $，不论它是否最终涉及到第 $ m $ 格，我们先将它们“都假设不会对最终结果贡献”的部分——即每条线段“不出现”且不影响答案的概率——用一个全局乘积来表示：

\[
A = \prod_{i=1}^{n} \left(1 - \frac{p_i}{q_i}\right) = \prod_{i=1}^{n} \frac{q_i - p_i}{q_i} \quad (\bmod\,998244353)。
\]

**2. 引入权重**

对于第 $ i $ 条线段，如果我们「后来」要让它出现，且「恰好」成为影响格子 $ m $ 的**唯一**线段，就要把上面已经乘入 $ A $ 里“它不出现”的那一份给“退回来”。退回因子等于

\[
\frac{\Pr[\text{它出现}]}{\Pr[\text{它不出现}]} = \frac{(p_i/q_i)}{((q_i - p_i)/q_i)} = \frac{p_i}{q_i - p_i} \quad (\bmod\,998244353)。
\]

我们把这个因子记作

\[
w_i = p_i \times (q_i - p_i)^{-1} \bmod 998244353。
\]

**3. 按右端点排序做前缀 DP**

- 令所有线段按 $ r_i $ 从小到大排序。
- 令数组 $ \mathtt{dp}[j] $ 表示“考虑完所有 $ r_i \le j $ 的线段后，恢复（退回）权重之后，恰好由一条线段覆盖**到**位置 $ j $ 的累积因子”。
- 初始化 $ \mathtt{dp}[0] = 1 $（相当于在最左边的“空位置”尚未开始时，没有线段覆盖也不需要退权）；其他 $ \mathtt{dp}[j] = 0 $。
- 遍历每条线段 $ (l_i, r_i, w_i) $（已按 $ r_i $ 排序），做

\[
\mathtt{dp}[r_i] \mathrel{+}= \mathtt{dp}[l_i - 1] \times w_i \quad (\bmod\,998244353)。
\]

这样，只有当某条线段以它的右端点正好“落在” $ j $ 上，且之前到 $ l_i - 1 $ 位置已经“没被其它线段覆盖”时，这条线段就“成为唯一覆盖到 $ r_i $”的那条。

**4. 答案组合**

最终答案就是

\[
\Pr[E] = A \times \mathtt{dp}[m] \bmod 998244353。
\]


### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=3e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;


ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inv(ll x){
    return qmi(x,mod-2);
}
void solve(){
    int n,m;
    cin>>n>>m;
    ll f[n+1];
    ll dp[m+1];
    for(int i=0;i<=m;i++)dp[i]=0;
    dp[0]=1;
    vector<array<ll,3>> d;
    for(int i=1;i<=n;i++){
        ll l,r,p,q;
        cin>>l>>r>>p>>q;
        d.push_back({r,l,i});
        f[i]=(p*inv(q-p))%mod;
        dp[0]=(dp[0]*((q-p)%mod*inv(q)%mod)%mod)%mod;
    }
    sort(d.begin(),d.end());
    for(int i=0;i<n;i++){
        auto [R,L,id]=d[i];
        dp[R]=(dp[R]+(dp[L-1]*f[id])%mod)%mod;
    }
    cout<<dp[m]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```





## [Codeforces Round 1039 (Div. 2) E1. Submedians (Easy Version)](https://codeforces.com/contest/2128/problem/E1)

### 题目描述

我们需要在长度至少为 $ k $ 的子数组中，找到能作为“中位数”出现的最大值 $ v_{\max} $。注意“中位数”的定义为：在长度为 $ m $ 的数组里，若一个值 $ v $ 满足以下条件，则称 $ v $ 是一个中位数：

- $ v $ 大于等于该数组中至少 $ \lceil m/2 \rceil $ 个元素；
- $ v $ 小于等于该数组中至少 $ \lceil m/2 \rceil $ 个元素。



### 思路
对于给定的候选值 $ x $，我们只需要判定是否存在长度 $ \ge k $ 的子数组，使得 $ x $ 可以成为该子数组的中位数。若能，则说明 $ v_{\max} \ge x $；否则 $ v_{\max} < x $。这样，我们可以在 $[1, n]$ 范围内对 $ v_{\max} $ 进行二分搜索，每次用 $ O(n) $ 的线性检查来判断。


**判定函数 $ \text{ck}(x) $**

我们需要判断是否存在子数组 $[l, r]$，满足 $ r - l + 1 \ge k $ 且 $ x $ 是该子数组的中位数。关键观察如下：

- 令数组 $ a_i $ 中每个位置映射为：
  \[
  b_i = \begin{cases}
  +1, & \text{若 } a_i \ge x, \\
  -1, & \text{若 } a_i < x.
  \end{cases}
  \]

- 若子数组 $[l, r]$ 中“大于等于 $ x $”的个数 $ \ge \lceil (r - l + 1)/2 \rceil $，当且仅当：
  \[
  \sum_{i=l}^{r} b_i \ge 0.
  \]

- 同理，若子数组长度为 $ m = r - l + 1 $，则 $ \lceil m/2 \rceil $ 既是“大于等于”的个数要求，也是“小于等于”的个数要求（因为如果“大于等于”的个数 $ \ge \lceil m/2 \rceil $，那么“小于”的个数等价于“非大于等于”的个数 $ \le \lfloor m/2 \rfloor $，满足中位数的另一个条件）。

因此，问题可以化简为：在前缀和数组
\[
S_i = \sum_{j=1}^i b_j
\]
中，是否存在 $(l, r)$ 使得 $ r - l + 1 \ge k $ 且 $ S_r - S_{l-1} \ge 0 $。

要在线性时间内判断，只需维护一个长度滑动窗口前的最小前缀和：

- 预先计算 $ S_0 = 0 $，以及 $ S_i $。
- 令 $ M_i = \min_{0 \le j \le i} S_j $。
- 当遍历到 $ i $，若 $ i \ge k $，则可考虑子数组结束于 $ i $ 且长度至少 $ k $ 的情况：此时最早可选的左边界前缀是 $ j = i - k $，我们用
  \[
  \text{minPref} = \min_{0 \le j \le i - k} S_j
  \]
  若 $ S_i - \text{minPref} \ge 0 $，则存在合法子数组，直接返回这一对 $(l, r)$。

这种做法只需一次从左到右的扫描，复杂度为 $ O(n) $。


**二分搜索整体流程**

1. **初始化**：$ L = 1 $，$ R = n $，$ \text{ans} = 0 $。
2. 循环直到 $ L > R $：
   - 取 $ \text{mid} = \lfloor (L + R) / 2 \rfloor $；
   - 调用 $ \text{ck}(\text{mid}) $ 检查可行性：
     - 若可行，则更新 $ \text{ans} = \text{mid} $ 并记录对应的子数组区间 $(\text{la}, \text{ra})$，同时令 $ L = \text{mid} + 1 $；
     - 否则令 $ R = \text{mid} - 1 $。
3. 最终输出 $ \text{ans}, \text{la}, \text{ra} $。

由于每次判定为 $ O(n) $，二分次数为 $ O(\log n) $，总复杂度为 $ O(n \log n) $，对于 $ n \le 3 \times 10^5 $ 且所有测试合计 $ \sum n \le 3 \times 10^5 $ 完全可行。

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=3e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;

int a[M];
int n,k;
array<int,3> ck(int x){
    vector<int> sum(n+1,0),per(n+1,0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+((a[i]>=x)?1:-1);
    }
    int Mi=0,L=-1;
    for(int i=1;i<=n;i++){
        if(i>=k){
            if(sum[i-k]<=Mi){
                Mi=sum[i-k];
                L=i-k+1;
            }
        }
        if(sum[i]>=Mi&&L!=-1){
            return {1,L,i};
        }
    }
    return {0,0,0};
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int L=1,R=n;
    int ans=0,la,ra;
    while(L<=R){
        int mid=L+R>>1;
        auto [ok,lx,rx]=ck(mid);
        if(ok){
            ans=mid;
            la=lx,ra=rx;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    cout<<ans<<" "<<la<<" "<<ra<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ZKX.in","r",stdin);
    freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
``` 

## [Codeforces Round 1040 (Div. 2) E3. Interactive RBS (Hard Version)](https://codeforces.com/contest/2130/problem/E3)


### 题目描述

* 隐藏了一个长度为 $n$（$2 \le n \le 1000$）的括号序列 $s$，仅包含字符 `'('` 和 `')'`，并且保证至少各有一个。
* 你可以进行最多 100 次查询。每次查询格式：

  ```
  ? k i_1 i_2 … i_k
  ```

  其中 $1 \le k \le 1000$，索引 $i_j$ 可重，可跨越全串。系统返回

  $$
    f(s_{i_1}s_{i_2}\dots s_{i_k})
  $$

  —该子串中**连续合法括号子串**（如 `"()"`, `"(())"`, `"()()"` 等）的总数。
* 最终输出完整括号序列：

  ```
  ! s_1 s_2 … s_n
  ```

### 二、核心思路

1. **定位一个 `(` 和一个 `)`**

   * 先对全串做一次查询，若返回 0，说明没有任何合法子串，必是全部 `)(` ⇒ 直接定位到两端。
   * 否则使用二分：在 $[1,n]$ 上维护区间 $[L,R]$，每次查询区间 $[L,mid]$ 的子串是否合法子串数是否 >0。根据结果向左或向右缩区间，最终找到一对相邻的异号位置 $z$ (')') 和 $y$ ('(')。

2. **构造“批量判定”方案**

   * 将剩余位置按每组 12 个分块处理。预定义重复次数数组

     $$
       p = \{1,2,3,5,7,10,15,21,30,43,61,87\}.
     $$
   * 对组内第 $j$ 个位置（相对组首）构造查询：

     ```
     [j, y, j, y, …, j, y]（共 p[j] 次 j 和 p[j] 次 y，再额外一个 y）
     ```
    $\underbrace{s_{1})s_{1})\dots s_{1})}_{p[1]} )\dots\underbrace{s_{12})s_{12})\dots s_{12})}_{p[12]} )$
     令构造总长度约 570+12，不超限。系统返回的合法子串数中，每个位置 $j$ 与固定位置 $y$ 的“成对贡献”$\tfrac{p[j](p[j]+1)}2$ 是唯一的，可从总和中逆推出该位置是 `(` 还是 `)`。

3. **处理尾部不足 12 个**

   * 若剩下不足 12 位，取用前缀和数组 $\mathrm{sum}[i]=\sum_{t=0}^{i} p[t]$ 计算合适的查询长度，同样逆推判断。


* **为什么能判定单点？**
  对一个位置 $j$ 及已知的某对 $y$，重复插入形成多次 `()` 配对，若 $s_j='('$，则每个 `j,y` 都能与后续的 `y,j` 构成合法子串；若是 `')'`，贡献极小。由于 $\tfrac{p(p+1)}2$ 在这些不同的 $p$ 中彼此不相等，可从整体返回值中“撕下”每个位置的贡献，判断括号类型。

* **为何选 12 个一组？**

  $$
    \sum_{i=0}^{11} p_i \approx 225, \quad 2\times225+12<1000
  $$

  在一次查询内可覆盖 12 个未知位，查询次数 $\lceil n/12\rceil\le100$。


* **查询次数**

  * 二分定位 $y,z$：$\lceil\log_2 n\rceil\le10$ 次。
  * 分组判定：$\lceil n/12\rceil\le84$ 次。
  * 总计 $\le 94<100$。

* **时间复杂度**

  * 每次输出查询需 $O(n)$／组大小 $O(12)$ 输出，整体 $O(n)$。
  * 交互部分为主，程序内计算均为常数／线性。



* **二分部分**：每次判断区间内是否含合法对，从而二分收缩。
* **批量构造**：对组内每个位置利用唯一的 $\tfrac{p(p+1)}2$ 来做“背包”式拆分。
* **逆推法**：从总合法子串数中依次减去最高权重的那个位置的贡献，剩余表示后续位置。

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=3e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;


int p[12] = { 1, 2, 3, 5, 7, 10, 15, 21, 30, 43, 61, 87 };
int sum[12];
void solve(){
    int n;
    cin>>n;
    cout<<"?"<<" "<<n<<" ";
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    int x;
    cin>>x;
    int z,y;
    if(!x)z=n,y=1;
    else{
        int L=1,R=n;
        while(L+1<R){
            int mid=L+R>>1;
            cout<<"?"<<" "<<mid-L+1<<" ";
            for(int i=L;i<=mid;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            int x;
            cin>>x;
            if(!x){
                L=mid;
            }
            else{
                R=mid;
            }
        }
        z=L,y=R;
    }
    
    vector<char> s(n+1);
    for(int i=1;i<=n;i+=12){
        if(i+11<=n){
            cout<<"?"<<" "<<570+12<<" ";
            for(int j=i;j<=i+11;j++){
                for(int k=1;k<=p[j-i];k++){
                    cout<<j<<" "<<y<<" ";
                }
                cout<<y<<" ";
            }
            cout<<endl;
            int x;
            cin>>x;
            for(int j=i+11;j>=i;j--){
                int w=(p[j-i]*(p[j-i]+1))/2;
                if(w<=x){
                    x-=w;
                    s[j]='(';
                }
                else{
                    s[j]=')';
                }
            }
        }
        else{
            cout<<"?"<<" "<<sum[n-i]*2+(n-i+1)<<" ";
            for(int j=i;j<=n;j++){
                for(int k=1;k<=p[j-i];k++){
                    cout<<j<<" "<<y<<" ";
                }
                cout<<y<<" ";
            }
            cout<<endl;
            int x;
            cin>>x;
            for(int j=n;j>=i;j--){
                int w=(p[j-i]*(p[j-i]+1))/2;
                if(w<=x){
                    x-=w;
                    s[j]='(';
                }
                else{
                    s[j]=')';
                }
            }
        }
    }
    cout<<"!"<<" ";
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    for(int i=0;i<12;i++){
        if(i==0)sum[i]=p[i];
        else{
            sum[i]=p[i]+sum[i-1];
        }
    }
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```


## [2025牛客暑期多校训练营2 G	Geometry Friend](https://ac.nowcoder.com/acm/contest/108299/G)

### 题目描述

给定一个逆时针给定的凸多边形 $A_0A_1\ldots A_{n-1}$ 和一个点 $P$。对于每组测试：

1. 如果点 $P$ 在多边形外部，输出 $2\pi$。
2. 否则，考虑所有与 $P$ 距离最远的多边形顶点集合，记作 $\{B_0,B_1,\dots,B_{m-1}\}$。对这些顶点，以它们关于 $P$ 的极角（按 $[0,2\pi)$ 范围）排序，找出相邻两角的最大差，再比较首尾“回环”差值，输出该最大差。

### 关键思路

1. **点在凸多边形内外判定**
   对于凸多边形，若顶点按逆时针给出，那么多边形的内部始终在每条有向边的「左侧」。

   * 边向量：$\vec{e}_i = A_{i+1} - A_i$
   * 点向量：$\vec{v}_i = P - A_i$
     若对任意 $i$，都有

   $$
     \text{cross}(\vec{e}_i,\,\vec{v}_i)\;\ge\;0
   $$

   则 $P$ 在（或 on）多边形内部；否则 $P$ 在外部。

2. **选取最远顶点**
   为避免浮点误差，用整型计算距离平方：

   $$
     d_i^2 = (A_i.x - P.x)^2 + (A_i.y - P.y)^2.
   $$

   扫一遍找最大值 $\max d_i^2$，再把所有满足 $d_i^2 = \max$ 的顶点收集到数组 $\{B_j\}$。

3. **最大空隙角**

   * 计算每个 $B_j$ 相对于 $P$ 的极角

     $$
       \theta_j = \operatorname{atan2l}(B_j.y - P.y,\; B_j.x - P.x),
     $$

     并将其规范到 $[0,2\pi)$：

     ```cpp
     if (θ < 0) θ += 2*PI;
     ```
   * 对这些角度排序，设排序后为 $\theta_0\le\theta_1\le\cdots\le\theta_{m-1}$。
   * 相邻差值 $\Delta_i = \theta_{i+1}-\theta_i$（$0\le i<m-1$）以及首尾回环差值

     $$
       \Delta_{\text{wrap}} = (\theta_0 + 2\pi) - \theta_{m-1}
     $$
   * 最大空隙 $\max\{\max_i\Delta_i,\;\Delta_{\text{wrap}}\}$ 即为答案。

4. **时间复杂度**

   * 判点：$O(n)$
   * 扫一遍找最远点：$O(n)$
   * 对最远点做极角、排序：$O(m\log m)$，其中 $m\le n$
   * 总体：$O(n + m\log m)$，完全可以应对 $n$ 到 $10^5$ 量级。

---

* **判点**：利用「每条有向边的左侧即内部」的凸多边形性质。
* **距离比较**：直接用整型距离平方避免 `sqrt` 和精度误差。
* **角度处理**：`atan2l` 返回 $[-π,π]$，转到 $[0,2π)$ 方便排序和差值计算。
* **最终答案**：非内部点直接 $2\pi$，否则最大极角空隙。

### 思路

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=6e6+10;
const int M=5e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;


struct point{
    ld x;
    ld y;
    point operator-(const point &a){
        return {x-a.x,y-a.y};
    }
};
ld crs(const point &a,const point &b){
    return a.x*b.y-b.x*a.y;
}
ld dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
ld L(const point &a){
    return sqrtl(dot(a,a));    
}

void solve(){
    cout<<fixed<<setprecision(15);
    int n;
    point p;
    cin>>n>>p.x>>p.y;
    vector<point> a(n),b;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int ok=1;
    for(int i=0;i<n;i++){
        if(crs(a[(i+1)%n]-a[i],p-a[i])<0)ok=0;
    }
    if(!ok){
        cout<<2*PI<<'\n';
    }
    else{
        ld Mx=0;
        for(int i=0;i<n;i++){
            Mx=max(dot(a[i]-p,a[i]-p),Mx);
        }
        for(int i=0;i<n;i++){
            if(dot(a[i]-p,a[i]-p)==Mx){
                b.push_back(a[i]);
            }
        }
        int m=b.size();
        b.push_back(b[0]);
        ld ans=0;
        for(int i=0;i<m;i++){
            ld th2=atan2l(b[i+1].y-p.y,b[i+1].x-p.x)<0?atan2l(b[i+1].y-p.y,b[i+1].x-p.x)+2*PI:atan2l(b[i+1].y-p.y,b[i+1].x-p.x);
            ld th1=atan2l(b[i].y-p.y,b[i].x-p.x)<0?atan2l(b[i].y-p.y,b[i].x-p.x)+2*PI:atan2l(b[i].y-p.y,b[i].x-p.x);
            if(th2-th1<=0)ans=max(th2-th1+2*PI,ans);
            else ans=max(th2-th1,ans);
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```



## [2025牛客暑期多校训练营2 H.Highway Upgrade](https://ac.nowcoder.com/acm/contest/108299/H)

### 题目描述

NowLand 有 $n$ 个城市和 $m$ 条单向高速公路，第 $i$ 条从 $u_i$ 指向 $v_i$，原行驶时间 $t_i$。每升级一次该高速公路，可在行驶时间上额外减少 $w_i$ 分钟；可以对同一条道路升级多次。现在想从城市 1 → 城市 $n$，若总共做 $k$ 次升级，求最短总通行时间。给 $q$ 个不同的 $k$ 值，各自输出答案。

* $4 \le n \le 10^5,\;1\le m\le3\times10^5$
* $2\le t_i\le10^{12},\;1\le w_i\le\min(t_i-1,10^9)$
* 保证图中 1 → $n$ 可达
* $1\le q\le3\times10^5$，每个 $k\le10^9$，且保证所有道路升级后时间均正

多组测试，总和 $\sum n\le2\times10^5,\;\sum m,\,\sum q\le6\times10^5$。

---

### 思路

1. **预处理最短路**

   * 在原图上，从 1 跑 Dijkstra 得到每个 $u$ 到达 1 的最短时间 $\mathrm{dis0}[u]$。
   * 在反向图上，从 $n$ 跑 Dijkstra 得到每个 $v$ 到达 $n$ 的最短时间 $\mathrm{dis1}[v]$。
   * 这样对于任意一条边 $(u,v,t,w)$，若 $u$ 和 $v$ 都可达，就可在这条边上“接”出一条完整路 1→$u$→$v$→$n$，

     $$
       \ell = \mathrm{dis0}[u] + t + \mathrm{dis1}[v].
     $$

     升级 $k$ 次后总耗时 $\ell - k\,w$。

2. **斜率优化 + 下凸壳**

   * 将每条边映射成一条直线

     $$
       f(k)=\ell - k\,w,
     $$

     收集所有 $(\ell,w)$ 对，按 $\ell$ 升序排序。
   * 维护一个「下凸壳」 $\mathcal{C}$，只保留斜率 $w$ 严格递增的那几条极值直线，并用三点交点比较弹出多余中间线：

     * 若已有尾两条 $A=(b_2,k_2)$, $B=(b_1,k_1)$，新来 $C=(b_3,k_3)$，且

       $$
         \frac{b_1-b_2}{k_1-k_2}
         \;\ge\;
         \frac{b_3-b_1}{k_3-k_1},
       $$

       则 $B$ 永远不会是最优，`pop_back()`。
   * 最终得到一组按斜率单调的直线集合 $Z$。

3. **每次查询二分查谷底**

   * 对固定 $k$，在 $Z$ 上找使 $f(k)$ 最小的索引。由于 斜率单调 $\Rightarrow$ $f_i(k)$ 关于索引 $i$ 先单调降再升，可在 $[0,|Z|-1]$ 上二分：

     ```cpp
     int L=0, R=Z.size()-2;
     while (L<=R) {
       int m=(L+R)>>1;
       if (f(m+1)<f(m)) L=m+1;
       else R=m-1;
     }
     // L 即最小时的那条线下标
     ```

---

**复杂度**

* **Dijkstra** 两次： $O((n+m)\log n)$
* **排序** 所有边： $O(m\log m)$
* **建凸壳**：每条线最多入栈／出栈一次，共 $O(m)$
* **每次查询** 二分： $O(\log m)$，总 $O(q\log m)$

总体：

$$
O\bigl((n+m)\log n + m\log m + q\log m\bigr),
$$

可应对 $n,m,q$ 高达 $10^5$\~$10^6$ 级。


### 代码

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=6e6+10;
const int M=5e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;

struct vc{
    int to;
    ll t;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<vc>> e1(n+1),e2(n+1);
    vector<array<ll,4>> b;
    for(int i=1;i<=m;i++){
        int u,v;
        ll t,w;
        cin>>u>>v>>t>>w;
        b.push_back({u,v,t,w});
        e1[u].push_back({v,t});
        e2[v].push_back({u,t});
    }
    vector<ll> d1(n+1,1e18),dn(n+1,1e18);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)v[i]=0;
    d1[1]=0;
    q.push({0,1});
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [y,d]:e1[t]){
            if(d1[y]>d+d1[t]){
                d1[y]=d+d1[t];
                q.push({d1[y],y});
            }
        }
    }
    for(int i=1;i<=n;i++)v[i]=0;
    dn[n]=0;
    q.push({0,n});
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        if(v[t])continue;
        v[t]=1;
        for(auto [y,d]:e2[t]){
            if(dn[y]>d+dn[t]){
                dn[y]=d+dn[t];
                q.push({dn[y],y});
            }
        }
    }
    vector<pair<ll,ll>> s,Z;
    for(auto [u,v,t,w]:b){
        if(d1[u]!=1e18&&dn[v]!=1e18){
            s.push_back({d1[u]+dn[v]+t,w});
        }
    }
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(!Z.empty()){
            if(s[i].second>Z.back().second){
                while(Z.size()>1){
                    auto [b2,k2] = Z[Z.size()-2]; // A
                    auto [b1,k1] = Z[Z.size()-1]; // B
                    auto [bs,ks] = s[i];
                    __int128 lhs = __int128(b1 - b2) * (ks - k1);
                    __int128 rhs = __int128(bs - b1) * (k1 - k2);
                    if (lhs >= rhs) {
                        Z.pop_back();  // B 永远不会用到，丢了
                    } else {
                        break;
                    }
                }
                Z.push_back(s[i]);
            }
        }
        else {
            Z.push_back(s[i]);
        }
    }
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;i++){
        ll k;
        cin>>k;
        int L=0,R=Z.size()-2;
        while(L<=R){
            int mid=(L+R)>>1;
            ll f1=Z[mid].first-k*Z[mid].second;
            ll f2=Z[mid+1].first-k*Z[mid+1].second;
            if(f1>f2){
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        cout<<Z[L].first-k*Z[L].second<<'\n';
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```


## [2025牛客暑期多校训练营2 D.Donkey Thinks...](https://ac.nowcoder.com/acm/contest/108299/D)

### 题目描述

* 有 $n$ 包薯片，每包第 $i$ 袋有

  * “快乐值” $h_i$
  * “体积” $s_i$
  * “精致度” $d_i$
* 背包容量为 $V$。选中若干袋（可不选）使得：

  $$
    \text{价值} \;=\;\sum h_i \;-\;\Bigl(\sum d_i\Bigr)\times\Bigl(V - \sum s_i\Bigr)
  $$

  最大化。若不选任何袋子，价值为 0。

---
### 思路
核心思路：枚举“剩余空间”＋降维背包

1. **剩余空间 $U$ 枚举**
   设已用容量 $S=\sum s_i$，剩余 $U=V-S$。价值可写成

   $$
     \sum h_i \;-\; U\sum d_i
     \;=\;\sum\bigl(h_i - d_i\times U\bigr).
   $$

   因此，如果**固定**某个 $U$，每包薯片 $i$ 都有一个“净收益”

   $$
     w_i(U)=h_i - d_i\times U.
   $$

   问题退化为：在容量恰好为 $S=V-U$ 的普通 0/1 背包中，选物品最大化 $\sum w_i(U)$。

2. **枚举 $U=0,1,\dots,V$**
   对每个 $U$ 重置一个 长度 $V-U+1$ 的 `dp[]`，做一次恰好装满容量 $S=V-U$ 的背包，求得最优值后更新答案。

---

**击破瓶颈：按体积分组＋取前 $k$ 大**

### 如果直接按物品做 DP

* 每轮枚举 $U$ 需遍历所有 $n$ 个物品，复杂度 $O(n\cdot V)$。
* 总复杂度 $O(nV^2)$，在 $n\le10^5,\ V\le500$ 下会超时。

### 优化思路

1. **体积分组**
   由于每个 $s_i\in[1,V]$，我们预先把物品按 $s_i$ 分到 `group[s_i]`。
2. **同体积只需取前 $\lfloor S/s\rfloor$ 大**
   在恰好装满容量 $S$ 时，体积为 $j$ 的物品最多能放 $\lfloor S/j\rfloor$ 件。
   因此，对每个体积 $j$ 的那一组，只要在它们的净收益数组中**挑前** $\lfloor S/j\rfloor$ 大的就足够，其余再小的，不可能出现在最优解里。

---

### `nth_element` 的妙用

假设某组有原始净收益数组 `psum[0..sz-1]`，要取其中最大的 `K = min(sz, S/j)` 个：

```cpp
// K = min(sz, S/j)
nth_element(psum.begin(),
            psum.begin() + (K-1),
            psum.begin() + sz,
            [](ll x, ll y){ return x > y; });

// 这之后，[0..K-1] 中是全局最大的 K 个元素（顺序未定），
// 只需遍历 i=0..K-1 即可。
for(int i = 0; i < K; i++){
    ll w = psum[i];
    // 用 w 做一次体积为 j 的 0/1 背包转移
    …
}
```

* `nth_element` 平均时间 $O(sz)$，比完全排序 $O(sz\log sz)$ 快一个对数因子。
* 对每个体积分组都只做一次部分划分，就能“去掉”大部分不可能用到的物品。

---

**时间复杂度分析**

* 外层枚举 $U$： $V+1$ 次。
* **每次枚举**：

  1. **重置 `dp[]`**： $O(V)$。
  2. **遍历体积分组** $j=1\dots S$：

     * 计算净收益：$\sum_j O(|\text{group}_j|)\;=\;O(n)$。
     * 部分排序 `nth_element`：$\sum_j O(|\text{group}_j|)\;=\;O(n)$。
     * 背包转移：$\sum_{j=1}^S O\bigl((S/j)\times S\bigr)\;=\;O(S\log S)\approx O(V^2)$。
* 整体约为

  $$
    \sum_{U=0}^{V}\Bigl(O(n) + O(V^2)\Bigr)
    \;=\;O\bigl(V\cdot n + V^3\bigr).
  $$

  由于题目给定 $\sum n\le10^5$、$\sum V^2\le2.5\times10^5$，该算法能在限时内通过。

---

* **枚举剩余空间** 将“残余体积×总精致度”这项交叉代价线性化。
* **按体积分组＋取前 $K$ 大** 巧用 `nth_element`，在常数上大幅优化。
* 复杂度 $O(V\cdot n + V^3)$ ，在 $V\le500$ 下可行。




```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=6e6+10;
const int M=5e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;


void solve(){
    int n,v;
    cin>>n>>v;
    ll h[n+1],s[n+1],d[n+1];
    vector<int> f[v+10];
    for(int i=1;i<=n;i++){
        cin>>h[i]>>s[i]>>d[i];
        if(s[i]<=v)f[s[i]].push_back(i);
    }
    vector<ll> dp(v+10,-1e18);
    ll ans=0;
    for(ll u=0;u<=v;u++){
        int siz=v-u;
        for(int j=1;j<=siz;j++)dp[j]=-1e18;
        dp[0]=0;
        vector<ll> q(n);
        for(int j=1;j<=siz;j++){
            if(f[j].empty())continue;
            for(int i=0;i<f[j].size();i++){
                q[i]=h[f[j][i]]-d[f[j][i]]*u;
            }
            int V=min(siz/j,(int)f[j].size());
            nth_element(q.begin(),q.begin()+V-1,q.begin()+f[j].size(),[&](ll x,ll y){
                return x>y;
            });
            for(int i=0;i<V;i++){
                for(int k=siz;k>=j;k--){
                    if(dp[k-j]!=-1e18){
                        dp[k]=max(dp[k-j]+q[i],dp[k]);
                    }
                }
            }
        }
        if(dp[siz]!=1e18)ans=max(ans,dp[siz]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
//！！！用优先队列时间是上面一个代码的两倍
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=6e6+10;
const int M=5e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;


void solve(){
    int n,v;
    cin>>n>>v;
    ll h[n+1],s[n+1],d[n+1];
    vector<int> f[v+10];
    for(int i=1;i<=n;i++){
        cin>>h[i]>>s[i]>>d[i];
        if(s[i]<=v)f[s[i]].push_back(i);
    }
    vector<ll> dp(v+10,-1e18);
    ll ans=0;
    for(ll u=0;u<=v;u++){
        int siz=v-u;
        for(int j=1;j<=siz;j++)dp[j]=-1e18;
        dp[0]=0;
        for(int j=1;j<=siz;j++){
            if(f[j].empty())continue;
            priority_queue<ll,vector<ll>> q;
            for(int i=0;i<f[j].size();i++){
                q.push(h[f[j][i]]-d[f[j][i]]*u);
            }
            int cnt=0;
            while(!q.empty()&&cnt<siz/j){
                ll w=q.top();
                q.pop();
                for(int k=siz;k>=j;k--){
                    if(dp[k-j]!=-1e18)dp[k]=max(dp[k-j]+w,dp[k]);
                }
                cnt++;
            }
        }
        if(dp[siz]!=1e18)ans=max(ans,dp[siz]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```


## [Educational Codeforces Round 180 (Rated for Div. 2) E - Tree Colorings](https://codeforces.com/contest/2112/problem/E)

### 题目描述

给定一棵有根树，每个节点可以染成三种颜色：蓝（B）、绿（G）、黄（Y）。称一种染色方案 “美丽”，当且仅当：

1. 根节点必须为绿色；
2. 在整棵树中，**蓝+绿** 节点所构成的连通子图中，任何两个节点之间的路径上不出现黄色节点；
3. 在整棵树中，**黄+绿** 节点所构成的连通子图中，任何两个节点之间的路径上不出现蓝色节点。

给定 $m$（最多 $5\times10^5$），问存在恰好有 $m$ 种美丽染色方案的有根树，最少需要多少个节点？若不存在，输出 $-1$。

---

### 二、关键观察

1. **子树独立性**
   对于某个节点 $v$，若它被染成绿色，则它每个子树的染色方案相互独立；若它被染成蓝或黄，则它整棵子树必须“同色”（均蓝或均黄），否则会违反上面连通性约束。

2. **子问题定义**
   令 $cnt_v$ 表示：以 $v$ 为根，且 $v$ 被染成绿色时，该子树中美丽染色方案的总数。

   * 如果子节点 $u$ 也染成绿色，则该子树有 $cnt_u$ 种方案；
   * 如果染成蓝（或黄），则该子树只能全部同色，方案数为 $1$。
     因此，对每个子节点 $u$ 可选的方案数为

   $$
     cnt_u \;+\; 2 \quad(\text{“绿” 或 “蓝” 或 “黄”})
   $$

   子树独立相乘：

   $$
     cnt_v \;=\;\prod_{u\in \text{children}(v)} \bigl(cnt_u + 2\bigr).
   $$

3. **最小化节点数的“逆”问题**
   设 $f(m)$ 为：存在恰好 $m$ 种方案的有根树，所需的最少节点数。

   * 若根节点只有它自己，则 $m=1$，显然 $f(1)=1$。
   * 若根有若干子树，分别贡献方案数 $x_1, x_2, \dots, x_k$，则总方案数为

     $$
       m = \prod_{i=1}^k (x_i + 2).
     $$

     并且节点总数为 $\sum_i f(x_i)$（因为每个子树再加上根节点一）再加上根节点 1：

     $$
       f(m) = 1 + \min_{\substack{k\ge1,\;x_1+2,\dots,x_k+2\ge3\\ \prod (x_i+2)=m}} \sum_{i=1}^k f(x_i).
     $$

   令我们更方便地定义：把$+2$“提前”到子问题上，

   $$
     \prod (x_i+2)=m
     \quad\Longleftrightarrow\quad
     \{x_i+2\}\text{ 是 }m\text{ 的一组因子分解。}
   $$

   考虑把最后一个子树的方案数设为 $d$（即 $x_k+2=d$），则剩下 $\prod_{i<k}(x_i+2)=m/d$，对应的节点开销是

   $$
     f\bigl(m/d\bigr)\quad+\quad f(d-2),
   $$

   再加上根节点 1，可以写成

   $$
     f(m) = 1 + \min_{d\mid m,\;d\ge3}\Bigl(f(m/d) + f(d-2)\Bigr).
   $$

   注意 $d$ 最小为 3，对应子树只有一个节点（方案数 $d-2=1$）。

---


```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=5e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;
vector<int> dp(M,1e9);
void init(){
    dp[1]=1;
    for(int x=3;x<M;x++){
        for(int m=x;m<M;m+=x){
            dp[m]=min(dp[m/x]+dp[x-2],dp[m]);
        }
    }
}
void solve(){
    int m;
    cin>>m;
    if(dp[m]==1e9)cout<<-1<<'\n';
    else {
        cout<<dp[m]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    init();
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Educational Codeforces Round 172 (Rated for Div. 2) D. Recommendations](https://codeforces.com/contest/2042/problem/D)

### 题目描述

给出 $n$ 个闭区间 $S_i=[l_i,r_i]$。对每个区间 $S_i$，考虑所有满足 $S_i\subseteq S_j$ 且 $j\ne i$ 的区间集合（称为它的“包区间”）。求这些包区间的交集长度减去 $|S_i|$。如果不存在包区间，输出 0。

区间端点均为整数，区间长度按整数计数（即 $|[l,r]| = r-l+1$）。

---

### 关键观察

若 $S_i\subseteq S_j$ 则必须满足 $l_j \le l_i$ 且 $r_j \ge r_i$。给定一组包区间，它们的交集是区间

$$
\Big[\max_{j\in J} l_j,\ \min_{j\in J} r_j\Big]
$$

因此我们只需要知道包区间中左端的最大值和右端的最小值即可。

为了把“包区间”转化为容易维护的子问题，做如下排序与约定。

---

### 排序与处理顺序（核心技巧）

将所有区间按 `(r 升序, l 降序)` 排序（即先按右端升序，右端相同按左端降序）。令排序后的数组为 `a[0..n-1]`。

理由：

* 若 $A\subseteq B$，则 $r_A \le r_B$（所以 $B$ 要么在 $A$ 的右侧，要么与之同右端）。
* 在相同 $r$ 的情况下，把更小左端（更宽的区间）放到后面（即 `l` 降序），可以使得在从右向左扫描时“已经加入”的集合恰好是当前区间右侧的候选包区间集合。

因此，从 `pos=n-1`（最右）向左遍历时，**Fenwick/树状数组中维护的就是当前位置右侧已处理过的区间** —— 这些就是可能的包区间（只需在它们中筛 `l_j <= l_i`）。

---

### 如何用数据结构维护 $\max l_j$ 和 $\min r_j$

我们只对那些位于当前区间右侧且满足 $l_j \le l_i$ 的区间感兴趣。对左端进行**离散化**（将不同的 $l$ 值映射到 $1..m$），然后：

* 用一个「FenwickMax」维护：在离散化位置 `pos(l_j)` 做点更新 `update(pos, l_j)`（合并操作取 `max`），那么 `query(pos(l_i))` 就返回所有 `l_j <= l_i` 且已加入的区间中 `max l_j`。
* 用一个「FenwickMin」维护：在离散化位置 `pos(l_j)` 做点更新 `update(pos, r_j)`（合并操作取 `min`），那么 `query(pos(l_i))` 就返回对应集合中 `min r_j`。

（注意：Fenwick 的实现把 `t[idx]` 存储为区块上的 `max`/`min` 值，点更新向上遍历，前缀查询向下遍历，从而实现点更新 + 前缀聚合）

---

### 重复区间（完全相等的处理）

若存在两个或以上完全相等的区间 $S$（即相同的 `l` 和 `r`），对于其中任意一个 $S_i$，另一个等值区间就是它的包区间，因此交集至少等于 $S_i$ 自身，答案必为 0。

实现上更稳妥的做法是**把相同 `(l,r)` 的区间作为一个块（block）一次性处理**：

* 若块大小 `L > 1`，则块内所有区间答案直接设为 0（不从 Fenwick 查询）。
* 不论是否 `L>1`，在处理完该块后把块内所有区间一次性加入 Fenwick（保证更左侧的区间能看到整个块）。

这是避免排序内部等值区间相对顺序带来错误的关键一步。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=5e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;
struct vc{
	int l;
    int r;
	int id;
    bool operator==(const vc a){
        return (a.l==l&&a.r==r);
    }
};
bool cmp(vc x,vc y){
	if(x.r!=y.r){
		return x.r<y.r;
	}
	if(x.l!=y.l){
		return x.l>y.l;
	}
    return x.id<y.id;
}
struct BIT{
	int n;
	vector<int> Mi,Mx;
	void init(int _){
		n=_;
		Mi.assign(n+1,inf);
        Mx.assign(n+1,-inf);
	}
    void addMi(int x,int k){
        for(int i=x;i<=n;i+=(i&-i)){
            Mi[i]=min(Mi[i],k);
        }
    }
    int qMi(int x){
        int res=inf;
        for(int i=x;i>=1;i-=(i&-i)){
            res=min(res,Mi[i]);
        }
        return res;
    }
    void addMx(int x,int k){
        for(int i=x;i<=n;i+=(i&-i)){
            Mx[i]=max(Mx[i],k);
        }
    }
    int qMx(int x){
        int res=-inf;
        for(int i=x;i>=1;i-=(i&-i)){
            res=max(res,Mx[i]);
        }
        return res;
    }
    
};
void solve(){  
    int n;
    cin>>n;
    vector<vc> a(n);
    vector<int> k,ans(n);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        k.push_back(a[i].l);
    }
    sort(a.begin(),a.end(),cmp);
    sort(k.begin(),k.end());
    k.erase(unique(k.begin(),k.end()),k.end());
    BIT f;
    f.init(k.size());
    int pos=n-1;
    while(pos>=0){
        int j=pos;
        while(j-1>=0&&a[j-1]==a[pos])j--;
        int L=pos-j+1;
        int lx=0,rx=k.size()-1,idx;
        while(lx<=rx){
            int mid=(lx+rx)>>1;
            if(k[mid]<=a[pos].l){
                idx=mid;
                lx=mid+1;
            }
            else{
                rx=mid-1;
            }
        }
        idx++;
        if(L==1){
            int mxl=f.qMx(idx);
            int mir=f.qMi(idx);
            if(mir==inf)ans[a[pos].id]=0;
            else{
                ans[a[pos].id]=(mir-mxl+1)-(a[pos].r-a[pos].l+1);
            }
        }
        else{
            for(int i=j;i<=pos;i++){
                ans[a[i].id]=0;
            }
        }
        f.addMi(idx,a[pos].r);
        f.addMx(idx,a[pos].l);
        pos=j-1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
} 
```




## [Educational Codeforces Round 166 (Rated for Div. 2) D. Invertible Bracket Sequences](https://codeforces.com/contest/1976/problem/D)

### 题目描述

令前缀和数组 $a[0\ldots n]$：

* $a[0]=0$；对 $i\ge1$，若 $s[i-1]='('$ 则 $a[i]=a[i-1]+1$，否则 $a[i]=a[i-1]-1$。

原串合法说明 $a[i]\ge0$ 对所有 $i$，且 $a[n]=0$。

考虑翻转一个非空子串 $s[L..R]$（下标以 **1** 开始）。翻转后前缀和 $a'$ 的变化：

* 若 $p < L$： $a'[p]=a[p]$（不变）。
* 若 $L \le p \le R$：因为段内每个字符符号取反，所以

  $$
  a'[p] = a[L-1] - (a[p]-a[L-1]) = 2a[L-1] - a[p].
  $$
* 若 $p > R$：整体段的净贡献变号，且由于必须最后仍为 0，必要条件是

  $$
  a[n] - 2(a[R]-a[L-1]) = 0 \iff a[R]=a[L-1].
  $$

结论一：翻转后仍合法的必要条件：$a[R]=a[L-1]$（即前缀和相等 —— 等价于翻转段中左右端高度相同）。

结论二（充分条件）：在满足 $a[R]=a[L-1]$ 的前提下，只需保证翻转段内部的新前缀和不小于 0：

* 对 $p\in[L..R]$，要求 $a'[p]=2a[L-1]-a[p]\ge0$，
  等价于 $\max_{p\in[L..R]} a[p] \le 2a[L-1]$。

因此问题等价于：

> 统计所有下标对 $(i,j)$（0 ≤ i < j ≤ n，注意这里 i 对应 $L-1$，j 对应 $R$）满足：
>
> 1. $a[i] = a[j]$；
> 2. $\max_{p=i+1}^{j} a[p] \le 2a[i]$。

并且子串长度 $j-i \ge 1$（题目已排除长度为 0 的翻转）。

---

### 思路

1. 计算前缀和数组 $a[0..n]$（长度为 n+1）。
2. 建一个哈希表/映射 `pos`：把每个相同的前缀值对应的位置索引列表 `pos[val]`（位置按增序）。

   * 这些位置即为可能的 i（作为 L-1）和 j（作为 R）。
3. 需要快速查询区间最大值 $\max_{p=l}^{r} a[p]$。用稀疏表（Sparse Table）预处理数组 `a`，支持 $O(1)$ 的区间最大查询。
4. 对每个位置 i（取 `i = pos[val][t]`，只枚举到 n-1，因为 j>i），在该值所在列表中二分查找最大的索引 `m>t`，使得 `max(i+1, pos[val][m]) ≤ 2 * a[i]`。找到的 m-t 个 j 都是合法的，累加到答案。

   * 每个 group 的每个元素做一次二分，复杂度合计 $O(n\log n)$。

这是与你给出的代码思路一致的标准实现，但我修正了若干下标/边界/稀疏表初始化的细节并加上注释。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;

struct ST {
    const int n, k;
    vector<int> in1, in2;
    vector<vector<int>> Max, Min;
    ST(int n) : n(n), in1(n + 1), in2(n + 1), k(__lg(n)) {
        Max.resize(k + 1, vector<int>(n + 1));
        Min.resize(k + 1, vector<int>(n + 1));
    }
    void init() {
        for (int i = 1; i <= n; i++) {
            Max[0][i] = in1[i];
            Min[0][i] = in2[i];
        }
        for (int i = 0, t = 1; i < k; i++, t <<= 1) {
            const int T = n - (t << 1) + 1;
            for (int j = 1; j <= T; j++) {
                Max[i + 1][j] = max(Max[i][j], Max[i][j + t]);
                Min[i + 1][j] = min(Min[i][j], Min[i][j + t]);
            }
        }
    }
    int getMax(int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        int k = __lg(r - l + 1);
        return max(Max[k][l], Max[k][r - (1 << k) + 1]);
    }
    int getMin(int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        int k = __lg(r - l + 1);
        return min(Min[k][l], Min[k][r - (1 << k) + 1]);
    }
};
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    s='0'+s;
    int a[n+10],k[n+10];
    a[0]=0;
    map<int,vector<int>> f;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+(s[i]=='('?1:-1);
        f[a[i]].push_back(i);
        k[i]=f[a[i]].size()-1;
    }
    ST r(n+1);
    for(int i=1;i<=n;i++){
        r.in1[i]=r.in2[i]=a[i];
    }
    r.init();
    ll ans=0;
    for(int i=1;i<n;i++){
        ll L=k[i],R=f[a[i]].size()-1;
        ll res=k[i];
        while(L<=R){
            ll mid=L+R>>1;
            if(r.getMax(i+1,f[a[i]][mid])<=2*a[i]){
                res=mid;
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        ans+=res-k[i];
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [#10003. 「一本通 1.1 例 4」加工生产调度](https://loj.ac/p/10003)

### 题目描述

某工厂收到了 $ n $ 个产品的订单，这 $ n $ 个产品分别在 $A$、$B$ 两个车间加工，并且必须先在 $A$ 车间加工才可以到 $B$ 车间加工。某个产品 $ i $ 在 $A$, $B$ 两车间加工的时间分别为 $ A_i, B_i $。怎样安排这 $ n $ 个产品的加工顺序，才能使总的加工时间最短。

这里所说的加工时间是指：从开始加工第一个产品到最后所有的产品都已在 $A$, $B$ 两车间加工完毕的时间。

### 思路

```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;
struct vc{
    int x,y,Mi,id;
};
bool cmp(vc a,vc b){
    return a.Mi<b.Mi;
}
void solve(){
    int n;
    cin>>n;
    vector<vc> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].x;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].y;
        a[i].Mi=min(a[i].x,a[i].y);
        a[i].id=i+1;
    }
    sort(a.begin(),a.end(),cmp);
    vector<vc> k(n);
    int q=0,h=n-1;
    for(int i=0;i<n;i++){
        if(a[i].Mi==a[i].x)k[q]=a[i],q++;
        else k[h]=a[i],h--;
    }
    int A=0,B=0;
    for(int i=0;i<n;i++){
        A+=k[i].x;
        if(B<A)B=A;
        B+=k[i].y;
    }
    cout<<B<<'\n';
    for(int i=0;i<n;i++){
        cout<<k[i].id<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [Educational Codeforces Round 175 (Rated for Div. 2)](https://codeforces.com/contest/2070/problem/E)

### 题目描述

给定长度为 $n$ 的二进制字符串 $s$（字符为 `0` 或 `1`）。考虑如下 **循环** 字符串上的游戏（注意题目中“首元素和末元素也被视为相邻” — 即子串内部视为环）：

* 两位玩家轮流操作，先手为 Alice（我们称第一位玩家），后手为 Bob。
* Alice 在回合中必须删除一对相邻字符，且这对必须是 `00`。
* Bob 在回合中必须删除一对相邻字符，且这对中至少包含一个 `1`（即 `01`、`10` 或 `11` 均可）。
* 无法进行合法操作的玩家输（长度 < 2 也算无法操作）。

问题：统计原串 $s$ 的所有（连续）子串 $s[l..r]$（这里把子串看成一个**循环**串）中，Alice 能在双方最优的情况下必胜的个数。

---

### 思路

将子串中 0 和 1 的个数分别记作 $c_0$ 和 $c_1$。定义量

$$
\text{num} = c_0 - 3 c_1.
$$

**重要不变量 / 直观事实（对博弈的标准化分析）**：

* 当 Alice 做一次合法删除（删除 `00`）时，$c_0 \leftarrow c_0 - 2$，于是 $\text{num} \leftarrow \text{num} - 2$。

* 当 Bob 做一次“理想的”回应时（他为了尽可能阻止 Alice，优先删 `01` / `10`），假设他能删走一个 `0` 和一个 `1`，则 $c_0 \leftarrow c_0 - 1$，$c_1 \leftarrow c_1 - 1$，于是 $\text{num}$ 恰好恢复到删除前的值：

  $$
  \text{num}' = (c_0-2) - 3(c_1-1) = c_0 - 3 c_1.
  $$

  因此在一轮 “Alice 做一次、Bob 做一次并尽可能不帮助 Alice”的情况下，$\text{num}$ 保持不变。

* Bob 总是能选择一个包含 `1` 的合法删除（即 `01`/`10`/`11`）**当且仅当**当前字符串中至少存在一个 `1`。在有 `1` 的情况下，Bob 通常会选择 `01`/`10`（比 `11` 更“坏”，因为 `11` 会减少两个 `1`，从而把 $\text{num}$ 增大 6，对 Alice 更有利），所以我们把 Bob 的“最坏回复”视作删 `01`/`10`（每轮合计对 $c_0,c_1$ 的净变化是 $-3,-1$）。

由此可以做如下分类（对终局情况的枚举）：

* 若 $\text{num} \ge 2$，Alice 能保证最终胜利。
* 若 $\text{num} = -1$，Alice 也能获胜（具体情况可构造：Alice 先手删 `00`，使得 Bob 之后无合法操作或会留下对 Alice 有利的局面——这里给出直观分类即可）。
* 若 $\text{num} = 0$ 或 $1$，Bob 能保证胜利。
* 若 $\text{num} \le -2$，Bob 胜（Alice 最终无法继续操作或者 Bob 能阻断她的多次操作）。

（上面分类是题解常见且被验证的结论；可通过对「每一轮 Alice 尽力并假定 Bob 做最坏回复」的归纳证明得到。）

因此，判断一个子串 Alice 是否必胜只看它的 $c_0$ 与 $c_1$ 的组合是否满足：

$$
c_0 - 3c_1 \ge 2 \quad\text{或}\quad c_0 - 3c_1 = -1.
$$

---

**把问题转换为前缀和计数（化简为枚举右端点，查询左端点个数）**

定义前缀数组（为方便，按下标从 0 到 n）：

$$
\text{pref}[i] = \#\text{0 in } s[1..i] - 3\cdot \#\text{1 in } s[1..i].
$$

注意 $\text{pref}[0] = 0$。

对任意子串 $s[l..r]$，其 $c_0 - 3c_1 = \text{pref}[r] - \text{pref}[l-1]$。我们需要统计有序对 $(l,r)$（$1\le l\le r\le n$），满足

$$
\text{pref}[r] - \text{pref}[l-1] \ge 2 \quad\text{或}\quad \text{pref}[r] - \text{pref}[l-1] = -1.
$$

等价地，对于固定 $r$，统计 $l$ 个数满足：

* $\text{pref}[l-1] \le \text{pref}[r] - 2$（对应第一个不等式），
* $\text{pref}[l-1] = \text{pref}[r] + 1$（对应第二个等式）。

因此我们可以按 $r$ 从左到右枚举，并维护已经出现过的所有 $\text{pref}[l-1]$ 的计数结构来快速回答两个类型的查询（“≤ X 的个数” 与 “等于 Y 的个数”）。典型做法是：

* 先把所有可能出现的前缀值坐标压（离散化）到 $[1..m]$；
* 用树状数组（Fenwick / BIT）维护每个离散值出现的前缀次数，以支持「≤ X 的个数（前缀和）」查询；
* 同时用哈希表（或 `unordered_map`）维护每个精确值的出现次数，以支持“等于 Y 的个数”查询（也可以直接用数组，如果压缩后范围已知）。

运行时：对每个 r：

1. 计算 `cur = pref[r]`。
2. 答案增加 `cnt_equal[cur+1]`（直接从哈希表读）。
3. 在离散数组上找到 $(cur - 2)$ 的下标idx：`idx = upper_bound(discrete, cur-2)`, 增加 `BIT.query(1, idx)`。
4. 把 `cur` 插入数据结构`BIT.add(pos(cur), +1)`；哈希表 `cnt_equal[cur]++`），以便后续作为 $l-1$。

注意初始时要把 `pref[0] = 0` 先插入作为 $l-1 = 0$ 的可能性

---


```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
struct BIT{
    int n;
    vector<int> t;
    void init(int _){
        n=_;
        t.resize(n+10,0);
    }
    void add(int x,int k){
        for(int i=x;i<=n;i+=i&-i){
            t[i]+=k;
        }
    }
    ll query(int l,int r){
        ll res=0;
        for(int i=l-1;i>=1;i-=i&-i){
            res-=t[i];
        }
        for(int i=r;i>=1;i-=i&-i){
            res+=t[i];
        }
        return res;
    }
};
int get(int x,vector<int> &d){
    int L=0,R=d.size()-1,idx=-1;
    while(L<=R){
        int mid=(L+R)>>1;
        if(d[mid]<=x){
            idx=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    if(idx!=-1)idx++;
    return idx;
}
void solve(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    int c0=0,c1=0;
    vector<int>d;
    for(int i=0;i<n;i++){
        c0+=(a[i]=='0');
        c1+=(a[i]=='1');
        d.push_back(c0-3*c1);
    }
    d.push_back(0);
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    ll ans=0;
    int sum=0;
    BIT r;
    r.init(d.size());
    map<int,ll>f;
    f[0]++;
    r.add(get(0,d),+1);
    for(int i=0;i<n;i++){
        sum+=(a[i]=='0');
        sum-=3*(a[i]=='1');
        ans+=f[sum+1];
        int idx=get(sum-2,d);
        if(idx!=-1){
            ans+=r.query(1,idx);
        }
        r.add(get(sum,d),+1);
        f[sum]++;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [Educational Codeforces Round 164 (Rated for Div. 2) D. Colored Balls](https://codeforces.com/contest/1954/problem/D)

### 题目描述

### 关键观察（公式）

对某一颜色子集 $S$，令该子集的球数总和为 $m=\sum_{i\in S} a_i$，最大单色球数为 $M=\max_{i\in S} a_i$。由于每组最多放 2 个球且每种颜色在一组中最多 1 个：

* 组数至少为 $M$（因为某种颜色有 $M$ 个球，必须分到不同组）；
* 组数至少为 $\lceil m/2\rceil$（每组最多放 2 个球）。

因此最少组数为

$$
\text{value}(S)=\max\big(M,\ \lceil m/2\rceil\big).
$$

并且该下界是可达的（构造性说明）：

* 若 $M\ge \lceil m/2\rceil$：把这 $M$ 个同色球各放到 $M$ 个组中，其余球数为 $m-M\le M$，把每个剩余球放到不同的已有组中（不会造成同色冲突），因此 $M$ 组足够。
* 若 $M< \lceil m/2\rceil$：可以用贪心（优先取当前剩余最多的两种颜色各取一个放一组）一直配对，直到只剩 0 或 1 个球；此法能做到 $\lceil m/2\rceil$ 组（这是标准配对思路），因此下界可达。

---

### 计数思路（DP）

我们需要计算所有 $2^n$ 个子集的 $\max(M, \lceil m/2\rceil)$ 的和。经典做法是按“子集的最大颜色球数”对子集进行分组计数（把每个非空子集唯一分配给其在原序列中**最右被选中**的元素索引 i，这样避免重复计数）。步骤：

1. 先把数组 $a$ 升序排序。
2. 对于固定的索引 $i$（视为被选中并且是被选元素中下标最大的那个），计算：选该 i（必选），并从前 $i-1$ 个元素任意选若干，使得总和为 $j$。计数记为 $f_i[j]$（即所有子集其最大位置正好为 i 且总和为 j 的个数）。

   * 若我们维护 `prev_sum[s]` 表示从前 $i-1$ 个元素中取任意（可能为空）使得和为 $s$ 的方法数，那么

     $$
     f_i[j] = \text{prev\_sum}[j-a_i]\quad\text{（当 }j\ge a_i\text{ 时）}.
     $$
3. 对于每个 $i,j$，这些子集对答案的贡献为

   $$
   f_i[j]\cdot \max\big(a_i,\ \lceil j/2\rceil\big).
   $$
4. 更新 `prev_sum` 为包含到第 $i$ 个元素后的新 `sum`（也就是把 $f_i$ 加进来），进入下一轮。

这样只需要维护一维 `prev_sum`（长度为总球数上限 +1）和每轮临时的 `f_i`，内存仅 $O(\text{sum})$，时间 $O(n\cdot \text{sum})$（这里 $\text{sum}\le 5000$）。


**实现要点**

* `prev_sum` 只保存前 $i-1$ 个元素的“和为 s 的子集数”。初始只有 `prev_sum[0]=1`（空集）。
* 对每个 `i`，`fi[j] = prev_sum[j-ai]`（当 `j>=ai`），这对应“选中第 i 个元素且它为选中元素中下标最大的情况”。
* 用 `fi` 直接累加对答案的贡献，然后把 `fi` 加入 `prev_sum`，用于后续 i 的计算。
* 所有运算对模 $998244353$ 取模（答案累加使用 `ll`，最后再取模输出；中间 `prev_sum`/`fi` 保证模化以避免增长）。

---


```c++
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e6+10;
const int M=2e5+10;
const int inf = 0x3f3f3f3f;
// const int mod = 1000000007;
const int mod = 998244353;

void solve(){
    int n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<vector<ll>> f(n+10,vector<ll>(5050,0)),sum(n+10,vector<ll>(5050,0));
    f[0][0]=sum[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5000;j++){
            if(j>=a[i])f[i][j]=(f[i][j]+sum[i-1][j-a[i]])%mod;
            sum[i][j]=(sum[i-1][j]+f[i][j])%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(ll j=1;j<=5000;j++){
            ans=(ans+(f[i][j]*max(a[i],(j+1)/2))%mod)%mod;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ZKX.in","r",stdin);
    // freopen("ZKX.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```




## [Educational Codeforces Round 160 (Rated for Div. 2) D - Array Collapse](https://codeforces.com/contest/1913/problem/D)

### 题目描述

给定长度为 $n$ 的数组 $p$（元素互不相同）。一次操作：选取一个连续子段，把该段中**除最小元素外**所有元素删除。问从 $p$ 能得到多少个不同的数组（称为“可达数组”），答案对 $998244353$ 取模。多组样例，总和 $n \le 3\cdot10^5$。

### 思路

**关键观察（为什么能做 DP + 单调栈）**

把最终保留下来的数组看成原数组的一个严格增下标序列（保留若干位置），记若以位置 $i$ 结尾的可达数组数量为 $dp[i]$。要把某个以 $j$ 结尾的方案接上位置 $i$（使得 $j$ 与 $i$ 成为最终数组中的相邻两项），区间 $[j,i]$ 必须满足：区间最小值出现在端点（即是 $a_j$ 或 $a_i$）——否则内部更小的元素会把端点之一“吃掉”。

因此，对于固定 $i$，所有能转移的 $j<i$ 可以分为两类：

* **类型 A（右端最小）**：区间 $[j,i]$ 的最小值是 $a_i$。这等价于在区间 $(j,i)$ 中没有比 $a_i$ 更小的元素。若令 $l_i$ 为 $i$ 左侧最近一个比 $a_i$ 小的位置，则类型 A 的 $j$ 必须满足 $j\in[l_i+1,\,i-1]$。
* **类型 B（左端最小）**：区间 $[j,i]$ 的最小值是 $a_j$。这些 $j$ 必须满足：区间 $[j,i]$ 中没有比 $a_j$ 更小的元素。随着从左到右扫描，满足这一性质的 $j$ 恰好保存在一个按值严格递增的单调栈中（栈中的每个下标在当前扫描到 $i$ 时都保证自己到 $i$ 的区间没有更小值）。

再补一点：如果在 $i$ 左侧没有比 $a_i$ 更小的元素（即 $l_i=0$），那么方案“只选择 $a_i$ 本身”也应该被计入（等于 +1）。

最终有转移公式：

$$
dp[i] = \sum_{j\in\text{类型B}} dp[j] \;+\; \sum_{j=l_i+1}^{i-1} dp[j] \;+\; [\text{若左侧无更小元素则 }1]
$$

这个公式通过维护单调栈、一个栈中 $dp$ 和（记为 $res$）以及前缀和 $sum[]$ 能在 $O(1)$ 时间得到。

* $dp[i]$：以位置 $i$ 的元素为最终数组最后一项的可达数组数。
* $s[i]$：前缀和，$s[i] = dp[1] + dp[2] + ... + dp[i]$（方便求区间和）。
* $stk$（单调栈，存下标）：栈内按 $a[idx]$ 严格递增。它保存的是“能作为左端最小值并且到当前扫描位置还没有被更小值覆盖”的下标集合。
* $res$（对应代码中的 $res$ / 也就是上面讲的 $sum$）：等于栈中所有 $dp[j]$ 的和，直接给出“类型 B”的贡献。
* $rep[i]$（或 $sufmin[i]$）：从 i 到 n 的后缀最小值，用于最后求答案（见下）。

**最终答案**是所有能作为最终数组最后一项的位置 $i$ 的 $dp[i]$ 之和。哪些位置能作为最终数组最后一项？必须保证在它右侧不存在更小的元素（否则右侧更小的元素在某步会把它删除），即 $a[i] = \min_{k\in[i..n]} a[k]$。因此我们把后缀最小 $rep[i]$ 预处理好，累加所有 $dp[i]$ 满足 $a[i] == rep[i]$。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e6+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;


void solve(){
    int n;
    cin>>n;
    int a[n+1];
    vector<int> rep(n+10,2e9);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        rep[i]=min(rep[i+1],a[i]);
    }
    vector<ll> sum(n+1,0),dp(n+1,0);
    ll res=0,ans=0;
    stack<int> s;
    for(int i=1;i<=n;i++){
        // 弹出栈中比 a[i] 大的元素——它们不再能作为未来区间的左端最小值
        while(!s.empty()&&a[i]<a[s.top()]){
            res=(res-dp[s.top()]+mod)%mod;
            s.pop();
        }
        if(s.empty()){
            // 没有左侧比 a[i] 小的：包含“以 a[i] 自身为开头”的方案
            // 前缀和表示所有 j in [1..i-1]
            dp[i]=1ll;
            dp[i]=(dp[i]+sum[i-1])%mod;
        }
        else{
            // 有栈顶 l = stk.top()
            // 类型 B 的贡献 = inStackSum
            // 类型 A 的贡献 = pref[i-1] - pref[l]
            dp[i]=res;
            dp[i]=(dp[i]+(sum[i-1]-sum[s.top()]+mod)%mod)%mod;
        }
        sum[i]=(sum[i-1]+dp[i])%mod;
        s.push(i);
        res=(res+dp[i])%mod;
        if(a[i]==rep[i]){// 如果 a[i] 是后缀最小值，则 dp[i] 可以作为最终答案的末尾
            ans=(ans+dp[i])%mod;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```




## [The 2021 ICPC Asia Shanghai Regional Programming Contest I. Steadily Growing Steam](https://codeforces.com/gym/103446/problem/I)

### 题目描述


有 $n$ 件物品，第 $i$ 件物品体积 $t_i$、价值 $v_i$。你可以先把最多 $k$ 件物品“体积翻倍”（即把某件物品的体积从 $t_i$ 变成 $2t_i$），然后从所有物品中任意选择若干件，将选中的物品分为两堆，使两堆体积和相等。求所选物品价值之和的最大值。

将“分为两堆体积和相同”问题等价于选择若干物品并给每件物品一个符号 $+1$（放在堆1）或 $-1$（放在堆2），要求带符号的体积和为 0。我们把被翻倍的物品视为体积变为 $2t_i$ 后再参与上述过程。

---
### 思路
**状态定义**

令偏移量为 $MID$。定义 DP 状态

$$
dp[i][w][j] = \text{考虑前 }i\text{ 件物品，当前“带符号体积和”为 }w{-}\text{MID，且已翻倍的物品数为 }j\text{ 时的最大价值}
$$

（注意实现中用一维索引 $w$ 存储偏移后的整数，下文用 $W = 2*sum_t + 1$ 表示数组宽度）

初始：$dp[0][MID][0] = 0$（没选任何物品、体积和为 0、翻倍 0 件）

目标：在处理完所有物品后，答案为 $max_{0<=j<=k} dp[n][MID][j]$（体积和为 0，对应偏移 MID）。

---

**转移（每个物品有 5 种选择）**

当处理第 $i$ 件物品（体积为 $t_i$，翻倍后为 $2t_i$）：

* 不选第 $i$ 件：$dp[i][w][j] = max(dp[i][w][j], dp[i-1][w][j])$
* 选第 $i$ 件放到正堆（记为 +t）：$dp[i][w][j] = max(dp[i][w][j], dp[i-1][w-t_i][j] + v_i)$ （有效索引）
* 选第 $i$ 件放到负堆（记为 -t）：$dp[i][w][j] = max(dp[i][w][j], dp[i-1][w+t_i][j] + v_i)$
* 如果还可以翻倍（j>=1），把第 $i$ 件翻倍并放正堆（+2t）：$dp[i][w][j] = max(dp[i][w][j], dp[i-1][w-2t_i][j-1] + v_i)$
* 翻倍并放负堆（-2t）：$dp[i][w][j] = max(dp[i][w][j], dp[i-1][w+2t_i][j-1] + v_i)$

注意：转移中涉及访问 $dp[i-1][*][*]$ 的不同 $w'$，因此循环顺序必须是外层按 $i$（上一层已算完），然后按 $w$、$j$。这是你原来 WA 的一个典型原因：$w$ 在外层会导致读取到未计算的 $i-1$ 层或覆盖值。

另外你原代码有个细节 $if (j-1 >= 1)$（即 $j>=2$）才允许翻倍转移，这显然错误，应为 $if (j >= 1)$（允许 $j==1$ 情况）。

---

**空间边界与实现注意**

* $w$ 的取值范围需要覆盖所有可能的带符号体积和。保守做法：$W = 2 * sum(t_i) + 1$，$MID = sum(t_i)$。如果固定写 1310/650，必须确保 $sum(t_i) <= 650$，否则会越界。
* 为节省内存，我们可以把 $i$ 维滚动成 $prev$、$cur$ 两层（$dp[i-1]$ 与 $dp[i]$），空间为 $O(W * (k+1))$。
* 用 $LLONG_MIN/4$ 或类似非常小的值作为 “-∞” 初始值，避免和 $-1$ 混淆（$-1$ 可能是合法价值）。
* 时间复杂度：每个物品处理 $W$ 个 $w$ 值、每个 $j$ 达到 $min(i,k)$，因此时间为 $O(n \cdot W \cdot \min(k,n))$。若 $W = 2\sum t_i + 1$，则复杂度 $O(n \cdot (\sum t_i) \cdot k)$（或 $O(n^2 \cdot \sum t_i)$ 最坏当 $k=O(n)$）。
* 空间复杂度：$O(W \cdot k)$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e6+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;


void solve(){
    int n,k;
    cin>>n>>k;
    ll v[n+1],t[n+1];
    for(int i=1;i<=n;i++){
        cin>>v[i]>>t[i];
    }
    vector<vector<vector<ll>>> dp(1310,vector<vector<ll>>(n+1,vector<ll>(n+1,-1)));
    dp[650][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int w=0;w<=1300;w++){// [-650,650-] -> [0,1300]
            for(int j=0;j<=i;j++){
                if(dp[w][i-1][j]!=-1)dp[w][i][j]=max(dp[w][i-1][j],dp[w][i][j]);
                if(w-t[i]>=0){
                    if(dp[w-t[i]][i-1][j]!=-1)dp[w][i][j]=max(dp[w][i][j],dp[w-t[i]][i-1][j]+v[i]);
                }
                if(w+t[i]<=1300){
                    if(dp[w+t[i]][i-1][j]!=-1)dp[w][i][j]=max(dp[w][i][j],dp[w+t[i]][i-1][j]+v[i]);
                }
                if(j>=1){
                    if(w-2*t[i]>=0){
                        if(dp[w-2*t[i]][i-1][j-1]!=-1)dp[w][i][j]=max(dp[w][i][j],dp[w-2*t[i]][i-1][j-1]+v[i]);
                    }
                    if(w+2*t[i]<=1300){
                        if(dp[w+2*t[i]][i-1][j-1]!=-1)dp[w][i][j]=max(dp[w][i][j],dp[w+2*t[i]][i-1][j-1]+v[i]);
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int j=0;j<=k;j++){
        ans=max(dp[650][n][j],ans);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [The 2021 ICPC Asia Nanjing Regional Contest H. Crystalfly](https://codeforces.com/gym/103470/problem/H)

### 题目描述
给定一棵有 $n$ 个节点的树，第 $i$ 个节点上有 $a_i$ 只晶蝶，现在从 1 号点开始走，每走到一个点，获得该点的晶蝶但会惊动相邻点的晶蝶，第 $i$ 个节点上的晶蝶被惊动后会在 $t_i$ 后飞走，求问能获得最大晶蝶数量。

数据范围：$n \leq 10^5, 1 \leq a_i \leq 10^9, 1 \leq t_i \leq 3$。

思路：
很明显是树形 dp。

从条件 $1 \leq t_i \leq 3$ 入手，这个条件非常重要，因为这意味着晶蝶被惊动后很快就会飞走。

有多快？假如当前走到一个节点 $i$，然后立马返回了，那么 $i$ 的子节点一定全飞走了，就算有的子节点 $v$ 的 $t_v = 3$ 还能拿到，但这一定不是最优解（能一步拿到为什么要折返走三步？）。

所以可以分析出几种行走方式：
1. 走到节点 $i$，然后走到它的某个子节点处，其他子节点全部飞走；
2. 走到节点 $i$，然后走到它的某个子节点 $v_1$ 处，立即返回，走到另一个 $t = 3$ 的子节点 $v_2$ 处，其余子节点全部飞走，$v_1$ 的子节点也全部飞走。

根据以上分析，我们可以设计出两种状态：
设 $f(i, 0)$ 表示当前走到点 $i$，$i$ 的蝴蝶已经飞走但子节点还在，我们在以 $i$ 为根的子树中继续抓蝴蝶最多能抓住几只蝴蝶。

$f(i, 1)$ 表示当前走到点 $i$，然后立马折返回去，即拿到 $i$ 的蝴蝶，但子节点全部飞走，这种情况下最多能抓住几只蝴蝶。

发现 1 的状态是可以由 0 的状态转移到的：
$$f(i, 1) = a_i + \sum_{j \in \text{subtree}(i), j \neq i} f(j, 0)$$

含义就是：第 $i$ 个点的蝴蝶能抓到，但各个子树的根上的蝴蝶都飞走了。

接下来就只用考虑 $f(i, 0)$ 怎么计算了。

考虑上面描述的两种行走方式：
设点 $i$ 的所有子节点 $j$ 的 $f(j, 0)$ 之和为 $sum$，即：
$$sum = \sum_{j \in \text{subtree}(i), j \neq i} f(j, 0)$$

对于方式 1，如图所示：

我们要加上所有子节点 $j$ 的 $f(j, 0)$，然后加上走向的那么子节点的蝴蝶数。

状态转移方程为：
$$f(i, 0) = sum + \max_{j \in \text{subtree}(i), j \neq i} a_j$$

对于方式 2，如图所示：

我们要选出两棵子树来走，其他都是 $f(j, 0)$。

状态转移方程为：
$$f(i, 0) = sum + \max_{j \in \text{subtree}(i), j \neq i} \{f(j, 1) - f(j, 0)\} + \max_{k \in \text{subtree}(i), k \neq i, k \neq j, t_k = 3} \{a_k\}$$

只考虑 $t = 3$ 的 $k$，不然来不及抓该点的蝴蝶。

朴素思考，要枚举 $j, k$ 分别求最大值，时间复杂度为 $O(n^2)$，TLE。

其实本质上就是求除去一个子结点 $j$，剩下的子节点的最大值，因为 $j$ 必须被枚举，所以就优化找 $k$ 的过程即可。

可以预处理出子节点中蝴蝶数量的最大值、次大值以及它们分别是哪个子节点。这样的话，在枚举 $j$ 时若 $j$ 为最大值所在的那个子节点，就选次大值；否则选最大值，优化掉一层循环。

最后答案即为 $f(1, 0) + a_1$。

综上所述，两种走方式的转移都是 $O(n)$，所以整个做法的时间复杂度为 $O(n)$。


### 思路


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e5+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;



ll a[N],dp[N][2],sum[N],Mx[N];
PII Tm[N][2];
int t[N];
ll ans;
vector<vector<int>> e(N);
bool cmp(int x,int y){
    return a[x]<a[y];
}
void dfs(int x,int f){
    Tm[x][0]={-1e10,0};
    Tm[x][1]={-1e10,0};
    for(auto y:e[x]){
        if(y==f)continue;
        else{
            dfs(y,x);
            sum[x]=sum[x]+dp[y][0];
            Mx[x]=max(Mx[x],a[y]);
            if(t[y]==3){
                if(a[y]>=Tm[x][1].first){
                    Tm[x][0]=Tm[x][1];
                    Tm[x][1].first=a[y];
                    Tm[x][1].second=y;
                }
                else if(a[y]>=Tm[x][0].first){
                    Tm[x][0].first=a[y];
                    Tm[x][0].second=y;
                }
            };
        }
    }
    dp[x][1]=a[x]+sum[x];
    dp[x][0]=Mx[x]+sum[x];
    for(auto y:e[x]){
        if(y==f)continue;
        else{
            if(Tm[x][1].second){
                if(y!=Tm[x][1].second)dp[x][0]=max(dp[x][0],sum[x]+dp[y][1]-dp[y][0]+Tm[x][1].first);
                else if(Tm[x][0].second){
                    dp[x][0]=max(dp[x][0],sum[x]+dp[y][1]-dp[y][0]+Tm[x][0].first);
                }
            }            
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=dp[i][0]=sum[i]=Mx[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans=0;
    dfs(1,0);
    cout<<dp[1][0]+a[1]<<'\n';
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [The 2023 ICPC Asia Nanjing Regional Contest (The 2nd Universal Cup. Stage 11: Nanjing) G - Knapsack](https://codeforces.com/gym/104821/problem/G)


### 题目简述

有 $n$ 件物品，第 $i$ 件的花费为 $w_i$，价值为 $v_i$。你有 $W$ 元可以花，此外商店允许你任选 $k$ 件物品**免费获得**（不占用预算）。每件物品最多获取一次（0/1）。问在最优策略下最多能获得的总价值。

约束：$n \le 5e3$，$W \le 1e4$，$0 \le k \le n$，$1 \le w_i \le W$，$1 \le v_i \le 1e9$。

### 思路

**关键观察与思路概览**

要同时处理“付钱买”和“任选 k 件免费”的组合，直接枚举哪些免费会很难（组合数巨大）。常见且高效的思路是：

1. **按重量升序排序**物品（若权重相同可按价值随意）。
2. 我们枚举一个“分界点” $i$（实际上是枚举某个下标），把物品分成两部分：前缀 $0..i$ 与后缀 $i+1..n-1$。

   * 设我们**只在前缀中购买（用钱）**；把 $k$ 件免费的物品**只从后缀中选取**。
3. 对于每个 $i$：

   * 用常规 **0/1 背包** 在前缀上求出所有花费 $0..W$ 下能达到的最大价值（这是一个 $O(W * prefix_size)$ 的 DP 增量过程，若按 i 逐步扩展则每件物品只处理一次，共 $O(nW)$）。
   * 预先用一个最小堆（大小限为 $k$）在后缀中维护最大的 $k$ 个价值，记作 $g[i+1]$：表示从后缀中任选 $k$ 件能获得的最大价值和（如果后缀中的物品少于 $k$ 件则就是所有值之和）。
   * 把两部分答案合并：在任意预算 $j$ 下，$dp[j] + g[i+1]$ 是一种可行策略的价值，取最大值。

最终对所有 $i$、所有预算 $j$ 取最大值即为答案。

---

**为何上面的枚举是完备的（正确性说明）**

我们用更简洁且等价的方式给出正确性说明（将图片中的要点并入）：

**关键结论（两条性质）**：在某个最优解中，可以找到一个满足下列两条性质的解（若当前最优解不满足，则可以通过交换或替换操作获得不劣解）：

1. 若物品 $a$ 被**免费**选走，物品 $b$ 被**付费**选走，则必有 $w_a \ge w_b$。否则我们把免费选走的身份在 $a$ 与 $b$ 之间交换（免费选 $b$，付费选 $a$），预算消耗不会增加且总价值不降低。

2. 若物品 $a$ 被**免费**选走，物品 $b$ **未被选走**，则必有 $v_a \ge v_b$。否则把免费选走的身份从 $a$ 换到 $b$（免费选 $b$，放弃 $a$），显然不会降低总价值。

由上面两条性质可得：如果把所有物品按 $w_i$ 从小到大排序，则在某个最优解中，存在一个分界下标 $M$，使得所有下标 $> M$（即较重的物品）的物品中，**价值前 $k$ 大的那些会被免费选走**，而所有被付费购买的物品都来自下标 $<= M$ 的前缀。

证明直观地解释了我们为什么可以只枚举“分界点”并把问题分成“前缀用于付费购买、后缀用于免费选取”的形式：任意最优解都可以通过上面的交换操作转化为这种结构而不降低答案，因此对所有 $M$ 的枚举是完备的。

备注：若 $k \ge n$，则可以把所有物品全部免费获得，答案就是所有 $v_i$ 之和；代码里做了单独处理。


**复杂度分析**

* 先排序：$O(n log n)$。
* 计算每个后缀的 k 最大值和：每件元素入堆一次，堆大小至多 $k$，复杂度 $O(n log k)$。
* 主 DP（按物品逐步推进的 0/1 背包）：每件物品遍历预算 $W$ 一次，总 $O(nW)$。

总体时间复杂度：$O(nW + n log n + n log k)$，在本题约束下是可行的。

空间复杂度：$O(W + n)$。


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e5+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;

void solve(){
    int n,V,k;
    cin>>n>>V>>k;
    vector<pair<ll,ll>>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin()+1,a.end());
    priority_queue<ll,vector<ll>,greater<ll>> q;
    ll sum=0;
    vector<ll> g(n+10,0);
    for(int i=n;i>=1;i--){
        q.push(a[i].second);
        sum+=a[i].second;
        if((int)q.size()>k){
            sum-=q.top();
            q.pop();
        }
        g[i]=sum;
    }
    vector<ll> dp(V+10,-1e18);
    dp[0]=0;
    ll ans=g[1];
    for(int i=1;i<=n;i++){
        for(int j=V;j>=a[i].first;j--){
            dp[j]=max(dp[j-a[i].first]+a[i].second,dp[j]);
        }
        for(int j=0;j<=V;j++){
            ans=max(dp[j]+g[i+1],ans);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [2022 Hubei Provincial Collegiate Programming Contest A - Nucleic Acid Test](https://codeforces.com/gym/103729)


### 题面描述

给定无向带权图 $n$ 个节点、$m$ 条边，图中有 $k$ 个核酸点。需要从某个核酸点出发，以速度 $v$ 遍历（访问）图中所有节点并最终回到出发的核酸点，且要求相邻两次经过核酸点的时间间隔不超过 $t$。求满足要求的最小整数速度 $v$，若不存在则输出 $-1$。

约束示例：$n\le 300$，边权与 $t$ 可达 $10^{9}$。


### 思路
**关键观察与结论**

1. **访问非核酸点的最优方式**
   假设某非核酸点 $x$ 到最近的核酸点的距离为 $d_x$。要保证遍历并返回到核酸点，最优的“贡献”是走来回一次 —— 距离为 $2d_x$。任何尝试通过在两核酸点间绕行来访问 $x$ 的路程 $\ge 2d_x$，因此非核酸点对总路程的必要上界为 $2d_x$。所以所有非核酸点只需考虑到其最近核酸点的距离，取其中的最大值,记为 $L = max(L , 2 \cdot d_x)$。

2. **核酸点之间的连接与“最长边”是瓶颈**
   核酸点之间必须连通（否则无法以核酸点间隔 \le t 回到核酸点）。在核酸点集合上任选一颗生成树（MST）来连通所有核酸点是最优的（因为多余边会增加在两个核酸点之间的最长必须通过的单段长度）。在 MST 中最长的边长度决定了在核酸点间单段所需覆盖的最长距离（记为 $Mx$）。若 $k=1$ 则 $Mx=0$。

3. **速度下界**
   为保证任意相邻两次经过核酸点的时间间隔 \le $t$，必须满足所有单段距离（包括访问非核酸点的来回段与核酸点间的最长单段）都 \le $v \cdot t$。因此所需的最小速度为：

   $$
   v_{\min} = \left\lceil \frac{\max(\text{L},\ \text{Mx})}{t} \right\rceil.
   $$

   若图不连通或 $t=0$（题目约定这两种情形无解），输出 $-1$。

**算法步骤**

1. 用 **Floyd–Warshall**（或对稀疏图用从每个核酸点做 $Dijkstra$）求出任意两点最短路 $dist[i][j]$。
2. 检查图连通性：若存在 $dist[i][j] == INF$，则输出 $-1$。
3. 计算 $L = max_{i \in  nuc} (L,2 * min_{s \notin nuc} dist[i][s])$。
4. 在核酸点集合上构造完全图，边权为核酸点间最短路 $dist[s_i][s_j]$，用 Kruskal 得到 MST，并记录 MST 中的最大边 Mx（若 $k == 1$ 则为 0）。
5. 若 $t==0$ 输出 -1，否则输出 $\lceil \max(L, Mx) / t \rceil$。

**复杂度**

* Floyd–Warshall：$O(n^3)$（当 $n\le 300$ 可接受）。
* 构造核酸完全图并 Kruskal：生成 $O(k^2)$ 条边并排序，复杂度 $O(k^2 \log k)$。
* 总体时间复杂度以 $O(n^3)$ 为主；空间复杂度 $O(n^2)$。

可选优化：若图稀疏（$m \ll n^2$），可以对每个核酸点运行 Dijkstra（$O(k (m \log n))$）代替 Floyd。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e5+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;

struct dsu{
    int n;
    vector<int> f;
    vector<int> sz;
    void init(int _){
        n=_;
        f.resize(n+10);
        sz.resize(n+10);
        for(int i=1;i<=n;i++){
            f[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        while(x!=f[x]){
            x=f[x]=f[f[x]];
        }
        return x;
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return ;
        if(sz[x]>sz[y])swap(x,y);
        f[x]=y;
        sz[y]+=sz[x];
        return ;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
}d;
ll Mx=0;
struct krl{
    using TII = tuple<ll,int,int>;
    priority_queue<TII,vector<TII>,greater<TII>> q;
    int n;
    int cnt;
    void init(int _){
        n=_;
    }
    void add(int w,int x,int y){
        q.push({w,x,y});
    }
    void work(){
        d.init(n+1);
        cnt=0;
        while(!q.empty()){
            auto [w,u,v]=q.top();
            q.pop();
            if(d.same(u,v))continue;
            d.merge(u,v);
            Mx=max(Mx,w);
        }
        return ;
    }
}kx;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int u[m+10],v[m+10];
    ll w[m+10];
    vector<int> f(n+10,0);
    int T;
    cin>>T;
    vector<vector<ll>> dis(n+10,vector<ll>(n+10,1e18));
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        dis[u[i]][v[i]]=w[i];
        dis[v[i]][u[i]]=w[i];
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        f[x]=1;
    }
    if(T==0){
        cout<<-1<<'\n';
        return ;
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++){
            if(dis[i][x]==1e18) continue;
            for(int j=1;j<=n;j++){
                if(dis[x][j]==1e18)continue;
                dis[i][j]=min(dis[i][x]+dis[x][j],dis[i][j]);
            }
        }
    }
    int ok=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dis[i][j]==1e18){
                ok=0;
                break;
            }
        }
    }
    if(!ok){
        cout<<-1<<'\n';
        return ;
    }
    kx.init(n+10);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i]&&f[j]){
                kx.add(dis[i][j],i,j);
            }
        }
    }
    kx.work();
    for(int i=1;i<=n;i++){
        if(!f[i]){
            ll L=1e18;
            for(int j=1;j<=n;j++){
                if(f[j]){
                    L=min(dis[i][j],L);
                }
            }
            Mx=max(2*L,Mx);
        }
    }
    cout<<(Mx+T-1)/T<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [2022 Hubei Provincial Collegiate Programming Contest  J Palindrome Reversion](https://codeforces.com/gym/103729)


### 题目描述

给定字符串 `s`，问是否存在一个区间（连续子串）把它翻转后使整个字符串变为回文。若存在，输出这样一个区间的左右端点（题目使用 1-based），否则输出 `-1 -1`。要求给出任意一个合法的区间。

---
### 思路

**关键观察（把问题简化到中间区间）**

把 `s` 两端相等的字符对依次去掉（双指针从两端向中间缩），直到遇到第一对不相等的位置 `l` 和 `r`。设去掉的字符对数为 `q`，剩下的中间子串为 `a = s[l..r]`（若 `l>=r`，说明原串本来就是回文，直接输出任意合法区间）。

证明（直观）：翻转某一段能否把 `s` 变成回文，翻转操作不会改变两端已经完全对称的前缀/后缀位置（因为这些字符与其镜像相等），所以我们只要考虑中间不相等的那一段 `a`。对 `a` 做一次“翻转前缀”或“翻转后缀”能否使 `a` 变为回文，即为原问题的必要且充分条件。

进一步可把所有可能的解归纳为三种形式（见题面常见证明）——在中间段 `a` 上只需检查两类操作：

* 翻转 `a` 的某个前缀（把 `a[1..R]` 反转）
* 或 翻转 `a` 的某个后缀（把 `a[L-R+1..L]` 反转）

因此我们在 `a` 上枚举 `R` 即可。

---

**哈希思路（为什么用哈希）**

要判断翻转后得到的字符串是否为回文，直接构造字符串再判断会耗费 O(n) 每次；用滚动哈希可以让“取子串/取反串/拼接比较”都变为 O(1)。为防碰撞使用双哈希（两个不同的 base 和 mod）。

定义约定（和你代码一致）：

* 在子问题中把 `a` 长度记为 `L`，哈希数组按 1-based 存：`hs[i]` 表示前 `i` 个字符的哈希（`hs[0]=0`）。因此取子串 `a[l..r]` 的哈希公式为：

```
hash(a[l..r]) = (hs[r] - hs[l-1] * pow[r-l+1]) mod MOD
```

* `rhs` 为 `rev(a)` 的前缀哈希（同样 1-based），这样可以 O(1) 得到任意子串的“反向哈希”。

实现里提供三个工具：

* `query1(l,r)`：返回 `a[l..r]` 的哈希（正向）。
* `query2(l,r)`：返回 `reverse(a[l..r])` 的哈希，内部通过 `rhs` 做索引映射（详见下文）。
* `sht(hash, len)`：把某段哈希左移 `len` 位（即乘以 `base^len`），用于拼接。
* `add(h1,h2)`：把两段哈希相加（拼接后的哈希值）。

---

**为什么 `query2` 要那样映射（索引变换）**
`rhs` 是 `rev(a)` 的前缀哈希数组。如果原串 `a` 的长度为 `L`，原区间 `a[x..y]` 在 `rev(a)` 中对应的位置是 `[L - y + 1, L - x + 1]`（1-based）。你在代码里把 `lx, rx` 映射为：

```cpp
r = n - lx + 1;
l = n - rx + 1;
```

（注意 `n` 在 `Hs` 结构里实际就是 `L`）然后直接按前缀差公式读取 `rhs`。这是正确且常用的做法。

---

**如何比较翻转后的中间段是否为回文（公式解释）**

以 “翻转前缀 `a[1..R]`” 为例，翻转后中间段变为：

```
reversed(a[1..R]) + a[R+1..L]
```

令：

* 左部分的哈希 `A = query2(1, R)`（反向哈希）
* 右部分的哈希 `B = query1(R+1, L)`

拼接哈希 `res1 = shift(A, len(B)) + B`（即把 A 左移 `L-R` 位再加上 B）。

若该结果是回文，则它等于它的反转。反转后应该是：

```
reversed(a[R+1..L]) + a[1..R]
```

其哈希 `res2` 可类似构造：

* `C = query2(R+1, L)`，`D = query1(1, R)`，`res2 = shift(C, R) + D`（由于 `D` 长为 `R`）

若 `res1 == res2`（双哈希相等）说明翻转前缀可以使中间段为回文。
你的代码正是按这个构造在循环中比较 `a1==a2`。

后缀翻转同理（只是把左右换一下，注意拼接位数）。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e5+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;
struct Hs{
    int n;
    string s;
    int mod1=1e9+7,mod2=1e9+9;
    ll b1=127,b2=131;
    // ll b1=10,b2=10;
    vector<ll> hs1,hs2,rhs1,rhs2,v1,v2;
    void init(string str){
        s=str;
        n=(int)s.size();
        hs1.assign(n+10,0);
        hs2.assign(n+10,0);
        rhs1.assign(n+10,0);
        rhs2.assign(n+10,0);
        v1.assign(n+10,1);
        v2.assign(n+10,1);
        for(int i=1;i<=n;i++){
            v1[i]=(v1[i-1]*b1)%mod1;
            v2[i]=(v2[i-1]*b2)%mod2;
        }
        for(int i=0;i<n;i++){
            ll a=(ll)(s[i]-'a'+1);
            hs1[i+1]=(hs1[i]*b1+a)%mod1;
            hs2[i+1]=(hs2[i]*b2+a)%mod2;
        }
        for(int i=0;i<n;i++){
            ll a=(ll)(s[n-i-1]-'a'+1);
            rhs1[i+1]=(rhs1[i]*b1+a)%mod1;
            rhs2[i+1]=(rhs2[i]*b2+a)%mod2;
        }
    }
    PII query1(int l,int r){
        if(l>r)return {-1,-1};
        int len=r-l+1;
        ll ans1=(hs1[r]-(hs1[l-1]*v1[len])%mod1+mod1)%mod1;
        ll ans2=(hs2[r]-(hs2[l-1]*v2[len])%mod2+mod2)%mod2;
        return {ans1,ans2};
    }
    PII query2(int l,int r){
        int lx=l,rx=r;
        r=n-lx+1;
        l=n-rx+1;
        if(l>r)return {-1,-1};
        int len=r-l+1;
        ll ans1=(rhs1[r]-(rhs1[l-1]*v1[len])%mod1+mod1)%mod1;
        ll ans2=(rhs2[r]-(rhs2[l-1]*v2[len])%mod2+mod2)%mod2;
        return {ans1,ans2};
    }
    PII sht(PII a,int len){
        return {(a.first*v1[len])%mod1,(a.second*v2[len])%mod2};
    }
    PII add(PII a,PII b){
        return {(a.first+b.first)%mod1,(a.second+b.second)%mod2};
    }
}hs;

void solve(){
    string s;
    cin>>s;
    int i=0,j=s.size()-1;
    int q=0;
    while(s[i]==s[j]){
        i++;
        j--;
        q++;
    }
    if(i>=j){
        cout<<1<<" "<<s.size()<<'\n';
        return ;
    }
    string a;
    while(i<=j){
        a+=s[i];
        i++;
    }
    hs.init(a);
    int L=a.size();
    //正向反转
    for(int R=2;R<a.size();R++){
        PII a1=hs.add(hs.sht(hs.query2(1,R),L-R),hs.query1(R+1,L));
        PII a2=hs.add(hs.sht(hs.query2(R+1,L),R),hs.query1(1,R));
        if(a1==a2){
            cout<<1+q<<" "<<R+q<<'\n';
            return ;
        }
    }
    //反向反转
    for(int R=2;R<a.size();R++){
        PII a1=hs.add(hs.sht(hs.query1(1,L-R),R),hs.query2(L-R+1,L));
        PII a2=hs.add(hs.sht(hs.query1(L-R+1,L),L-R),hs.query2(1,L-R));
        if(a1==a2){
            cout<<L-R+q+1<<" "<<L+q<<'\n';
            return ;
        }
    }
    cout<<-1<<" "<<-1<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [2022 Hubei Provincial Collegiate Programming Contest  E	Multigate](https://codeforces.com/gym/103729)

### 题目描述

给 $a_1..a_n$（每个 $<2^{30}$）、$b_1..b_n\in\{0,1\}$。递推

$$
x_i=\begin{cases}
x_{i-1}\ \&\ a_i & b_i=0,\\
x_{i-1}\ |\ a_i & b_i=1.
\end{cases}
$$

有 $q$ 个独立询问：给定初始 $x_0=x$ 和最多可以翻转（0↔1）的次数 $k$，问在最多翻转 $k$ 个 $b_i$ 的情况下能得到的最大 $x_n$。

约束：$n,q\le 2\times10^5,\ a_i,x<2^{30}$。

---
### 思路

1. **每一位独立**：位操作（AND/OR）按位独立，可把问题按位分析或把 30 位一起用位掩码处理。
2. **最优翻转位置**：若只允许翻 $k$ 个 `b_i=0`，把它们放到**最右侧的 $k$ 个 `b_i=0`** 上是最优的（下述给出交换证明）。因此每次查询只需找到“把后缀从某位置变为全部 OR”的分界点 `idx`，把前缀按原 b 操作运行，把后缀全部当作 OR 操作。
3. **前缀两种初始值的预计算**：对前缀 `1..i`，预先计算两种情形的结果（把初始值设为全 0 / 全 1）：

   * $X_i$ 表示当初始 $x_0=0$ 时，经过前缀 $1..i$ 的结果（按原 b）。
   * $Y_i$ 表示当初始 $x_0=\underbrace{11\ldots1}_{30}$（所有 1）时，经过前缀 $1..i$ 的结果。
     这两个值都是 30 位整数，分别表示每位在两种初始下的演化结果。
4. **任意初始值 $v$ 通过前缀的结果计算**：设前缀处理到位置 $i$ 的两个预计算值为 $X_i$（对 0）和 $Y_i$（对 1），那么对任意初始 $v$（30 位），前缀结果为（按位合并的常用等式）

$$
\operatorname{pref}(v,i) = (v\ \&\ Y_i)\;|\;(\,\neg v\ \&\ X_i\,).
$$

在 30 位语境下可写成（更方便无符号实现）

$$
\operatorname{pref}(v,i) = X_i \;|\; \bigl(v\ \&\ (Y_i \oplus X_i)\bigr).
$$

（这两式等价，后一式常用于实现，避免直接取按位非带来高位影响。）
5\. **后缀全部 OR 的贡献**：若从 `idx` 开始把该后缀中所有原本为 0 的 $b$ 都翻成 1，那么 `idx` 之后的操作都为 OR，于是后缀对最终结果的贡献是

$$
\operatorname{rep}[idx] = a_{idx}\;|\;a_{idx+1}\;|\;\dots\;|\;a_n.
$$

6. **查询组合**：假设把后缀从 `idx` 开始“变为全 OR”，则答案为

$$
\operatorname{ans} = \operatorname{pref}(v,\,idx-1)\;|\;\operatorname{rep}[idx].
$$

---

**为什么“翻最后 $k$ 个 0 一定优”——交换论证（简洁版）**

考虑两个下标 $i<j$ 且 $b_i=b_j=0$。若某方案翻转了 $i$ 而没翻 $j$，我们把翻转从 $i$ 移到 $j$（即不翻 $i$，改为翻 $j$）。对任意一位单独考虑其在位置 $j$ 的 $a_j$ 位：

* 若该位在 $a_j$ 上为 0，则在位置 $j$ 把 $b_j$ 设成 1 没作用（OR 0 等于原值），因此把翻转放在 $i$ 上也不会使位变好——翻 $i$ 是无益的。
* 若该位在 $a_j$ 上为 1，则把 $b_j$ 设为 1 会在位置 $j$ 将该位变成 1（或保留为 1），而把翻转放在更左侧的 $i$ 上将该位变为 OR 的效果会在更早传播，后续 AND/OR 的组合不可能比在更靠后位置做 OR 更有优势——换句话说，**在更右的位置改为 OR，对最终输出该位的“变为 1”更有利或至少不劣**。
  把这样的交换反复进行，能把任意翻在左侧的 0 移到右侧，最终得到“翻最右的 k 个 0”的方案且结果不变或更优，所以最右 k 个 0 的做法是最优。

（这是典型的交换论证，按位独立逐位考虑即可。）

---


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e5+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;



void solve(){
    int n,q;
    cin>>n>>q;
    int a[n+1],b[n+1];
    int id[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int per[n+10][30][2],rep[n+10];
    for(int j=0;j<30;j++){
        per[0][j][0]=0;
        per[0][j][1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<30;j++){
            if(b[i])per[i][j][0]=per[i-1][j][0]|(a[i]>>j&1);
            else per[i][j][0]=per[i-1][j][0]&(a[i]>>j&1);
            if(b[i])per[i][j][1]=per[i-1][j][1]|(a[i]>>j&1);
            else per[i][j][1]=per[i-1][j][1]&(a[i]>>j&1);    
        }
    }
    int cur=0;
    rep[n+1]=0;
    for(int i=n;i>=1;i--){
        cur|=a[i];
        rep[i]=cur;
    }
    int c0=0;
    id[c0]=n+1;
    for(int i=n;i>=1;i--){
        if(!b[i])c0++;
        id[c0]=i;
    }
    for(int i=1;i<=q;i++){
        int x,k;
        cin>>x>>k;
        if(k>c0)cout<<(rep[1]|x)<<'\n';
        else{
            int ans=0;
            for(int j=0;j<30;j++){
                if(x>>j&1){
                    ans+=per[id[k]-1][j][1]*(1<<j);
                }
                else{
                    ans+=per[id[k]-1][j][0]*(1<<j);
                }
            }
            cout<<(ans|rep[id[k]])<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
// freopen("ZKX.in","r",stdin); 
// freopen("ZKX.out","w",stdout);
// cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
```

## [The 2023 CCPC (Qinhuangdao) Onsite (The 2nd Universal Cup. Stage 9: Qinhuangdao) J - Keyi LIkes Reading](https://codeforces.com/gym/104787/problem/J)

### 题目描述

有 $d\le 13$ 种不同的单词长度（题中 $a_i\in[1,13]$），对于每个长度 $x$，有 `cnt[x]` 个单词，并保证 `cnt[x] ≤ W`。每天如果学某个长度 $k$ 的单词，就必须把词典里**所有长度为 $k$** 的单词当天全部学完。每天学习单词总数不能超过 $W$。问最少天数把所有单词学完。

等价为：有至多 13 个“物品”，第 $i$ 个物品体积为 `cnt[i]`，把这些物品装到容量为 $W$ 的最少箱子里（每个物品不可拆分）。这是经典的“最小箱子数（二进制 dp）”问题，因 $d\le13$ 可以用状态压缩 DP 做到 $O(2^d \cdot d)$。

---

### 思路

* 记出现过的长度为集合 $L$，令 $d=|L|\le 13$。把它们编号为 $0,\dots,d-1$，令重量 $w_i$ 为第 $i$ 类单词数（$1\le w_i\le W$）。总容量为 $W$。

* 状态：用位掩码 $\text{mask}\in[0,2^d)$ 表示已经学完的类别集合。
  定义

  $$
  \text{dp}[\text{mask}]=(D(\text{mask}),\;L(\text{mask}))
  $$

  其中 $D$ = 已用天数（箱子数，$\ge1$），$L$ = 当前第 $D$ 天已学的单词数（$0\le L\le W$）。按字典序最小化对比：$(D_1,L_1)\prec(D_2,L_2)$ 当且仅当 $D_1<D_2$ 或 $D_1=D_2$ 且 $L_1<L_2$。

* 初始化：

  $$
  \text{dp}[0]=(1,0).
  $$

* 转移：对任意 $\text{mask}$ 与任意 $i$（第 $i$ 位在 $\text{mask}$ 中为 0），设 $\text{need}=w_i$，$(d,l)=\text{dp}[\text{mask}]$。则候选状态

  $$
  (d',l')=
  \begin{cases}
  (d,\; l+\text{need}), & l+\text{need}\le W,\\
  (d+1,\; \text{need}), & l+\text{need}>W.
  \end{cases}
  $$

  更新

  $$
  \text{dp}[\text{mask}\cup\{i\}]\leftarrow \min_{\text{lex}}\big(\text{dp}[\text{mask}\cup\{i\}],\ (d',l')\big).
  $$

* 答案：

  $$
  \text{ans}=D\big((1\ll d)-1\big).
  $$

* 正确性（要点）：从 $\text{mask}=0$ 到满集的每一条路径对应一种物品放入顺序（排列）。对同一 $\text{mask}$，若 $(D_1,L_1)\preceq(D_2,L_2)$ 则状态 1 支配状态 2，对所有后续扩展不会更差，因此只保留字典序最小者不丢最优解。可用按 $|\text{mask}|$ 做归纳证明。

* 复杂度：状态数 $2^d$，每状态枚举 $d$ 个 $i$；时间 $O(d\cdot 2^d)$，空间 $O(2^d)$。实作中把 $d$ 降到仅出现过的长度（最多 13）。

* 注意：开新天时应设 $L'=\text{need}$，**不要修改容量 $W$**（这一点是常见错误）。


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e5+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;

void solve(){
    int n,w;
    cin>>n>>w;
    vector<int> a(13,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x-1]++;
    }
    int mask=(1<<13)-1;
    vector<pair<int,int>> dp(mask+10,{1e9,1e9});
    dp[0]={1,0};
    for(int i=0;i<=mask;i++){
        for(int j=0;j<13;j++){
            if(i>>j&1)continue;
            auto [c1,c2]=dp[i];
            if(c2+a[j]>w){
                c1++;
                c2=a[j];
            }
            else{
                c2+=a[j];
            }
            int k=i|(1<<j);
            if(dp[k].first>c1||(dp[k].first==c1&&dp[k].second>c2)){
                dp[k]={c1,c2};
            }
        }
    }
    cout<<dp[mask].first<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [The 2023 CCPC (Qinhuangdao) Onsite (The 2nd Universal Cup. Stage 9: Qinhuangdao) F. Mystery of Prime](https://codeforces.com/gym/104787/problem/F)

### 题目描述

把数组中尽量少的元素修改成任意正整数，使得每一对相邻数之和都是质数；输出最少修改次数。

### 思路
* 改动一个元素只能取三类有代表性的值（把多数情况抽象化即可）：

  1. 改成 `1`；
  2. 改成某个 **偶数**（≥2）；
  3. 改成某个 **奇数 > 1**。
* 只有当**相邻两个位置都保持原值**时，必须检查原值之和是否为质数；其余情况只需判断“是否存在一个属于某类的具体值能使和为质数”。
* 对于同奇偶性的两个固定数 (x,y)，是否存在与之奇偶性相反的 (z) 使 (x+z,y+z) 都为质数，本质等价于“是否存在素数对差为 (x-y)”——这是一般性猜想（Polignac）未证。但在本题数域内可以**暴力验证**出一个安全上界 (L)（经验/暴力检验取 (L=1140)），因此“是否存在”可在有限范围内确定。


1. 预处理质数表 `is_prime[]`，上界取 `MAXP = max(a_i) + L + 5`（题中 `a_i ≤ 1e5`，取 `L=1140`）。
2. 预计算 `canFixed[v][type]`（`v` 为某个固定原值，`type`=1/2/3 对应上面三类）：

   * `type=1`：检查 `is_prime[v+1]`；
   * `type=2`（改为偶）：若 `v` 奇，则枚举 `z=2,4,6,...,L` 检查 `is_prime[v+z]`；若 `v` 偶，则不可能；
   * `type=3`（改为奇>1）：若 `v` 偶，则枚举 `z=3,5,7,...,L` 检查 `is_prime[v+z]`；若 `v` 奇则不可能。
3. 构造类与类的兼容矩阵 `allowedChanged`（基于奇偶性快速判定）：例如 `1+1=2` 合法，`1+even` 可能，`even+odd` 可能，`even+even` / `odd+odd(>1)` 不可能。
4. 4 状态 DP：`dp[i][s]` 表示处理到第 `i` 个且第 `i` 个处于状态 `s`（0=不改，1=改成1，2=改偶，3=改奇>1）的最小修改次数。转移只在相邻状态兼容时允许：

   * `(0,0)`：需 `is_prime[a[i-1]+a[i]]`；
   * `(0, t)`：需 `canFixed[a[i-1]][t]`；
   * `(s, 0)`：需 `canFixed[a[i]][s]`；
   * `(s, t)`（都改）：需 `allowedChanged[s][t]`。
     转移加上当前状态的修改代价（`0` 或 `1`）。
5. 答案为 `min_s dp[n][s]`。


* 预筛素数：`O(MAXP log log MAXP)`。
* 构造 `canFixed`：`O(MAX_A * L)`，在题目范围约为 `1e5 * 1140 ≈ 1.14e8` 次 `is_prime` 访问（C++ 查表，实测可接受）。
* DP：`O(n)`（常数 16 转移）。
* 总体可在竞赛/OJ 时间内通过。


* `L=1140` 不是数学证明的常数，而是通过暴力在 `a_i ≤ 1e5` 范围内验证得到的安全上界；因此算法在题目的输入限制下是严格正确且高效的。
* 特别注意 `1+1=2` 的特殊处理已被包含在状态和兼容矩阵里。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e6+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;

std::vector<int> minp, primes, phi;

void sieve(int n) {
    minp.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    primes.clear();
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            phi[i] = i - 1;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}
bool ck(int x){
    return minp[x]==x;
}
void solve(){
    sieve(N);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(4,1e9));
    dp[1][0]=0;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    for(int i=2;i<=n;i++){
        if(ck(a[i]+a[i-1])){
            dp[i][0]=min(dp[i-1][0],dp[i][0]);
        }
        if(ck(a[i]+1)){
            dp[i][0]=min(dp[i-1][1],dp[i][0]);
        }
        if(a[i]%2){
            dp[i][0]=min(dp[i-1][2],dp[i][0]);
        }
        else{
            dp[i][0]=min(dp[i-1][3],dp[i][0]);
        }


        if(ck(1+a[i-1])){
            dp[i][1]=min(dp[i-1][0]+1,dp[i][1]);
        }
        dp[i][1]=min(dp[i-1][1]+1,dp[i][1]);
        dp[i][1]=min(dp[i-1][2]+1,dp[i][1]);



        if(a[i-1]%2){
            dp[i][2]=min(dp[i-1][0]+1,dp[i][2]);
        }
        else{
            dp[i][3]=min(dp[i-1][0]+1,dp[i][3]);
        }
        dp[i][2]=min(dp[i-1][1]+1,dp[i][2]);
        dp[i][2]=min(dp[i-1][3]+1,dp[i][2]);
        dp[i][3]=min(dp[i-1][2]+1,dp[i][3]);
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]});

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
// freopen("ZKX.in","r",stdin); 
// freopen("ZKX.out","w",stdout);
// cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';

// 验证：对所有 1 <= x,y <= 100000 且 x≡y (mod 2)，存在 1 <= z <= 1140 (z 与 x 奇偶相反)
// 使得 x+z 和 y+z 都为质数。
```


## [2025 Shaanxi ICPC Provincial Contest](https://codeforces.com/gym/105891/problem/D)

### 题目描述

给定初始值 `v` 和 `n` 个操作，每个操作要么是 `+ a_i` （加法），要么是 `* a_i`（乘法）。你可以任意重排这 `n` 个操作的顺序，但必须保持所有“+”操作之间的相对顺序（按你最终选择的规则）和“*”操作之间的相对顺序不变（题中已知并可证明的结论：在最优解里，所有 `+` 的值按从大到小执行，所有 `*` 的值按从大到小执行）。目标是：当依次执行前 1、2、…、n 步时，记录每一步的 `v`，求这些前缀 `v` 的平均值最大化（等价于最大化前缀和 `sum`，最后输出 `sum/n`）。

限制：`n ≤ 30`。

---

### 思路

你的 AC 解就是把“交错选择 + 与 *”的问题转成在 `(i, j)` 网格上从 `(0,0)` 到 `(K,M)` 的动态规划 / 分层 BFS，并在每个格子只保留**非支配的 (now, sum)** 对（即 Pareto 前沿 / 阶梯状点）。下面把关键点逐条总结清楚。

* 可以先把所有 `+` 操作按照加数从大到小排序，把所有 `*` 操作按照乘数从大到小排序。只需决定两组操作如何交错（何时取 `+`，何时取 `*`）。
* 这样任意一个搜索节点只由 `(i, j)` 定位（已用加法数 i，已用乘法数 j），并伴随若干个 `(now, sum)` 状态。

**状态与转移**

* 状态：`dp[i][j]` 保存若干对 `(now, sum)`，表示已经用了 `i` 个加法和 `j` 个乘法后可达到的当前 `v`（now）和到当前为止的前缀和（sum）。
* 转移：

  * 若还可用加法（i < K）：从 `(now,sum)` 生成 `(now + adds[i], sum + now + adds[i])` 推到 `dp[i+1][j]`。
  * 若还可用乘法（j < M）：生成 `(now * muls[j], sum + now * muls[j])` 推到 `dp[i][j+1]`。
* 最终答案是 `max sum` 在 `dp[K][M]` 中，输出 `max_sum / n`。

**剪枝（保持阶梯状 / 非支配集合）**

* 在同一个 `(i,j)`，若存在两对 `(now1,sum1)` 和 `(now2,sum2)` 满足 `now1 >= now2 && sum1 >= sum2`（至少一处严格），那么后者总不会优于前者，故可删去。
* 实现方式（你代码中的 `f` 函数）：

  1. 按 `now` 降序排序（`now` 相同则按 `sum` 降序）。
  2. 从左到右保留那些 `sum` 大于当前记录的最大 `sum` 的点；这样结果就是 `now` 降序而 `sum` 严格上升的阶梯状点（Pareto 前沿）。
* 这个剪枝在实际数据中将大幅压缩每个格子的状态数，使得算法在 `n ≤ 30` 的限制下很快。


* 先读入并把 `J`（加法数组）和 `C`（乘法数组）分别从大到小排序；
* 用三重 `vector` `dp[K+10][M+10]` 存每个格子的候选点；
* 按层（t 从 0 到 n）遍历所有 `i,j`，对 `dp[i][j]` 调 `f` 做剪枝后再向右、向下扩展；
* 在结束时在 `dp[K][M]` 找最大 `sum` 输出 `sum/n`；
* 使用 `long double`（`ld`）保精度。

---


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 25);
const int N=1e6+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;

void f(vector<pair<ld,ld>> &a){
    if(a.empty())return ;
    else{
        sort(a.begin(),a.end(),[&](const pair<ld,ld> &x,const pair<ld,ld> &y){
            if(x.first!=y.first){
                return x.first>y.first;
            }
            return x.second>y.second;
        });
        vector<pair<ld,ld>> r;
        ld sum=-1;
        for(auto [cur,now]:a){
            if(now>sum){
                r.push_back({cur,now});
                sum=now;
            }
        }
        r.swap(a);
    }
}
void solve(){
    ld n;
    ld v;
    cin>>n>>v;
    vector<ld> C,J;
    ld ans=0;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        ld x;
        cin>>x;
        if(c=='*'){        
            C.push_back(x);
        }
        else{
            J.push_back(x);
        }
    }
    sort(J.begin(),J.end(),greater<ld>());
    sort(C.begin(),C.end(),greater<ld>());
    vector<vector<vector<pair<ld,ld>>>> dp(J.size()+10,vector<vector<pair<ld,ld>>>(C.size()+10));
    dp[0][0].push_back({v,0});
    for(int t=0;t<=n;t++){
        for(int i=0;i<=J.size();i++){
            int j=t-i;
            if(j<=C.size()&&j>=0){
                f(dp[i][j]);
                if(i+1<=J.size()){
                    for(auto [cur,now]:dp[i][j]){
                        dp[i+1][j].push_back({cur+J[i],now+cur+J[i]});
                    }
                }
                if(j+1<=C.size()){
                    for(auto [cur,now]:dp[i][j]){
                        dp[i][j+1].push_back({cur*C[j],now+cur*C[j]});
                    }
                }
            }
        }
    }
    for(auto [cur,now]:dp[J.size()][C.size()]){
        ans=max(now,ans);
    }
    cout<<fixed<<setprecision(10);
    cout<<ans/n<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [The 2024 ICPC Asia Kunming Regional Contest (The 3rd Universal Cup. Stage 20: Kunming) C - Coin](https://codeforces.com/gym/105588/problem/C)


### 题目描述

将 $ n $ 个人排成一排，每轮淘汰下标模 $ k $ 余 1 位置上的人。问最后剩下的人一开始位于第几位？

$ 2 \leq n, k \leq 10^{12} $


### 思路

基本思路：从最后一轮开始，逆推胜者在每一轮中的位置。

这样就涉及两个子问题：

- 总轮数是几轮？
- 某一轮位于第 $ x $ 位的人，前一轮位于哪里？


**子问题：总轮数是几轮？**

假设队列中还有 $ x $ 个人，则下一轮会淘汰 $\left\lceil \frac{x}{k} \right\rceil$ 人。

直接模拟是不可行的：当 $ k $ 比较大时，轮数会接近 $ n $。

考虑对 $ k $ 分治：

- 当 $ k \leq \sqrt{n} $ 时：每一轮淘汰的人数大于 $ \sqrt{n} $ 人，因此总轮数不会超过 $ \sqrt{n} $ 轮，可以直接模拟。
- 当 $ k > \sqrt{n} $ 时：注意到 $\left\lceil \frac{x}{k} \right\rceil$ 的变化不会超过 $ \sqrt{n} $ 次。可以计算这个值在多少轮之后会变化，$ O(1) $ 的模拟变化之前的轮次。

因此，我们可以在 $ O(\sqrt{n}) $ 的时间内计算出轮数。


**子问题：某一轮位于第 $ x $ 位的人，前一轮位于哪里？**

考虑所有位置小于等于 $ x $ 的人，将这些人按每 $ k-1 $ 个人分组。每有一组，就意味着上一轮有一个编号比胜者小的人被淘汰了。

因此，某一轮位于第 $ x $ 位的人，前一轮位于第 $ x + \left\lceil \frac{x}{k-1} \right\rceil $ 位。

但是，总轮数可能接近 $ n $，还需要对 $ k $ 分治：

- 当 $ k \leq \sqrt{n} $ 时：总轮数不会超过 $ \sqrt{n} $ 轮，可以直接模拟。
- 当 $ k > \sqrt{n} $ 时：注意到 $\left\lceil \frac{x}{k-1} \right\rceil$ 的变化次数同样是 $ O(\sqrt{n}) $ 的。依然可以计算这个值在多少轮之后会变化，$ O(1) $ 的模拟变化之前的轮次。

因此，我们可以在 $ O(\sqrt{n}) $ 的时间内逆推出胜者一开始的位置。
好 — 我把**代码中那些关键数学推导**写得更严谨、逐步推导清楚（包含边界 / 整数运算的处理和为什么 `cnt--`、为什么取 `t` 的形式）。内容分块：逆推公式、正向批量跳过（计算 `t`）的推导、逆推批量跳过（计算 `t`）的推导、以及若干实现细节与复杂度证明。

**1. 逆推公式的严格推导（`prev(x) = x + ⌈x/(k-1)⌉`）**

令当前轮剩下 (x) 人（编号从 (1) 到 (x)）。上一轮中共有一些被淘汰者插在幸存者之间，使得上一轮的人数是某个 (X\ge x)。我们把上一轮的序列看作 “幸存者 + 被淘汰者混排”，但幸存者相对顺序不变。

每 (k) 人中有 1 个被淘汰（即位置满足下标 mod (k \equiv 1) 的人被删），故在上一轮中，对任意一段连续的 (k) 个原始位置，会有 1 个被删，剩 (k-1) 个幸存。于是在上一轮，把幸存者按每 (k-1) 个一组来划分，组数为 (\big\lceil \frac{x}{k-1}\big\rceil)。每组之间（以及组前后）会插入被淘汰的位置，总共被插入的被淘汰者数就是这组数（形式上可用鸽巢类比证明）。因此上一轮中，使得第 (x) 个幸存者在上一轮中的原始下标向右移动了正好 (\big\lceil \frac{x}{k-1}\big\rceil) 个被淘汰者的位置，即
$$
\boxed{\ \text{prev}(x)=x+\left\lceil\frac{x}{k-1}\right\rceil\ }
$$
（这是组合计数的直接推导；也可把映射写成单调映射证明一一对应。）

在整数运算中用整型写为 `x + (x + k - 2) / (k - 1)`，因为 $(\lceil x/(k-1)\rceil = \frac{x + (k-1) - 1}{k-1} = \frac{x + k - 2}{k-1})$。

**2. 正向计算轮数时批量跳过的推导（`d = ⌈now/k⌉`，求 `t`）**

我们要正向模拟人数从 `now` 逐轮减少：每轮淘汰 $(\lceil now/k\rceil)$ 人。记当前的淘汰数为
$$
d=\left\lceil\frac{\text{now} }{k}\right\rceil.
$$
当 (d) 在若干轮内保持不变时，可以把这些轮合并一次性做：若在接下来 (t) 轮内淘汰人数都等于 (d)，那么人数变为
$$
\text{now}' = \text{now} - t\cdot d.
$$
我们想取最大的 (t) 使得在这 (t) 輪后 (d) 仍等于原来的值（或更常用的批量跳到 (d) 改变的第一步），根据 (d=\lceil now/k\rceil) 的定义有：

$$
(d-1)k < \text{now} \le d k.
$$
当 `now` 下降到 (\le (d-1)k) 时，(\lceil now/k\rceil) 将变为 (\le d-1)，即淘汰人数会减少。于是我们要找最小的正整数 (t) 使得
$$
\text{now} - t d \le (d-1)k.
$$
解得
$$
t \ge \frac{\text{now} - (d-1)k}{d},
$$
因此取最小整数满足上式，即
$$
\boxed{\ t=\left\lceil\frac{\text{now}-(d-1)k}{d}\right\rceil\ }.
$$
这正是代码里 `t = ((now-(d-1)*k) + d - 1) / d` 的含义。我们用这个 (t) 把 `now` 和 `cnt` 一次性更新为 `now -= t*d; cnt += t;`，这把所有 (d) 不变的轮次合并了。如此每次 `d` 变化一次便做一次合并，整体循环次数是 `d` 值变化次数（(O(\sqrt n))），而不是每一轮都做一次。

**关于 `cnt--`**：代码里批量循环写作 `while (now) { ...; cnt += t; } cnt--;`。原因是：

* 若把循环条件写为 `while(now > 1)`，逻辑会和第一分支一致，但在合并跳跃写法中更方便以 `while(now)` 来处理（允许到 `now=0`）；
* 当 `now` 减到 1 时，下一次仍会计算 `d=1`，并再做一次 (t=1) 的操作把 `now` 变为 0，因此 `cnt` 会多加 1。所以最后需要把多加的 1 去掉，得到「到 `now==1` 时的轮数」。所以 `cnt--` 是修正边界，保证最终 `cnt` 表示“从初始 (n) 到只剩 1 人所需要的轮数”。

**3. 逆推阶段（由 `ans` 从 1 逆推到初始位置）批量跳过的推导**

逆推公式是 `ans := ans + ceil(ans/(k-1))` 每一步。设当前 `ans`，定义
$$
\delta = \left\lceil\frac{\text{ans} }{k-1}\right\rceil
$$
为本次逆推要增加的量。如果连续应用多次且 (\delta) 不变，则做 (s) 次后的值为
$$
\text{ans}'=\text{ans}+s\cdot\delta.
$$
我们希望找到在 (\delta) 保持不变的最大次数 (s)。(\delta) 的定义等价为
$$
(\delta-1)(k-1) < \text{ans} \le \delta (k-1).
$$
要使 (\delta) 仍然等于原值，必须有 (\text{ans}' \le \delta(k-1))，即
$$
\text{ans} + s\delta \le \delta(k-1) \quad\Longrightarrow\quad s \le \frac{\delta(k-1) - \text{ans} }{\delta}.
$$

令 (s_{\max} = \left\lfloor \dfrac{\delta(k-1) - \text{ans} }{\delta} \right\rfloor) 为能保持 (\delta) 不变的最多步数。那么如果想「跳到 (\delta) 改变的第一步」，应执行 (s_{\max}+1) 步。代码中选择执行


$$
t = s_{\max} + 1 = \left\lfloor \frac{\delta(k-1) - \text{ans} }{\delta}\right\rfloor + 1,
$$
并在循环里用 `min(t, cnt)` 限制为剩余的轮数 `cnt`。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 35);
const int N=1e6+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;



void solve(){
    ll n,k;
    cin>>n>>k;
    if(sqrt(n)>=k){
        ll now=n;
        ll cnt=0;
        while(now>1){
            now-=(now+k-1)/k;
            cnt++;
        }
        ll ans=1;
        while(cnt){
            cnt--;
            ans=ans+(ans+k-2)/(k-1);
        }
        cout<<ans<<'\n';
    }
    else{
        ll now=n,cnt=0;
        while(now){
            ll d=(now+k-1)/k;
            ll t=((now-(d-1)*k)+d-1)/d;
            now-=t*d;
            cnt+=t;
        }
        cnt--;

        ll ans=1;
        while(cnt){
            ll dt=(ans+k-2)/(k-1);
            ll t=(dt*(k-1)-ans)/dt+1;
            ans+=min(t,cnt)*dt;
            cnt-=min(t,cnt);
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```





## [The 2024 ICPC Asia Kunming Regional Contest (The 3rd Universal Cup. Stage 20: Kunming) E - Extracting Weights](https://codeforces.com/gym/105588/problem/E)

### 题目描述

给定一棵 $n$ 个节点的树$(1 \le n \le 250)$，每个节点有一个权值 $w_i$。
已知根节点 $1$ 的权值为 $w_1 = 0$。

你可以提出若干询问，每个询问为：

选取两个点 $(u, v)$，若它们之间的简单路径长度为 $k$，则询问结果为路径上所有节点权值的异或和：
$$
Q(u,v) = w_{x_1} \oplus w_{x_2} \oplus \cdots \oplus w_{x_{k+1} }
$$
其中 $(x_1, x_2, \dots, x_{k+1})$  为从 (u) 到 (v) 的路径。

已知 $ w_1 = 0 $，要求判断是否能够通过这些询问求出所有节点的权值。
若可以，需要构造一种询问方案并给出还原过程。

---

### 思路
**1. 异或方程建模**

每一次询问对应于一个关于所有 $ w_i $ 的异或方程：
$$
\bigoplus_{x \in \text{path}(u,v)} w_x = Q(u,v)
$$
由于异或运算在 $(\mathbb{F}_2)$ 上等价于加法，因此可以将每个询问表示为一个 0-1 向量方程。
最终，我们得到一个关于 $(w_2, w_3, \dots, w_n)$ 的线性方程组。


**2. 构造方程组**

枚举所有点对 $(u,v)$，若路径长度为 $k$，则生成对应的方程。
对每个方程构造长度 $n-1$ 的 bitset：

$$
b_i[j] =
\begin{cases}
1 & \text{若节点 } (j+1) \text{ 在路径上}\
0 & \text{否则}
\end{cases}
$$

这些 bitset 构成一个矩阵 $A$，每一行对应一个询问。


**3. 判断可解性**

* 使用 **高斯消元**$GF(2)$ 下判断矩阵 $A$ 是否满秩,秩为 $n-1$。
* 若满秩，则存在 $n-1$ 个线性无关方程，可解出所有非根节点权值。

注意：
不要先假设 $w_1=0$ 再解 $n-1$ 个方程，而是将 $w_1=0$ 视为一个方程插入系统中。
因为在某些情况下，根节点约束也可能通过其他方程推导出来。


1. **DFS**：预处理每个节点的父节点 `f[x]` 和深度 `dep[x]`。
2. **path(x, y)**：返回两点间的节点路径。
3. **方程生成**：

   * 枚举所有点对 $(i, j)$，若路径长度为 $k$，生成对应的 bitset。
4. **高斯消元**：

   * 在所有 bitset 上进行异或消元，判断是否能得到 $n-1$ 个线性无关方程。
   * 若不能，输出 `NO`。
5. **恢复过程**：

   * 输出所有询问（`?` 开头），等待交互返回路径异或值。
   * 将这些返回值代入线性方程组，再次执行高斯消元求得 (w_i)。
   * 最后输出结果（`!` 开头）。

* 枚举所有点对： $O(n^2)$
* 求路径长度： $O(n)$
* 构造方程： $O(n^3)$
* 高斯消元bitset 优化：
  $$
  O\left(\frac{n^4}{64} + n^3\right)
  $$

在 $( n \le 250 )$ 时可轻松通过。

**最终结论：**
$$
\boxed{\text{复杂度 } O(n^4 / 64 + n^3), \quad \text{核心思想：路径异或 = 线性方程组。} }
$$

---


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 35);
const int N=1e6+10;
const int M=2e5+10;
// const int mod = 1000000007;
const int mod = 998244353;

vector<int> dep(500,0),f(500,0);
vector<vector<int>> e(500);
void dfs(int x,int fa){
    for(auto y:e[x]){
        if(y==fa)continue;
        f[y]=x;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
vector<int> path(int x,int y){
    vector<int> res;
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]>dep[y]){
        res.push_back(x);
        x=f[x];
    }
    while(x!=y){
        res.push_back(x);
        res.push_back(y);
        x=f[x];
        y=f[y];
    }
    res.push_back(x);
    return res;
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(1,0);
    vector<bitset<300>> p,np;
    vector<pair<int,int>> g;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<int> res=path(i,j);
            if(res.size()==k+1){
                bitset<300> t;
                for(auto x:res){
                    if(x>1)t.set(x-2);
                }
                g.push_back({i,j});
                p.push_back(t);
            }
        }
    }

    for(int i=0;i<n-1;i++){
        int Z=-1;
        for(int j=i;j<p.size();j++){
            if(p[j][i]){
                Z=j;
                break;
            }
        }
        if(Z==-1){
            cout<<"NO"<<endl;
            return ;
        }
        if(Z!=i){
            swap(p[Z],p[i]);
            swap(g[Z],g[i]);
        }
        for(int j=i+1;j<p.size();j++){
            if(p[j][i])p[j]^=p[i];
        }
    }

    cout<<"YES"<<endl;
    cout<<"?"<<" "<<n-1<<" ";
    for(int i=0;i<n-1;i++){
        cout<<g[i].first<<" "<<g[i].second<<" ";
    }
    cout<<endl;
    vector<int> ans(n);
    for(int i=0;i<n-1;i++){
        cin>>ans[i];
    }
    for(int i=0;i<n-1;i++){
        vector<int> res=path(g[i].first,g[i].second);
        bitset<300> t;
        for(auto x:res){
            if(x>1)t.set(x-2);
        }
        np.push_back(t);
    }

    for(int i=0;i<n-1;i++){
        int Z=-1;
        for(int j=i;j<np.size();j++){
            if(np[j][i]){
                Z=j;
                break;
            }
        }
        if(Z!=i){
            swap(np[Z],np[i]);
            swap(ans[Z],ans[i]);
        }
        for(int j=0;j<n-1;j++){
            if(j!=i&&np[j][i]){
                ans[j]^=ans[i];
                np[j]^=np[i];
            }
            
        }
    }
    cout<<"!"<<" ";
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<" "; 
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    // cin>>_;
    _=1;
    while(_--){
        solve();
    }
    return 0;
}
```


## [The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)](https://codeforces.com/gym/104976/problem/F)

### 题目描述
给定一棵 n 个点的无根树，每个点的点权互不相同。q 次询问，每次询问 x 点的 k-邻域内所有点的点权的 mex。


### 思路

把点按点权从小到大排序；对于每个前缀维护这个点集合的直径两端 `(L[i],R[i])`（增量更新只需检查新点与当前直径两端的距离）；每个查询对 mid 做二分：判断权 ≤ mid 的点是否都在 x 的 k-邻域内，等价于判断 `max(dist(x, L[mid]), dist(x, R[mid])) ≤ k`（若成立说明前缀内所有点到 x 距离 ≤ k）。用 欧拉序+ST表做 O(1) LCA / 带权距离查询，从而总复杂度 (O((n+q)\log n))。

---


1. **读入 / 排序**

   * 读 `w[1..n]`，构造 `r[]` 按 `w` 升序排列（`r[i]` 表示第 i 小权的节点编号）。

2. **O(1) LCA + 带权距离**

   * 做 Euler Tour（记录 `d[]` 序列长度 `m = 2*n-1`，记录每个节点在 `d[]` 中的第一次出现 `dfn[]`）。
   * 维护两个量：`depth`（按边数的层数，用于 RMQ 比较），`f[]`（从根到节点的权和，用于计算带权距离）。
   * 建稀疏表 `st[k][i]` 存区间最小深度节点（RMQ），查询 LCA 即在 `dfn[u]..dfn[v]` 区间取深度最小的点，时间 O(1)。
   * 带权距离：`dist(u,v) = f[u] + f[v] - 2 * f[lca(u,v)]`。

3. **前缀直径增量维护**

   * 令前缀 `S_{i-1}` 的直径端点为 `(L,R)`，当前直径长度 `D = dist(L,R)`。加入新点 `v` 后，只需计算 `dL = dist(L,v)` 与 `dR = dist(R,v)`，若 `max(dL,dR) > D` 则更新直径为产生最大值的那一对，否则不变。
   * 证明：集合中离 `v` 最远的点必是 `(L` 或 `R)` 中之一（详见前面证明），因此只需检查二者。

4. **mex 的处理（前缀到 mid 的 mex）**

   * 按前缀依次把权值 `w[r[i]]` 标记为存在，用一个计数结构（`unordered_set`/`vector<bool>`/`map`）维护当前最小缺失值 `cur`，并记录 `ans[i] = cur`（即前缀 `i` 的 mex）。
   * 在查询二分后输出 `ans[res]`（res 为满足条件的最大 mid）。

5. **查询过程**

   * 每个查询对 `mid` 做二分（范围 `1..n`），用 O(1) 的 `dist(x, L[mid])`、`dist(x, R[mid])` 检查条件，因此每次查询 `O(\log n)`。

6. **不要把加权距离当作「深度」去比较**

   * `depth` 用边数（整数）用于 RMQ 的比较；`dep`（我代码叫 `f` 或 `distw`）存加权距离，两者必须区分。你修复后把 `depth` 用于 RMQ，比对 `depth[a] < depth[b]`，这样 LCA 才正确。

7. **稀疏表维度与边界严格按欧拉序长度 `m = 2*n-1` 设置**

   * 预先 `K = __lg(m) + 1`，`Mi` 列数至少 `m+1`，稀疏表构造循环索引 `i + (1<<k) -1 <= m`。你已用正确边界避免越界/错误结果。

8. **前缀直径更新必须与当前直径比较**

   * 只有 `max(dL,dR) > curDist` 才更新，否则保持原端点。你已把这步写清楚避免误更新。

9. **还要记录第一次出现位置 `dfn[]`**

   * `dfn[x]` 放 Euler 序列中第一次出现的索引，RMQ 区间为 `[dfn[u], dfn[v]]`。你按此实现并使用 1-based 索引，整体一致。

10. **迭代 DFS/递归深度注意**

   * 你采用递归但谨慎处理（若 n 很大可改迭代以避栈溢出）。你当前实现能 AC，说明规模受控或栈足够。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=1e6+10;
const int M=5e5+10;
const int mod = 1000000007;
// const int mod = 998244353;



struct st_LCA{
    int n,K,m,cnt;
    vector<int> dfn,dep,d;
    vector<ll> f;
    vector<vector<PII>> e;
    vector<vector<int>> Mi;
    vector<int> lg;
    st_LCA(int _){
        cnt=0;
        n=_;
        m=2*n-1;
        K=__lg(m) + 1;
        e.resize(n+1);
        f.resize(n+1);
        dep.resize(n+1,0);
        dfn.resize(n+1);
        d.resize(n*2+1);
        Mi.resize(K,vector<int>(m+1,0));
        lg.assign(m + 1, 0);
    }
    void add(int u,int v,int l){
        e[u].push_back({v,l});
        e[v].push_back({u,l});
    }
    void dfs(int x,int fa){
        d[++cnt]=x;//求欧拉序
        dfn[x]=cnt;//记录每个点第一次出现
        for(auto [y,l]:e[x]){
            if(y==fa){
                continue;
            }
            f[y]=f[x]+l;//算到根的距离
            dep[y]=dep[x]+1;//节点的高度
            dfs(y,x);
            d[++cnt]=x;
        }
    }
    void init(){
        lg[0] = -1;
        for (int i = 1; i <= m; ++i) lg[i] = lg[i >> 1] + 1;
        for (int i = 1; i <= m; ++i) Mi[0][i] = d[i];
        for (int k = 1; k < K; ++k) {
            int len = 1 << (k - 1);
            for (int i = 1; i + (1 << k) - 1 <= m; ++i) {
                int a = Mi[k-1][i];
                int b = Mi[k-1][i + len];
                Mi[k][i] = (dep[a] < dep[b]) ? a : b;//ST表记录欧拉序区间深度最小点的id
            }
        }
    }
    void work(int root=1){
        dfs(root,0);
        init();
    }
    int lca(int x,int y){
        int l = dfn[x], r = dfn[y];
        if (l > r) swap(l, r);
        int len = r - l + 1;
        int k = lg[len];
        int a = Mi[k][l];
        int b = Mi[k][r - (1 << k) + 1];
        return (dep[a] < dep[b]) ? a : b;
    }
    ll dis(int x,int y){
        return f[x]+f[y]-2*f[lca(x,y)];//计算两点的距离
    }
};
void solve(){
    int n,q;
    cin>>n>>q;
    int w[n+10];
    vector<int> r(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>w[i];
        r[i]=i;
    }
    st_LCA a(n);
    for(int i=1;i<n;i++){
        int u,v;
        ll l;
        cin>>u>>v>>l;
        a.add(u,v,l);
    }
    a.work(1);
    sort(r.begin()+1,r.end(),[&](int x,int y){
        return w[x]<w[y];
    });
    map<int,int> v;
    vector<int> ans(n+10,0);
    int cur=0;
    for(int i=1;i<=n;i++){//预处理前缀的mex
        v[w[r[i]]]++;
        while(v[cur]){
            cur++;
        }
        ans[i]=cur;
    }
    int ld[n+10],rd[n+10];
    ld[1]=rd[1]=r[1];
    ld[2]=r[1];
    rd[2]=r[2];
    for(int i=3;i<=n;i++){
        int x=r[i];
        ll L=a.dis(ld[i-1],x);
        ll R=a.dis(rd[i-1],x);
        ll Y=a.dis(ld[i-1],rd[i-1]);
        if(max(L,R)>Y){//维护前缀直径的两个端点，就是前缀的最远点
            if(L>R){
                rd[i]=x;
                ld[i]=ld[i-1];
            }
            else if(L<R){
                ld[i]=x;
                rd[i]=rd[i-1];
            }
        }
        else{
            rd[i]=rd[i-1];
            ld[i]=ld[i-1];
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        ll k;
        cin>>x>>k;
        int l=1,r=n,res=0;
        while(l<=r){//mex具有单调性，二分能取到有效的最远位置
            int mid=l+r>>1;
            if(max(a.dis(x,ld[mid]),a.dis(x,rd[mid]))<=k){//满足到最远点的距离小于等于k，则所有前缀的距离都小于等于k
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans[res]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    // cin>>_;
    _=1;
    while(_--){
        solve();
    }
    return 0;
}
```

## [The 2023 ICPC Asia Hangzhou Regional Contest B. Festival Decorating](https://codeforces.com/gym/104976/problem/B)

### 题目描述

有 $n$ 盏路灯，编号从 $1$ 到 $n$。第 $i$ 盏路灯位于坐标 `x_i`，颜色为 `c_i`。坐标互不相同，所有坐标与颜色的取值范围均不超过 `250000`。有 `q` 个询问，每个询问给出一个距离 `d`。对于每个询问，要求找出最小编号的路灯 `u`，使得在坐标 `x_u + d` 处存在一盏路灯且该路灯的颜色 **不等于** `c_u`。如果不存在这样的 `u`，输出 `0`。

输入：`n, q`，接着 `n` 行每行 `x_i, c_i`，再接 `q` 行每行一个 `d`。  
输出：对每个 `d` 输出最小满足条件的路灯编号或 `0`。

---

### 思路
利用位集（`bitset`）并行处理多个 `d`：  
- 用位集 `all` 标记所有有灯的坐标。  
- 对于某盏灯 `u`，把与其同色的位置从 `all` 中去掉得到 `cur`（表示存在**不同颜色**的坐标集合）。  
- 右移 `cur` `x[u]` 位：`cur >> x[u]` 的索引 `d` 表示是否存在在 `x[u] + d` 的不同颜色的灯。  
- 把待回答的所有 `d` 也放进一个位集 `ques`，通过 `ques & (cur >> x[u])` 一次性得到当前灯能满足的所有未回答的 `d`。

**保证最小编号**
按灯编号从小到大枚举 `u`：第一次为某个 `d` 找到满足的 `u` 时就记录并从 `ques` 中清除该 `d`，因此记录的编号一定是最小编号。

**大/小（Heavy–Light）优化**
- 若颜色出现次数 ≤ `B`（轻色），逐个坐标 `cur.reset(pos)`，复杂度与出现次数线性相关。  
- 若颜色出现次数 > `B`（重色），预先把该颜色的位置做成位集 `ext[color]`，直接用位运算 `cur = all ^ ext[color]`（或 `cur &= ~ext[color]`）并行处理。  
阈值 `B` 通常取 `~500` 或接近 `sqrt(n)`。

- 使用 `bitset<N>` 表示坐标集合和查询集合 `p`。  
- `all.set(x[i])` 标记所有灯的位置；`v[color]` 存该颜色的所有坐标；若 `v[color].size() > B` 则为重色，把坐标做成 `ext`（`e[t]`）。  
- 读取所有查询 `d`，`p.set(d)` 表示该距离尚未有答案。  
- 对每个灯 `i`：
  1. `cur = all`；
  2. 若轻色：对 `v[c[i]]` 中每个坐标 `cur.reset(pos)`；若重色：`cur ^= e[ zd[c[i]] ]`；  
  3. `tr = p & (cur >> x[i])` —— 当前灯能回答且尚未回答的所有 `d`；  
  4. 遍历 `tr` 中的 1 位（用 `_Find_first/_Find_next`），记录 `ans[d] = i` 并 `p.reset(d)`。  
- 最后按输入顺序输出 `ans[k[i]]`。

**复杂度**
- 位运算（拷贝/右移/按位与）代价大约为 `O(N / w)`（`w` 为机器字长），理论最坏约 `O(n * N / w)`（写成 `O(n^2 / w)`）。  
- 大/小优化在实际数据中大幅减少常数，轻色使用点删除、重色使用位运算，整体能在比赛数据下通过。

**边界与实现细节**
- `ans` 应按距离下标存储，大小为 `N`（例如 `250005`），否则会越界。  
- 仔细处理全局结构的初始化/重置（尤其当支持多组测试时）。  
- `_Find_first/_Find_next` 是 `libstdc++` 的扩展接口，能高效遍历 `bitset` 的 1 位。  
- `B` 可根据实际测试微调（如 `500`、`505`、或 `sqrt(n)`）。

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
// const int N=1e6+10;
// const int M=5e5+10;
const int mod = 1000000007;
// const int mod = 998244353;
const int N=250005,B=500;
int x[N],c[N],zd[N],k[N];
bitset<N> a,e[B],p;
vector<int> v[N];
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c[i];
        a.set(x[i]);//bitset 标记灯的位置
        v[c[i]].push_back(x[i]);//颜色存储坐标
    }
    int t=0;
    for(int i=1;i<=n;i++){
        if((int)v[i].size()>B){//根号分治，将颜色的数量大小进行分类
            zd[i]=t;
            for(auto x:v[i]){
                e[t].set(x);
            }
            t++;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>k[i];
        p.set(k[i]);//查询离线下来，把所有的d_{i}标记在bitset上面
    }
    vector<int> ans(N,0);
    for(int i=1;i<=n;i++){
        bitset<N> cur=a,tr=p;
        if(v[c[i]].size()<=B){//先将同色的位置都去掉，根据颜色的数量 根号分类
            for(auto x:v[c[i]]){
                cur.reset(x);
            }
        }else{  
            cur^=e[zd[c[i]]];
        }
        tr&=(cur>>x[i]);//对于当前的编号的灯左移之后，与上那些还没有回答的距离位置，就是这些的答案
        for(int x=tr._Find_first();x!=tr.size();x=tr._Find_next(x)){
            ans[x]=i;
            p.reset(x);
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[k[i]]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [The 2024 International Collegiate Programming Contest in Hubei Province, China K - Points on the Number Axis B](https://codeforces.com/gym/105139/problem/K)

### 题目描述

有 $n$ 个有序的数，每次随机选择两个相邻的数 $a, b$，将它们删除并加入 $\frac{a+b}{2}$，求最后剩下的数的期望。
$1 \leq n \leq 10^6$

---

### 思路

**推导：由递推式推出 $ w_{n,i} $ 的通项公式**
打表找系数的规律得到递归式
$$
    [w_{1,1}]=[1]
$$
$$
    [w_{2,1},w_{2,2}]=[\frac{1}{2},\frac{1}{2}]
$$
$$
    [w_{3,1},w_{3,2},w_{3,3}]=[\frac{3}{4},\frac{1}{2},\frac{3}{4}]
$$
$$
    [w_{4,1},w_{4,2},w_{4,3},w_{4,4}]=[\frac{15}{8},\frac{9}{8},\frac{9}{8},\frac{15}{8}]
$$
$$
        .......
$$

已知递推关系：
$$
w_{1,1}=1,\qquad
w_{n,i}=\frac{2i-3}{2}\,w_{n-1,i-1}+\frac{2n-2i-1}{2}\,w_{n-1,i}.
$$



**第一步. 归一化以消去线性因子**

观察递推中两个系数：
$$
\frac{2i-3}{2},\quad \frac{2n-2i-1}{2},
$$
它们在不断递推时会累乘，显然会生成奇数的乘积（双阶乘）。  
为了将递推转化为更干净的形式（类似帕斯卡递推），我们引入新的归一化量：

$$
u_{n,i}:=\;w_{n,i}\;\cdot\;\frac{2^{\,n-1}}{(2i-3)!!\,(2n-2i-1)!!},
$$
其中
$$
(2k-1)!! = (2k-1)(2k-3)\cdots1,\quad (-1)!!=1.
$$

这样选是因为双阶乘部分能抵消递推中不断出现的奇数因子，  
而 $2^{n-1}$ 抵消分母中的幂次 $2$。


**第二步. 用 $ u_{n,i} $ 改写递推式**

由定义：
$$
w_{n,i}=u_{n,i}\cdot\frac{(2i-3)!!\,(2n-2i-1)!!}{2^{\,n-1}}.
$$

把 $w_{n-1,i-1}$ 与 $w_{n-1,i}$ 也改写成 $u$ 的形式：

$$
\begin{aligned}
w_{n-1,i-1}=u_{n-1,i-1}\cdot\frac{(2i-5)!!\,(2n-2i-1)!!}{2^{\,n-2}},
w_{n-1,i}=u_{n-1,i}\cdot\frac{(2i-3)!!\,(2n-2i-3)!!}{2^{\,n-2}}.
\end{aligned}
$$

代入原递推式：
$$
\begin{aligned}
w_{n,i}
&=\frac{2i-3}{2}\,u_{n-1,i-1}\frac{(2i-5)!!(2n-2i-1)!!}{2^{\,n-2}}
+\frac{2n-2i-1}{2}\,u_{n-1,i}\frac{(2i-3)!!(2n-2i-3)!!}{2^{\,n-2}}.
\end{aligned}
$$

现在两边同乘 $\dfrac{2^{\,n-1}}{(2i-3)!!(2n-2i-1)!!}$，得到：

$$
\begin{aligned}
u_{n,i}
&=\frac{2^{\,n-1}}{(2i-3)!!(2n-2i-1)!!}\Bigg[
\frac{2i-3}{2}\,u_{n-1,i-1}\frac{(2i-5)!!(2n-2i-1)!!}{2^{\,n-2}}\\
&\quad+\frac{2n-2i-1}{2}\,u_{n-1,i}\frac{(2i-3)!!(2n-2i-3)!!}{2^{\,n-2}}
\Bigg].
\end{aligned}
$$

逐项化简（注意 $\frac{2^{n-1}}{2^{n-2}}=2$）：

- 第一项：
  $$
  \frac{2^{\,n-1}}{(2i-3)!!(2n-2i-1)!!}\cdot
  \frac{2i-3}{2}\cdot\frac{(2i-5)!!(2n-2i-1)!!}{2^{\,n-2}}
  =u_{n-1,i-1}.
  $$
  （因为 $(2i-3)(2i-5)!!=(2i-3)!!$，其余全部抵消）

- 第二项：
  $$
  \frac{2^{\,n-1}}{(2i-3)!!(2n-2i-1)!!}\cdot
  \frac{2n-2i-1}{2}\cdot\frac{(2i-3)!!(2n-2i-3)!!}{2^{\,n-2}}
  =u_{n-1,i}.
  $$
  （同理 $(2n-2i-1)(2n-2i-3)!!=(2n-2i-1)!!$ 抵消）

于是得到极简的递推关系：

$$
\boxed{u_{n,i}=u_{n-1,i-1}+u_{n-1,i}}.
$$


**第三步. 解出 $ u_{n,i} $**

上式正是帕斯卡三角的递推公式。  
配合初值：

$$
u_{1,1}=w_{1,1}\frac{2^{0}}{(-1)!!(-1)!!}=1,
\quad
u_{n,0}=u_{n,n+1}=0,
$$

可得：

$$
\boxed{u_{n,i}=\binom{n-1}{i-1}}.
$$

（可以用归纳法证明：利用帕斯卡恒等式。）


**第四步. 将 $ u_{n,i} $ 还原为 $ w_{n,i} $**

由定义：
$$
w_{n,i}=u_{n,i}\cdot\frac{(2i-3)!!\,(2n-2i-1)!!}{2^{\,n-1}}.
$$

代入 $u_{n,i}=\binom{n-1}{i-1}$，得到通项：

$$
\boxed{
w_{n,i}=\binom{n-1}{i-1}\,\frac{(2i-3)!!\,(2n-2i-1)!!}{2^{\,n-1}}.
}
$$


**第五步. 将双阶乘化为普通阶乘**

用恒等式：
$$
(2k-1)!!=\frac{(2k)!}{2^k k!},
$$
并设 $a=i-1,\;b=n-i$，得：

$$
\begin{aligned}
w_{n,i}
&=\frac{(n-1)!}{a!\,b!}\cdot
\frac{(2a)!}{2^{a}a!}\cdot
\frac{(2b)!}{2^{b}b!}\cdot\frac{1}{2^{\,n-1}}
&=\boxed{
\frac{(n-1)!\,(2(i-1))!\,(2(n-i))!}{2^{\,2n-2}\,((i-1)!)^2\,((n-i)!)^2}.
}
\end{aligned}
$$

$$
\begin{aligned}
E = \frac{\sum_{i=1}^{n}w_{n,i}*a[i]}{(n-1)!} =\sum_{i=1}^{n}\left (   \frac{\binom{2(i-1)}{i-1}\cdot \binom{2(n-i)}{n-i}  }{2^{2n-2} } \cdot a[i]\right ) 
\end{aligned}
$$

---

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=1e6+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
ll fct[M],invf[M];
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=a*res%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inv(ll x){
    return qmi(x,mod-2)%mod;
}
void init(){
    fct[0]=1;
    for(int i=1;i<=2000000;i++){
        fct[i]=(fct[i-1]*i)%mod;
    }
    invf[2000000]=inv(fct[2000000]);
    for(int i=2000000-1;i>=0;i--){
        invf[i]=(invf[i+1]*(i+1))%mod;
    }
}
ll C(int n,int m){
    if(n==0||m==0)return 1;
    return ((fct[n]*invf[m])%mod*invf[n-m])%mod;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    vector<ll> w(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init();
    ll E=0;
    for(int i=1;i<=n;i++){
        w[i]=(C(2*(i-1),i-1)*C(2*(n-i),n-i))%mod;
        w[i]=(w[i]*inv(qmi(2,2*n-2)))%mod;
        w[i]=(w[i]*a[i])%mod;
        E=(w[i]+E)%mod;
    }
    cout<<E<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}


```


## [P1972 [SDOI2009] HH 的项链](https://www.luogu.com.cn/problem/P1972)


### 题目描述

给定长度为 `n` 的数组 `a[1..n]`（值域 ≤ 1e6），有 `m` 个查询，每个查询给出区间 `[l,r]`，问区间内不同元素的个数。

**输入**
- `n`
- `a1 a2 ... an`
- `m`
- 接下来 `m` 行，每行 `l r`

**输出**
- 对每个查询输出一个整数：区间 `[l,r]` 中不同元素的数量。

**约束**
- `1 ≤ n,m ≤ 5e5`（总量 ≤ 1e6），`1 ≤ a_i ≤ 1e6`



### 核心想法（离线 + 树状数组）

枚举右端点 `r`（从 1 到 n），维护一个 Fenwick(BIT)：对于当前处理到的前缀 `1..r`，在 BIT 的位置 `i` 保持 `1` 当且仅当 `i` 是 `a[i]` 在前缀 `1..r` 中的**最后一次出现位置**（否则为 `0`）。
这样对于任意询问区间 `[l,r]`，当我们已经处理到 `r` 时，`BIT.query(l,r)` 恰好等于区间内不同元素的个数（因为每种值在该区间内只有它的**最后一次出现位置**会被计 1）。

实现步骤：

1. 读入所有查询，按 `r` 把查询编号分组（`vector<vector<int>> byR`）。
2. 从 `i=1` 到 `n`：

   * 若 `last[a[i]] != 0`，在 BIT 把 `last[a[i]]` 对应位置减 `1`（移除之前的“最后出现”标记）。
   * 在 BIT 把当前位置 `i` 加 `1`（标记当前位置为该值的新最后出现）。
   * 对所有 `r==i` 的查询，用 BIT 的区间和 `sum(r)-sum(l-1)` 得到答案。
3. 输出答案。

**正确性**

BIT 在任一时刻只对每个值保留其最新位置为 `1`，因此在区间 `[l,r]` 内被计 `1` 的恰好是区间内所有**不同值的最后出现位置**，数量即为不同元素个数。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=1e6+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;

struct BIT{
    int n;
    vector<int> t;
    void init(int _){
        n=_;
        t.resize(n+1,0);
    }
    void add(int x,int k){
        for(int i=x;i<=n;i+=(i&-i)){
            t[i]+=k;
        }
    }
    int sum(int x){
        int res=0;
        for(int i=x;i>=1;i-=(i&-i)){
            res+=t[i];
        }
        return res;
    }
    int query(int l,int r){
        return sum(r)-sum(l-1);
    }
};
void solve(){
    int n;
    cin>>n;
    BIT a;
    a.init(N);
    int b[n+1];
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int Q;
    cin>>Q;
    vector<array<int,3>> q(Q);
    vector<int> R[n+1];
    vector<int> ans(Q);
    vector<int> pos(N,0);
    for(int i=0;i<Q;i++){
        cin>>q[i][1]>>q[i][2];
        R[q[i][2]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(pos[b[i]]!=0){
            a.add(pos[b[i]],-1);
        }
        a.add(i,1);
        for(auto x:R[i]){
            ans[x]=a.query(q[x][1],q[x][2]);
        }
        pos[b[i]]=i;
    }
    for(int i=0;i<Q;i++){
        cout<<ans[i]<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```




## [The 10th Shandong Provincial Collegiate Programming Contest L.Flipping Game](https://codeforces.com/gym/104459/problem/L)

### 题目描述
令 $(n,k,m)$ 与初始串 $(s,t)$ 给出，设 $c=\mathrm{Ham}(s,t)$。定义
$$
f(i,j)={\text{前 }i\text{ 轮后恰有 }j\text{ 盏亮的方案数} },
$$
模 $\mod =998244353 $。

初值：
\[
f(0,j)=\begin{cases}1,&j=c,\\0,&\text{其他}.\end{cases}
\]

转移枚举本轮从 $j$ 个亮中熄灭 $a$ 个，且从 $n-j$ 个灭中点亮 $m-a$ 个：
\[
k = j + m - 2x,
\]
\[
x\in\Big[\max(0,,m-(n-j)),\ \min(j,m)\Big],
\]
\[
f(i+1,k) \equiv f(i+1,k) + f(i,j)\cdot \binom{j}{x}\binom{n-j}{,m-x,}\pmod{MOD}.
\]

等价的写法固定 $(j,k)$ 求 $x$：
\[
x=\frac{j+m-k}{2}\quad\text{（需为整数且满足上界下界）},
\]
若满足则
\[
f(i+1,k) \equiv f(i+1,j)+ f(i,j)\cdot \binom{j}{x}\binom{n-j}{m-x}\pmod{MOD}.
\]

答案：
\[
\text{ans}=f(k,0)\pmod{MOD}.
\]


### 思路



```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=1e6+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll inv(ll x){
    return qmi(x,mod-2)%mod;
}
ll fct[500],invf[500];
void init(int n){
    fct[0]=1;
    for(int i=1;i<=n;i++){
        fct[i]=(fct[i-1]*i)%mod;
    }
    invf[n]=inv(fct[n]);
    for(int i=n-1;i>=0;i--){
        invf[i]=(invf[i+1]*(i+1))%mod;
    }
}
ll C(int n,int m){
    if(m<=n&&m>=0&&n>=0){
        return ((fct[n]*invf[m])%mod*invf[n-m])%mod;
    }
    else{
        return 0;
    }
}
void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    string a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]!=b[i]);
    }
    vector<vector<ll>> dp(k+1,vector<ll>(n+1,0));
    dp[0][cnt]=1;
    init(200);
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if((m+j-k)%2==0){
                    int b=(m+j-k)/2;
                    int a=m-b;
                    dp[i][j]=(dp[i][j]+((dp[i-1][k]*C(n-k,b))%mod*C(k,a))%mod)%mod;
                }

            }
        }
    }
    cout<<dp[k][0]%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [The 10th Shandong Provincial Collegiate Programming Contest K - Happy Equation](https://codeforces.com/gym/104459/problem/K)


### 题目描述
方程如下：
\[
a^x \equiv x^a \pmod{2^p}
\]
给定一个整数 $ a $，请帮助 Little Sub 计算满足上述方程的 $ x $ 的数量，其中 $ 1 \le x \le 2^p $。

**输入**

有多个测试用例。输入的第一行包含一个整数 $ T $（约 $ 1000 $），表示测试用例的数量。对于每个测试用例：

第一行包含两个整数 $ a $ 和 $ p $（$ 1 \leq a \leq 10^9 $，$ 1 \leq p \leq 30 $）。

### 思路

1. **奇偶性分析**  
   - 如果 $ a $ 是奇数，那么 $ a^x $ 和 $ x^a $ 都是奇数，且在模 $ 2^p $ 下，奇数的幂次性质较为简单。根据题目的性质，当 $ a $ 是奇数时，满足条件的 $ x $ 只有 $ x = 1 $。因此，直接输出 $ 1 $。
   - 如果 $ a $ 是偶数，问题变得复杂，需要进一步分析。

2. **偶数情况的分析**  
   - 对于偶数 $ a $，我们需要找到满足 $ a^x \equiv x^a \pmod{2^p} $ 的 $ x $ 的数量。
   - 通过数学分析和实验，可以发现当 $ a $ 是偶数时，满足条件的 $ x $ 的数量可以通过以下步骤计算：
     - 枚举 $ x $ 从 $ 1 $ 到 $ p-1 $，检查 $ a^x \equiv x^a \pmod{2^p} $ 是否成立，统计满足条件的 $ x $ 的数量。
     - 计算一个额外的增量，公式为 $ 2^{p - \lceil \frac{p}{a} \rceil} - \left\lfloor \frac{p-1}{2^{\lceil \frac{p}{a} \rceil}b } \right\rfloor $。



```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=1e6+10;
const int M=2e6+10;
// const int mod = 1000000007;
const int mod = 998244353;
ll qmi(ll a,ll b,ll Mod){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%Mod;
        }
        a=a*a%Mod;
        b>>=1;
    }
    return res%Mod;
}

void solve(){
    int a,p;
    cin>>a>>p;
    if(a&1)cout<<1<<'\n';
    else{
        int Mx=(1<<p);
        int cnt=0;
        for(int x=1;x<p;x++){
            if(qmi(a,x,Mx)==qmi(x,a,Mx)){
                cnt++;
            }   
        }
        int k=(p+a-1)/a;
        cnt+=(1<<(p-k))-((p-1)/(1<<k));
        cout<<cnt<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```

## [The 10th Shandong Provincial Collegiate Programming Contest I -Connected Intervals](https://codeforces.com/gym/104459/problem/I)

### 题目描述


给定一棵 `n` 节点树，节点编号为 `1..n`。区间 `[l,r]`（`1≤l≤r≤n`）若由编号在 `[l,r]` 的顶点诱导出的子图连通，则称为**连通区间**。求连通区间总数。

### 思路
枚举右端 `r`，维护对所有左端 `l` 的连通块数 `f(l,r)`；把 `r` 加入时对所有 `l` 的变化是区间加法：对所有 `l≤r` 做 `+1`，对于每个邻居 `y<r`，对所有 `l≤y` 做 `-1`。用线段树维护并查询 `f(l,r)==1` 的个数。


* 新点 `r` 先增加 1 个连通块（`+1`）。
* `r` 在 `[l,r-1]` 内的每个邻居 `u` 原本位于不同连通块（树的唯一路径性质），把它们连入 `r` 会把不同块合成 1 个，合并次数为邻居数 `t`（所以 `-t`）。
* 因此对所有 `l`：`f(l,r) = f(l,r-1) + 1 - (#neighbors of r in [l,r-1])`，对应上面的区间加法实现。


**线段树维护（简洁版）**

维护每个节点三项：

* `Mi`：区间最小值
* `cnt`：最小值出现次数
* `lz`：懒标记（区间加值）

利用性质：若某段 `Mi == 1`，则该段内等于 1 的个数为 `cnt`；否则为 0。
核心操作：

```c++
void pushup(int p){
    Mi[p] = min(Mi[lc], Mi[rc]);
    cnt[p] = 0;
    if (Mi[p] == Mi[lc]) cnt[p] += cnt[lc];
    if (Mi[p] == Mi[rc]) cnt[p] += cnt[rc];
}
void pushdown(int p){
    if (lz[p]){
        Mi[lc] += lz[p]; lz[lc] += lz[p];
        Mi[rc] += lz[p]; lz[rc] += lz[p];
        lz[p] = 0;
    }
}
void build(int p,int l,int r){
    lz[p]=0; if(l==r){Mi[p]=0;cnt[p]=1;return;}
    build(lc,l,m); build(rc,m+1,r); pushup(p);
}
void add(int p,int L,int R,int v){ // 区间加
    if (R<l[p]||L>r[p]) return;
    if (L<=l[p] && r[p]<=R){ Mi[p]+=v; lz[p]+=v; return; }
    pushdown(p); add(lc,L,R,v); add(rc,L,R,v); pushup(p);
}
int query(int p,int L,int R){ // 统计等于1的个数
    if (R<l[p]||L>r[p]) return 0;
    if (L<=l[p] && r[p]<=R) return Mi[p]==1 ? cnt[p] : 0;
    pushdown(p); return query(lc,L,R)+query(rc,L,R);
}
```

* 每个边最多被处理一次（在编号较大的端点处处理），总共 `O(n)` 次 `add`。
* 每次 `add`/`query` 为 `O(log n)`，所以总时间 `O(n log n)`，空间 `O(n)`。



### 思路

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=3e5+10;
const int M=1e6+10;
// const int mod = 1000000007;
const int mod = 998244353;

struct Tr{
    int Mi;
    int cnt;
    int lz;
    int l,r;
}tr[N<<2];
void pushup(int p){
    tr[p].Mi=min(tr[p<<1].Mi,tr[p<<1|1].Mi);
    tr[p].cnt=0;
    tr[p].cnt+=(tr[p].Mi==tr[p<<1].Mi)?tr[p<<1].cnt:0;
    tr[p].cnt+=(tr[p].Mi==tr[p<<1|1].Mi)?tr[p<<1|1].cnt:0;
}
void pushdown(int p){
    if(tr[p].lz){
        tr[p<<1].lz+=tr[p].lz;
        tr[p<<1].Mi+=tr[p].lz;
        tr[p<<1|1].lz+=tr[p].lz;
        tr[p<<1|1].Mi+=tr[p].lz;
        tr[p].lz=0;
    }
}
void build(int p,int l,int r){
    tr[p].l=l,tr[p].r=r;
    tr[p].lz=0;
    if(l==r){
        tr[p].Mi=0;
        tr[p].cnt=1;
        return ;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void add(int p,int L,int R,int k){
    if(tr[p].r<L||tr[p].l>R)return ;    
    if(tr[p].l>=L&&tr[p].r<=R){
        tr[p].Mi+=k;
        tr[p].lz+=k;
        return ;
    }
    pushdown(p);
    if(L<=tr[p<<1].r){
        add(p<<1,L,R,k);
    }
    if(R>=tr[p<<1|1].l){
        add(p<<1|1,L,R,k);
    }
    pushup(p);
}
ll query(int p,int L,int R){
    if(tr[p].l>=L&&tr[p].r<=R){
        return tr[p].Mi==1?tr[p].cnt:0;
    }
    pushdown(p);
    ll res = 0;
    if (L<=tr[p<<1].r) res+=query(p<<1,L,R);
    if (R>=tr[p<<1|1].l) res+=query(p<<1|1,L,R);
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> e(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    build(1,1,n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        add(1,1,i,1);
        for(auto y:e[i]){
            if(y<i){
                add(1,1,y,-1);
            }
        }
        ans+=query(1,1,i);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```


## [2025“钉耙编程”中国大学生算法设计暑期联赛（1） 1005	传送门](https://acm.hdu.edu.cn/contest/problem?cid=1172&pid=1005)

### 题目描述


大陆上有 `n` 个遗迹，`m` 条双向传送门。每条传送门标注一个魔法协会编号 `c`（颜色）。
从遗迹 `1` 出发要到遗迹 `n`，规则是：连续使用同一协会（同一颜色）的传送门只需支付 1 枚金币；每次切换到另一个协会时需要额外再支付 1 枚金币。要求计算从 `1` 到 `n` 的最少金币数。保证可达。


### 思路
**状态建模**

将问题建模为带状态的最短路问题：每个状态为 `(x, last_color)`，代表当前在节点 `x`，上一条使用的传送门颜色是 `last_color`（起点用 `0` 或其它不存在的颜色表示“还没付过任何协会”）。
从 `(x, last_color)` 经过一条颜色为 `cy` 的边到达 `y` 时：

* 若 `cy == last_color`，则不需要额外付费，代价 `0`；
* 若 `cy != last_color`，则需要付 1 枚金币，代价 `1`。

初始状态为 `(1, 0)`，目标是到达任意 `(n, any_color)` 的最小总代价（金币数）。

**搜索方法**

这就是一个 0/1 权重的最短路问题（边权只有 0 或 1），可以用：

* 0-1 BFS（用 `deque`，当权值 0 时 push_front，权值 1 时 push_back），或者
* Dijkstra / 优先队列（你当前代码使用的方式），把 `d` 表示到达该状态的金币数，优先弹出 `d` 小的状态。



**常见实现优化 / 变体**

* 用 `deque` 做 0-1 BFS 可以把时间从 `O(m log m)` 降到 `O(m)`（常数更好），因为权重只有 0/1。
* 用 `unordered_map` 或将 `(node,color)` 映射到整型 id 而不是 `map<pair,int>` 可以显著加速（`map` 为红黑树，常数较大）。
* 如果颜色值非常大但重复较多，可对颜色做压缩或只为节点维护其邻接的颜色集合并用 `unordered_set` 记录访问过的颜色状态。
* 另一种图转换（更结构化的建图法）：构造超级节点：

  * 对于每个 `(node, color)` 创建一个状态节点；
  * 把所有 `(u,color)` 与 `(v,color)`（原边 u-v 颜色为 color）用 0-cost 边连接；
  * 从原始节点 `u` 到 `(u,color)` 加一条代价为 1 的边（表示“切换/开始使用该颜色”）。
    这样在普通 Dijkstra/0-1 BFS 下同样可解，且有利于某些变体的证明和实现。
    （本质还是在做 `(node, last_color)` 状态图的显式构造。）
--- 
```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=3e5+10;
const int M=1e6+10;
// const int mod = 1000000007;
const int mod = 998244353;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> e(n+1); 
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        e[u].push_back({v,c});
        e[v].push_back({u,c});
    }
    map<pair<int,int>,int>v;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
    q.push({0,1,0});
    int ans=1e9;
    while(!q.empty()){  
        auto [d,x,c]=q.top();
        q.pop();
        if(x==n)ans=min(d,ans);
        if(v[{x,c}])continue;
        else{
            v[{x,c}]=1;
            for(auto [y,cy]:e[x]){
                if(cy!=c){
                    q.push({d+1,y,cy});
                }
                else{
                    q.push({d,y,cy});
                }
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```




## [2025“钉耙编程”中国大学生算法设计暑期联赛（1）1003	奸商](https://acm.hdu.edu.cn/contest/problem?cid=1172&pid=1003)


### 题目描述

给定只包含 a..q（17 个字母）的字符串，对所有长度 ≥ len 的子串进行检查：一个子串若存在镜像对相等则称“优秀”。你可以为若干字母付费让“巨人对该字母产生幻觉”（即在检查时该字母可被视为任意不小于它的字母，独立且可在不同子串/出现时取不同值）。求使得所有被检查的子串都能被视作优秀的最小总费用。


### 思路

只要保证**每一个被检查的（长度 ≥ len）的子串** 至少能通过“幻觉”变成 **优秀**（即存在一对镜像位置相等），就能活命。对每个“坏”（当前非优秀）的子串，统计出一组字母 —— 只要对这组中任意一个字母施加幻觉，该子串就能变成优秀。把这些组作为约束，枚举所有字母的幻觉选择（17位掩码），找满足所有约束且费用最小的方案。

**为什么只看偶数长度**

奇数长度的字符串中间字符总是与自己镜像相等，**必然优秀**，所以只需考虑**偶数长度**子串。代码通过对称展开的方式只生成了偶数长度的子串（见下）。

枚举以“中点”对称的偶数长度子串，并收集“坏子串”的掩码集合 `sets`


解释：

* `m` 表示偶数长度子串的“右中点”索引（用0-based理解时，中心在 `m-1` 和 `m` 之间）。对每个 `m`，用 `l` 向左扩，`r = 2*m - l` 对称向右扩（`r-1` 为右端索引）。
* `if (r > n) break;`：越界终止。
* `if (s[l] == s[r-1]) break;`：一旦发现某一对镜像字符相等，**当前扩展得到的所有更长的子串都会包含这个相等对，从而是优秀的**，因此不需再继续从该 `m` 向外扩（也不会产生“全部不相等”的坏子串）。
* `x = min(a[l], a[r-1]); mask |= 1<<x;`：

  * 对于一对不相等的字符（比如 c 和 e），要通过“把某个字母幻觉成另一个”使它们相等，只能把**较小的字母提升到较大的字母**（幻觉只能把字母变为 ASCII 值更大或相等的字母）。因此要“修复”这一对，必须对较小的字母施幻觉。把 `min(...)` 放入 `mask` 表示：这个子串的每一个不相等镜像对都对应一个“候选被幻觉的字母”，只要对这些候选字母中的任意一个施幻觉，整对就能相等，从而使子串成为优秀。
* `if (r - l >= len) { sets.push_back(mask); break; }`：当当前形成的偶长度子串长度达到检查下界 `len` 时，如果在扩展过程中没有遇到相等对（否则已在上一步 `break`），那么当前子串就是一个“坏子串”。将它对应的 `mask`（表示能把该子串变好的候选字母集合）加入 `sets`。`break` 是因为对于同一中心 `m`，更长的子串只会在 `mask` 上累加更多位 —— 我们记录第一个达到 `len` 的“坏”子串掩码即可（实际上记录任一个也可，代码选择第一个并 `break` 来避免重复）。

**枚举所有幻觉方案（2^17），求最小花费**

```cpp
int ans = 1E9;
for (int s = 0; s < (1 << 17); s++) {
    int cost = 0;
    for (int i = 0; i < 17; i++) if (s >> i & 1) cost += w[i];
    bool ok = true;
    for (auto t : sets) {
        if (!(s & t)) { ok = false; break; }
    }
    if (ok) ans = std::min(ans, cost);
}
cout << ans << "\n";
```

解释：

* 这里 `s` 是一个 17 位掩码，`s >> i & 1` 为 1 表示对字母 `i`（`a+i`）**施加幻觉**（代码中把设为 1 的位对应花费 `w[i]`）。
* 对于每个记录的“坏子串” `t`（t 是一个掩码，位集为能修复该子串的字母集合），需要 `s & t != 0` —— 意味着在你选的幻觉集合中至少存在一个字母属于 `t`，这样该子串就能被修复为优秀。若所有 `t` 都满足这一点，则方案 `s` 合法。
* 在合法方案里取最小 `cost` 即为答案。

**为什么这样正确**

* 对于任何偶数长度的子串，如果它已经有某对镜像字母相等，则它本身优秀，不需要控制。故只需关注“完全不含相等镜像对”的子串（代码中扩展直到遇到相等对才停）。
* 若子串在所有镜像对上都不同，那么要让子串变成优秀，至少需要把其中某一对修成相等。由于幻觉只能把字母提高（变成 >= 自身的字母），要把一对变相等，必然把 **较小的那个字母** 提高到较大的字母（或更高但可取相同字符），因此记录 `min(a[l], a[r-1])` 的集合是恰当的。只要幻觉集合包含集合中的任一字母，那个子串就能被修复。
* 因为幻觉设置对字符串的所有出现都起作用，且检查不同子串时“同一字母”可以被巨人“以不同幻觉值识别”（题目允许这种任意性），所以上述“至少选集合中一个字母”条件是充分且必要的。


```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=3e5+10;
const int M=1e6+10;
// const int mod = 1000000007;
const int mod = 998244353;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s='+'+s;
    int c[20];
    for(int i=0;i<17;i++){
        cin>>c[i];
    }
    int m;
    cin>>m;
    if(m&1)m++;
    vector<int> pos;
    for(int i=m/2;i<=n-m/2;i++){
        int ok=0;
        int x=0;
        for(int L=i,R=i+1;L>=i-m/2+1&&R<=i+m/2;L--,R++){
            if(s[L]==s[R]){
                ok=1;
                break;
            }
            else{
                x|=1<<min(s[R]-'a',s[L]-'a');
            }
        }
        if(!ok){
            pos.push_back(x);
        }
    }
    int ans=1e9;
    for(int i=0;i<(1<<17);i++){
        int res=0;
        for(int j=0;j<17;j++){
            if(i&(1<<j))res+=c[j];
        }
        int ok=1;
        for(auto k:pos){
            if(!(k&i)){
                ok=0;
            }
        }
        if(ok)ans=min(ans,res);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
```



## [2025“钉耙编程”中国大学生算法设计暑期联赛（1）](https://acm.hdu.edu.cn/contest/problem?cid=1172&pid=1007)

### 题目描述

给一棵有 $n$ 个节点的树和每个节点的值 $a[i]$，以及目标 $x(2 ≤ x ≤ 1e7)$。问有多少条简单路径（端点可以相同，即单点路径也算）使得路径上所有节点值的 $LCM$ 恰好等于 $x$

---

## 关键数学变换（式子）

设对任意正整数 $i$：

* $F(i)$ = “路径上所有节点的值都 *除* $i$” 的路径数 —— 等价于路径的 LCM **整除** $i$。
* $G(i)$ = 路径的 LCM **恰好等于** $i$ 的路径数。

显然有关系：
\[
F(i)=\sum_{d\mid i} G(d)
\]
对每个 $i$， $F(i)$ 是所有恰好为 $d$ 的路径，其中 $d\mid i$的和。于是对固定的 $x$ 应用莫比乌斯反演：
\[
G(x)=\sum_{d\mid x} \mu\left(\frac{x}{d}\right),F(d)
\]
这里 $\mu$ 是莫比乌斯函数 $μ$。

这个公式就是代码中的主体操作：对所有 $d\mid x$（代码里用 `i` 表示），计算 $F(i)$，然后加权乘以 $\mu(x/i)$ 累加到 `ans`。

---

## 如何计算 $F(i)$（代码里的具体做法）

对于固定的 $i$，路径的 LCM 能整除 $i$ 等价于**路径上每个节点值 (a_j) 都整除 (i)**（因为若所有节点的值都 | i，则它们的 LCM 也 | i，反之 LCM | i 必然每个值 | i）。所以：

1. 遍历节点，令 `chk[j] = 1` 当且仅当 `a[j] | i`（代码判断是 `if (i % a[j] == 0)`）。
2. 在原树上，把 `chk==1` 的节点视为“有效节点”，`chk==0` 的节点把树切开成若干连通块（每块内部节点都满足 a|i）。
3. 每个连通块有 (m) 个节点，则该块内部产生的 **路径数**（包括单点路径）为 $\binom{m}{2} + m = m(m+1)/2$，因为任意两节点之间有唯一一条简单路径，且单点路径也要计入。
4. 因此 $F(i)$ 就是对每个由 `chk==1` 构成的连通分量累加 $m(m+1)/2$。

代码中 `dfs` 实现了这个计数：对 `sz[u]` 累加子树中 `chk` 的节点数，若当前节点 `u` 是一个被标记块的根（`chk[u] && !chk[fa]`）则把该块大小贡献 `sz[u]*(sz[u]+1)/2` 到 `res`。遇到 `chk[u]==0` 时把 `sz[u]=0` 以隔断。

---

## 为什么循环是 `for (i=1..x) if (x % i == 0)`？

因为要枚举 $d$ 遍历 $x$ 的所有因子（分母形式是 $x/d$ 出现在 μ 中）。代码里还提前检查 `mu[x/i]` 是否为 0 来跳过那些 μ 为 0 的情况（优化）。

最后 `ans += mu[x/i] * res;` 就是把每个 $F(i)$ 按 $\mu(x/i)$ 加权求和，得到 $G(x)$。

---

## 代码要点对应解释（对照你贴的代码）

* `mu_init(10000000)`：线性筛预处理莫比乌斯函数到 $10^7$（因为 $x \le 10^7$。
* 外层循环 `for (int i=1;i<=x;i++) if (x%i==0 && mu[x/i])`：枚举 $i\mid x$，且跳过 $\mu(x/i)=0$ 的项。
* 内部 `for j` 把 `chk[j]=1` 当且仅当 `a[j]|i`。
* `dfs(1,0,res)`：一次 DFS 计算 `res = F(i)`（路径数使得所有节点都 | i）。

  * `sz[u] = chk[u];` -> 基本计数
  * 累加子节点 `sz[u] += sz[v]`
  * 如果 `chk[u] && !chk[fa]`，说明 `u` 是该被标记连通块的根，给 `res += sz[u]*(sz[u]+1)/2`
  * `if (!chk[u]) sz[u]=0;` 用来隔断（不向上带非标记信息）
* `ans += mu[x/i] * res;` 最后对每个 i 做莫比乌斯加权

（注意：代码中 `chk[0]` 默认应为 0，因而 `dfs(1,0,...)` 时 `chk[fa]` 在 `fa=0` 能正确判断根是否为块根）

---

## 正确性小结

* $F(i)$ 的定义与实现严格对应；
* 莫比乌斯反演把“整除”计数反推出“恰等于 x”；
* `sz*(sz+1)/2` 正确计数某一连通子树内所有简单路径（包含单点路径）；
* 因为树上任意两点路径唯一，连通子树内部的任意两节点对会产生恰好一条包含在该子树内的路径，故计数无重与漏。

---


### 思路

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld PI = acosl(-1);
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);
const int N=1e5+10;
const int M=1e6+10;
// const int mod = 1000000007;
const int mod = 998244353;

std::vector<ll> minp, primes, phi, mu;

void sieve(int n) {//预处理莫比乌斯函数
    minp.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    mu.assign(n + 1, 0);
    primes.clear();
    phi[1] = 1;
    mu[1] = 1;
    
    for (ll i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            phi[i] = i - 1;
            mu[i] = -1;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
            mu[i * p] = -mu[i];
        }
    }
}
vector<vector<int>> e(N);
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    int v[n+1];
    for(int i=1;i<=x;i++){
        if(x%i==0&&mu[x/i]){
            for(int j=1;j<=n;j++){
                v[j]=(i%a[j]==0)?0:1;//不能整除的为断点
            }
            ll res=0;//在i的约数下的简单路径 连通块方案数
            for(int j=1;j<=n;j++){
                if(!v[j]){
                    ll kt=0;
                    queue<int> q;
                    q.push(j);
                    while(!q.empty()){
                        int t=q.front();
                        q.pop();
                        if(v[t])continue;
                        v[t]=1;
                        kt++;
                        for(auto z:e[t]){
                            if(!v[z]){
                                q.push(z);
                            }
                        }
                    }
                    res=res+(kt*(kt+1))/2;//整个连通块选了个作为端点的简单路径数量
                }
            }   
            ans=ans+mu[x/i]*res;//计算G(x)=mu[x/i]*F[i]
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(10000000);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}

```