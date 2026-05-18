#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double 
using namespace std;
const int N=3e5+10;
const int inf = 0x3f3f3f3f;

struct vc{
    ld  x,y,theart;
    vc operator - (const vc& p) const 
    { 
        return {x - p.x, y - p.y, 0}; 
    }
};
vc a[N+10],s[N+10];
ld cross(vc p1, vc p2){
    return p1.x * p2.y - p1.y * p2.x; 
}
ld L(vc p1,vc p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool cmp(vc pa,vc pb){
    if(pa.theart==pb.theart){
        return L(pa,a[1])<L(pb,a[1]);
    }
    else{
        return pa.theart<pb.theart;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    ld PI=3.14159265358979323846;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        if(a[i].y<a[1].y||a[i].y==a[1].y&&a[i].x<a[1].x){
            swap(a[1],a[i]);
        }
    }
    for(int i=2;i<=n;i++){
        a[i].theart=atan2(a[i].y-a[1].y,a[i].x-a[1].x);
    }
    sort(a+2,a+n+1,cmp);
    int top=0;
    s[++top]=a[1];
    s[++top]=a[2];
    for(int i=3;i<=n;i++){
        while(top>2&&cross(s[top]-s[top-1],a[i]-s[top-1])<=0)top--;
        s[++top]=a[i];
    }
    ld ans=0;
    for(int i=1;i<=top;i++){
        ans+=L(s[i],s[i%top+1]);
    }
    ans+=PI*d*2;
    cout<<fixed<<setprecision(0)<<ans<<'\n';
    return 0;
}


