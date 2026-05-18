#include <bits/stdc++.h>
const int N=2e5+10;
const int mod=998244353;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cout<<qmi(m-i,n)*qmi(qmi(m-1,mod-2),n)%mod<<" ";
    }
    return 0;
}