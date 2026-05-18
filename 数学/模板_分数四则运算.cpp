#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;

ll gcd(ll x,ll y){
    return y?gcd(y,x%y):x;
}
void fsjs(){
    ll a,b,op,c,d;
    cin>>a>>b>>op>>c>>d;
    if(b==0||d==0||(c==0&&op==4)){
        cout<<"inf"<<'\n';
        return ;
    }
    if(op==2)c=-c;
    if(op==4)swap(c,d);
    ll fz,fm;
    if(op==1||op==2){
        fz=a*d+b*c;
        fm=b*d;
    }
    if(op==3||op==4){
        fz=a*c;
        fm=b*d;
    }
    ll g=gcd(fz,fm);
    fz/=g,fm/=g;
    if(fm<0)fz=-fz,fm=-fm;
    cout<<fz<<" "<<fm<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        fsjs();
    }
    return 0;
}
