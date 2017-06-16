#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 1100
#define LON 20
#define ALPH 30
string ss[MAX];
int indu[ALPH],outdu[ALPH],first[ALPH],print[MAX];
bool vis[MAX];
int begin_number,start,cnt;
struct Edge
{
    int v,next;
}edge[MAX];
bool cmp(string str1,string str2)
{
    return str1 > str2;
}
void insert(int x,int y)
{
    edge[begin_number].v = y;
    edge[begin_number].next = first[x];
    first[x] = begin_number++;
}
void init()
{
    begin_number = 0;cnt = 0;
    memset(first,-1,sizeof(first));
    memset(vis,0,sizeof(vis));
    memset(indu,0,sizeof(indu));
    memset(outdu,0,sizeof(outdu));
}
bool connection()
{
    int in = 0,out = 0;
    for(int i = 26;i >= 0;i--)
        if(indu[i] - outdu[i] == 1)  // odd only can be two or zero
        {
            out++;
            start = i;
        }
        else if(outdu[i] - indu[i] == 1)
            in++;
        else if(indu[i] == outdu[i])
        {
            if(indu[i] && !in && !out)
                start = i;
        }
        else return false;
    if(in > 1 || out > 1 || in != out)return false;
    return true;
}
void Euler(int start)
{
    for(int index = first[start];index != -1;index = edge[index].next)
        if(!vis[index])
        {
            vis[index] = 1;
            Euler(edge[index].v);
            print[cnt++] = index;
        }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        init();
        for(int i = 0;i < n;i++)
            cin >> ss[i];
        sort(ss,ss + n,cmp);
        for(int i = 0;i < n;i++)
        {
            insert((int)ss[i][0] - 'a',(int)ss[i][ss[i].size() - 1] - 'a');   // insert is not in  opposite order
            indu[(int)ss[i][0] - 'a']++;
            outdu[(int)ss[i][ss[i].size() - 1] - 'a']++;
        }
        if(!connection())
        {
            puts("***");
            continue;
        }
        Euler(start);
        if(cnt == n)for(int i = n - 1;i >= 0;i--)     // when map is separated into two part use this to judge
        {
            if(i == 0)cout << ss[print[i]] << endl;
            else cout << ss[print[i]] << '.';
        }
        else puts("***");
    }
}
