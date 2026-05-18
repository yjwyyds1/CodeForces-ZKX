#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double 
using namespace std;
const int N=3e5+10;
const int inf = 0x3f3f3f3f;
// cout<<fixed<<setprecision(0)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull n;
    cin>>n;
    cout<<n*(n-1)/2*(n-2)/3*(n-3)/4<<'\n';//C(n,4)
    return 0;
}


