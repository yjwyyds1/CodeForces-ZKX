#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double 
using namespace std;
const int N=3e5+10;
const int inf = 0x3f3f3f3f;


struct vc{
    ll x,y;
};
double L(vc p1,vc p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
ld f(vc p1,vc p2,vc p3){
    ld dx12=L(p1,p2);
    ld dx13=L(p1,p3);
    ld dx23=L(p2,p3);
    ld p=(dx12+dx13+dx23)/2;
    return sqrt(p*(p-dx12)*(p-dx13)*(p-dx23))/dx13;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vc> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=2;i++){
        a.push_back(a[i]);
    }
    ld ans=inf;
    for(int i=1;i<=n;i++){
        ans=min(f(a[i],a[i+1],a[i+2]),ans);
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
    return 0;
}


