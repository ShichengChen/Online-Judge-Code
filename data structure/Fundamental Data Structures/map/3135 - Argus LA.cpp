#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Node
{
        int period,Q_num,sum;
        bool operator < (const Node & nod)const{
            return sum < nod.sum || (nod.sum == sum && Q_num < nod.Q_num);
        }
};
priority_queue<Node>que;
int main()
{
    int k;
    char s[20];
    while(scanf("%s",s) && s[0] != '#')
    {
        Node node;
        scanf("%d%d",&node.Q_num,&node.period);
        node.sum = node.period;
        que.push(node);
    }
    scanf("%d",&k);
    while(k--)
    {
        Node cur = que.top();   que.pop();
        printf("%d\n",cur.Q_num);
        cur.sum += cur.period;
        que.push(cur);
    }
}
