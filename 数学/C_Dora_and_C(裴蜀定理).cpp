#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int d=__gcd(a,b);
        int c[n];
        for(int i=0;i<n;i++){
            cin>>c[i];
            c[i]%=d;
        }
        sort(c,c+n);
        int ans=c[n-1]-c[0];
        for(int i=0;i<n-1;i++){
            ans=min(ans,c[i]+d-c[i+1]);
        }
        cout<<ans<<'\n';
    }
    
    
    return 0;
}