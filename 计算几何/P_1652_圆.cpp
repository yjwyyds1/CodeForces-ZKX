#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double 
using namespace std;
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
// cout<<fixed<<setprecision(0)
struct vc{
    int x,y,r;
}a[N];
ld L(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool ck(int x1,int y1,int ox,int oy,int R){
    if(L(x1,y1,ox,oy)>R){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].y;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].r;
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(ck(x1,y1,a[i].x,a[i].y,a[i].r)^ck(x2,y2,a[i].x,a[i].y,a[i].r)){
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}


