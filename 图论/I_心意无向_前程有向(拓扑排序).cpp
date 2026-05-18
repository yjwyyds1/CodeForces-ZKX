#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vector<pair<int,int>> p;
    vector<vector<int>> e(n+1);
    vector<int> d(n+1,0);
    for(int i=1;i<=m1;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    for(int i=1;i<=m2;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        d[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!d[i])q.push(i);
    }
    vector<int> tp;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        tp.push_back(t);
        for(auto x:e[t]){
            d[x]--;
            if(!d[x]){
                q.push(x);
            }
        }
    }
    if(tp.size()!=n){
        cout<<-1<<'\n';
    }
    else{
        vector<int> f(n+1);
        for(int i=0;i<n;i++){
            f[tp[i]]=i;
        }
        for(int i=0;i<m1;i++){
            int k1=p[i].first,k2=p[i].second;
            if(f[k1]<f[k2]){
                cout<<k1<<" "<<k2<<'\n';
            }
            else{
                cout<<k2<<" "<<k1<<'\n';
            }
        }
    }
    return 0;
}
