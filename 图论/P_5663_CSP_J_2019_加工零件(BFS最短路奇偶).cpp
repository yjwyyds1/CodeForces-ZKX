#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
vector<vector<int>> e(N);
vector<int> f1(N,1e9);//奇数
vector<int> f2(N,1e9);//偶数
void bfs(){
    queue<pair<int,int>>q;
    f2[1]=0;
    q.push({1,0});
    while(!q.empty()){
        int x=q.front().first;
        int L=q.front().second;
        q.pop();
        for(auto y:e[x]){
            if(L%2){    
                if(L+1<f2[y]){
                    f2[y]=L+1;
                    q.push({y,L+1});
                }
            }
            else{
                if(L+1<f1[y]){
                    f1[y]=L+1;
                    q.push({y,L+1});
                }
            }
        }
    }
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    bfs();
    for(int i=1;i<=q;i++){
        int a,s;
        cin>>a>>s;
        if((s>=f1[a]&&s%2)||(s>=f2[a]&&s%2==0)){
            cout<<"Yes"<<'\n';
        }
        else{
            cout<<"No"<<"\n";
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
