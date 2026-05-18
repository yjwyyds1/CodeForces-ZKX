#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;

ll ck(int k,int x){
    __int128 kx=1,ans=0;
    for(int i=0;i<=x;i++){
        ans+=kx;
        kx*=k;
        if(ans>1e18) return 2e18;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        ll n;
        cin>>n;
        int ok=0;
        for(int i=2;i<=63;i++){
            int l=2,r=1e9;
            while(l<=r){
                int mid=l+r>>1;
                if(ck(mid,i)==n){
                    ok=1;
                    break;
                }
                if(ck(mid,i)<n){
                    l=mid+1;
                }
                if(ck(mid,i)>n){
                    r=mid-1;
                }
            }
            if(ok){
                break;
            }
        }
        if(ok){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
    
    
    return 0;
}