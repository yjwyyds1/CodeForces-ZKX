#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;
const int N=1e6+10;
bool v[N];
int pr[N], cnt;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll n;
    cin>>n;
    ll ct=0;
    for(int i=2;i<=n;i++)
    {
        if(!v[i]) pr[ct++]=i;
        for(int j=0;pr[j]<=n/i&&j<=ct;j++)
        {
            v[pr[j]*i]=1;
            if(i%pr[j]==0)break;
        }
    }
    // for(int i=2;i<=n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<'\n';
    cout<<ct<<'\n';
    return 0;
}