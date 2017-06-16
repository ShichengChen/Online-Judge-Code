#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
#define MAXN 1000005
int arr[MAXN];
set<int>se;
map<int,int>ma;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {

        se.clear(),ma.clear();
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&arr[i]);
            se.insert(arr[i]);
        }
        int total = se.size();
        int minn = n,num = 0;
        for(int i = 0,j = 0;i < n;i++)
        {
            if(ma[arr[i]]++ == 0)num++;
            if(num < total)continue;
            do
            {
                minn = min(minn,i - j + 1);
            }while(--ma[arr[j++]]);
            num--;
        }
        printf("%d\n",minn);
    }
}
