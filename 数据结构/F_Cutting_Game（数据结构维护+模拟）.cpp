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
    int _;
    cin>>_;
    while(_--){
        int n,m,f,q;
        cin>>n>>m>>f>>q;
        set<pair<int,int>> pox,poy;
        for(int i=1;i<=f;i++){
            int x,y;
            cin>>x>>y;
            pox.insert({x,y});
            poy.insert({y,x});
        }
        vector<int> a(2,0);
        int lx=1,ly=1,rx=n,ry=m;
        int t=0;
        for(int i=1;i<=q;i++){
            char c;
            int k;
            cin>>c>>k;
            if(c=='U'){
                while(!pox.empty()&&(*pox.begin()).first<lx+k){
                    int x=(*pox.begin()).first;
                    int y=(*pox.begin()).second;
                    pox.erase({x,y});
                    poy.erase({y,x});
                    a[t]++;
                }
                lx+=k;
            }
            if(c=='D'){
                while(!pox.empty()){
                    int x=(*prev(pox.end())).first;
                    int y=(*prev(pox.end())).second;
                    if(x<=rx-k)break;
                    pox.erase({x,y});
                    poy.erase({y,x});
                    a[t]++;
                }
                rx-=k;
            }
            if(c=='L'){
                while(!poy.empty()&&(*poy.begin()).first<ly+k){
                    int x=(*poy.begin()).second;
                    int y=(*poy.begin()).first;
                    pox.erase({x,y});
                    poy.erase({y,x});
                    a[t]++;
                }
                ly+=k;
            }
            if(c=='R'){
                while(!poy.empty()){
                    int x=(*prev(poy.end())).second;
                    int y=(*prev(poy.end())).first;
                    if(y<=ry-k)break;
                    pox.erase({x,y});
                    poy.erase({y,x});
                    a[t]++;
                }
                ry-=k;
            }
            t^=1;
        }
        cout<<a[0]<<" "<<a[1]<<'\n';
    }
    return 0;
}