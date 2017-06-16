#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAXN 300010
#define SIZE 4096
int num[MAXN],block[MAXN / SIZE + 1][SIZE];
int n,m,u,l,r,v,p;
int query()
{
    int lb = l / SIZE,rb = r / SIZE;
    int k = 0;
    if(lb == rb)
    {
        for(int i = l;i <= r;i++)
            if(num[i] < v)k++;
        return k;
    }
    for(int i = l;i < (lb + 1) * SIZE;i++)
        if(num[i] < v)k++;
    for(int i = rb * SIZE;i <= r;i++)
        if(num[i] < v)k++;
    for(int i = lb + 1;i < rb;i++)
        k += lower_bound(block[i],block[i] + SIZE,v) - block[i];
    return k;
}
void modify(int val)
{
    swap(num[p],val);
    int b = p / SIZE;
    if(b == (n - 1) / SIZE && (p + 1) % SIZE)return;
    int i;
    for(i = 0;;i++)if(val == block[b][i])break;
    block[b][i] = num[p];
    for(;i != SIZE - 1 && block[b][i] > block[b][i + 1];i++)
        swap(block[b][i],block[b][i + 1]);
    for(;i && block[b][i] < block[b][i - 1];i--)
        swap(block[b][i],block[b][i - 1]);
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&u) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
            block[i / SIZE][i % SIZE] = num[i];
        }
        for(int i = 0;i < n / SIZE;i++)
            sort(block[i],block[i] + SIZE);
        while(m--)
        {
            scanf("%d%d%d%d",&l,&r,&v,&p);
            l--,r--,p--;
            int k = query();
            modify((ll)u * k / (r - l + 1));
        }
        for(int i = 0;i < n;i++)
            printf("%d\n",num[i]);
    }
}
