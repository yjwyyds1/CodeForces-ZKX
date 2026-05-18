#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class DSU {
public:
    vector<int> parent, size;
 
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
 
    // 查找根节点并进行路径压缩
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
 
    // 合并两个集合，并返回是否成功合并
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            return true;
        }
        return false;
    }
 
    // 获取某个集合的大小
    int getSize(int x) {
        return size[find(x)];
    }
};
 
void solve() {
    int t;
    // cin >> t;
    t=1;
    while (t--) {
        int n, d;
        cin >> n >> d;
 
        vector<pair<int, int>> conditions(d);
        for (int i = 0; i < d; ++i) {
            cin >> conditions[i].first >> conditions[i].second;
            conditions[i].first--;  // 转换为0索引
            conditions[i].second--;
        }
 
        DSU dsu(n);
        vector<int> result(d);
        int extraOps = 0; // 记录多余的合并操作
        int maxSize = 1;
 
        for (int i = 0; i < d; ++i) {
            int p = conditions[i].first;
            int q = conditions[i].second;
 
            if (!dsu.unionSets(p, q)) {
                extraOps++; // 如果这两个点已经在同一个集合中
            }
 
            vector<int> sizes;
            for (int j = 0; j < n; ++j) {
                if (dsu.find(j) == j) {
                    sizes.push_back(dsu.getSize(j));
                }
            }
            sort(sizes.rbegin(), sizes.rend()); // 按照集合大小从大到小排序
 
            // 尝试使用额外的合并次数，最大化一个人熟悉的总人数
            maxSize = 0;
            for (int j = 0; j <= extraOps && j < sizes.size(); ++j) {
                maxSize += sizes[j];
            }
            result[i] = maxSize-1;
        }
 
        for (int i = 0; i < d; ++i) {
            cout << result[i] << endl;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
 
// void solve() {
//     int n,d;
//     cin>>n>>d;
//     vector<int> fa(n + 1), sz(n + 1);
//     auto find = [&](auto self, int x)->int
//     {
//         return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//     };
//     for (int i = 1; i<= n; i++) fa[i] = i, sz[i] = 1;
//     set<pair<int, int>>minn, maxx;
//     for (int i = 1; i < n; i++) minn.insert({1, i});
//     maxx.insert({1, n});
//     int ans = 1, cnt = 1;
//     for (int i = 1; i <= d; i++) {
//         int u, v;
//         cin>>u>>v;
//         u = find(find,u), v=find(find,v);
//         if (u==v) {
//             cnt++;
//             ans+= minn.rbegin()->first;
//             maxx.insert(*minn.rbegin());
//             minn.erase(*minn.rbegin());
//         } else {
//             if (sz[u] < sz[v] | (sz[u] == sz[v] & u < v)) swap(u, v);
//             int num = minn.count({sz[u], u}) + minn.count({sz[v], v});
//             switch (num) {
//                 case 0: {   
//                     fa[v] = u;
//                     maxx.erase({sz[u], u});
//                     maxx.erase({sz[v], v});
//                     sz[u] += sz[v];
//                     ans += minn.rbegin()->first;
//                     maxx.insert({sz[u], u});
//                     maxx.insert(*minn.rbegin());
//                     minn.erase(*minn.rbegin());
//                     break;
//                 }
//                 case 1: {
//                     if (minn.count({sz[u], u}) > minn.count({sz[v], v})){
//                         swap(u, v);
//                     }
//                     fa[v] = u;
//                     maxx.erase({sz[u], u});
//                     minn.erase({sz[v], v});
//                     sz[u] += sz[v];
//                     ans += sz[v];
//                     maxx.insert({sz[u], u});
//                     break;
//                 }
//                 case 2: {
//                     fa[v] = u;
//                     minn.erase({sz[u], u});
//                     minn.erase({sz[v], v});
//                     sz[u] += sz[v];
//                     if (sz[u] < maxx.begin()->first)
//                         minn.insert({sz[u], u});
//                     else {
//                         ans += sz[u] - maxx.begin()->first;
//                         minn.insert(*maxx.begin());
//                         maxx.erase(*maxx.begin());
//                         maxx.insert({sz[u], u});
//                     }
//                     break;
//                 }
//             }
//         }
//         cout<<ans-1<<endl;
//     }
// }
// int main() {
//     int T;
//     cin>>T;
//     while(T--) {
//         solve();
//     }
//     return 0;
// }
//  #include <bits/stdc++.h>
// #include <bits/extc++.h>
 
// using namespace std;
 
// template<typename Type, typename Comp = less<Type>>
// using treap = __gnu_pbds::tree<Type,__gnu_pbds::null_type,Comp,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// void solve() {
//     int n, d;
//     cin>>n>>d;
//     vector<int> pa(n + 1), cnt(n + 1, 1);
//     iota(pa.begin(), pa.end(), 0ll);
//     auto find = [&](auto self, int x)->int
//     {
//         return pa[x] == x ? x : pa[x] = self(self, pa[x]);
//     };
//     int lf = 1;
//     treap<pair<int, int>>st;
//     for (int i = 1; i<=n;i++) st.insert({-1, i});
//     int sum = 1;
//     while (d--) {
//         int x, y;
//         cin>>x>>y;
//         int f1 = find(find, x), f2 = find(find, y);
//         if (f1!=f2) {
//             pa[f2] = f1;
//             int ind1 = st.order_of_key({-cnt[f1], f1});
//             int ind2 = st.order_of_key({-cnt[f2], f2});
//             if (ind1 < lf) sum -= cnt[f1];
//             if (ind2 < lf) sum -= cnt[f2];
//             st.erase({-cnt[f1], f1});
//             st.erase({-cnt[f2], f2});
//             cnt[f1] += cnt[f2];
//             st.insert({-cnt[f1], f1});
//             int n_ind = st.order_of_key({-cnt[f1], f1});
//             if (ind1 < lf&&ind2 < lf) { //区间内有两个，补偿代价
//                 sum += cnt[f1]; //变大后肯定在区间内
//                 if (st.size()>=lf) sum += -(*st.find_by_order(lf -1)).first;
//                 } else if (ind1>=lf&&ind2>=lf) { //区间内一个都没有，但可能会进入区间
//                 if (n_ind < lf) { //进入区间，顶出来一个
//                     sum += cnt[f1];
//                     sum -= -(*st.find_by_order(lf)).first;
//                 }
//             } else {
//                 if (n_ind < lf) { //进入区间,1换1
//                     sum += cnt[f1];
//                 }
//             }
//         } else {
//             lf++;
//             if (st.size()>=lf) sum += -(*st.find_by_order(lf - 1)).first;
//         }
//         cout<<sum - 1<<'\n';
//     }
// }
// int main() {
//     int T;
//     cin>>T;
//     while (T--) {
//         solve();
//     }
//     return 0;
//  }