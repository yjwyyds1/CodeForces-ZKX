#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,d,s;
    cin>>n>>d>>s;
    n/=s,d/=s;
    if(d==0)cout<<s<<'\n';
    else{
        if(n<=d+1)cout<<n*s<<'\n';
        else{
            n=min(n,2*d);
            if(n%2==0)cout<<n*s<<'\n';
            else{
                for(ll i=2;i*i<=n;i++){
                    if(n%i==0){
                        if(n-n/i<=d){
                            cout<<n*s<<'\n';
                            return 0;
                        }
                    }
                }
                cout<<(n-1)*s<<'\n';
            }
        }
    }
    return 0;
}
