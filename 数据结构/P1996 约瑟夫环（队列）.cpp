#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
// int s=strlen(a);

ll n,k;
void resolve()
{
    cin>>n>>k;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    ll t=1;
    while(!q.empty())
    {
        if(t==k)
        {
            cout<<q.front()<<" ";
            q.pop();
            t=1;
        }
        else
        {
            t++;
            // cout<<q.front()<<" ";
            q.push(q.front());
            q.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    resolve();
    return 0;
}
