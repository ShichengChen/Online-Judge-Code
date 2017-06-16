#include<cstdio>
#include<map>
using namespace std;
typedef pair<int ,int> point;
map<int,int>row,column;
map<point,int>fruit;
int main()
{
    int _,n,m,k,i,j,t,cnt=0;
    scanf("%d",&_);
    while(_--)
    {
        row.clear();
        column.clear();
        fruit.clear();
        scanf("%d%d%d",&n,&m,&k);
        while(k--)
        {
            scanf("%d%d%d",&i,&j,&t);
            row[i] = i , column[j] = j;
            fruit[point(j,i)] = t;
        }
        scanf("%d",&k);
        printf("Case #%d:\n",++cnt);
        while(k--)
        {
            int q;
            scanf("%d%d%d",&q,&i,&j);
            if(q==1)
                swap(row[i],row[j]);
            else if(q==2)
                swap(column[i],column[j]);
            else
                printf("%d\n",fruit[point(column[j],row[i])]);
        }
    }
}
