#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int n;
vector<int> a(N);
bool ck(int k){//n分成k段
    if(k==n)return 1;
    int d=-1;
    for(int i=1;i<=k;i++){
        for(int j=i;j<=n;j+=k){
            if(d==-1)d=abs(a[j]-a[i]);
            else{
                d=__gcd(d,abs(a[j]-a[i]));
            }
        }
        if(d==1){
            return 0;
        }
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll ans=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(ck(i)){
                    ans++;
                }
                if(i!=n/i){
                    if(ck(n/i)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    
    
    return 0;
}