#include <bits/stdc++.h>
const int N=1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    getline(cin,a);
    int Z=1,F=0;
    int n;
    for(int i=0;i<a.size();i++){
        if(a[i]=='+')Z++;
        if(a[i]=='-')F++;
        if(a[i]=='=')n=stoi(a.substr(i+1));
    }
    stack<int> z,f; 
    int ok=1;
    // cout<<Z<<" "<<F<<" "<<n<<'\n';
    if(Z>=F){
        if(Z-F<n){//Z==F
            if(Z==F){
                if(Z<2)ok=0;
                else{
                    if(n>=2){
                        z.push(n),z.push(2);
                        for(int i=3;i<=Z;i++)z.push(1);
                        for(int i=1;i<=F;i++)f.push(1);
                    }
                    else{
                        ok=0;
                    }
                }
            }
            else{
                z.push(n-(Z-F-1));
                for(int i=2;i<=Z;i++)z.push(1);
                for(int i=1;i<=F;i++)f.push(1);
            }
        }
        // else if(Z-F==n){
        //     for(int i=1;i<=Z;i++)z.push(1);
        //     for(int i=1;i<=F;i++)f.push(1);
        // }
        else if(Z-F>=n){
            if(Z-F*n>n)ok=0;
            else{
                for(int i=1;i<=Z;i++)z.push(1);
                int c=Z-F-n;
                for(int i=1;i<=F;i++){
                    if(c>0){
                        if(c>=n-1){
                            f.push(n);
                            c-=n-1;
                        }else{
                            f.push(c+1);
                            c=0;
                        }
                    }
                    else{
                        f.push(1);
                    }
                }
            }
        }
    }
    else if(Z<F){
        if(Z*n-F<n){
            ok=0;
        }
        else{
            int c=F-Z+n;
            // cout<<c<<'\n';
            for(int i=1;i<=F;i++)f.push(1);
            for(int i=1;i<=Z;i++){
                if(c>0){
                    if(c>=n-1){
                        z.push(n);
                        c-=n-1;
                    }else{
                        z.push(c+1);
                        c=0;
                    }
                }
                else{
                    z.push(1);
                }
            }
        }
    }
    if(ok){
        cout<<"Possible"<<'\n';
        for(int i=0;i<a.size();i++){
            if(a[i]=='?'){
                if(i==0){
                    cout<<z.top();
                    z.pop();
                }
                else{
                    if(a[i-2]=='+'){
                        cout<<z.top();
                        z.pop();
                    }
                    if(a[i-2]=='-'){
                        cout<<f.top();
                        f.pop();
                    }
                }
            }
            else{
                cout<<a[i];
            }
        }
    }
    else{
        cout<<"Impossible"<<'\n';
    }
    // if(Z>=F){
    //     if(F*n+n<Z)cout<<"Impossible"<<'\n';
    //     else{
    //         cout<<"Possible"<<'\n';
    //         stack<int> f;
    //         while(Z){
    //             f.push(min(n,Z-(F-1)));
    //             Z-=min(n,Z-(F-1));
    //             F--;
    //         }
    //         for(int i=1;i<a.size();i++){
    //             if(a[i]=='?'&&a[i-2]=='+'){
    //                 cout<<1;
    //             }
    //             else if(a[i]=='?'&&a[i-2]=='-'){
    //                 cout<<f.top();
    //                 f.pop();
    //             }else{
    //                 cout<<a[i];
    //             }
    //         }
    //     }
    // }
    // else if(F>Z){
    //  if(Z*n<F)cout<<"Impossible"<<'\n';
    //     else{
    //         cout<<"Possible"<<'\n';
    //         cout<<n;
    //         stack<int> f;
    //         while(Z){
    //             f.push(min(n,Z-(F-1)));
    //             Z-=min(n,Z-(F-1));
    //             F--;
    //         }
    //         for(int i=1;i<a.size();i++){
    //             if(a[i]=='?'&&a[i-2]=='+'){
    //                 cout<<1;
    //             }
    //             else if(a[i]=='?'&&a[i-2]=='-'){
    //                 cout<<f.top();
    //                 f.pop();
    //             }else{
    //                 cout<<a[i];
    //             }
    //         }
    //     }
    // }
    return 0;
}
