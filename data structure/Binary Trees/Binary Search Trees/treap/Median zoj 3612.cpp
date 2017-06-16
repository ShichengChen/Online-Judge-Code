#include<cstdlib>
#include<iostream>
using namespace std;
struct Node
{
    int value,rank,kth;
    Node * son[2];
    Node(int value) : value(value) {
        son[0] = son[1] = NULL;
        rank = rand();
        kth = 1;
    }
    bool operator < (const Node & nod)const{
        return rank < nod.rank;
    }
    int cmp(int val){
        if(value == val)return -1;
        return val < value ? 0 : 1;
    }
    void maintain(){
        kth = 1;
        if(son[0] != NULL)kth += son[0] -> kth;
        if(son[1] != NULL)kth += son[1] -> kth;
    }
};
void rotate(Node * & o,int d)
{
    Node * k = o -> son[1 ^ d];
    o -> son[1 ^ d] = k -> son[d];
    k -> son[d] = o;
    o -> maintain();
    k -> maintain();
    o = k;
}
void insert(Node * & o,int val)
{
    if(o == NULL) o = new Node(val);
    else
    {
        int d = val < o -> value ? 0 : 1;
        insert(o -> son[d],val);
        if(o < o -> son[d])rotate(o,d ^ 1);
    }
    o -> maintain();///maintain inserted point's ancestors
}
void remove(Node * & o,int val)
{
    int d = o -> cmp(val);
    if(d == -1)
    {
        Node * u = o;
        if(o -> son[0] != NULL && o -> son[1] != NULL)
        {
            bool d2 = o -> son[0] < o -> son[1];
            rotate(o,d2 ^ 1);
            remove(o -> son[d2 ^ 1],val);
        }
        else
        {
            if(o -> son[0] == NULL)  o = o -> son[1];
            else    o = o -> son[0];
            delete u;
        }
    }
    else
        remove(o -> son[d],val);
    if(o != NULL)o -> maintain(); ///o maybe point to the NULL
}
#include<cstdio>
bool find(Node * o , int val)
{
    while(o != NULL)
    {
        int d = o -> cmp(val);
        if(d == -1)return true;
        o = o -> son[d];
    }
    return false;
}
int findkth(Node * & o , int k)
{
    int d = (o -> son[1] == NULL ? 0 : o -> son[1] -> kth);
    if(k - d - 1 == 0)return o -> value;
    else if(k - d - 1 > 0) return findkth(o -> son[0] , k - d - 1);
    return findkth(o -> son[1] , k);
}
void deletetree(Node * & o)
{
    if(o == NULL)return;
    if(o -> son[0] != NULL)deletetree(o -> son[0]);
    if(o -> son[1] != NULL)deletetree(o -> son[1]);
    delete o;
    o = NULL;
}
void findm(Node * & o)
{
    int all = o -> kth;
    if((all & 1) == 1)
    {
         int ans = findkth(o , all / 2 + 1);
         printf("%d\n",ans);
         return;
    }
    long long ans = 1ll * findkth(o , all / 2 + 1) + findkth(o , all / 2);
    if(ans & 1)printf("%.1f\n",ans * 1.0 / 2);
    else printf("%lld\n",ans / 2);
}
int main()
{
    int _,n,x;
    char op[10];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        Node * o = NULL;
        deletetree(o);
        while(n--)
        {
            scanf("%s%d",op,&x);
            if(op[0] == 'r')
            {
                if(!find(o , x))puts("Wrong!");
                else
                {
                    remove(o,x);
                    if(o == NULL)puts("Empty!");
                    else findm(o);
                }
            }
            else
            {
                insert(o , x);
                findm(o);
            }
        }
    }
}
