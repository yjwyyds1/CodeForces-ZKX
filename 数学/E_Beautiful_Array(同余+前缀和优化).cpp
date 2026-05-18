#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        map<int,vector<int>> mod;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mod[a[i]%k].push_back(a[i]);
        }
        if(n%2){
            int cnt=0;
            for(auto [x,y]:mod){
                if(mod[x].size()%2){
                    cnt++;
                }
            }
            if(cnt>1){
                cout<<-1<<'\n';
            }
            else{
                ll ans=0;
                for(auto [x,y]:mod){
                    sort(mod[x].begin(),mod[x].end());
                    // for(int i=0;i<mod[x].size();i++){
                    //     cout<<mod[x][i]<<" ";
                    // }
                    // cout<<'\n';
                    if(mod[x].size()%2==0){
                        for(int i=0;i<mod[x].size();i+=2){
                            ans+=(mod[x][i+1]-mod[x][i])/k;
                        }
                    }
                    else{
                        if(mod[x].size()==1){
                            continue;
                        }
                        else{
                            vector<ll> sj,so;
                            ll res=1e18;
                            sj.push_back(0),so.push_back(0);
                            for(int i=0;i<mod[x].size()-1;i++){
                                if(i%2==0){
                                    sj.push_back(sj.back()+(mod[x][i+1]-mod[x][i])/k);
                                }
                                else{
                                    so.push_back(so.back()+(mod[x][i+1]-mod[x][i])/k);
                                }
                            }
                            for(int i=0;i<mod[x].size();i++){
                                if(i%2){
                                    res=min(res,sj[(i+1)/2]+so[mod[x].size()/2]-so[i/2]);
                                }
                                else{
                                    res=min(res,sj[i/2]+so[mod[x].size()/2]-so[i/2]);
                                }

                            }
                            ans+=res;
                            // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
                        }
                    }
                    // cout<<ans<<'\n';
                    
                }
                cout<<ans<<'\n';
            }
            
        }
        else{
            int cnt=0;
            for(auto [x,y]:mod){
                if(mod[x].size()%2){
                    cnt++;
                }
            }
            if(cnt){
                cout<<-1<<'\n';
            }
            else{
                ll ans=0;
                for(auto [x,y]:mod){
                    sort(mod[x].begin(),mod[x].end());
                    for(int i=0;i<mod[x].size();i+=2){
                        ans+=(mod[x][i+1]-mod[x][i])/k;
                    }
                }
                cout<<ans<<'\n';
            }
        }
    }
    
    
    return 0;
}
// 3 9 18 30     2 4
// 1 10 22 4 28
// 2 14 17 20    5
