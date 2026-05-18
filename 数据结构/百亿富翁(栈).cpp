#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin>>n;
    int a[n+1],l[n+1],r[n+1];
    stack<int> s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
      while(s.size()&&a[s.top()]<=a[i])s.pop();
      if(s.size())
      {
        l[i]=s.top();
      }
      else 
      {
        l[i]=-1;
      }
      s.push(i);
    }
    while(s.size())s.pop();
    for(int i=n;i>=1;i--)
    {
      while(s.size()&&a[s.top()]<=a[i])s.pop();
      if(s.size())
      {
        r[i]=s.top();
      }
      else 
      {
        r[i]=-1;
      }
      s.push(i);
    }
    for(int i=1;i<=n;i++)cout<<l[i]<<" ";
    cout<<'\n';
    for(int i=1;i<=n;i++)cout<<r[i]<<" ";
    cout<<'\n';
    return 0;
}