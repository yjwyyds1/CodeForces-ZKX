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
        int mask=0;
        int a[n],b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<pair<int,int>> rg;
        rg.push_back({0,n-1});
        for(int i=29;i>=0;i--){
            int ok=1;
            vector<pair<int,int>> nxt;
            for(auto [L,R]:rg){
                vector<int> cnt(2,0);
                for(int j=L;j<=R;j++)cnt[0]+=(a[j]>>i&1);
                for(int j=L;j<=R;j++)cnt[1]+=((b[j]>>i&1)==0);
                if(cnt[0]==cnt[1]){
                    if(cnt[0]&&cnt[0]!=(R-L+1)){
                        partition(a+L,a+R+1,[&](int x){
                            return (x>>i&1)==1;
                        });
                        partition(b+L,b+R+1,[&](int x){
                            return (x>>i&1)==0; 
                        });
                        nxt.emplace_back(L,cnt[0]+L-1);
                        nxt.emplace_back(L+cnt[0],R);
                    }   
                    else{
                        nxt.emplace_back(L,R);
                    }
                }
                else{
                    ok=0;
                    break;
                }
            }
            if(ok){
                rg=nxt;
                mask|=(1<<i);
            }
        }
        cout<<mask<<'\n';
    }
    return 0;
}