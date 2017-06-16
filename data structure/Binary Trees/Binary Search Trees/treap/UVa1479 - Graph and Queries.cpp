#include<cstdlib>
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
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define MAXE 60060
#define MAXP 20020
#define MAXO 500020
struct Command
{
    char type;
    int x,y;
}command[MAXO];
struct Edge
{
    int u,v;
}edge[MAXE];
int fa[MAXP],w[MAXP];
long long query_tot ;
int query_cnt;
bool removed[MAXE];
Node * root[MAXP];
int findfa(int i)
{
    return fa[i] == i ? fa[i] : fa[i] = findfa(fa[i]);
}
int find_kth(Node * & o,int k)
{
    if(o == NULL || o -> kth < k || k <= 0) return 0;
    int s = (o -> son[1] == NULL) ? 0 : o -> son[1] -> kth;
    if(k - 1 - s == 0)return o -> value;
    else if(k - 1 - s > 0)return find_kth(o -> son[0],k - 1 - s);
    else return find_kth(o -> son[1],k);
}
void merge_tree(Node * & o,Node * & root)///have modify in this point
{
    if(o -> son[0] != NULL)merge_tree(o -> son[0],root);
    if(o -> son[1] != NULL)merge_tree(o -> son[1],root);
    insert(root,o -> value);
    delete o;
    o = NULL;  /// point o is deleted will point to random
}
void delete_tree(Node * & o)///have modified in this point
{
    if(o -> son[0] != NULL)delete_tree(o -> son[0]);
    if(o -> son[1] != NULL)delete_tree(o -> son[1]);
    delete o;
    o = NULL; /// make point point to NULL
}
void add_edge(int i)
{
    int fu = findfa(edge[i].u) , fv = findfa(edge[i].v);
    if(fu != fv)
        if(root[fu] -> kth < root[fv] -> kth)
        {
            fa[fu] = fv;
            merge_tree(root[fu],root[fv]);
        }
        else
        {
            fa[fv] = fu;
            merge_tree(root[fv],root[fu]);
        }
}
void query(int x,int k)
{
    int fx = findfa(x);
    query_cnt ++;
    query_tot += find_kth(root[fx],k);
}
void change_weight(int x,int v)
{
    int fx = findfa(x);
    remove(root[fx],w[x]);
    insert(root[fx],v);
    w[x] = v;   /// this point have been midified;
}
int main()
{
    int n,m,cnt,cas = 1;
    while(scanf("%d%d",&n,&m), m| n)
    {
        memset(removed,false,sizeof(removed));
        cnt = 0;
        for(int i = 1;i <= n;i++) scanf("%d",&w[i]);
        for(int i = 1;i <= m;i++) scanf("%d%d",&edge[i].u,&edge[i].v);
        while(1)
        {
            char op;
            int x,y;
            scanf(" %c",&op);
            if(op == 'D')
            {
                scanf("%d",&x);
                removed[x] = true;
            }
            else if(op == 'Q')   scanf("%d%d",&x,&y);
            else if(op == 'C')
            {
                scanf("%d%d",&x,&y);
                swap(w[x],y);   /// mean this point was changed
            }
            else break;
            command[++cnt] = Command{op,x,y};
        }
        for(int i = 1;i <= n;i++)
        {
            fa[i] = i;
            if(root[i] != NULL)delete_tree(root[i]);
            root[i] = new Node(w[i]);
        }
        for(int i = 1;i <= m;i++)if(removed[i] == 0)
            add_edge(i);
        query_tot = query_cnt = 0;
        for(int i = cnt;i >= 1;i--)
            if(command[i].type == 'D')add_edge(command[i].x);
            else if(command[i].type == 'Q')query(command[i].x,command[i].y);
            else change_weight(command[i].x,command[i].y);
        printf("Case %d: %.6lf\n",cas++,query_tot / (double)query_cnt);
    }
}
