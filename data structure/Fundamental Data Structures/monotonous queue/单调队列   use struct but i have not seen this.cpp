#include<cstdio>
using namespace std;
#define maxn 10000005

long long n,A,B;
struct node
{
   long long value,index;     
}  Q[maxn];

long long ans;


void solve()
{
    long long tmp,head,tail;
    node cur;
    cur.value=1;
    head=0;tail=-1;
    ans=1;
    for (int i=1;i<=n;i++)
    {
        cur.index=i;
        cur.value=(cur.value*A)%B;
        while(head<=tail && Q[tail].value>=cur.value)  tail--;
        Q[++tail]=cur;
        tmp=i-A-1;
        while(Q[head].index<tmp) head++;
        ans=(Q[head].value*ans) %B;
    }
    printf("%lld\n",ans);
    
}
int main(){
   
    while(scanf("%lld%lld%lld",&n,&A,&B)!=EOF)
    {
         solve();                                           
    }
  
    return 0;   
}
