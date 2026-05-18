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
        ll n;
        cin>>n;
        vector<pair<ll,ll>> stk;
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll a,b;
            cin>>a>>b;
            ll len=0;
            while(!stk.empty()&&(a>0||stk.back().first==b)){
                if(stk.back().first==b){
                    len+=stk.back().second;
                    stk.pop_back();
                }
                else{
                    ll t=min(a,stk.back().second);
                    a-=t;
                    stk.back().second-=t;
                    len+=t;
                    if(stk.back().second==0){
                        stk.pop_back();
                    }
                }
            }
            ans+=a;
            len+=a;
            stk.push_back({b,len});
            cout<<ans<<" ";
        }
        cout<<'\n';
    }
    
    
    return 0;
}