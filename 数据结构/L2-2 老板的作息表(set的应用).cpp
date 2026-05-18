#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long int
#define dbg1(a) cout<<a<<'\n';
#define dbg2(a, b) cout<<a<<" "<<b<<'\n';
#define dbg3(a, b, c) cout<<a<<" "<<b<<" "<<c<<'\n';
#define f first
#define s second
using namespace std;
const int N=1e6+10;
// int s=strlen(a);

set<pair<string,string>>d;//set自动排序
int main() 
{
    int n;
    string a,b,c="00:00:00";
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>b;//读两次把—覆盖
        d.insert({a,b});
    }
    d.insert({"23:59:59",""});
    for(auto x:d)
    {
        if(x.first>c)cout<<c<<" - "<<x.first<<'\n';
        c=x.second;
    }
    return 0;
}