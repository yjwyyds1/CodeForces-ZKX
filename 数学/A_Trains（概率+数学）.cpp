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
    ll a,b;
    cin>>a>>b;
    ll L=lcm(a,b);
    a=L/a,b=L/b;
    if(a>b){
        b++;
    }
    else{
        a++;
    }
    if(a>b){
        cout<<"Dasha";
    }
    if(a==b){
        cout<<"Equal";
    }
    if(a<b){
        cout<<"Masha";
    }
    return 0;
}
