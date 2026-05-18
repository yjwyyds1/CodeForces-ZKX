#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;

struct q{
    long double l;
    long double r;
    
}a[N];
bool cmp(q a,q b){
    if(a.l!=b.l){
        return a.l<b.l;
    }
    else{
        return a.r<b.r;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,R;
    cin>>n>>R;
    int ok=1;
    ll ans=1;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(y>R){
            ok=0;
        }
        else{
            a[i].l=x-sqrtf((R*R)-(y*y));
            a[i].r=x+sqrtf((R*R)-(y*y));
        }
    }
    sort(a+1,a+n+1,cmp);
    long double lx=-inf,rx=inf;
    for(int i=1;i<=n;i++){
        lx=max(a[i].l,lx);
        rx=min(a[i].r,rx);
        if(i>1){
            lx=max(a[i].l,lx);
            rx=min(a[i].r,rx);
            if(lx>rx){
                ans++;
                lx=a[i].l;
                rx=a[i].r;
            }
        }
    }
    if(ok==0){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans<<'\n';
    }
    return 0;
}


