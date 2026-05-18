#include <bits/stdc++.h>
const int N=1e8+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
ll gcd(ll x,ll y){
    if(y){
        return gcd(y,x%y);
    }
    else{
        return x;
    }
}
bool numlist[N];
int prime[N], cnt;
void work(int n){
	for(int i=2; i<=n; i++){
		if(numlist[i]==false)prime[++cnt] = i ;
		for(int j=1; j<=cnt&&i*prime[j]<=n; j++){
			numlist[i*prime[j]] = true ;
			if(i%prime[j]==0){
                break;
            }
		} 
	}
	return;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    work(N);
    // for(int i=1;i<=100;i++){
    //     cout<<prime[i]<<" ";
    // }
    // cout<<'\n';
    int n;
    cin>>n;
    int _;
    cin>>_;
    while (_--)
    {
        int x;
        cin>>x;
        cout<<prime[x]<<'\n';
        // int x,y;
        // cin>>x>>y;
        // if(gcd(x,y)!=1){
        //     cout<<0<<'\n';
        // }
        // else{
        //     if(y-x==1){
        //         cout<<-1<<'\n';
        //     }
        //     else{
        //         int b=y-x;
        //         int a=x;
        //         int ans=1e9;
        //         for(int i=1;prime[i]*prime[i]<=b;i++){
        //             if(b%prime[i]) continue;
        //             while(b%prime[i]==0){
        //                 b/=prime[i];
        //             }
        //             ans=min(ans,prime[i]-a%prime[i]);
        //         }
        //         if (b>1)
        //         {
        //             int t=b;
        //             if(b%t) continue;
        //             while(b%t==0) b/=t;
        //             ans=min(ans,t-a%t);
        //         }
        //         cout<<ans<<'\n';
        //     }
        // }
        
    }
    return 0;
}