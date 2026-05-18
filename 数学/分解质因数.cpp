#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int _;
    cin>>_;
    while(_--)
    {
        ll n;
        cin>>n;
        for(int i=2;i<=n/i;i++)
        {
            int ct=0;
            while(n%i==0)
            {
                n/=i;
                ct++;
            }
            if(ct>0)
            {
                cout<<i<<" "<<ct<<'\n'; 
            }
        }
        if(n>1)
        {
            cout<<n<<" "<<1<<'\n';
        }
        cout<<'\n';
    }

    return 0;
}