#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
// int s=strlen(a);

ll n;
char a[N];
stack<char> b;


void sovle()
{
    cin>>a;
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        if(a[i]=='(')b.push(a[i]);
        if(a[i]==')'&&b.empty())
        {
            cout<<"NO"<<'\n';
            return ;
        }
        if(a[i]==')'&&!b.empty())b.pop();
    }
    if(b.empty())cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sovle();
    return 0;
}