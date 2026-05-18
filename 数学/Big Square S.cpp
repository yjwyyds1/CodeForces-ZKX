#include <bits/stdc++.h>
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int mp[500][500];
int main() 
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>> d;
    vector<pair<int,int>> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='J'){
                d.push_back({i,j});
                mp[i][j]=1;
            }
            if(a[i][j]=='*'){
                k.push_back({i,j});
            }
        }
    }
    // for(int i=0;i<d.size();i++){
    //     cout<<d[i].first<<" "<<d[i].second<<'\n';
    // }
    // cout<<'\n';
    int ans=0;
    for(int i=0;i<k.size();i++){
        for(int j=0;j<d.size();j++){
            int t=k[i].first+k[i].second+d[j].first+d[j].second;
            if(t%2) continue;
            else t>>=1;
            int x1=t-d[j].second;
            int y1=t-k[i].first;
            int x2=t-k[i].second;
            int y2=t-d[j].first;
            if(0<=x1&&x1<=n&&0<=y1&&y1<=n&&0<=x2&&x2<=n&&0<=y2&&y2<=n){
                if(mp[x1][y1]&&mp[x2][y2]){
                    ans=max(ans,((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>>1);
                }
            }
        }
    }
    for(int i=0;i<d.size();i++){
        for(int j=i+1;j<d.size();j++){
            int t=d[i].first+d[i].second+d[j].first+d[j].second;
            if(t%2) continue;
            else t>>=1;
            int x1=t-d[j].second;
            int y1=t-d[i].first;
            int x2=t-d[i].second;
            int y2=t-d[j].first;
            if(0<=x1&&x1<=n&&0<=y1&&y1<=n&&0<=x2&&x2<=n&&0<=y2&&y2<=n){
                if(mp[x1][y1]&&mp[x2][y2]){
                    ans=max(ans,((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>>1);
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}