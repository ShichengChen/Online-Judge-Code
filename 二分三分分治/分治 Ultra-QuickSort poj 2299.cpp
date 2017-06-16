#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<string>
#include<cmath>
using namespace std;
#define MAX 500500
int array[MAX],cur[MAX];
long long sum;
void merge(int l,int r,int mid)
{
    int i = l,j = mid + 1,begin = l;
    while(i <= mid || j <= r)
    {
        if(j > r || i <= mid && array[i] <= array[j])
            cur[begin++] = array[i++];
        else
        {
            sum += (j - begin);
            cur[begin++] = array[j++];
        }
    }
    for(int i = l;i <= r;i++)
        array[i] = cur[i];
}
void merge_sort(int l,int r)
{
    if(l == r)return;
    int mid = (l + r) / 2;
    merge_sort(l,mid);
    merge_sort(mid + 1,r);
    merge(l,r,mid);
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&array[i]);
        sum = 0;
        merge_sort(1,n);
        printf("%lld\n",sum);
    }
}
