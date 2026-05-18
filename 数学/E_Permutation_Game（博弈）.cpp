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
        vector<int> a(n+1);
        int f=0,s=0,p=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p+=(a[i]!=i&&a[i]!=n-i+1);
            f+=(a[i]==i);
            s+=(a[i]==n-i+1);
        }
        if(f+p<s)cout<<"Second"<<'\n';
        else if(s+p<=f)cout<<"First"<<'\n';
        else cout<<"Tie"<<'\n';
        // if(p==n)cout<<"Tie"<<'\n';
        // else{
        //     if(f>s)cout<<"First"<<'\n';
        //     else if(f<s){
        //         cout<<"Second"<<'\n';
        //     }
        // }
        
        // else if(f==s){
        //     cout<<""<<'\n';
        // }
    }
    return 0;
}