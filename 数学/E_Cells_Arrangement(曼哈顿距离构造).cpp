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
        int n;
        cin>>n;
        cout<<1<<" "<<1<<'\n';
        cout<<1<<" "<<2<<'\n';
        for(int i=3;i<=n;i++){
            cout<<i<<" "<<i<<'\n';
        }
        cout<<'\n';
    }
    
    
    return 0;
}