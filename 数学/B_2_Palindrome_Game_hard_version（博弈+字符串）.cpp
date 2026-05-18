// #include <bits/stdc++.h>
// const int N=2e5+10;
// const int inf = 0x3f3f3f3f;
// using namespace std;
// using ull = unsigned long long int;
// using ll = long long int;
// using ld = long double;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int _;
//     cin>>_;
//     while(_--){
//         int n;
//         cin>>n;
//         string a;
//         cin>>a;
//         int l=0;
//         for(int i=0;i<a.size();i++){
//             l+=(a[i]=='0');
//         }
//         if(l==0)cout<<"DRAW"<<'\n';
//         else{
//             if(l%2&&l>1){
//                 cout<<"ALICE"<<'\n';
//             }
//             else{
//                 cout<<"BOB"<<'\n';
//             }
//         }
        
//         // if(l==0)
//         // else{
//         //     if(l==1){
//         //         cout<<"BOB"<<'\n';
//         //     }
//         //     else{
//         //         if(n%2){
//         //             if(l==3){
//         //                 cout<<"ALICE"<<'\n';
//         //             }
//         //             else{
//         //                 cout<<
//         //             }
//         //         }
//         //         if(l%2)cout<<"AILCE"<<'\n';
//         //         else{
//         //             cout<<"BOB"<<'\n';
//         //         }
//         //     }
//         // }
        
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// //#define map unordered_map
// #define re register
// #define ll long long
// #define forl(i,a,b) for(re ll i=a;i<=b;i++)
// #define forr(i,a,b) for(re ll i=a;i>=b;i--)
// #define forll(i,a,b,c) for(re ll i=a;i<=b;i+=c)
// #define forrr(i,a,b,c) for(re ll i=a;i>=b;i-=c)
// #define pii pair<ll,ll>
// #define mid ((l+r)>>1)
// #define lowbit(x) (x&-x)
// #define pb push_back
// #define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define endl '\n'
// #define QwQ return 0;
// ll _t_;
// void _clear(){}
// ll n;
// string s;
// bool check(string s)
// {
// 	ll L=1,R=n;
// 	while(L<=R && s[L]==s[R])
// 		L++,R--;
// 	return L>=R;
// }
// /*
// 11010

// 11011 0:1

// 11111 1:1


// 1001101

// 1011001

// 1011101 0:1

// 1111101 1:1

// 1011111
// */
// void solve()
// {
// 	_clear();
// 	cin>>n>>s;
// 	s=' '+s;
// 	if(check(s))
// 	{
// 		ll sum=0;
// 		for(auto i:s)
// 			sum+=i=='0';
// 		if(sum%2==0)
// 		{
// 			cout<<"BOB\n";
// 			return ;
// 		}
// 		if(sum==1)
// 		{
// 			cout<<"BOB\n";
// 			return ;
// 		}
// 		cout<<"ALICE\n";
// 		return ;
// 	}
// 	ll sum=0;
// 	for(auto i:s)
// 		sum+=i=='0';
// 	if(n%2 && sum==2 && s[(n+1)/2]=='0')
// 		cout<<"DRAW\n";
// 	else
// 		cout<<"ALICE\n";
// //	exit(-1);
// }
// int main()
// {
// //	freopen("tst.txt","r",stdin);
// //	freopen("sans.txt","w",stdout);
// 	IOS;
// 	_t_=1;
//  	cin>>_t_;
// 	while(_t_--)
// 		solve();
// 	QwQ;
// }
#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        int l=0,cnt=0;
        for(int i=0;i<a.size();i++){
            l+=(a[i]=='0');
        }
        for(int i=0;i<n/2;i++){
            cnt+=(a[i]!=a[n-i-1]);
        }
        if(cnt==0){
            if(l==0)cout<<"DRAW"<<'\n';
            else{
                if(l%2&&l>1){
                    cout<<"ALICE"<<'\n';
                }
                else{
                    cout<<"BOB"<<'\n';
                }
            }
        }
        else{
            if(n%2&&a[n/2]=='0'&&l==2){
                cout<<"DRAW"<<'\n';
            }
            else{
                cout<<"ALICE"<<'\n';
            }
            // int A=0,B=0;
            // B+=cnt;
            // if(n%2){
            //     if(a[n/2]=='0'){
            //         A++;
            //         l--;
            //         A+=(l-cnt)/2;
            //         B+=((l-cnt)+1)/2;
            //     }
            //     else{
            //         if(l-cnt>0){
            //             A+=(l-cnt)/2+1;
            //             B+=(l-cnt)/2-1;
            //         }
            //     }
            // }
            // else{
            //     if(l-cnt>0){
            //         A+=(l-cnt)/2+1;
            //         B+=(l-cnt)/2-1;
            //     }
            // }
            // if(A!=B){
            //     cout<<(A<B?"ALICE":"BOB")<<'\n';
            // }
            // else{
            //     cout<<"DRAW"<<'\n';
            // }
        }
    }
    return 0;
}