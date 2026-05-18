#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
ll gcd(ll x,ll y){
    return (y?gcd(y,x%y):x);
}
struct Line {
    ll A, B, C;
    Line(ll A, ll B, ll C) {
        int gcd_ab = gcd(A,gcd(B,C));
        this->A = A / gcd_ab;
        this->B = B / gcd_ab;
        this->C = C / gcd_ab;
 
        if (this->A < 0 || (this->A == 0 && this->B < 0)) {
            this->A = -this->A;
            this->B = -this->B;
            this->C = -this->C;
        }
    }
    bool operator<(const Line& other) const {
        return std::tie(A, B, C) < std::tie(other.A, other.B, other.C);
    }
};


Line F(ll x1,ll y1,ll x2,ll y2){
    return Line(2*(y2-y1),2*(x1-x2),(x1*x1+y1*y1)-(x2*x2+y2*y2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        set<Line> s;
        int n;
        cin>>n;
        vector<pair<ll,ll>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
        }
        for(int i=0;i<n;i++){
            cin>>a[i].second;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                s.insert(F(a[i].first,a[i].second,a[j].first,a[j].second));
            }
        }
        cout<<s.size()<<'\n';
    }
    return 0;
}