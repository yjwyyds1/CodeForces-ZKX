#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using PII=pair<ll,ll>;
using PIII=pair<int,pair<int,int>>;
const ld ESP = 1e-10;
const ld PI = acosl(-1);
const int N=1e5+10;
const int M=2e6+10;
const int mod = 1000000007;
// const int mod = 998244353;
//随机化
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> Tp(1, 100);
// cout<<fixed<<setprecision(10);

const ll INF = (1LL << 60);
const ll NINF = -(1LL << 60);

struct SegTree {
    int n;
    struct Node {
        ll mx = NINF, mx2 = NINF, mn = INF, mn2 = INF;
        ll cmx = 0, cmn = 0, tmx = NINF, tmn = INF, tad = 0, sum = 0;
    } t[N << 2];

    void set_leaf(int u, ll v) {
        t[u].mx = t[u].mn = v;
        t[u].mx2 = NINF; t[u].mn2 = INF;
        t[u].cmx = t[u].cmn = 1;
        t[u].sum = v;
        t[u].tad = 0; t[u].tmx = NINF; t[u].tmn = INF;
    }

    void pushup(int u) {
        int l = u << 1, r = u << 1 | 1;
        t[u].sum = t[l].sum + t[r].sum;
        if (t[l].mx == t[r].mx) {
            t[u].mx = t[l].mx; t[u].cmx = t[l].cmx + t[r].cmx;
            t[u].mx2 = max(t[l].mx2, t[r].mx2);
        } else if (t[l].mx > t[r].mx) {
            t[u].mx = t[l].mx; t[u].cmx = t[l].cmx;
            t[u].mx2 = max(t[l].mx2, t[r].mx);
        } else {
            t[u].mx = t[r].mx; t[u].cmx = t[r].cmx;
            t[u].mx2 = max(t[l].mx, t[r].mx2);
        }
        if (t[l].mn == t[r].mn) {
            t[u].mn = t[l].mn; t[u].cmn = t[l].cmn + t[r].cmn;
            t[u].mn2 = min(t[l].mn2, t[r].mn2);
        } else if (t[l].mn < t[r].mn) {
            t[u].mn = t[l].mn; t[u].cmn = t[l].cmn;
            t[u].mn2 = min(t[l].mn2, t[r].mn);
        } else {
            t[u].mn = t[r].mn; t[u].cmn = t[r].cmn;
            t[u].mn2 = min(t[l].mn, t[r].mn2);
        }
    }

    void push_add(int u, int l, int r, ll v) {
        t[u].sum += (r - l + 1LL) * v;
        t[u].mx += v; t[u].mn += v;
        if (t[u].mx2 != NINF) t[u].mx2 += v;
        if (t[u].mn2 != INF)  t[u].mn2 += v;
        if (t[u].tmx != NINF) t[u].tmx += v;
        if (t[u].tmn != INF)  t[u].tmn += v;
        t[u].tad += v;
    }

    void push_min(int u, ll tg) {
        if (t[u].mx <= tg) return;
        t[u].sum += (tg - t[u].mx) * t[u].cmx;
        if (t[u].mn2 == t[u].mx) t[u].mn2 = tg;
        if (t[u].mn == t[u].mx)  t[u].mn = tg;
        if (t[u].tmx > tg)       t[u].tmx = tg;
        t[u].mx = tg; t[u].tmn = tg;
    }

    void push_max(int u, ll tg) {
        if (t[u].mn > tg) return;
        t[u].sum += (tg - t[u].mn) * t[u].cmn;
        if (t[u].mx2 == t[u].mn) t[u].mx2 = tg;
        if (t[u].mx == t[u].mn)  t[u].mx = tg;
        if (t[u].tmn < tg)       t[u].tmn = tg;
        t[u].mn = tg; t[u].tmx = tg;
    }

    void pushdown(int u, int l, int r) {
        int mid = (l + r) >> 1, L = u << 1, R = u << 1 | 1;
        if (t[u].tad) {
            push_add(L, l, mid, t[u].tad);
            push_add(R, mid + 1, r, t[u].tad);
        }
        if (t[u].tmx != NINF) { push_max(L, t[u].tmx); push_max(R, t[u].tmx); }
        if (t[u].tmn != INF)  { push_min(L, t[u].tmn); push_min(R, t[u].tmn); }
        t[u].tad = 0; t[u].tmx = NINF; t[u].tmn = INF;
    }

    void build(int u, int l, int r, ll a[]) {
        if (l == r) { set_leaf(u, a[l]); return; }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        pushup(u);
    }

    void add(int u, int l, int r, int L, int R, ll v) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) { push_add(u, l, r, v); return; }
        int mid = (l + r) >> 1; pushdown(u, l, r);
        add(u << 1, l, mid, L, R, v);
        add(u << 1 | 1, mid + 1, r, L, R, v);
        pushup(u);
    }

    void tomin(int u, int l, int r, int L, int R, ll v) {
        if (R < l || r < L || t[u].mx <= v) return;
        if (L <= l && r <= R && t[u].mx2 < v) { push_min(u, v); return; }
        int mid = (l + r) >> 1; pushdown(u, l, r);
        tomin(u << 1, l, mid, L, R, v);
        tomin(u << 1 | 1, mid + 1, r, L, R, v);
        pushup(u);
    }

    void tomax(int u, int l, int r, int L, int R, ll v) {
        if (R < l || r < L || t[u].mn >= v) return;
        if (L <= l && r <= R && t[u].mn2 > v) { push_max(u, v); return; }
        int mid = (l + r) >> 1; pushdown(u, l, r);
        tomax(u << 1, l, mid, L, R, v);
        tomax(u << 1 | 1, mid + 1, r, L, R, v);
        pushup(u);
    }

    ll qsum(int u, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return t[u].sum;
        int mid = (l + r) >> 1; pushdown(u, l, r);
        return qsum(u << 1, l, mid, L, R) + qsum(u << 1 | 1, mid + 1, r, L, R);
    }

    ll qmax(int u, int l, int r, int L, int R) {
        if (R < l || r < L) return NINF;
        if (L <= l && r <= R) return t[u].mx;
        int mid = (l + r) >> 1; pushdown(u, l, r);
        return max(qmax(u << 1, l, mid, L, R), qmax(u << 1 | 1, mid + 1, r, L, R));
    }

    ll qmin(int u, int l, int r, int L, int R) {
        if (R < l || r < L) return INF;
        if (L <= l && r <= R) return t[u].mn;
        int mid = (l + r) >> 1; pushdown(u, l, r);
        return min(qmin(u << 1, l, mid, L, R), qmin(u << 1 | 1, mid + 1, r, L, R));
    }

    // 对外包装（从根开始调用）
    void build(int _n, ll a[]) { n = _n; build(1, 1, n, a); }
    void add(int L, int R, ll v) { add(1, 1, n, L, R, v); }
    void tomin(int L, int R, ll v) { tomin(1, 1, n, L, R, v); }
    void tomax(int L, int R, ll v) { tomax(1, 1, n, L, R, v); }
    ll qsum(int L, int R) { return qsum(1, 1, n, L, R); }
    ll qmax(int L, int R) { return qmax(1, 1, n, L, R); }
    ll qmin(int L, int R) { return qmin(1, 1, n, L, R); }
};
void solve(){
    int n;cin>>n;
    ll a[n+1],f[n+10],g[n+10];
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        f[i]=g[i]=0;
    }
    SegTree F,G;
    for(int i=1;i<=n;i++){
        f[i]=max(f[i-1],a[i]);
    }
    F.build(n+1,f);
    for(int i=n;i>=1;i--){
        g[i]=max(g[i+1],a[i]);
    }
    G.build(n+1,g);
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        ll x,h;
        cin>>x>>h;
        a[x]+=h;
        sum+=h;
        F.tomax(x,n,a[x]);
        G.tomax(1,x,a[x]);
        cout<<(F.qsum(1,n)+G.qsum(1,n)-n*F.qmax(1,n)-sum)<<'\n';
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
