#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
// int s=strlen(a);

// ll n,k;
char  a[N];
stack<int> b;
int x1,x2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    int s=strlen(a);
    int now=0;
    for(int i=0;i<s;i++)
    {
        if(a[i]>='0'&&a[i]<='9') now*=10,now+=a[i]-'0';
        else if(a[i]=='.'){
            b.push(now);
            now=0;
        }
        if(a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='+')
        {
            x1=b.top(),b.pop();
            x2=b.top(),b.pop();
            if(a[i]=='-')b.push(x2-x1);
            if(a[i]=='/')b.push(x2/x1);
            if(a[i]=='*')b.push(x1*x2);
            if(a[i]=='+')b.push(x1+x2);
        }
    }
    cout<<b.top()<<'\n';
    return 0;
}