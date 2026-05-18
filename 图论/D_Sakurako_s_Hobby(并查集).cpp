#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[N];
string b;
int ans[N];
int f[N];
int Find(int x)
{
    if(f[x]==x)return x;
    else 
    {
        f[x]=Find(f[x]);
        return f[x];
    }
}
void uion(int i,int j)
{
    i=Find(i);
    j=Find(j);
    if(ans[i]<ans[j]){
        f[i]=j;
        ans[j]+=ans[i];
    }
    else{
        f[j]=i;
        ans[i]+=ans[j];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[i]=i;
        }
        cin>>b;
        b='%'+b;
        for(int i=1;i<=n;i++){
            ans[i]=(b[i]=='0');
        }
        for(int i=1;i<=n;i++){
            uion(i,a[i]);
        }
        for(int i=1;i<=n;i++){
            cout<<ans[Find(i)]/2<<" ";
        }
        cout<<'\n';
    }
    
    
    return 0;
}
// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;
// const int N=1e6+10;

// int main() 
// {
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++)f[i]=i;
//     for(int i=1;i<=q;i++)
//     {
//         char a;
//         int b,c;
//         cin>>a>>b>>c;
//         if(a=='M')
//         {
//             uion(b,c);
//         }
//         if(a=='Q')
//         {
//             if(Find(b)==Find(c)) cout<<"Yes"<<'\n';
//             else cout<<"No"<<'\n';
//         }
//     }
//     return 0;
// }