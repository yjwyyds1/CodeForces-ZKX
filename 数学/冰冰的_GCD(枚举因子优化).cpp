#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
ll gcd(ll x,ll y){
    return (y?gcd(y,x%y):x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> v(n+1);
    vector<int> a(n+1),b(n+1),c(n+1),d(n+1),f(n+1),g(n+1);
    for(int i=2;i<=n;i++){
        for(int j=1;i*j<=n;j++){
            v[i*j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    vector<int> L(n+1,n+1);
    for(int i=n;i>=1;i--){
        int idx=n+1;
        for(auto x:v[b[i]]){
            if(idx>L[x]){
                idx=L[x];
            }
        }
        if(idx<=n){
            f[i]=gcd(b[i],b[idx]);
        }
        else{
            f[i]=b[i];
        }
        for(auto x:v[b[i]]){
            L[x]=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j*i<=n;j++){
            if(d[i*j]>=c[i])g[i]++;
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        cout<<g[f[x]]<<'\n';
    }
    return 0;
}
