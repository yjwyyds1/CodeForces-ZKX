#include <bits/stdc++.h>
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
int a[N];
int ans[N];
struct BIT
{
	const int n;
	vector<ll> tree;
	BIT(int n) : n(n), tree(n + 1) {};
	// 询问前x个数的和
	ll Query(int x)
	{
		ll res = 0;
		for (int i = x; i > 0; i -= (i & -i)) res += tree[i];
		return res;
	}
	// 第l个位置+z
	void Modify(int l, ll z)
	{
		if (l <= 0) return;
		for (int i = l; i <= n; i += (i & -i)) tree[i] += z;
	}
};
void solve(){
    int n;
    cin>>n;
    BIT T(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        T.Modify(i,1);
    }
    for(int i=n;i>=1;i--){
        if(i==n){
            ans[a[i]]=i;
            T.Modify(a[i],-1);
        }
        else{
            int L=1,R=n,ans1=0,ans2=0;
            while(L<=R){
                int mid=L+R>>1;
                if(T.Query(mid)<a[i]){
                    L=mid+1;
                }
                else{
                    R=mid-1;
                }
            }
            ans[L]=i;
            T.Modify(L,-1);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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
