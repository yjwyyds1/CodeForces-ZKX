#include <bits/stdc++.h>
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int mp[5050][5050];
int main() 
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    int  ans=0;
    vector<pair<int,int>> d;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        d.push_back({x,y});
        mp[x][y]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=d[i].first+d[i].second+d[j].first+d[j].second;
            if(t%2)continue;
            else t>>=1;
            int x1=t-d[j].second;
            int y1=t-d[i].first;
            int x2=t-d[i].second;
            int y2=t-d[j].first;
            if(0<=x1&&x1<=5000&&0<=y1&&y1<=5000&&0<=x2&&x2<=5000&&0<=y2&&y2<=5000){
                if(mp[x1][y1]&&mp[x2][y2]){
                    ans=max(ans,((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>>1);
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}