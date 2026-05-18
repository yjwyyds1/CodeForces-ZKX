#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#define inf 0x3f3f3f3f
#define ll long long int
#define dbg1(a) cout<<a<<'\n';
#define dbg2(a, b) cout<<a<<" "<<b<<'\n';
#define dbg3(a, b, c) cout<<a<<" "<<b<<" "<<c<<'\n';
#define f first
#define s second
using namespace std;
const int N=1e6+10;
// int s=strlen(a);
bool f(int x)
{
    if(x<2)
    {
        return 0;
    }
    else
    {
        for(int i=2;i<=x/i;i++)
        {
            if(x%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int _;
    cin>>_;
    while(_--)
    {
        int n;
        cin>>n;
        cout<<(f(n)?"Yes":"No")<<'\n';
    }
    return 0;
}
