#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        ll l,r,g;
        cin>>l>>r>>g;
        ll t1=(l/g);
        ll t2=(r/g);
        if(t1*g<l){
            t1++;
        }
        if(t1==t2){
            if(t1*g==g)cout<<t1*g<<" "<<t2*g<<'\n';
            else{
                cout<<-1<<" "<<-1<<'\n';
            }
        }
        else{
            ll l=t1, r=t2;
            ll ansA=0,ansB=0;
            int ok=0;
            for (ll len = r - l; len >= 0; len --) {
                for (ll i = l; i <= r - len; i ++) {
                    if (__gcd(i, i + len) == 1) {
                        ansA=i,ansB=i+len;
                        ok=1;
                        break;
                    }
                }
                if(ok)break;
            }
            if(ansA==0&&ansB==0)cout<<-1<<" "<<-1<<'\n';
            else{
                cout<<ansA*g<<" "<<ansB*g<<'\n';
            }    
        }
        
    }
    return 0;
}