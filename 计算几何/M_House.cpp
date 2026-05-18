#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;

struct point
{
    ll x;
    ll y;
    ll operator^(point b) const{
        return x*b.y-y*b.x;
    }
    ll operator*(point b) const{
        return x*b.x+y*b.y;
    }
};
point operator-(point A,const point &B){
    A.x-=B.x;
    A.y-=B.y;
    return A;
}
ll dis(point A,point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<point> k(n+10);
    for(int i=1;i<=n;i++){
        cin>>k[i].x>>k[i].y;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){//枚举C
        for(int j=1;j<=n;j++){//枚举D
            if(i==j){
                continue;
            }
            else{
                point CD=(k[j]-k[i]);
                map<ll,ll> mp1,mp2;
                int L=0,R=0;
                for(int t=1;t<=n;t++){
                    point CX=(k[t]-k[i]);
                    if((CD^CX)==0){
                        continue;
                    }
                    if((CD^CX)<0){
                        if(dis(k[t],k[i])==dis(k[t],k[j])){
                            L++;
                        }
                    }
                    if((CD^CX)>0){
                        point CB=(k[t]-k[i]);
                        point DA=(k[t]-k[j]);
                        if(CB*CD==0){
                            mp1[dis(k[t],k[i])]++;
                        }
                        if(DA*CD==0){
                            mp2[dis(k[t],k[j])]++;
                        }
                    }
                }
                for(auto [x,y]:mp1){
                    if(mp2[x]){
                        R++;
                    }
                }
                ans+=L*R;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}