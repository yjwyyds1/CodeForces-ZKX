#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<ll> a(n+10),b(m+10);
    ll sa=0,sb=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa+=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        sb+=b[i];
    }
    map<ll,ll> Ma,Mb;
    for(int i=1;i<=n;i++){
        Ma[sa-a[i]]=1;
        // cout<<sa-a[i]<<'\n';
    }
    for(int i=1;i<=m;i++){
        Mb[sb-b[i]]=1;
        // cout<<sb-b[i]<<'\n';
    }
    /*
    0
    -5
    1

    1
    -3
    0 
    */
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        int ok=1;
        for(int i=1;i<=sqrt(abs(x));i++){
            if(x%i==0&&((Ma[i]&&Mb[x/i]||Mb[i]&&Ma[x/i])||(Ma[-i]&&Mb[-x/i]||Mb[-i]&&Ma[-x/i]))){
                cout<<"YES"<<endl;
                ok=0;
                break;
            }
        }
        if(ok) cout<<"NO"<<endl;
    }
    // ll sum=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         sum+=a[i]*b[j];
    //     }
    // }
    // cout<<sum<<'\n';
    // map<ll,ll> f; 
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         f[sum-(a[i]*sb+b[j]*sa-a[i]*b[j])]=1;
    //         // cout<<sum-(a[i]*sa+b[j]*sb-(a[i]*b[j]))<<'\n';
    //         // cout<<sum<<" "<<(a[i]*sb+b[j]*sa-(a[i]*b[j]))<<'\n';
    //         /*
    //         2
    //         2
    //         2
    //         7
    //         -13
    //         2
    //         1
    //         5
    //         2
    //         */
    //         // cout<<(a[i]*sb+b[j]*sa-(a[i]*b[j]))<<'\n';
    //     }
    // }
    // for(int i=1;i<=q;i++){
    //     int c;
    //     cin>>c;
    //     ll ans=sum-c;
    //     int ok=0;
    //     for(int j=1;j<=n;j++){
    //         int idx=lower_bound(b.begin()+1,b.end(),(ans-sb*a[i])/(sa-a[i]))-b.begin()+1;
    //         if(idx<=m&&idx>=1&&b[idx]*sa+a[i]*sb-a[i]*b[idx]==ans){
    //             cout<<"YES"<<'\n';
    //             ok=1;
    //             break;
    //         }
    //     }
    //     if(!ok)cout<<"NO"<<'\n';
    //     // cout<<(f[c]?"YES":"NO")<<'\n';
    // }
    return 0;
}
