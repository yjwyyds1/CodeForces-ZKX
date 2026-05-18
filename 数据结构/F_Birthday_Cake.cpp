#include <bits/stdc++.h>
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
int mod1=1e9+7,mod2=1e9+11;
int p=13331;
ull p1[N],p2[N];
ull hs1[N],hs2[N];
map<pair<ull,ull>,ull> Z;

void pre(){
    p1[0]=1,p2[0]=1;
    for(int i=1;i<N;i++){
        p1[i]=(p1[i-1]*p)%mod1;
        p2[i]=(p2[i-1]*p)%mod2;
    }
}
pair<ull,ull> get(int L,int R){
    ull get1=(hs1[R]-hs1[L-1]*p1[R-L+1]%mod1+mod1)%mod1;
    ull get2=(hs2[R]-hs2[L-1]*p2[R-L+1]%mod2+mod2)%mod2;
    return {get1,get2};
}

void solve(){
    pre();
    int n;
    cin>>n;
    vector<pair<ull,ull>> b;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int len=s.size();
        s='?'+s;
        for(int j=1;j<=len;j++){
            hs1[j]=(hs1[j-1]*p%mod1+s[j]-'a'+1)%mod1;
            hs2[j]=(hs2[j-1]*p%mod2+s[j]-'a'+1)%mod2;
        }
        // cout<<hs1[len]<<" "<<hs2[len]<<'\n';
        Z[{hs1[len],hs2[len]}]++;
        for(int j=1;2*j<len;j++){
            if(get(1,j)==get(len-j+1,len)){
                b.push_back(get(j+1,len-j));
            }
        }
    }
    ll ans=0;
    for(auto i:Z){
        // cout<<i.second<<'\n';
        ans+=i.second*(i.second-1)/2;
    }
    // cout<<ans<<'\n';
    for(int i=0;i<b.size();i++){
        ans+=Z[b[i]];
    }
    cout<<ans;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    // freopen("zkx.in","r",stdin);
	// freopen("zkx.out","w",stdout);
    int _;
    // cin>>_;
    _=1;
    while(_--){
        solve();
    }
    return 0;
}
