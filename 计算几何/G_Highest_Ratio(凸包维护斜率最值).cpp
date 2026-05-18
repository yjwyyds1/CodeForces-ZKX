#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<ld> a(N,0);
vector<ld> ans(N);
vector<int> s(N);

ld f(int x,int y){
    return  (a[x]-a[y])/(x-y);  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int top=0;
    top++;
    s[top]=n;
    for(int i=n-1;i>=0;i--){
        while(top>1&&f(s[top-1],i)<f(s[top-1],s[top])){
            top--;
        }
        ans[i+1]=f(s[top],i);
        top++;
        s[top]=i;
    }
    cout<<fixed<<setprecision(8);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }   
    return 0;
}