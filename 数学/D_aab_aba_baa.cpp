#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
void solve(){
    ll A,B,k;
    cin>>A>>B>>k;
    ll c[61][61];
    for(int i=0;i<=A+B;i++){
        c[i][0]=1;
        c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    // for(int i=0;i<=A+B;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    string s;
    while(A&&B){
        // cout<<k<<" "<<c[A+B-1][A-1]<<'\n';
        if(k<=c[A+B-1][A-1]){
            s+='a';
            A--;
        }
        else{
            s+='b';
            k-=c[A+B-1][A-1];
            B--;
        }
    }
    for(int i=1;i<=A;i++)s+='a';
    for(int i=1;i<=B;i++)s+='b';
    cout<<s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//  freopen("zkx.in","r",stdin);
	//  freopen("zkx.out","w",stdout);
    int _;
    _=1;
    // cin>>_;
     while(_--){
        solve();
    }
    return 0;
}