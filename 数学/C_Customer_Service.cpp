#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        vector<vector<int>> a(n+10,vector<int>(n+10));
        vector<int> s(n+10,0);
        // set<int> p;
        priority_queue<int> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
            for(int j=n;j>=1;j--){
                if(a[i][j]!=1)break;
                else{
                    s[i]++;
                }
            }
            // b.push_back(s[i]);
            q.push(-s[i]);
        }
        int ans=0;
        while(!q.empty()){
            int x=-q.top();
            q.pop();
            if(x>=ans)ans++;
        }
        cout<<ans<<'\n';
        // for(int i=1;i<=n;i++){
        //     if(!p.count(i)){
        //         cout<<i<<'\n';
        //         break;
        //     }
        // }
    }
    return 0;
}