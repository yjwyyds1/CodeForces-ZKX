#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int n;
vector<int> x(7);
int f(int x){
    int res=0;
    while(x){
        res++;
        x/=10;
    }
    return res;
}
void c(){
    string ns=to_string(n);
    int now=0;
    for(int i=1;i<=6;i++){
        x[i]=x[i-1]*10+(ns[now]-'0');
        now=(now+1)%f(n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        cin>>n;
        c();
        //n*a-x=b   x必须是由n拼接而成的
        //a*len[n]-len[x]=b
        //x-len[x]=a*(n-len[n])
        vector<pair<int,int>> ans;
        for(int i=1;i<=10000;i++){
            for(int j=1;j<=6;j++){
                int b=i*f(n)-j;
                if(n*i-x[j]==b&&(1<=b&&b<=min(10000,i*n))){
                    ans.push_back({i,b});
                }
            }
            
        }
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<'\n';
        }
        // cout<<'\n';
    }

    
    
    return 0;
}