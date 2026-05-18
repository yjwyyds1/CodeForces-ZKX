#include <iostream>
using namespace std;
const int N=2e7+10;
long long int per[N],f[N],sum[N],ct;
bool v[N];
void in()
{
  f[1]=0;
  for(int i=2;i<=N;i++)
  {
    if(!v[i]) f[i]=i,per[ct++]=i;
    for(int j=0;per[j]<=N/i&&j<ct;j++)
    {
      v[i*per[j]]=1;
      f[i*per[j]]=per[j];
      if(i%per[j]==0)
      {
        break;
      }
    }
  }
}

int main()
{
  int _;
  cin>>_;
  in();
  for(int i=1;i<=N;i++)
  {
    sum[i]=sum[i-1]+f[i];
  }
  while(_--)
  {
    int n;
    cin>>n;
    cout<<sum[n]<<'\n';
  }
  return 0;
}