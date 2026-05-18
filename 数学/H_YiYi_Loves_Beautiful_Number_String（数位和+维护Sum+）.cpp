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
    map<int,vector<int>> mp;
    for(int i=0;i<=5e6;i++){
        int j=i,k=0;
        while(j){
            k+=j%10;
            j/=10;
        }
        mp[i+k].push_back(i);
    }
    int _;
    cin>>_;
    while(_--){
        int n,q;
        cin>>n>>q;
        string a;
        cin>>a;
        vector<int> cnt(10,0);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i]-'0',cnt[a[i]-'0']++;
        }
        for(int i=1;i<=q;i++){
            int x;
            char c;
            cin>>x>>c;
            x--;
            cnt[a[x]-'0']--,sum-=a[x]-'0';
            a[x]=c;
            cnt[a[x]-'0']++,sum+=a[x]-'0';
            int f=0;
            for(auto ans:mp[sum]){
                vector<int> p(10,0);
                int res=ans;
                while(res){
                    p[res%10]++;
                    res/=10;
                }
                int ok=1;
                for(int j=0;j<=9;j++){
                    if(p[j]>cnt[j]){
                        ok=0;
                    }
                }
                if(ok)f=1;
            }
            cout<<(f?"YES":"NO")<<'\n';
        }
    }
    return 0;
}
