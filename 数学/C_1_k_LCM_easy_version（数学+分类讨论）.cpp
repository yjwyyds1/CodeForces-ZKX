#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=k-3;i++){
            cout<<1<<" ";
        }
        n-=(k-3);
        if(n%2){
            if(n%3==0){
                cout<<n/3<<" "<<n/3<<" "<<n/3<<'\n';
            }
            else{
                cout<<1<<" "<<n/2<<" "<<n/2<<'\n';
            }
        }
        else{
            int now=1;
            while(n%2==0&&n>4){
                n/=2;
                now*=2;
            }
            if(n%2){
                cout<<now<<" "<<(n/2)*now<<" "<<(n/2)*now<<'\n';
            }
            else{
                cout<<now<<" "<<now<<" "<<2*now<<'\n';
            }
        }
        // if(n%3==0){
        //     for(int i=1;i<=3;i++){
        //         cout<<n/3<<" ";
        //     }
        //     cout<<'\n';
        // }
        // else if(n%3==1){
        //     if(n%2){

        //     }
        //     else{

        //     }
        //     // if((n/3)%2){
        //     //     cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<'\n';
        //     // }
        //     // else{
        //     //     cout<<1<<" "<<n/2<<" "<<n/2<<'\n';
        //     // }
        // }
        // else if(n%3==2){
        //     if((n/3)%2){
        //         cout<<1<<" "<<n/2<<" "<<n/2<<'\n';
        //     }
        //     else{
        //         n/=2;
        //         // cout<<n<<'\n';
        //         if((n/3)%2){
        //             cout<<4<<" "<<((n-2)/2)*2<<" "<<((n-2)/2)*2<<'\n';
        //         }
        //         else{
        //             cout<<2<<" "<<(n/2)*2<<" "<<(n/2)*2<<'\n';
                    
        //         }
        //     }
        // }
    }
    return 0;
}