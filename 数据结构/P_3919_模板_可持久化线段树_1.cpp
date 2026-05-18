#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e7 + 10;
int top;
int a[N],root[N];
struct vc{
    int l,r,vl;
}tr[N];


int maketree(int idx,int begin,int end){
	idx=++top;
	if(begin==end){
		tr[idx].vl=a[begin];
		return top;
	}
	int mid=(begin+end)>>1;
	tr[idx].l=maketree(tr[idx].l,begin,mid);
	tr[idx].r=maketree(tr[idx].r,mid+1,end);
	return idx;
}
int update(int idx,int begin,int end,int x,int k){
    top++;
    tr[top]=tr[idx];
    idx=top;
    if(begin==end){
        tr[idx].vl=k;
    }
    else{
        int mid=(begin+end)>>1;
        if(x<=mid){
            tr[idx].l=update(tr[idx].l,begin,mid,x,k);
        }
        else{
            tr[idx].r=update(tr[idx].r,mid+1,end,x,k);
        }
    }
    return idx;
}

int query(int idx,int begin,int end,int x){
    if(begin==end){
        return tr[idx].vl;
    }
    else{
        int mid=(begin+end)>>1;
        if(x<=mid){
            return query(tr[idx].l,begin,mid,x);
        }
        else{
            return query(tr[idx].r,mid+1,end,x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    root[0]=maketree(0,1,n);
    for(int i=1;i<=m;i++){
        int d,p,t;
        cin>>d>>p>>t;
        if(p==1){
            int k;
            cin>>k;
            root[i]=update(root[d],1,n,t,k);
        }else{
            cout<<query(root[d],1,n,t)<<'\n';
            root[i]=root[d];
        }
    }
    return 0; 
}