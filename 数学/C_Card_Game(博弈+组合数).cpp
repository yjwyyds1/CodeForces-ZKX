#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
ll C[70][70];
ll A[70],B[70];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mod=998244353;
    for(int i=0;i<=60;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    A[2]=1,B[2]=0;
    for(int i=4;i<=60;i+=2){
        A[i]=(C[i-1][i/2]+B[i-2])%mod;
        B[i]=(C[i][i/2]-A[i]-1+mod)%mod;
    }
    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        cout<<A[n]<<" "<<B[n]<<" "<<1<<'\n';
    }
    return 0;
}