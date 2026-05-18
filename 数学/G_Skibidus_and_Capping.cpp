#include <bits/stdc++.h>
const int N=2e5+10;
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
    sieve(N);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        vector<int> a(n+10),b;
        map<ll,ll> cnt,pcnt,Tcnt,Tpcnt,Ocnt,Opcnt;
        ll s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(sum[a[i]]-sum[a[i]-1]<=2){
                b.push_back(a[i]);
                cnt[a[i]]++;
                if(sum[a[i]]-sum[a[i]-1]==1){
                    Ocnt[a[i]]++;
                    s++;
                }
                else{
                    vector<int> M;
                    int h=a[i];
                    for(auto m:primes){
                        while(h%m==0){
                            M.push_back(m);
                            h/=m;
                        }
                        if(!M.empty()){
                            break;
                        }
                    }
                    if(h>1)M.push_back(h);
                    if(M[0]!=M[1])Tcnt[M[0]]++,Tcnt[M[1]]++;
                    else{
                        Tcnt[M[0]]++;
                    }
                }
                // cout<<a[i]<<" ";
            }
        }
        ll ans=0;
        int prs=0;
        for(int i=0;i<b.size();i++){
            if(sum[b[i]]-sum[b[i]-1]==1){
                ans+=s-prs;
                prs++;
                Opcnt[b[i]]++;
                ans-=cnt[b[i]]-pcnt[b[i]];
                pcnt[b[i]]++;
                ans+=Tcnt[b[i]]-Tpcnt[b[i]];
            }
            else{
                ans+=cnt[b[i]]-pcnt[b[i]];
                pcnt[b[i]]++;
                vector<int> M;
                int h=b[i];
                for(auto m:primes){
                    while(h%m==0){
                        M.push_back(m);
                        h/=m;
                    }
                    if(!M.empty()){
                        break;
                    }
                }
                if(h>1)M.push_back(h);
                if(M[0]!=M[1]){
                    ans+=Ocnt[M[0]]-Opcnt[M[0]];
                    ans+=Ocnt[M[1]]-Opcnt[M[1]];
                    Tpcnt[M[0]]++,Tpcnt[M[1]]++;
                }
                else{
                    ans+=Ocnt[M[0]]-Opcnt[M[0]];
                    Tpcnt[M[0]]++;
                }
            }
        }
        cout<<ans<<'\n';
        // cout<<'\n';
    }
    return 0;
}