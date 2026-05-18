#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
std::vector<int> minp;//最小质因数
std::vector<int> primes;//质数列表
std::vector<int> phi;//欧拉函数
std::vector<int> sum;//质数个数
void sieve(int n) {
    minp.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
            sum[i] = 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            sum[i * p] = sum[i] + 1;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
    for(int i=2;i<=n;i++)sum[i]+=sum[i-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(5e6);
    int _;
    cin>>_;
    while(_--){
        int a,b;
        cin>>a>>b;
        cout<<sum[a]-sum[b]<<'\n';
    }
    
    return 0;
}