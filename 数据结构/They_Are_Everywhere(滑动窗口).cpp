#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll  long long int
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
int n;
string a;
int ct=0;
bool ck(int x){
    map<char,int> mk;
    int t=0;
    for(int i=0;i<x;i++){
        if(!mk[a[i]])t++;
        mk[a[i]]++;
    }
    if(t==ct)return 1;
    for(int i=x;i<n;i++){
        if(!mk[a[i]])t++;
        mk[a[i]]++;
        mk[a[i-x]]--;
        if(mk[a[i-x]]==0)t--;
        if(t==ct){
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>a;
    map<char,int> mp;
    for(int i=0;i<n;i++){
        if(!mp[a[i]])ct++;
        mp[a[i]]++;
    }
    int l=1,r=n;
    int ans=n;
    while(l<=r){
        int mid=l+r>>1;
        if(ck(mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
    // int l=0,r=n-1;
    // for(;l<n;l++){
    //     if(mp[a[l]]==1){
    //         break;
    //     }
    //     else{
    //         mp[a[l]]--;
    //     }
    // }
    // for(;r>=0;r--){
    //     if(mp[a[r]]==1){
    //         break;
    //     }
    //     else{
    //         mp[a[r]]--;
    //     }
    // }
    // cout<<r-l+1<<'\n';

