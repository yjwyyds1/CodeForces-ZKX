#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
vector<vector<int>> sum(5500,vector<int>(5500,0));
int n;
bool ck(int x){
    int ok=1;
    for(int i=1;i<=n;i+=x){
        for(int j=1;j<=n;j+=x){
            ll S=sum[i+x-1][j+x-1]-sum[i+x-1][j-1]-sum[i-1][j+x-1]+sum[i-1][j-1];
            ok&=(S==x*x||S==0);
            if(ok==0)return 0;
        }
    }
    return 1;
    // int ok=1;
    // int x1=1,y1=1,x2=n,y2=x;
    // for(int i=1;i<=n/x;i++){
    //     ll XH=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
    //     ok&=(XH==(x2-x1+1)*(y2-y1+1)||XH==0);
    //     if(ok==0)return 0;
    //     y2+=x;
    //     x1+=x;
    //     y1+=x;
    // }
    // x1=1,y1=1,x2=x,y2=n;
    // for(int i=1;i<=n;i++){
    //     ll XH=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
    //     ok&=(XH==(x2-x1+1)*(y2-y1+1)||XH==0);
    //     if(ok==0)return 0;
    //     x1+=x;
    //     y1+=x;
    //     x2+=x;
    // }
    // return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<vector<int>> f(n+10,vector<int>(n+10));
    map<char,string> p;
    p['0']="0000";
    p['1']="0001";
    p['2']="0010";
    p['3']="0011";
    p['4']="0100";
    p['5']="0101";
    p['6']="0110";
    p['7']="0111";
    p['8']="1000";
    p['9']="1001";
    p['A']="1010";
    p['B']="1011";
    p['C']="1100";
    p['D']="1101";
    p['E']="1110";
    p['F']="1111";
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        for(int j=0;j<a.size();j++){
            for(int k=j*4+1;k<=(j+1)*4;k++){
                f[i][k]=p[a[j]][k%4-1==-1?3:k%4-1]-'0';
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+f[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j];
    //     }
    //     cout<<'\n';
    // }
    int ans=1;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(ck(i))ans=max(ans,i);
            if(n/i!=i){
                if(ck(n/i))ans=max(ans,n/i);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}