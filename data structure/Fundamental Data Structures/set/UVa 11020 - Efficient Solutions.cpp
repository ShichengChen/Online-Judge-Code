#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
struct Node
{
    int x,y;
    Node(int x,int y) : x(x) , y(y) {}
    bool operator < (const Node & nod)const{
        return (y < nod.y) || (y == nod.y && x < nod.x);
    }
};
multiset<Node>gather;
multiset<Node>::iterator it;
int solve(int x,int y)
{
    it = gather.lower_bound(Node(x,y));
    if(it == gather.begin() || (--it) -> x > x)
    {
        gather.insert(Node(x,y));
        it = gather.upper_bound(Node(x,y));
        while(it != gather.end() && it -> x >= x)gather.erase(it++);
    }
    return gather.size();
}
int main()
{
    int _,n,x,y;
    scanf("%d",&_);
    for(int i = 1;i <= _;i++)
    {
        if(i == 1)printf("Case #%d:\n",i);
        else printf("\nCase #%d:\n",i);
        gather.clear();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&x,&y);
            int ans = solve(x,y);
            printf("%d\n",ans);
        }
    }
}
