#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        string a;
        cin>>a;
        ll t=a.size();
        ll n;
        cin>>n;
        n--;
        ll cnt=0;
        while(n>=t){
            n-=t;
            t--;
            cnt++;
        }
        // cout<<cnt<<" "<<n<<'\n';
        vector<char> s;
        for(int i=0;i<a.size();i++){
            while(cnt&&(!s.empty()&&s.back()>a[i])){
                s.pop_back();
                cnt--;
            }
            s.push_back(a[i]);
        }
        while(cnt)
        {
            s.pop_back();
            cnt--;
        }
        // for(int i=0;i<s.size();i++){
        //     cout<<s[i];
        // }
        // cout<<'\n';
        cout<<s[n];
        // string a;
        // cin>>a;
        // int now=a.size();
        // a=" "+a+" ";//如果已经正序了就一直删最后一个，空格是32
        // int n;
        // cin>>n;
        // vector<char> s;
        // for(int i=1;i<=a.size()+1;i++){
        //     while(now<n&&(!s.empty()&&s.back()>a[i])){
        //         s.pop_back();
        //         n-=now;
        //         now--;
        //     }
        //     s.push_back(a[i]);
        // }
        // // for(int i=0;i<s.size();i++){
        // //     cout<<s[i]<<" ";
        // // }
        // // cout<<'\n';
        // cout<<s[n-1];
    }
    
    
    return 0;
}