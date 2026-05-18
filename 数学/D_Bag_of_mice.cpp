#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w,b;
    cin>>w>>b;
    vector<vector<ld>> dp(w+10,vector<ld>(b+10));
    for(ld i=1;i<=w;i++){
        dp[i][0]=1;
        dp[i][1]=i/(i+1);
    }
    for(ld i=1;i<=w;i++){//白鼠
        for(ld j=2;j<=b;j++){//黑鼠
            dp[i][j]+=i/(i+j);
            dp[i][j]+=(j/(i+j)*(j-1)/(i+j-1)*(i/(j+i-2))*dp[i-1][j-2]);
            if(j>=3){
                dp[i][j]+=(j/(i+j)*(j-1)/(i+j-1)*((j-2)/(i+j-2))*dp[i][j-3]);
            }
        }
    }
    cout<<fixed<<setprecision(9);
    cout<<dp[w][b];
    return 0;
}