#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e6+10;
queue<int> q;
stack<int> s;

int main() 
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        q.push(l);
    }
    while(1)
    {
        vector<int> a;
        bool t=0;
        while(1)
        {
            if(!a.size())
            {
                if(s.size())
                {
                    a.push_back(s.top());
                    s.pop();
                }
                else
                {
                    if(q.size())
                    {
                        a.push_back(q.front());
                        q.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(s.size()&&s.top()<=a.back())
                {
                    a.push_back(s.top());
                    s.pop();
                }
                else
                {
                    while(q.size()&&s.size()<=m)
                    {
                        auto r=q.front();
                        if(r<=a.back())
                        {
                            a.push_back(r);
                            q.pop();
                            break;
                        }
                        else
                        {
                            if(s.size()==m)
                            {
                                t=1;
                                break;
                            }
                            else
                            {
                                s.push(r);
                                q.pop();
                            }
                        }
                    }
                    if(!q.size()&&(!s.size()||s.top()>a.back()))
                    {
                        break;
                    }
                }
            }
            if(t||a.size()==k)
            {
                break;
            }
        }
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        if(!s.size()&&!q.size())
        {
            break;
        }
    }
    return 0;
}