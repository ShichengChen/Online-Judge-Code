/*
only fa[x] = y || fa[x] = findfa[y]   is wrong such as this data
// 1 2    3 4   1 3
so need use if(fa[findfa(x)] != findfa(y))
                            fa[findfa(x)] = findfa(y)          //!!!!!!!
odd is pairing
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXP 101000
#define MAXL 202000
int fa[MAXP],odd[MAXP],indu[MAXP],ans;
bool root[MAXP];
void init(int n)
{
    ans = 0;
    memset(root,0,sizeof(root));
    memset(odd,0,sizeof(odd));
    memset(indu,0,sizeof(indu));
    for(int i = 1;i <= n;i++)fa[i] = i;
}
int findfa(int i)
{
   return fa[i] == i ? i : fa[i] =  findfa(fa[i]);
}
int main()
{
    int n, m;
	while (scanf("%d%d",&n, &m) != EOF)
	{
        init(n);
        for(int i = 0;i < m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (x > y)
				x ^= y ^= x ^= y;
            indu[x]++;indu[y]++;
            fa[findfa(x)] = findfa(y);
        }
        for(int i = 1;i <= n;i++)
        {
            int fat = findfa(i);
            if(indu[i] != 0)
                root[fat] = 1;
            if(indu[i] % 2)
                odd[fat] ++;
        }
        for(int i = 1;i <= n;i++)
            if(root[i])ans += odd[i] == 0 ? 1 : odd[i] / 2;
        printf("%d\n",ans);
	}
}
