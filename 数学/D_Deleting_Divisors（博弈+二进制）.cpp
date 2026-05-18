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
        int n;
        cin>>n;
        int cnt=0,z=0;
        for(int i=31;i>=0;i--){
            cnt+=(n>>i&1);
            if(n>>i&1)z=max(i,z);
        }        
        if(cnt==1){
            if(z==0){
                cout<<"Bob"<<'\n';
            }
            else{
                if(z%2==0)cout<<"Alice"<<'\n';
                else cout<<"Bob"<<'\n';
            }
            
        }
        else{
            cout<<(n%2?"Bob":"Alice")<<'\n';
        }
    }
    return 0;
}