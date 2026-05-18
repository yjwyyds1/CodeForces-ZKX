#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int ans=1e9;
void dfs(int x,int y,int cnt){
    if(x<1||y<1||cnt>=ans)return ;
    if(x==1&&y==1)ans=min(cnt,ans);
    dfs(x-y,y,cnt+1);
    dfs(x,y-x,cnt+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        dfs(n,i,0);
    }
    cout<<ans<<'\n';
    return 0;
}