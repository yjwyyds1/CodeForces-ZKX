#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int f[N],v[N],sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=1e6;i++){//nlog(n)算出每一个数的因数个数
        for(int j=i;j<=1e6;j+=i){
            f[j]++;
        }
    }
    for(int i=1;i<=1e6;i++)
    {
        v[i]=(f[i]<=4?1:0);
    }    
    for(int i=1;i<=1e6;i++){
        sum[i]=sum[i-1]+v[i];
    }
    int _;
    cin>>_;
    while (_--)
    {
        int L,R;
        cin>>L>>R;
        cout<<sum[R]-sum[L-1]<<'\n';
    }
    return 0;
}