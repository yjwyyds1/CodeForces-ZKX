#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int _;
    // cin>>_;
    // while (_--)
    // {
        
    // }
    int n;
    cin>>n;
    vector<ll> a(n+10);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        for(ll j=2;j*j<=a[i];j++){
            while(a[i]%(j*j)==0){
                a[i]/=(j*j);//去掉所有分解出来的偶数幂
            }
        }
    }
    map<ll,ll> mp;
    ll ans=0; 
    for(ll i=1;i<=n;i++){
        if(a[i]){//如存在另外一对，就可以凑成偶数
            ans+=mp[a[i]];
            ans+=mp[0];
        }
        else{
            ans+=i-1;
        }
        mp[a[i]]++;
    }
    cout<<ans<<'\n';
    return 0;
}