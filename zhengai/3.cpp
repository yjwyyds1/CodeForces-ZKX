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
int b[1000];
struct fs{
    int x;
    int y;
    bool operator> (const fs & a)const{
        return x*a.y>y*a.x;
    }
    void T(fs &a){
        int d=gcd(a.x,a.y);
        a.x/=d;
        a.y/=d;
    }
}ans;
int n;
void dfs(int x,int sum,int p){
    if(x==n+1){
        fs cur={sum,p};
        if(ans.x==-1){
            ans=cur;
        }else{
            if(cur>ans){
                ans=cur;    
            }
        }
        return ;
    }
    if(b[x]==1){
        dfs(x+1,sum+1,p+1);
    }else if(b[x]==-1){
        if(p>=2){
            dfs(x+1,sum,p-1);
        }else{
            return ;
        }
    }else{
        dfs(x+1,sum+1,p+1);
        if(p>=2){
            dfs(x+1,sum,p-1);
        }else{
            return ;
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    ans={-1,-1};
    dfs(1,1,1);
    ans.T(ans);
    if(ans.x==-1){
        cout<<-1<<'\n';
    }else{
        cout<<ans.x<<" "<<ans.y<<'\n';
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