#include <bits/stdc++.h>
const int N=1200010;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
int a[N],f[N],d[N],ans[N];
void solve(){
    int n,k;
    int M=1e6;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]++;
    }
    for(int i=1;i<=M;i++){
        for(int j=i;j<=M;j+=i){
            d[i]+=f[j];
        }
    }
    for(int i=1;i<=M;i++){
        if(d[i]>=k){
            for(int j=i;j<=M;j+=i){
                ans[j]=max(ans[j],i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[a[i]]<<'\n';
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
