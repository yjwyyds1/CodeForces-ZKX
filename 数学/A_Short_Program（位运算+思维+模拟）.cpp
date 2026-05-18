#include <bits/stdc++.h>
const int N=2e5+9;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<char,int>> a(n+1);
    vector<char> b(10,'?');
    for(int i=1;i<=n;i++){
        char c;
        int x;
        cin>>c>>x;
        a[i]={c,x};
        if(c=='&'){
            for(int j=9;j>=0;j--){
                if((x>>j&1)==0){
                    b[j]='0';
                }
            }
        }
        if(c=='|'){
            for(int j=9;j>=0;j--){
                if((x>>j&1)==1){
                    b[j]='1';
                }
            }
        }
        if(c=='^'){
            for(int j=9;j>=0;j--){
                if(b[j]!='?'){
                    int ee=int(b[j]-'0');
                    if(ee==(x>>j&1)){
                        b[j]='0';
                    }
                    else{
                        b[j]='1';
                    }
                }
                
            }
        }
    }
    int ah=0;
    int ayh=0;
    int ay=0;
    for(int i=0;i<=9;i++){
        if(b[i]=='?'){
            vector<int> U(2);
            for(int k=0;k<=1;k++){
                U[k]=k;
                for(int t=1;t<=n;t++){
                    if(a[t].first=='&'){
                        U[k]&=(a[t].second>>i&1);
                    }
                    if(a[t].first=='|'){
                        U[k]|=(a[t].second>>i&1);
                    }
                    if(a[t].first=='^'){
                        U[k]^=(a[t].second>>i&1);
                    }
                }
            }
            if(U[0]==U[1]){
                if(U[0]==1){
                    ayh+=(1<<i);
                }
            }
            else{
                if(U[0]==0&&U[1]==1){
                    ay+=1<<i;
                }
                if(U[0]==1&&U[1]==0){
                    ay+=1<<i;
                    ayh+=1<<i;
                }
            }
        }
        else{
            if(b[i]=='1'){
                ah+=(1<<i);
            }
        }
    }
    cout<<3<<'\n';
    cout<<'&'<<" "<<ay<<'\n';
    cout<<'|'<<" "<<ah<<'\n';
    cout<<'^'<<" "<<ayh<<'\n';
    return 0;
}