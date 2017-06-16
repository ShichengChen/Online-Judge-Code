/*
first think clearly about recursion
then write it to iteration (µÝÍÆ£¬µü´ú)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define N 12
#define INF 1 << 30
//#define ss system("pause");
struct Matrix
{
    int left,right;
}matrix[N];
int d[N][N],middle[N][N];
int number_of_A;
void dp(int end)
{
    for(int l = 2;l <=end;l++)
    {
        for(int i = 1;i + l - 1 <= end;i++)
        {
            if(l == 2)
            {
                d[i][i + 1] = matrix[i].left * matrix[i].right * matrix[i + 1].right;
                continue;
            }
            for(int j = i;j < i + l - 1;j++)
            {
                int current = d[i][j] + d[j + 1][i + l - 1] + matrix[i].left * matrix[j].right * matrix[i + l - 1].right;
                if(d[i][i + l - 1] > current)
                {
                    d[i][i + l - 1] = current;
                    middle[i][i + l - 1] = j;
                }
            }
        }
    }
}
void print(int begin,int end)
{
    if(end == begin)
    {
        printf("A%d",number_of_A++);
        return;
    }
    if(end - begin == 1)
    {
        printf("(A%d x A%d)",number_of_A,number_of_A + 1);
        number_of_A += 2;
        return;
    }
    printf("(");
    print(begin,middle[begin][end]);
    printf(" x ");
    print(middle[begin][end] + 1,end);
    printf(")");
}
int main()
{
    int n,T = 1;
    while(scanf("%d",&n) &&  n)
    {
        memset(d,0,sizeof(d));
        memset(matrix,0,sizeof(matrix));
        memset(middle,0,sizeof(middle));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <=n;j++)if(i != j)d[i][j] = INF;
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&matrix[i].left,&matrix[i].right);
        dp(n);
        printf("Case %d: ",T++);
        number_of_A = 1;
        print(1,n);
        printf("\n");
    }
    return 0;
}
