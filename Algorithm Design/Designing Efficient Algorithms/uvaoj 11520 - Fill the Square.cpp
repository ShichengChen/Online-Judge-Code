#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 12
char ch[MAXN][MAXN];
int main()
{
    int _,n;
    cin >> _;
    for(int kcas = 1;kcas <= _;kcas++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            scanf("%s", ch[i]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)if(ch[i][j] == '.')
                for(char k = 'A';k <= 'Z';k++)
                {
                    bool ok = true;
                    if(i - 1 >= 0 && ch[i - 1][j] == k)ok = false;
                    if(j - 1 >= 0 && ch[i][j - 1] == k)ok = false;
                    if(i + 1 < n && ch[i + 1][j] == k)ok = false;
                    if(j + 1 < n && ch[i][j + 1] == k)ok = false;
                    if(ok)
                    {
                        ch[i][j] = k;
                        break;
                    }
                }
        printf("Case %d:\n", kcas);
        for(int i = 0;i < n;i++)
            printf("%s\n", ch[i]);
    }
}
