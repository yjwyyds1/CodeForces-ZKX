#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll  long long int
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    deque<int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]>=a[i])q.pop_back();
        q.push_back(i);
        if(q.front()<i-k+1)q.pop_front();
        if(i>=k)cout<<a[q.front()]<<" ";
    }
    cout<<'\n';
    q.clear();
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]<=a[i])q.pop_back();
        q.push_back(i);
        if(q.front()<i-k+1)q.pop_front();
        if(i>=k)cout<<a[q.front()]<<" ";
    }
    cout<<'\n';
    return 0;
}
