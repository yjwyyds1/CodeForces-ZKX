#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,y;
    cin>>x>>y;
    if(y%x!=0){
        cout<<0<<'\n';
    }
    else{
        x=y/x;
        ll cnt=0;
        set<int> s;
        for(int i=2;i*i<=x;i++){
            while(x%i==0){
                s.insert(i);
                x/=i;
            }
        }
        if(x>1){
            s.insert(x);
        }

        cnt+=s.size();
        cout<<(1ll<<cnt)<<'\n';
    }
    
    return 0;
}
// ll yz=2;
// while(x>1){
//     if(x%yz==0){
//         cnt++;
//         while(x%yz==0){
//             x/=yz;
//         }
//     }
//     yz++;
// }
// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     ll x,y;
//     cin>>x>>y;
//     if(y%x!=0){
//         cout<<0<<'\n';
//     }
//     else{
//         x=y/x;
//         ll cnt=0;
//         // cout<<x<<'\n';
//         for(ll i=2;i*i<=x;i++){
//             // if(x<=1)break;
//             int ok=0;
//             while(x%i==0){
//                 ok=1;
//                 x/=i;
//             }
//             if(ok){
//                 // cout<<x<<'\n';
//                 cnt++;
//             }
            
//         }
//         if(x>1)cnt++;
//         cout<<(1ll<<cnt)<<'\n';
//     }
    
//     return 0;
// }