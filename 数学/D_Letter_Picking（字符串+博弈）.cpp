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
    while (_--)
    {
        string a;
        cin>>a;
        int n=a.size();
        a='2'+a;
        int l=1,r=n;
        while(l<r&&a[l]==a[r])l++,r--;
        if(l>=r){
            cout<<"Draw"<<'\n';
        }
        else{
            int ok=1;
            for(int i=l;i+1<=r;i+=2){
                if(a[i]!=a[i+1]){
                    ok=0;
                }
            }
            cout<<(ok==1?"Draw":"Alice")<<'\n';
        }
        
    
    }
    return 0;
}