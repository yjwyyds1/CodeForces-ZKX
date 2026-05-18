// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;
// const int N=1e6+10;

// map<string,int> mp;

// int main() 
// {
//     int q;
//     cin>>q;
//     while(q--)
//     {
//         char a;
//         string b;
//         cin>>a>>b;
//         if(a=='I')
//         {
//             mp[b]++;
//         }
//         if(a=='Q')
//         {
//             cout<<mp[b]<<'\n';
//         }
//     } 
//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e6+10;

int s[N][26];
int ct[N];
int idx;
void insert(string b)
{
    int q=0;
    for(int i=0;b[i];i++)
    {
        int x=b[i]-'a';
        if(!s[q][x]) idx++,s[q][x]=idx;
        q=s[q][x];
    }
    ct[q]++;
}
int queny(string b)
{
    int q=0;
    for(int i=0;b[i];i++)
    {
        int x=b[i]-'a';
        if(!s[q][x])return 0;
        q=s[q][x];
    }
    return ct[q];
}
int main() 
{
    int q;
    cin>>q;
    while(q--)
    {
        char a;
        string b;
        cin>>a>>b;
        if(a=='I')
        {
            insert(b);
        }
        if(a=='Q')
        {
            cout<<queny(b)<<'\n';
        }
    } 
    return 0;
}